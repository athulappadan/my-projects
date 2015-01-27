#include "helper.h"

struct node *eval(struct node *x, struct node *envNode)
{
        if (x == NULL) {
                printf("x is nil\n");
                return NULL;
        }
        if (x->flag == 's') {
                char *var = x->str;
                return findEnv(var, envNode)[hash(var)];
        }

        else if (x->flag != 'l')
                return copyNode(x);

        else if (x->list->flag == 's' && strcmp(x->list->str, "quote") == 0)
                return x->list->next;

        else if (x->list->flag == 's' && strcmp(x->list->str, "if") == 0) {
                struct node *test, *conseq, *alt, *cond;

                test = copyNode(x->list->next);
                conseq = copyNode(x->list->next->next);
                alt = x->list->next->next->next;

                cond = eval(test, envNode);

                switch(cond->flag) {
                        case 'i':
                                if (cond->num)
                                        return eval(conseq, envNode);
                        case 'f':
                                if (cond->f)
                                        return eval(conseq, envNode);
                        case 'S':
                                if (cond->str)
                                        return eval(conseq, envNode);
                }
                return eval(alt, envNode);
        }

        else if (x->list->flag == 's' && strcmp(x->list->str, "define") == 0) {
                char *var = x->list->next->str;
                struct node *exp = x->list->next->next;
                envNode->currentEnv[hash(var)] = eval(exp, envNode);
                return NULL;
        }

        else if (x->list->flag == 's' && strcmp(x->list->str, "set!") == 0) {
                char *var = x->list->next->str;
                struct node *exp = x->list->next->next;
                findEnv(var, envNode)[hash(var)] = eval(exp, envNode);
                return NULL;
        }

        else if (x->list->flag == 's' && strcmp(x->list->str, "lambda") == 0) {
                struct node *new = (struct node *) malloc(sizeof(struct node));

                new->flag = 'p';
                new->parms = x->list->next->list;
                new->body = x->list->next->next;
                new->env = envNode;
                new->next = NULL;
                return new;
        }

        else {
                struct node *proc, *current, *args = NULL;
                proc = eval(copyNode(x->list), envNode);
                current = x->list->next;
                while (current != NULL) {
                        appendNode(&args, copyNode(eval(current, envNode)));
                        current = current->next;
                }

                if (proc->flag == 'p')
                        return eval(proc->body, Env(proc->parms, args, proc->env));
                else
                        return (proc->fptr)(args);
        }
}

struct node *Env(struct node *parms, struct node *args, struct node *envNode)
{
        struct node *new = (struct node *) malloc(sizeof(struct node));
        new->flag = 'e';
        new->currentEnv = (struct node **) calloc(HASHSIZ, sizeof(struct node *));
        new->outerEnv = envNode;
        new->next = NULL;

        while (parms != NULL && args != NULL) {
                new->currentEnv[hash(parms->str)] = copyNode(args);
                parms = parms->next;
                args = args->next;
        }

        return new;
}

struct node **findEnv(char *w, struct node *envNode)
{
        struct node *env = NULL;

        if (envNode == NULL) {
                printf("error: unknown variable %s\n", w);
                exit(0);
        }

        if ((env = envNode->currentEnv[hash(w)]) != NULL)
                return envNode->currentEnv;

        return findEnv(w, envNode->outerEnv);
}

struct node *copyNode(struct node *old)
{
        if (old == NULL)
                return NULL;

        struct node *new = (struct node *) malloc(sizeof(struct node));
        *new = *old;
        new->next = NULL;
        return new;
}


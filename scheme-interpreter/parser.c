#include "helper.h"

struct node *parse(char *program)
{
        struct node *head = NULL;

        head = tokenize(program);

        return read_from_tokens(&head);
}

struct node *tokenize(char *p)
{
        char word[MAX], *w;
        struct node *head = NULL;

        while (*p) {
                w = word;
                while (isspace(*p))
                        ++p;
                if (*p == '\0')
                        return head;
                else if (*p == '(' || *p == ')') {
                        *w++ = *p++;
                        *w = '\0';
                        appendNode(&head, newNode(word));
                }
                else {
                        while (*p && !isspace(*p) && *p != '(' && *p != ')')
                                *w++ = *p++;
                        *w = '\0';
                        appendNode(&head, newNode(word));
                }
        }
        return head;
}

struct node *newNode(char *w)
{
        struct node *h = NULL;

        if (h = isNumber(w)) {
                h->next = NULL;
                return h;
        }
        else
                return isString(w);
}

void appendNode(struct node **hRef, struct node *new)
{
        struct node *current = *hRef;

        if (current == NULL) {
                *hRef = new;
                return;
        }
        while (current->next != NULL)
                current = current->next;
        current->next = new;
}

struct node *isNumber(char *w)
{
        int i = 0;
        int sign = 1;
        long sum = 0;
        double frac = 0;

        struct node *new = NULL;

        if (*w == '-') {
                sign = -1;
                if (*++w == '\0')
                        return new;      // just a symbol '-'
        }
        while (isdigit(*w)) {
                sum = sum * 10 + (*w - '0');
                w++;
        }
        if (*w == '\0') {
                new = (struct node *) malloc(sizeof(struct node));
                new->num = sum * sign;
                new->flag = 'i';
                return new;
        }
        else if (*w == '.') {
                ++w;
                while (isdigit(*w)) {
                        frac = frac * 10.0 + (*w - '0');
                        ++w;
                        ++i;
                }
                if (*w == '\0') {
                        new = (struct node *) malloc(sizeof(struct node));
                        new->f = ((double)sum + frac/power(10, i)) * sign;
                        new->flag = 'f';
                        return new;
                }
        }
        return new;
}

struct node *isString(char *w)
{
        char *str;
        int len = strlen(w);
        struct node *h = (struct node *) malloc(sizeof(struct node));

        if (*w == '"' && *(w+len-1) == '"') {      // literal string
                str = (char *) calloc(len-1, sizeof(char));
                strncpy(str, w+1, len-2);
                str[len-2] = '\0';
                h->flag = 'S';
        }
        else {
                str = strdup(w);
                h->flag = 's';
        }
        h->str = str;
        h->next = NULL;
        return h;
}

double power(int base, int exp)
{
        double acc = 1.0;

        while (exp-- > 0)
                acc = acc * base;
        return acc;
}

struct node *read_from_tokens(struct node **tokens)
{
        struct node *token;

        token = pop(tokens);

        if (token != NULL && (token->flag == 'S' || token->flag == 's') && strcmp(token->str, "(") == 0) {
                struct node *L = (struct node *) malloc(sizeof(struct node));
                L->flag = 'l';
                L->list = NULL;
                L->next = NULL;

                while ((*tokens)->flag != 's' || strcmp((*tokens)->str, ")") != 0)
                        appendNode(&(L->list), read_from_tokens(tokens));

                pop(tokens);    // pop last ')'
                return L;
        }
        else
                return token;
}

struct node *pop(struct node **hRef)
{
        struct node *temp = *hRef;

        if (temp == NULL)
                return NULL;
        *hRef = (*hRef)->next;
        temp->next = NULL;

        return temp;
}


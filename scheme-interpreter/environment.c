#include "helper.h"

struct node *StandardEnv(void)
{
        struct node *new = (struct node *) malloc(sizeof(struct node));
        struct node **env = (struct node **) calloc(HASHSIZ, sizeof(struct node *));

        env[hash("+")]      =   updateEnv(add, "+");
        env[hash("-")]      =   updateEnv(sub, "-");
        env[hash("*")]      =   updateEnv(mul, "*");
        env[hash("/")]      =   updateEnv(div_, "/");

        env[hash(">")]      =   updateEnv(gt, ">");
        env[hash("<")]      =   updateEnv(lt, "<");
        env[hash(">=")]     =   updateEnv(ge, ">=");
        env[hash("<=")]     =   updateEnv(le, "<=");

/*        env[hash("sqrt")]   =   updateEnv(sqroot, "sqrt");
        env[hash("abs")]    =   updateEnv(absVal, "abs");
        env[hash("pow")]    =   updateEnv(pow, "pow");
        env[hash("exp")]    =   updateEnv(expt, "exp");
        env[hash("cos")]    =   updateEnv(cosine, "cos");
        env[hash("sin")]    =   updateEnv(sine, "sin");
        env[hash("log")]    =   updateEnv(logthm, "log"); */

        env[hash("begin")]  =   updateEnv(begin, "begin");
        env[hash("min")]    =   updateEnv(min, "min");
        env[hash("max")]    =   updateEnv(max, "max");
        env[hash("len")]    =   updateEnv(len, "len");
        env[hash("cdr")]    =   updateEnv(cdr, "cdr");
        env[hash("car")]    =   updateEnv(car, "car");
//        env[hash("cons")]   =   updateEnv(cons, "cons"); 

        env[hash("pi")]     =   newNode("3.14"); 

        new->flag = 'e';
        new->currentEnv = env;
        new->outerEnv = NULL;
        new->next = NULL;

        return new;
}

long hash(char *w)
{
        int i = 0;
        long val = 0;

        while (*w) {
                val = val + (*w) * power(10, i);
                w++;
                i++;
        }
        return val%HASHSIZ;
}

struct node *updateEnv(struct node *(*fptr) (struct node *), char *s)
{
        struct node *new = (struct node *) malloc(sizeof(struct node));

        new->flag = 'F';
        new->fptr = fptr;
        new->str = strdup(s);
        new->next = NULL;

        return new;
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#define MAX         100
#define MAXINPUT    5000
#define HASHSIZ     1000

struct node {
        long num;                       //  flag =  'i'
        double f;                       //          'f'
        char *str;                      //          's'
        struct node *list;              //          'l'

        struct node *(*fptr) (struct node *);  //   'F'

        struct node **currentEnv;       //          'e'
        struct node *outerEnv;          //          'e'

        struct node *parms;             //          'p'
        struct node *body;              //          'p'
        struct node *env;               //          'p'

        char flag;
        struct node *next;
};

/* parse functions                      */

struct node *parse(char *);
struct node *tokenize(char *);
struct node *newNode(char *);
void appendNode(struct node **, struct node *);
struct node *isNumber(char *);
struct node *isString(char *);
double power(int, int);

struct node *read_from_tokens(struct node **);
struct node *pop(struct node **);

/* environment methods                  */

struct node *StandardEnv(void);
long hash(char *);
struct node *updateEnv(struct node *(*fptr) (struct node *), char *s);


/* eval functions                       */

struct node *eval(struct node *, struct node *);
struct node *Env(struct node *, struct node *, struct node *);
struct node **findEnv(char *, struct node *);
struct node *copyNode(struct node *);


/* main                                 */

void repl(void);
void show(struct node *);


/* math library functions               */

int length(struct node *);

struct node *add(struct node *);
struct node *sub(struct node *);
struct node *mul(struct node *);
struct node *div_(struct node *);

struct node *gt(struct node *);
struct node *lt(struct node *);
struct node *ge(struct node *);
struct node *le(struct node *);

struct node *begin(struct node *);
struct node *car(struct node *);
struct node *cdr(struct node *);
struct node *len(struct node *);
struct node *max(struct node *);
struct node *min(struct node *);

struct node *sqroot(struct node *);
struct node *absVal(struct node *);
struct node *powr(struct node *);
struct node *expt(struct node *);
struct node *cosine(struct node *);
struct node *sine(struct node *);
struct node *logBe(struct node *);

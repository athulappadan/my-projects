#define MAX 100

enum datakind {Char, String};

struct node {
        union {
                char chr;
                char buf[MAX];
        };
        enum datakind kind;
        int frq;
        char *code;
        struct node *next;
        struct node *left;
        struct node *right;
};

/* tree functions       */

void make_tree(struct node **);
void assign_code(struct node *, char *, char *);
void show_all(struct node *);
void char_to_str(char, char *);


/* list functions       */

void push(struct node **, int, char);
struct node *make_list(char *);

int length(struct node *);
struct node *pop(struct node **);

/* sort functions       */

void mergeSort(struct node **);
void FrontBackSplit(struct node *, struct node **, struct node **);
struct node *sortedMerge(struct node*, struct node *);
void moveNode(struct node **, struct node **);
void append(struct node **, struct node *);

/* main functions       */

void encode(char *, struct node *);
void decode(struct node *, char *);
struct node *find(struct node *, char);


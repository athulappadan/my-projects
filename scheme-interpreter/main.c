#include "helper.h"

main()
{
        repl();
}

void repl(void)
{
        char *quit;
        char program[MAXINPUT];
        struct node *result, *global_env;

        global_env = StandardEnv();
        while (1) {
                result = NULL;
                printf("scheme->");

                if ((quit = fgets(program, MAXINPUT, stdin)) == NULL) {
                        printf("\nEnd of input stream reached\nMoriturus te saluto!!!\n");
                        exit(0);
                }
                printf("\n");

                if (result = eval(parse(program), global_env)) {

                        printf("Value: ");
                        show(result);
                        printf("\n");
                }
                else 
                        printf("(none)\n");
        }
}

void show(struct node *current)
{
        if (current == NULL)
                return ;

        switch(current->flag) {
                case 'i':           //  int
                        printf("%ld", current->num);
                        break;
                case 'f':           //  float
                        printf("%f", current->f);
                        break;
                case 'F':           // function
                        printf("<built-in function %s>", current->str);
                        break;
                case 'S':           //  string
                        printf(" \"%s\"", current->str);
                        break;
                case 's':           //  symbol
                        printf("%s", current->str);
                        break;
                case 'p':           //  procedure
                        printf("scheme Procedure object at %p>", current);
                        break;
                case 'l':           //  list
                        printf(" (");
                        show(current->list);
                        printf(" )");
                        break;
        }

        show(current->next);
}



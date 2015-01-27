#include "helper.h"

int length(struct node *current)
{
        int len = 0;

        while (current != NULL) {
                len++;
                current = current->next;
        }

        return len;
}

struct node *add(struct node *head)
{
        double result;
        int flagi = 0;
        int flagf = 0;
        long resulti = 0;
        double resultf = 0;
        struct node *new = NULL;

        while (head != NULL) {
                switch(head->flag) {
                        case 'i':
                                resulti += head->num;
                                flagi = 1;
                                break;
                        case 'f':
                                resultf += head->f;
                                flagf = 1;
                                break;
                        case 'S':
                                printf("error> the object \"%s\" passed as argument to + is of incorrect type\n", head->str);
                                exit(0);
                }
                head = head->next;
        }

        new = (struct node *) malloc(sizeof(struct node));

        if ((flagi && flagf) || flagf) {
                new->flag = 'f';
                new->f = (double) resulti + resultf;
        }

        else if (flagi) {
                new->flag = 'i';
                new->num = resulti;
        }
        else {
                new->flag = 'i';
                new->num = 0;
        }
        new->next = NULL;

        return new;
}

struct node *sub(struct node *head)
{
        int flagi = 0;
        int flagf = 0;
        long resulti = 0;
        double resultf = 0;
        struct node *new = NULL;

        if (length(head) > 1) {
                switch(head->flag) {
                        case 'i':
                                resulti = head->num;
                                flagi = 1;
                                break;
                        case 'f':
                                resultf = head->f;
                                flagf = 1;
                                break;
                        case 'S':
                                printf("error> The object \"%s\", passed as argument is not the correct type\n", head->str);
                                exit(0);
                }
                head = head->next;
        }

        while (head != NULL) {
                switch(head->flag) {
                        case 'i':
                                resulti -= head->num;
                                flagi = 1;
                                break;
                        case 'f':
                                resultf -= head->f;
                                flagf = 1;
                                break;
                        case 'S':
                                printf("error> The object \"%s\", passed as argument is not the correct type\n", head->str);
                                exit(0);
                }
                head = head->next;
        }

        new = (struct node *) malloc(sizeof(struct node));
        if ((flagi && flagf) || flagf) {
                new->flag = 'f';
                new->f = (double) resulti + resultf;
        }
        else if (flagi) {
                new->flag = 'i';
                new->num = resulti;
        }
        else {
                new->flag = 'i';
                new->num = 0;
        }
        new->next = NULL;

        return new;
}

struct node *mul(struct node *head)
{
        int flagi = 0;
        int flagf = 0;
        long resulti = 1;
        double resultf = 1;
        struct node *new = NULL;

        while (head != NULL) {
                switch(head->flag) {
                        case 'i':
                                resulti *= head->num;
                                flagi = 1;
                                break;
                        case 'f':
                                resultf *= head->f;
                                flagf = 1;
                                break;
                        case 'S':
                                printf("error> The object \"%s\", passed as argument is not the correct type\n", head->str);
                                exit(0);
                }
                head = head->next;
        }

        new = (struct node *) malloc(sizeof(struct node));
        if ((flagi && flagf) || flagf) {
                new->flag = 'f';
                new->f = (double)resulti * resultf;
        }
        else if (flagi) {
                new->flag = 'i';
                new->num = resulti;
        }
        else {
                new->flag = 'i';
                new->num = 0;
        }
        new->next = NULL;

        return new;
}

struct node *div_(struct node *head)
{
        int len = 0;
        int flagi = 0;
        int flagf = 0;
        long resulti = 1;
        double resultf = 1;
        struct node *new = NULL;
        struct node *current = head;

        while (current != NULL) {
                len++;
                if (current->flag == 'f')
                        flagf = 1;
                current = current->next;
        }

        if (len > 1) {
                switch(head->flag) {
                        case 'i':
                                if (flagf)
                                        resultf = (double) head->num;
                                else
                                        resulti = head->num;
                                flagi = 1;
                                break;

                        case 'f':
                                resultf = head->f;
                                flagf  = 1;
                                break;

                        case 'S':
                                printf("error> The object \"%s\", passed as argument is not the correct type\n", head->str);
                                exit(0);
                }
                head = head->next;
        }

        while (head != NULL) {
                switch(head->flag) {
                        case 'i':
                                if (flagf)
                                        resultf /= (double) head->num;
                                else
                                        resulti /= head->num;
                                break;
                        case 'f':
                                resultf /= head->f;
                                break;
                        case 'S':
                                printf("error> The object \"%s\", passed as argument is not the correct type\n", head->str);
                                exit(0);
                }
                head= head->next;
        }

        new = (struct node *) malloc(sizeof(struct node));
        if ((flagi && flagf) || flagf) {
                new->flag = 'f';
                new->f = (double)resulti * resultf;
        }
        else if (flagi) {
                new->flag = 'i';
                new->num = resulti;
        }
        else {
                new->flag = 'i';
                new->num = 1;
        }

        new->next = NULL;
        return new;
}

struct node *gt(struct node *head)
{
        double x, y;
        struct node *new = (struct node *) malloc(sizeof(struct node));

        if ((length(head)) < 2) {
                new->flag = 'i';
                new->num = 1;
                new->next = NULL;
                return new;
        }

        switch(head->flag) {
                case 'i':
                        x = (double) head->num;
                        break;
                case 'f':
                        x = head->f;
                        break;
                case 'S':
                        printf("error> The object \"%s\", passed as the first argument to > is not the correct object\n", head->str);
                        exit(0);
        }

        head = head->next;

        while (head != NULL) {
                switch(head->flag) {
                        case 'i':
                                y = (double) head->num;
                                break;
                        case 'f':
                                y = head->f;
                                break;
                        case 'S':
                                printf("error> The object \"%s\", passed as the first argument to > is not the correct object\n", head->str);
                                exit(0);
                }
                if (x <= y) {
                        new->flag = 'i';
                        new->num = 0;
                        new->next = NULL;
                        return new;
                }
                x = y;
                head = head->next;
        }

        new->flag = 'i';
        new->num = 1;
        new->next = NULL;
        return new;
}

struct node *lt(struct node *head)
{
        double x, y;
        struct node *new = (struct node *) malloc(sizeof(struct node));

        if ((length(head)) < 2) {
                new->flag = 'i';
                new->num  = 1;
                new->next = NULL;
                return new;
        }

        switch(head->flag) {
                case 'i':
                        x = (double) head->num;
                        break;
                case 'f':
                        x = head->f;
                        break;
                case 'S':
                        printf("error> The object \"%s\", passed as the first argument to > is not the correct object\n", head->str);
                        exit(0);
        }

        head = head->next;
        while(head != NULL) {
                switch(head->flag) {
                        case 'i':
                                y = (double) head->num;
                                break;
                        case 'f':
                                y = head->f;
                                break;
                        case 'S':
                                printf("error> The object \"%s\", passed as the first argument to > is not the correct object\n", head->str);
                                exit(0);
                }
                if (x >= y) {
                        new->flag = 'i';
                        new->num = 0;
                        new->next = NULL;
                        return new;
                }
                x = y;
                head = head->next;
        }

        new->flag = 'i';
        new->num = 1;
        new->next = NULL;
        return new;
}

struct node *ge(struct node *head)
{
        double x, y;
        struct node *new = (struct node *) malloc(sizeof(struct node));

        if ((length(head)) < 2) {
                new->flag = 'i';
                new->num = 1;
                new->next = NULL;
                return new;
        }

        switch(head->flag) {
                case 'i':
                        x = (double) head->num;
                        break;
                case 'f':
                        x = head->f;
                        break;
                case 'S':
                        printf("error> The object \"%s\", passed as the first argument to > is not the correct object\n", head->str);
                        exit(0);
        }
        head = head->next;

        while (head != NULL) {
                switch(head->flag) {
                        case 'i':
                                y = (double) head->num;
                                break;
                        case 'f':
                                y = head->f;
                                break;
                        case 'S':
                                printf("error> The object \"%s\", passed as the first argument to > is not the correct object\n", head->str);
                                exit(0);
                }
                if (x < y) {
                        new->flag = 'i';
                        new->num = 0;
                        new->next = NULL;
                        return new;
                }
                x = y;
                head = head->next;
        }

        new->flag = 'i';
        new->num = 1;
        new->next = NULL;
        return new;
}

struct node *le(struct node *head)
{
        double x, y;
        struct node *new = (struct node *) malloc(sizeof(struct node));

        if ((length(head)) < 2) {
                new->flag = 'i';
                new->num = 1;
                new->next = NULL;
                return new;
        }

        switch(head->flag) {
                case 'i':
                        x = (double) head->num;
                        break;
                case 'f':
                        x = head->f;
                        break;
                case 'S':
                        printf("error> The object \"%s\", passed as the first argument to > is not the correct object\n", head->str);
                        exit(0);
        }
        
        head = head->next;
        while(head != NULL){
                switch(head->flag) {
                        case 'i':
                                y = (double) head->num;
                                break;
                        case 'f':
                                y = head->f;
                                break;
                        case 'S':
                                printf("error> The object \"%s\", passed as the first argument to > is not the correct object\n", head->str);
                                break;
                }
                if (x > y) {
                        new->flag = 'i';
                        new->num = 0;
                        new->next = NULL;
                        return new;
                }
                x = y;
                head = head->next;
        }

        new->flag = 'i';
        new->num = 1;
        new->next = NULL;
        return new;
}

struct node *begin(struct node *current)
{
        while (current != NULL)
                current = current->next;
        
        return current;
}

struct node *car(struct node *head)
{
        if (head->flag != 'l') {
                printf("error> The object passed as first argument to car is not the correct type\n");
                exit(0);
        }
        if (head->list == NULL) {
                printf("error> The object passed as first argument to car is not the correct type\n");
                exit(0);
        }

        return copyNode(head->list);
}

struct node *cdr(struct node *head)
{
        if (head->flag != 'l') {
                printf("error> The object passed as first argument to cdr is not the correct type\n");
                exit(0);
        }

        struct node *new = (struct node *) malloc(sizeof(struct node));
        new->flag = 'l';
        new->list = head->list->next;;
        new->next = NULL;

        return new;
}

struct node *len(struct node *head)
{
        struct node *new = NULL;

        if (head->flag != 'l') {
                printf("error> The object passed as argument to len is not a list\n");
                exit(0);
        }

        new = (struct node *) malloc(sizeof(struct node));
        new->flag = 'i';
        new->num = length(head->list);
        new->next = NULL;

        return new;
}

struct node *max(struct node *head)
{
        double maxnum;
        struct node *current = head;

        if (head == NULL) {
                printf("error> \n\nmax has been called with zero arguments. It needs atleast one argument\n");
                exit(0);
        }

        switch(head->flag) {
                case 'i':
                        maxnum = (double) head->num;
                        break;
                case 'f':
                        maxnum = head->f;
                        break;
                default:
                        printf("error> The object passed to max is not a real number\n");
                        exit(0);
        }
        
        head = head->next;
        while(head !=NULL) {
                switch(head->flag) {
                        case 'i':
                                if (maxnum < head->num) {
                                        maxnum = (double) head->num;
                                        current = head;
                                }
                                break;
                        case 'f':
                                if (maxnum < head->f) {
                                        maxnum = head->f;
                                        current = head;
                                }
                                break;
                        default:
                                printf("error> The object passed to max is not a real number\n");
                                exit(0);
                }
                head = head->next;
        }
        return copyNode(current);
}

struct node *min(struct node *head)
{
        double  minnum;
        struct node *current = head;

        if (head == NULL) {
                printf("error> min has been called with zero arguments. It needs atleast one argument\n");
                exit(0);
        }

        switch(head->flag) {
                case 'i':
                        minnum = (double) head->num;
                        break;
                case 'f':
                        minnum = head->f;
                        break;
                default:
                        printf("error> The object passed as argument to min, is not a real number\n");
                        exit(0);
        }
        head = head->next;

        while (head != NULL) {
                switch(head->flag) {
                        case 'i':
                                if(minnum > head->num) {
                                        minnum = (double) head->num;
                                        current = head;
                                }
                                break;
                        case 'f':
                                if (minnum > head->f) {
                                        minnum = head->f;
                                        current = head;
                                }
                                break;
                        default:
                                printf("error> The object passed as argument to min, is not a real number\n");
                                exit(0);
                }
                head = head->next;
        }

        return copyNode(current);
}



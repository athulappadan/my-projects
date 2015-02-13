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

struct node *sqroot(struct node *head)
{
        double result;
        struct node *new = NULL;

        if (head->next != NULL) {
                printf("error> \n\nsqroot has been caled with %d arguments; it requires exactly one argument\n", length(head));
                exit(0);
        }

        switch (head->flag) {
                case 'i':
                        result = sqrt(head->num);
                        break;
                case 'f':
                        result = sqrt(head->f);
                        break;
                case 'S':
                        printf("error> The object \"%s\", passed as the first argument to sqrt() is not the correct type.\n", head->str);
                        exit(0);
        }

        new = (struct node *) malloc(sizeof(struct node));
        new->flag = 'f';
        new->f = result;
        new->next = NULL;

        return new;
}

struct node *absVal(struct node *head)
{
        long result;
        struct node *new = NULL;

        if (head->next != NULL) {
                printf("error> \n\nabsVal has benn called with %d arguments; it requires exactly one argument\n", length(head));
                exit(0);
        }

        switch(head->flag) {
                case 'i':
                        result = abs(head->num);
                        break;
                case 'f':
                        result = abs(head->f);
                        break;
                case 'S':
                        printf("error> The object \"%s\", passed as the first argument to absVal is not the correct type.\n", head->str);
                        exit(0);
        }

        new = (struct node *) malloc(sizeof(struct node));
        new->flag = 'i';
        new->num = result;
        new->next = NULL;

        return new;
}

struct node *powr(struct node *head)
{
        int l;
        double x, y;
        double result;
        struct node *new = NULL;

        if(l = length(head) != 2) {
                printf("error> \n\npowr has been called with %d argumnets; it requires 2 arguments\n", length(head));
                exit(0);
        }

        switch(head->flag) {
                case 'i':
                        x = (double) head->num;
                        break;
                case 'f':
                        x = head->f;
                        break;
                case 'S':
                        printf("error> The object \"%s\", passed as the first argument to powr is not the correct type.\n", head->str);
                        exit(0);
        }

        switch(head->next->flag) {
                case 'i':
                        y = (double) head->next->num;
                        break;
                case 'f':
                        y = head->next->f;
                        break;
                case 'S':
                        printf("error> The object \"%s\", passed as the second argument to powr is not the correct type.\n", head->next->str);
                        exit(0);
        }

        result = pow(x, y);
        new = (struct node *) malloc(sizeof(struct node));
        new->flag = 'f';
        new->f = result;
        new->next = NULL;

        return new;
}

struct node *expt(struct node *head)
{
        double result;
        struct node *new = NULL;

        if (head->next != NULL) {
                printf("error> \n\nexp has been called with %d arguments; it requires exactly one argument\n", length(head));
                exit(0);
        }

        switch(head->flag) {
                case 'i':
                        result = exp(head->num);
                        break;
                case 'f':
                        result = exp(head->f);
                        break;
                case 'S':
                        printf("error> The object \"%s\", passed as the first argument to expt is not the correct type\n", head->str);
                        exit(0);
        }

        new = (struct node *) malloc(sizeof(struct node));
        new->flag = 'f';
        new->f = result;
        new->next = NULL;

        return new;
}

struct node *cosine(struct node *head)
{
        double result;
        struct node *new = NULL;

        if (head->next != NULL) {
                printf("error> \n\ncosine has been called with %d arguments; it requires exactly one agument\n", length(head));
                exit(0);
        }

        switch(head->flag) {
                case 'i':
                        result = cos(head->num);
                        break;
                case 'f':
                        result = cos(head->f);
                        break;
                case 'S':
                        printf("error> The object \"%s\", passed as the first argument to cosine is not the correct type\n", head->str);
                        exit(0);
        }

        new = (struct node *) malloc(sizeof(struct node));
        new->flag = 'f';
        new->f = result;
        new->next = NULL;

        return new;
}

struct node *sine(struct node *head)
{
        double result;
        struct node *new = NULL;

        if (head->next != NULL) {
                printf("error> \n\nsine has been called with %d arguments; it requires exactly one argument\n", length(head));
                exit(0);
        }

        switch(head->flag) {
                case 'i':
                        result = sin(head->num);
                        break;
                case 'f':
                        result = sin(head->f);
                        break;
                case 'S':
                        printf("error> The object \"%s\", passed as the first argument to sine is not the correct type\n", head->str);
                        exit(0);
        }

        new = (struct node *) malloc(sizeof(struct node));
        new->flag = 'f';
        new->f = result;
        new->next = NULL;

        return new;
}

struct node *logBe(struct node *head)
{
        double result;
        struct node *new = NULL;

        if (head->next !=  NULL){
                printf("error> \n\nlogBe has been called with %d arguments; it requires exactly one argument\n", length(head));
                exit(0);
        }

        switch(head->flag) {
                case 'i':
                        result = log(head->num);
                        break;
                case 'f':
                        result = log(head->f);
                        break;
                case 'S':
                        printf("error> The object\"%s\", passed as the first argument to logBe is not the correct type\n", head->str);
                        exit(0);
        }

        new = (struct node *) malloc(sizeof(struct node));
        new->flag = 'f';
        new->f = result;
        new->next = NULL;

        return new;
}

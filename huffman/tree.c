#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "helper.h"


void make_tree(struct node **headRef)
{
        char str1[MAX], str2[MAX];
        struct node *head = *headRef;
        struct node *child1 = pop(headRef);
        struct node *child2 = pop(headRef);

        struct node *parent = malloc(sizeof(struct node));
       
        parent->frq = (child1->frq) + (child2->frq);
        parent->left = child1;
        parent->right = child2;

        if (child1->kind == Char)
                char_to_str(child1->chr, str1);
                
        else if (child1->kind == String)
                strcpy(str1, child1->buf);

        if (child2->kind == Char)
                char_to_str(child2->chr, str2);
        else
                strcpy(str2, child2->buf); 

        strcat(str1, str2); 

        strcpy(parent->buf, str1);
        parent->kind = String;

        append(headRef, parent);
        mergeSort(headRef);

}

void assign_code(struct node *h, char *p, char *k)
{
        if (h != NULL) {
                h->code = malloc(sizeof(char));
                strcpy(h->code, k);
                strcat(h->code, p);
                assign_code(h->left, "0", h->code);
                assign_code(h->right, "1", h->code);
        }

        return;
}

void show_all(struct node *h)
{
        if (h != NULL) {
                show_all(h->left);
                if (h->kind == Char)
                        printf("%c %s\n", h->chr, h->code);
                show_all(h->right);
        }

        return;
}

void char_to_str(char c, char *s)
{
        s[0] = c;
        s[1] = '\0';
}


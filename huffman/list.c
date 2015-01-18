#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "helper.h"

void push(struct node **headRef, int key, char val)
{
        struct node *newNode = malloc(sizeof(struct node));
        
        newNode->kind = Char;
        newNode->chr = val;
        newNode->frq = key;
        newNode->next = *headRef;
        newNode->left = NULL;
        newNode->right = NULL;
        *headRef = newNode;
}

struct node *make_list(char *str)
{
        struct node *head = NULL;

        int i = 0, count;
        char dup;

        while (str[i] != '\0') {
                count = 1;

                while (str[i] == str[i+1]) {
                        count++;
                        i++;
                }

                dup = str[i];
                i++;

                push(&head, count, dup);
        }
        return head;
}

int length(struct node *head)
{
        struct node *current = head;
        int count = 0;

        while (current != NULL) {
                current = current->next;
                count++;
        }
        return count;
}

struct node *pop(struct node **headRef)
{
        struct node *head;

        head = *headRef;
        *headRef = head->next;
        head->next = NULL;
        return head;
}

void mergeSort(struct node **headRef)
{
        struct node *head = *headRef;
        struct node *a, *b;

        if ((head ==NULL) || (head->next == NULL))
                return;

        FrontBackSplit(head, &a, &b);

        mergeSort(&a);
        mergeSort(&b);

        *headRef = sortedMerge(a, b);
}

void FrontBackSplit(struct node *source, struct node **front, struct node **back)
{
        struct node *slow, *fast;

        if (source == NULL || source->next == NULL) {
                *front = source;
                *back = NULL;
        }

        slow = source;
        fast = source->next;

        while (fast != NULL) {
                fast = fast->next;
                if (fast != NULL) {
                        slow = slow->next;
                        fast = fast->next;
                }
        }

        *front = source;
        *back = slow->next;
        slow->next = NULL;
}

struct node *sortedMerge(struct node *a, struct node *b)
{
        struct node dummy;
        struct node *tail = &dummy;

        dummy.next = NULL;

        while (1) {
                if (a == NULL) {
                        tail->next = b;
                        break;
                }

                else if (b == NULL) {
                        tail->next = a;
                        break;
                }

                if (a->frq < b->frq)
                        moveNode(&(tail->next), &a);
                else if (a->frq > b->frq)
                        moveNode(&(tail->next), &b);

                else {
                        if (a->kind == Char && b->kind == Char) {
                                if (a->chr < b->chr)
                                        moveNode(&(tail->next), &a);
                                else
                                        moveNode(&(tail->next), &b);
                        }
                        else if (a->kind == String && b->kind == String) {
                                if (strcmp(a->buf, b->buf))
                                        moveNode(&(tail->next), &b);
                                else
                                        moveNode(&(tail->next), &a);
                        }
                        else {
                                if (a->kind == Char)
                                        moveNode(&(tail->next), &a);
                                else
                                        moveNode(&(tail->next), &b);
                        }
                }

                tail = tail->next;
        }
        return (dummy.next);
}

void moveNode(struct node **dest, struct node **source)
{
        struct node *newNode = *source;
        assert(newNode != NULL);

        *source = newNode->next;
        newNode->next = *dest;
        *dest = newNode;
}

void append(struct node **headRef, struct node *parent)
{
        struct node *head = *headRef;
        parent->next = head;
        *headRef = parent;
}


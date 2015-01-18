#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "helper.h"

char encoded_str[MAX] = "";
char decoded_str[MAX] = "";

void encode(char *str, struct node *root)
{
        struct node *link;
        char *code;
        int i;

        for (i = 0; str[i] != '\0'; i++) {
                link = find(root, str[i]);
                code = link->code;
                strcat(encoded_str, code);
        }
}

void decode(struct node *root, char *str)
{
        int i;
        struct node *h = root;

        for (i = 0; str[i] != '\0'; i++) {
                if (str[i] == '0')
                        h = h->left;
                else
                        h = h->right;
                if (h->kind == Char) {
                        strcat(decoded_str, h->buf);
                        h = root;
                }
        }
}

struct node *find(struct node *h, char c)
{
        struct node *l, *r, *ans;
        l = NULL;
        r = NULL;
        ans = NULL;

        if (h == NULL) 
                return NULL;

        else {
                if (h->kind == Char && h->chr == c)
                        ans = h;
                else {
                        l = find(h->left, c);
                        ans = l;
                        if (ans == NULL) {
                                r = find(h->right, c);
                                ans = r;
                        }
                }
                if (ans != NULL)
                        return ans;
        }
}

main()
{
        char str[MAX];
       // strcpy(str, "aaabccdeeeeeffg");
        printf("Enter the string\n");
        scanf("%s", str);
        struct node *head = make_list(str);
        mergeSort(&head);

        while (length(head) > 1)
                make_tree(&head);

        assign_code(head, "", "");

        printf("The corresponding individual codes are:\n");
        show_all(head);

        encode(str, head);
        printf("Enoded string is: %s\n", encoded_str);

        decode(head, encoded_str);
        printf("Decoded string is: %s\n", decoded_str);

}

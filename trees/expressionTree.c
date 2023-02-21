#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

struct tree
{
        char info;
        struct tree *lptr, *rptr;
};
typedef struct tree node;

node *create(char post[])
{
        node *new1, *st[20];
        char sym;
        int i, t = -1;

        for (i = 0; post[i] != '\0'; i++)
        {
                sym = post[i];
                new1 = (node *)malloc(sizeof(node));
                new1->info = sym;
                new1->lptr = new1->rptr = NULL;

                if (isalnum(sym))
                        st[++t] = new1;
                else
                {
                        new1->rptr = st[t--];
                        new1->lptr = st[t--];
                        st[++t] = new1;
                }
        }
        return st[t--];
}

float eval(node *root)
{
        float num;
        switch (root->info)
        {
        case '+':
                return (eval(root->lptr) + eval(root->rptr));
        case '-':
                return (eval(root->lptr) - eval(root->rptr));
        case '*':
                return (eval(root->lptr) * eval(root->rptr));
        case '/':
                return (eval(root->lptr) / eval(root->rptr));
        default:
                if (isalpha(root->info))
                {
                        printf("%c ", root->info);
                        scanf("%f", &num);
                        return (num);
                }
        }
}

int main()
{
        char postfix[20];
        float res;
        node *root = NULL;
        printf("\n Enter Postfix expression\n");
        scanf("%s", postfix);

        root = create(postfix);
        res = eval(root);
        printf(" Result = %f\n", res);
        return 0;
}
/*INPUT
 * ab+cde+**
 * */
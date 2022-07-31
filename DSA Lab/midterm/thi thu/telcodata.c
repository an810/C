// telcodata BST 
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_LEN 20

typedef struct Node
{
    char fromnum[MAX_LEN];
    int nbcall;
    int duration;
    struct Node* left;
    struct Node* right;
}Node;

Node* root;
int total_call = 0;
int checknum = 1;

Node* makeNode(char *fromnum, int nbcall, int duration)
{
    Node* newnode = (Node*)malloc(sizeof(Node));
    strcpy(newnode->fromnum, fromnum);
    newnode->nbcall = nbcall; 
    newnode->duration = duration;
    newnode->left = NULL; newnode->right = NULL;
    return newnode;
}

Node* insertBST(char *fromnum, int nbcall, int duration, Node* r)
{
    if (r == NULL)
    {
        r = makeNode(fromnum, nbcall, duration);
        return r;
    }
    int check = strcmp(r->fromnum, fromnum);
    if (check == 0 ) return r;
    if (check < 0) r->right = insertBST(fromnum, nbcall, duration, r->right);
    else r->left = insertBST(fromnum, nbcall, duration, r->left);
    return r;
}

Node* find(char* num, Node* r)
{
    if (r== NULL) return NULL;
    int check = strcmp(r->fromnum,num);
    if (check == 0) return r;
    if (check < 0) return find(num, r->left);
    else return find(num,r->right);
}

int main()
{
    char cmd1[MAX_LEN];
    char cmd2[MAX_LEN];
    root = NULL;
    while(1)
    {
        scanf("%s", cmd1);
        if (strcmp(cmd1, "#") == 0) break;
        if (strcmp(cmd1, "call") == 0)
        {
            char fnum[MAX_LEN], tnum[MAX_LEN], date[MAX_LEN];  
            int gio1, phut1, giay1, gio2, phut2, giay2;
            scanf("%s %s %s %d:%d:%d %d:%d:%d", fnum, tnum, date, &gio1, &phut1, &giay1, &gio2, &phut2, &giay2);
            int duration = (gio2 - gio1) * 3600 + (phut2 - phut1) * 60 + (giay2 - giay1);
            if (strlen(fnum)<10 || strlen(tnum)<10) checknum = 0;
            total_call++;
            Node* p = find(fnum, root);
            if (p == NULL)
            {
                root = insertBST(fnum, 1, duration, root);
            }
            else 
            {
                p->duration+= duration;
                p->nbcall++;
            }
        }
    }
    while(1)
    {
        scanf("%s", cmd2);
        if (strcmp(cmd2, "#") == 0) break;
        if (strcmp(cmd2, "?check_phone_number") == 0)
        {
            printf("%d\n", checknum);
        }
        else if (strcmp(cmd2, "?number_calls_from") == 0)
        {
            char fnum[MAX_LEN];
            scanf("%s", fnum);
            Node* p = find(fnum,root);
            if (p==NULL) printf("0\n");
            else printf("%d\n",p->nbcall );
        } 
        else if (strcmp(cmd2, "?number_total_calls")==0)
        {
            printf("%d\n", total_call);
        }
        else if (strcmp(cmd2, "?count_time_calls_from") == 0)
        {
            char fnum[MAX_LEN];
            scanf("%s", fnum);
            Node* p = find(fnum, root);
            if (p==NULL) printf("0\n");
            else printf("%d\n", p->duration);
        }
    }
    
    return 0;
}
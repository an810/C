#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 1000


typedef struct Tdata
{
    int coef;
    int exp;
}Data;

typedef struct TNode
{
    Data data;
    struct TNode* prev;
    struct TNode* next;
}Node;

Node* Poly[N];

long long Pow(int x, int n)
{
    if (x==1) return 1;
    if (n==1) return x;
    long long pow = Pow(x,n/2);
    return pow*pow*Pow(x, n%2);
}

Node* MakeNode(int coef, int exp)
{
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->data.coef = coef;
    newnode->data.exp = exp;
    newnode->prev = NULL;
    newnode->next = NULL;
    return newnode;
}

void Create(int id)
{
    if (Poly[id] == NULL)
    {
        Poly[id] = MakeNode(-9999,-9999);
    }
}

void AddTerm(int id, int coef, int exp)
{
    if (Poly[id] == NULL) Create(id);
    Node* cur = Poly[id];
    while (cur != NULL)
    {
        if (cur->data.exp == exp)
        {
            cur->data.coef += coef;
            break;
        } 
        if (cur->data.exp < exp)
        {
            Node* temp = MakeNode(coef,exp);
            temp->next = cur;
            temp->prev = cur->prev;
            if (cur->prev != NULL) cur->prev->next = temp;
            cur->prev = temp;
            if (cur == Poly[id]) Poly[id]=temp; // nếu số mũ cur nhỏ hơn số mũ cần điền vào mà cur đang ở head thì cho head bằng temp
            break;
        }
        cur = cur->next;
    }
}

void EvaluatePoly(int id, int value)
{
    if (Poly[id] == NULL) return;
    long long ans=0;
    Node* cur = Poly[id];
    while (cur->data.coef != -9999)
    {
        ans += cur->data.coef * Pow(value,cur->data.exp);
        cur = cur->next;
    }
    printf("%lld\n",ans);
}

void AddPoly(int id1, int id2, int id3)
{
    Node *cur;
    cur=Poly[id1];
    while (cur->data.coef!=-9999)
    {
        AddTerm(id3,cur->data.coef,cur->data.exp);
        cur=cur->next;
    }
    cur=Poly[id2];
    while (cur->data.coef!=-9999)
    {
        AddTerm(id3,cur->data.coef,cur->data.exp);
        cur=cur->next;
    }

}

void PrintPoly(int id)
{
    if (Poly[id] == NULL) return;
    Node* cur = Poly[id];
    while(cur->data.coef != -9999)
    {
        printf("%d %d ",cur->data.coef, cur->data.exp);
        cur = cur->next;
    }
    printf("\n");
}

void Destroy(int id)
{
    if (Poly[id] == NULL) return;
    Node* cur = Poly[id];
    while (cur != NULL)
    {
        Node* temp = cur;
        cur = cur->next;
        free(temp);
    }
    Poly[id] = NULL;
}

int main()
{
    char cmd[100]="";
    while(1)
    {
        scanf("%s ",cmd);
        if (!strcmp(cmd, "AddTerm")) 
        {
            int id, coef, exp;
            scanf("%d%d%d", &id, &coef, &exp);
            AddTerm(id,coef,exp);
        } else
        if (!strcmp(cmd, "EvaluatePoly"))
        {
            int id, value;
            scanf("%d%d",&id, &value);
            EvaluatePoly(id,value); 
        } else 
        if (!strcmp(cmd, "AddPoly"))
        {
            int id1, id2, id3;
            scanf("%d%d%d", &id1, &id2, &id3);
            AddPoly(id1, id2, id3);
        } else 
        if (!strcmp(cmd, "PrintPoly"))
        {
            int id;
            scanf("%d",&id);
            PrintPoly(id); 
        } else
        if (!strcmp(cmd,"Destroy"))
        {
            int id;
            scanf("%d",&id);
            Destroy(id);
        }else
        if (!strcmp(cmd,"*")) break;
    }
    return 0;


}
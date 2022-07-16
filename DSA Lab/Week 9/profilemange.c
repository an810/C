#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define Max 256

typedef struct TNode
{
    char name[Max];
    char email[Max];
    struct TNode* next;
}Profile;

Profile *first, *last;

Profile* makeprofile(char *name, char *email)
{
    Profile* newprofile = (Profile*)malloc(sizeof(Profile));
    strcpy(newprofile->name, name);
    strcpy(newprofile->email, email);
    newprofile->next = NULL;
    return newprofile;
}

void initlist()
{
    first = NULL; last = NULL;
}

int listempty()
{
    return first == NULL && last == NULL;
}

void print()
{
    if (listempty()) return;
    Profile* p=first;
    while(p!= NULL)
    {
        printf("%s\t%s\n", p->name, p->email);
        p=p->next;
    }
}

void insertlast(char* name, char* email)
{
    Profile* temp = makeprofile(name, email);
    if(listempty()) 
    {
        first = temp; last = temp;
    } else
    {
        last->next = temp;
        last = temp;
    }
}

Profile* Remove(Profile* f,char* name) // f->first
{
    if (listempty()) return NULL;
    if (strcmp(f->name, name)==0)
    {
        Profile* tmp = f->next;
        free(f);
        if (tmp==NULL) last=NULL;
        return tmp;
    } else {
        f->next = Remove(f->next,name);
        return f;
    }
}

void processinsert()
{
    printf("Enter name and email:\n");
    char name[Max], email[Max];
    scanf("%s %s", name, email);
    insertlast(name, email);
}

void processremove()
{
    printf("Enter name:\n");
    char name[Max];
    scanf("%s", name);
    first = Remove(first, name);
}

void find()
{
    printf("Enter name:\n");
    char name[Max];
    scanf("%s", name);
    Profile* temp = NULL;
    Profile* p = first;
    while(p!= NULL)
    {
        if (strcmp(p->name,name)==0)
        {
            temp = p;
            break;
        }
        p = p->next;
    }
    if (temp == NULL)
    {
        printf("Profile does not exist\n");
    } else
    {
        printf("Profile %s %s\n", temp->name, temp->email);
    }
}

void load()
{
    printf("Enter filename:\n");
    char filename[Max];
    scanf("%s", filename);
    FILE* f= fopen(filename,"r");
    if (f== NULL) printf("Failed. The file does not exists\n");
    while (!feof(f))
    {   
        char name[Max], email[Max];
        fscanf(f, "%s %s", name, email);
        insertlast(name, email);
    }
    fclose(f);
}

void store()
{
    printf("Enter filename:\n");
    char filename[Max];
    scanf("%s", filename);
    FILE* f = fopen(filename, "w");
    Profile* p= first;
    if (p == NULL) return;
    while (p!=NULL)
    {
        fprintf(f,"%s %s\n", p->name, p->email);
        p=p->next;
    }
    fclose(f);
}

int main()
{   
    initlist();   
    while (1)
    {
        printf("Enter command:\n");
        char cmd[Max];
        scanf("%s",cmd);
        if (strcmp(cmd, "Quit")==0) break;
        else if (strcmp(cmd, "Load")==0) load();
        else if (strcmp(cmd, "Print")==0) print();
        else if (strcmp(cmd, "Find")==0) find();
        else if (strcmp(cmd, "Insert")==0) processinsert();
        else if (strcmp(cmd, "Remove")==0) processremove();
        else if (strcmp(cmd, "Store")==0) store();
    }
    return 0;
}
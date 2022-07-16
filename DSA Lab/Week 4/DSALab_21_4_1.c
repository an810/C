#include<stdio.h>
#include<string.h>
 
#define MAX_SZ 32

typedef struct ElementType{
    char name[50];
    int age;
}Element;

void executeCreate()
{
    char filename[50];
    printf("Input filename:"); scanf(" %s", filename);
    FILE* f= fopen(filename,"wb");
    fclose(f);
}

void executeLoad()
{
    char filename[100];
    printf("Input filename:"); scanf(" %s", filename);
    FILE* f= fopen(filename,"rb");
    if (f == NULL)
    {
        printf("Cannot open the file  %s for loading\n", filename);
    }
    Element buffers[MAX_SZ];
    while (1)
    {
        int sz = fread(buffers, sizeof(Element), MAX_SZ, f);
        for(int i=0; i<sz; i++)
        {
            printf("name = %s, age = %d\n", buffers[i].name, buffers[i].age);
        }
        if (sz<MAX_SZ) break;
    }
    fclose(f);
}

void executeExtend()
{
    char filename[50];
    printf("Input filename:"); scanf(" %s", filename);
    Element e;
    FILE* f= fopen(filename, "ab");
    if( f== NULL)
    {
        printf("Cannot open file  %s for appending\n", filename);
    } else {
        printf("Input name: "); scanf(" %s", &e.name);
        printf("Input age: "); scanf("%d", &e.age);
        int sz = fwrite(&e, sizeof(Element),1,f);
        if (sz == 1) printf("Write successfully! \n");
    }
    fclose(f);
}

void executeReadAt()
{
    char filename[100];
    printf("Input filename: "); scanf(" %s", filename);
    FILE* f= fopen(filename, "rb");
    if (f==NULL)
    {
        printf("Cannot open file  %s for reading\n", filename); return;
    }
    int i; printf("Input a index: "); scanf("%d", &i);
    fseek(f, sizeof(Element)*i, SEEK_SET);
    Element e;
    int sz = fread(&e, sizeof(Element), 1, f);
    if (sz ==0) 
    {
        printf("Cannot read the record at index %d\n", i); return;
    }
    printf("Read student name=  %s, age= %d\n", e.name, e.age);
    fclose(f);
}

int main()
{
    char cmd[50];
    while(1)
    {
        printf("Input a command: "); scanf(" %s", cmd);
        if (strcmp(cmd,"q") == 0)
        {
            break;
        } else if (strcmp(cmd,"create") == 0) {
            executeCreate();
        } else if (strcmp(cmd,"load-all") == 0) {
            executeLoad();
        } else if (strcmp(cmd,"extend") == 0) {
            executeExtend();
        } else if (strcmp(cmd, "read-at") == 0) {
            executeReadAt();
        }
    }
    return 0;
}
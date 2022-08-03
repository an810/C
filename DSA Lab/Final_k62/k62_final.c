#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node
{
    char class_code[11];
    char course_code[11];
    char time_location[50];
    struct Node* next;
}Node;

Node* head = NULL;
Node *new_head = NULL;

Node* makeNode(char class[], char course[], char timelocation[])
{
    Node *p = (Node *)malloc(sizeof(Node));
    strcpy(p->class_code,class);
    strcpy(p->course_code,course);
    strcpy(p->time_location,timelocation);
    p->next = NULL;
    return p;
}

Node* insertNode(Node *head, char class[], char course[], char timelocation[])
{
    Node *p = makeNode(class,course,timelocation);
    if (head == NULL)
    {
        head = p;
    }
    else
    {
        Node *cur = head;
        while (cur->next != NULL)
        {
            cur = cur->next;
        }
        cur->next = p;
    }
    return head;
}

Node* findNode(Node *head, char class[])
{
    Node *cur = head;
    while (cur != NULL)
    {
        if (strcmp(cur->class_code,class) == 0)
        {
            return cur;
        }
        cur = cur->next;
    }
    return NULL;
}

void read_file()
{
    FILE * fin = fopen("input.txt", "r");
    if (fopen == NULL) 
    {
        printf("Can not open the file. Please try again!\n");
    }
    char class_code[11];
    char course_code[11];
    char time_location[50];
    while(1)
    {
        fscanf(fin, "%s", class_code);
        fscanf(fin, "%s\n", course_code);
        fscanf(fin, "%[^\n]", time_location);
        head = insertNode(head, class_code, course_code, time_location);
        if (feof(fin)) break;
    }
    fclose(fin);
}

void traverse(Node* h)
{
    Node *cur = h;
    for (cur = h; cur != NULL; cur = cur->next)
    {
        printf("%s\n", cur->class_code);
        printf("%s\n", cur->course_code);
        printf("%s\n", cur->time_location);
    }
}

void search()
{
    char class_code[11];
    printf("Enter the class code: ");
    scanf("%s", class_code);
    Node *cur = findNode(head, class_code);
    if (cur == NULL)
    {
        printf("Not found!\n");
    }
    else
    {
        printf("%s\n", cur->class_code);
        printf("%s\n", cur->course_code);
        printf("%s\n", cur->time_location);
    }
}

void delete_class()
{
    char class_code[11];
    printf("Enter the class code: ");
    scanf("%s", class_code);
    Node *cur = findNode(head, class_code);
    if (cur == NULL)
    {
        printf("Not found!\n");
    }
    else
    {
        Node *prev = head;
        while (prev->next != cur)
        {
            prev = prev->next;
        }
        prev->next = cur->next;
        free(cur);
    }
}

void order_class()
{
    Node *cur = head;
    while (cur != NULL)
    {
        if (new_head == NULL) new_head = makeNode(cur->class_code, cur->course_code, cur->time_location);
        else
        {
            Node *p = new_head;
            if (strcmp(cur->class_code, p->class_code) < 0)
            {
                new_head = makeNode(cur->class_code, cur->course_code, cur->time_location);
                new_head->next = p;
            }
            else
            {
                while (p->next != NULL)
                {
                    if (strcmp(cur->class_code, p->next->class_code) < 0)
                    {
                        break;
                    }
                    p = p->next;
                }
                Node *q = p->next;
                p->next = makeNode(cur->class_code, cur->course_code, cur->time_location);
                p->next->next = q;
            }
        }
        cur = cur->next;
    }
    traverse(new_head);
}

//new linkedlist to count the number of classes in each day
typedef struct Node_course
{
    char course_code[11];
    int number_course;
    struct Node_course* next;
}Node_course;
Node_course *head_course = NULL;
Node_course * makecourse(char course[])
{
    Node_course *p = (Node_course *)malloc(sizeof(Node_course));
    strcpy(p->course_code,course);
    p->number_course = 1;
    p->next = NULL;
    return p;
}

Node_course* findcourse(Node_course *h, char course[])
{
    Node_course *cur = h;
    while (cur != NULL)
    {
        if (strcmp(cur->course_code,course) == 0)
        {
            return cur;
        }
        cur = cur->next;
    }
    return NULL;
}

Node_course* insertcourse(Node_course *head, char course[])
{
    Node_course *p = makecourse(course);
    if (head == NULL)
    {
        head = p;
    }
    else
    {
        Node_course *cur = head;
        while (cur->next != NULL)
        {
            cur = cur->next;
        }
        cur->next = p;
    }
    return head;
}

void count_class()
{
    Node *cur = head;
    while (cur != NULL)
    {
        Node_course *p = findcourse(head_course, cur->course_code);
        if (p == NULL)
        {
            head_course = insertcourse(head_course, cur->course_code);
        }
        else
        {
            p->number_course++;
        }
        cur = cur->next;
    }
    Node_course *cur_course = head_course;
    while (cur_course != NULL)
    {
        printf("%s %d\n", cur_course->course_code, cur_course->number_course);
        cur_course = cur_course->next;
    }
}

int main()
{
    int choice;
    do 
    {
        printf("---------Menu---------\n");
        printf("1. Read file\n");
        printf("2. Traverse the list\n");
        printf("3. Search classes\n");
        printf("4. Delete class\n");
        printf("5. Order classes\n");
        printf("6. Count classes\n");
        printf("7. Exit\n");
        printf("Your choice is: "); 
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                read_file();
                break;
            case 2:
                traverse(head);
                break;
            case 3:
                search();
                break;
            case 4:
                delete_class();
                break;
            case 5:
                order_class();
                break;
            case 6:
                count_class();
                break;
            case 7:
                break;
            default:
                printf("Wrong number!\n");
        }
    } while (choice != 7);  
    return 0;
}
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LEN 50


// telecom data check and query
typedef struct TNode
{
    char from_num[MAX_LEN];
    char to_num[MAX_LEN];
    int call_duration;
    struct TNode* next;
}Node;

Node* head;

Node* makeNode(char *fnum, char *tnum, int duration)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->from_num, fnum);
    strcpy(newNode->to_num, tnum);
    newNode->call_duration = duration;
    newNode->next = NULL;
    return newNode;
}

int check_phone_number(Node* head)
{
    int count =0;
    if (head == NULL) return 0;
    Node* temp = head;
    while (temp != NULL)
    {
        if (strlen(temp->from_num) != 10) count++;
        if (strlen(temp->to_num) != 10) count++;
        temp = temp->next;
    }
    if (count == 0) return 1;
    else return 0;
}
//number of calls from a number
int count_calls_from(Node* head, char* fnum)
{
    int count = 0;
    if (head == NULL) return 0;
    Node* temp = head;
    while (temp != NULL)
    {
        if (strcmp(temp->from_num, fnum) == 0) count++;
        temp = temp->next;
    }
    return count;
}
//number of total calls
int count_total_calls(Node* head)
{
    int count = 0;
    if (head == NULL) return 0;
    Node* temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}
//duration of calls from a number
int duration_from(Node* head, char* fnum)
{
    int duration = 0;
    if (head == NULL) return 0;
    Node* temp = head;
    while (temp != NULL)
    {
        if (strcmp(temp->from_num, fnum) == 0) duration += temp->call_duration;
        temp = temp->next;
    }
    return duration;
}

int main()
{
    char cmd1[MAX_LEN];
    char cmd2[MAX_LEN];
    head = NULL;
    while(1)
    {
        scanf("%s", cmd1);
        if (strcmp(cmd1, "#") == 0) break;
        if (strcmp(cmd1, "call") == 0)
        {
            char date[MAX_LEN];
            Node* temp = makeNode(date,date,0);   
            int gio1, phut1, giay1, gio2, phut2, giay2;
            scanf("%s %s %s %d:%d:%d %d:%d:%d", temp->from_num, temp->to_num, date, &gio1, &phut1, &giay1, &gio2, &phut2, &giay2);
            temp->call_duration = (gio2 - gio1) * 3600 + (phut2 - phut1) * 60 + (giay2 - giay1);
            if (head == NULL)
            {
                head = temp;
            }
            else
            {
                Node* temp2 = head;
                while (temp2->next != NULL)
                {
                    temp2 = temp2->next;
                }
                temp2->next = temp;
            }
        }
    }
    while(1)
    {
        scanf("%s", cmd2);
        if (strcmp(cmd2, "#") == 0) break;
        if (strcmp(cmd2, "?check_phone_number") == 0)
        {
            printf("%d\n", check_phone_number(head));
        }
        else if (strcmp(cmd2, "?number_calls_from") == 0)
        {
            char fnum[MAX_LEN];
            scanf("%s", fnum);
            printf("%d\n", count_calls_from(head, fnum));
        } 
        else if (strcmp(cmd2, "?number_total_calls")==0)
        {
            printf("%d\n", count_total_calls(head));
        }
        else if (strcmp(cmd2, "?count_time_calls_from") == 0)
        {
            char fnum[MAX_LEN];
            scanf("%s", fnum);
            printf("%d\n", duration_from(head, fnum));
        }
    }
    
    return 0;
}
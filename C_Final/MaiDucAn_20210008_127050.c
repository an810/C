#include<stdio.h>
#include<ctype.h>
#include<string.h>

#define MAX 100

typedef struct info
{
    long ID;
    int chapter;
    char content[50];
}question;

int current_question = 0;
question question_list[MAX];

void Read(void);
void Search(void);
void Add(void);
void Count(void);
void Check(void);

int main ()
{
    int choice;
    do {
        printf("1. Read\n");
        printf("2. Search\n");
        printf("3. Add\n");
        printf("4. Count\n");
        printf("5. Check\n");
        printf("6. Exit\n");
        printf("Enter your choice: \n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                Read();
                break;
            case 2:
                Search();
                break;
            case 3:
                Add();
                break;
            case 4:
                Count();
                break;
            case 5:
                Check();
                break;
            case 6:
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    } while (choice != 6);
    return 0;
}

void Read(void)
{
    int n;
    for (;;)
    {
        printf("Please enter the number of questions: \n");
        scanf("%d", &n);
        if (n < 1 || n > MAX)
            printf("Invalid number input\n");
        else
            break;
    }

    for (int i = 0; i < n; i++)
    {
        question_list[i].ID = i + 1;
        for(;;)
        {
            printf("Please enter the chapter and the content of the questions: \n");
            scanf("%d %[^\n]*c", &question_list[i].chapter, question_list[i].content);
            if (question_list[i].chapter < 1 || question_list[i].chapter > 20)
                printf("Invalid chapter input\n");
            else
                break;
        }
    }
    printf("ID     Chapter     Content\n");
    for (int j = 0; j < n; j++)
    {
        printf("%ld\t %d\t %s\n", question_list[j].ID, question_list[j].chapter, question_list[j].content);
    }
    current_question = n;
}

void Search(void)
{
    int ID;
    int count;
    printf("Please enter the ID of the question you want to search: \n");
    scanf("%d", &ID);
    for (int i = 0; i < MAX; i++)
    {
        if (question_list[i].ID == ID)
        {
            printf("The question you want to search is: \n");
            printf("ID     Chapter     Content\n");
            printf("%ld\t %d\t %s\n", question_list[i].ID, question_list[i].chapter, question_list[i].content);
            count++;
        }
    }
    if (count == 0)
        printf("The question you want to search is not found\n");
}

void Add(void) 
{
    int n;
    for(;;)
    {   
        printf("Please enter the number of questions you want to add: \n");
        scanf("%d", &n);
        if (current_question + n > MAX)
            printf("The number of questions you want to add is too large\n");
        else
            break;
    }
    for (int i = 0; i < n; i++)
    {
        question_list[current_question].ID = current_question + 1;
        for(;;)
        {
            printf("Please enter the chapter and the content of the questions: \n");
            scanf("%d %[^\n]*c", &question_list[current_question].chapter, question_list[current_question].content);
            if (question_list[current_question].chapter < 1 || question_list[current_question].chapter > 20)
                printf("Invalid chapter input\n");
            else
                break;
        }
        current_question++;
    }
    printf("ID     Chapter     Content\n");
    for (int j = 0; j < current_question; j++)
    {
        printf("%ld\t %d\t %s\n", question_list[j].ID, question_list[j].chapter, question_list[j].content);
    }
}

void Count(void)
{
	int chap[20] = {0};
	for (int i = 0; i < current_question; i++)
			chap[question_list[i].chapter - 1]++;
	printf("Chap    Count\n");
	for (int i = 0; i < 20; i++)
	{
		if (chap[i])
			printf("%-4d    %-5d\n", i + 1, chap[i]);
	}
}

void Check(void)
{
	printf("ID      Chap      Content\n");
	for (int i = 0; i < current_question; i++)
	{
		if (isupper(question_list[i].content[0]) && strchr(question_list[i].content, '*') == 0 && strchr(question_list[i].content, '$') == 0 && strchr(question_list[i].content, '\\') == 0)
        {
            printf("%ld\t %d\t %s\n", question_list[i].ID, question_list[i].chapter, question_list[i].content);
        }
	}
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Node
{
    int block;
    struct Node *next;
};

struct File
{
    char name[20];
    struct Node *head;
};

int bit[100], n;
struct File file[20];
int fcount = 0;

void showBitVector()
{
    int i;

    printf("\nBit Vector: ");

    for(i = 0; i < n; i++)
        printf("%d ", bit[i]);
}

void createFile()
{
    int i, b, blocks;
    struct Node *newnode, *temp;

    printf("\nEnter file name: ");
    scanf("%s", file[fcount].name);

    printf("Enter number of blocks: ");
    scanf("%d", &blocks);

    file[fcount].head = NULL;

    for(i = 0; i < blocks; i++)
    {
        printf("Enter block number: ");
        scanf("%d", &b);

        if(b < 0 || b >= n || bit[b] == 1)
        {
            printf("Block not free! Enter again.\n");
            i--;
            continue;
        }

        bit[b] = 1;

        newnode = (struct Node *)malloc(sizeof(struct Node));
        newnode->block = b;
        newnode->next = NULL;

        if(file[fcount].head == NULL)
            file[fcount].head = newnode;
        else
        {
            temp = file[fcount].head;

            while(temp->next != NULL)
                temp = temp->next;

            temp->next = newnode;
        }
    }

    fcount++;

    printf("File created successfully.\n");
}

void showDirectory()
{
    int i;
    struct Node *temp;

    printf("\nDirectory:\n");

    for(i = 0; i < fcount; i++)
    {
        printf("%s: ", file[i].name);

        temp = file[i].head;

        while(temp != NULL)
        {
            printf("%d ", temp->block);
            temp = temp->next;
        }

        printf("\n");
    }
}

int main()
{
    int i, choice;

    printf("Enter number of blocks: ");
    scanf("%d", &n);

    srand(time(0));

    for(i = 0; i < n; i++)
        bit[i] = rand() % 2;

    do
    {
        printf("\n\n1. Show Bit Vector");
        printf("\n2. Create New File");
        printf("\n3. Show Directory");
        printf("\n4. Exit");

        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                showBitVector();
                break;

            case 2:
                createFile();
                break;

            case 3:
                showDirectory();
                break;

            case 4:
                printf("\nExit");
                break;

            default:
                printf("\nInvalid choice!");
        }

    } while(choice != 4);

    return 0;
}
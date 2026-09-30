#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct File
{
    char name[20];
    int start;
    int length;
};

void showBitVector(int block[], int n)
{
    int i;

    printf("\nBit Vector:\n");

    for(i = 0; i < n; i++)
        printf("%d ", block[i]);

    printf("\n");
}

void createFile(int block[], int n, struct File files[], int *count)
{
    char name[20];
    int length, i, j;
    int start = -1;
    int freeBlocks;

    printf("\nEnter file name: ");
    scanf("%s", name);

    printf("Enter number of blocks required: ");
    scanf("%d", &length);

    /* Find consecutive free blocks */
    for(i = 0; i <= n - length; i++)
    {
        freeBlocks = 1;

        for(j = i; j < i + length; j++)
        {
            if(block[j] == 1)
            {
                freeBlocks = 0;
                break;
            }
        }

        if(freeBlocks == 1)
        {
            start = i;
            break;
        }
    }

    if(start == -1)
    {
        printf("File cannot be created.");
        return;
    }

    for(i = start; i < start + length; i++)
        block[i] = 1;

    strcpy(files[*count].name, name);
    files[*count].start = start;
    files[*count].length = length;

    (*count)++;

    printf("File created successfully.");
    printf("\nStarting Block = %d", start);
}

void showDirectory(struct File files[], int count)
{
    int i;

    printf("\n\nDirectory:\n");

    if(count == 0)
    {
        printf("No files available.\n");
        return;
    }

    printf("File\tStart\tLength\n");

    for(i = 0; i < count; i++)
    {
        printf("%s\t%d\t%d\n",files[i].name,files[i].start,files[i].length);
    }
}

int main()
{
    int n, i, choice;
    int block[100];
    struct File files[20];
    int count = 0;

    srand(time(0));

    printf("Enter number of blocks: ");
    scanf("%d", &n);

    /* Randomly allocate blocks */
    for(i = 0; i < n; i++)
        block[i] = rand() % 2;

    while(1)
    {
        printf("\n\n--- MENU ---");
        printf("\n1. Show Bit Vector");
        printf("\n2. Create New File");
        printf("\n3. Show Directory");
        printf("\n4. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                showBitVector(block, n);
                break;

            case 2:
                createFile(block, n, files, &count);
                break;

            case 3:
                showDirectory(files, count);
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice.");
        }
    }

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct File
{
    char name[20];
    int indexBlock;
    int blocks[50];
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
    int i, length;
    char name[20];

    printf("\nEnter file name: ");
    scanf("%s", name);

    printf("Enter number of blocks required: ");
    scanf("%d", &length);

    /* Find index block */
    int index = -1;

    for(i = 0; i < n; i++)
    {
        if(block[i] == 0)
        {
            index = i;
            break;
        }
    }

    if(index == -1)
    {
        printf("No free block for index block.");
        return;
    }

    /* Find data blocks */
    int found = 0;

    for(i = 0; i < n && found < length; i++)
    {
        if(block[i] == 0 && i != index)
        {
            files[*count].blocks[found] = i;
            found++;
        }
    }

    if(found < length)
    {
        printf("Not enough free blocks.");
        return;
    }

    block[index] = 1;

    for(i = 0; i < length; i++)
        block[files[*count].blocks[i]] = 1;

    strcpy(files[*count].name, name);
    files[*count].indexBlock = index;
    files[*count].length = length;

    (*count)++;

    printf("\nFile created successfully.");
    printf("\nIndex Block = %d", index);
}

void showDirectory(struct File files[], int count)
{
    int i, j;

    printf("\n\nDirectory:\n");

    if(count == 0)
    {
        printf("No files available.\n");
        return;
    }

    for(i = 0; i < count; i++)
    {
        printf("\nFile Name: %s", files[i].name);
        printf("\nIndex Block: %d", files[i].indexBlock);

        printf("\nData Blocks: ");

        for(j = 0; j < files[i].length; j++)
            printf("%d ", files[i].blocks[j]);

        printf("\n");
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

    /* Randomly allocate/free blocks */
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
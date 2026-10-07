#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct File
{
    char name[20];
    int start, length;
};

int main()
{
    int n, i, j, choice, len, start, free;
    int bit[100];
    struct File f[20];
    int count = 0;

    printf("Enter number of disk blocks: ");
    scanf("%d", &n);

    srand(time(0));

    // Randomly allocate some blocks
    for (i = 0; i < n; i++)
        bit[i] = rand() % 2;

    while (1)
    {
        printf("\n\n--- MENU ---");
        printf("\n1. Show Bit Vector");
        printf("\n2. Create New File");
        printf("\n3. Show Directory");
        printf("\n4. Delete File");
        printf("\n5. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nBit Vector:\n");
            for (i = 0; i < n; i++)
                printf("%d ", bit[i]);
            break;

        case 2:
            printf("\nEnter file name: ");
            scanf("%s", f[count].name);

            printf("Enter file size (number of blocks): ");
            scanf("%d", &len);

            start = -1;

            // Find contiguous free blocks
            for (i = 0; i <= n - len; i++)
            {
                free = 1;

                for (j = i; j < i + len; j++)
                {
                    if (bit[j] == 1)
                    {
                        free = 0;
                        break;
                    }
                }

                if (free)
                {
                    start = i;
                    break;
                }
            }

            if (start == -1)
            {
                printf("Contiguous space not available!");
            }
            else
            {
                f[count].start = start;
                f[count].length = len;

                for (i = start; i < start + len; i++)
                    bit[i] = 1;

                count++;

                printf("File created successfully.");
                printf("\nStarting block = %d", start);
            }
            break;

        case 3:
            printf("\nDirectory:\n");
            printf("File\tStart\tLength\n");

            for (i = 0; i < count; i++)
                printf("%s\t%d\t%d\n",
                       f[i].name,
                       f[i].start,
                       f[i].length);
            break;

        case 4:
        {
            char name[20];
            int found = 0;

            printf("\nEnter file name to delete: ");
            scanf("%s", name);

            for (i = 0; i < count; i++)
            {
                if (strcmp(f[i].name, name) == 0)
                {
                    // Free allocated blocks
                    for (j = f[i].start;
                         j < f[i].start + f[i].length;
                         j++)
                    {
                        bit[j] = 0;
                    }

                    // Remove file from directory
                    for (j = i; j < count - 1; j++)
                        f[j] = f[j + 1];

                    count--;
                    found = 1;

                    printf("File deleted successfully.");
                    break;
                }
            }

            if (!found)
                printf("File not found!");

            break;
        }

        case 5:
            printf("\nExiting...");
            return 0;

        default:
            printf("\nInvalid choice!");
        }
    }

    return 0;
}
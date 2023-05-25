#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count = 0, i, j, total, size, num, tsize;
char val[100];
void frames();
void trans();
void sort();

struct frame
{
    int seq;
    int len;
    char data[20];
    int flag;
} n[20], m[20], temp;

int main()
{
    printf("\nEnter the data: ");
    scanf("%[^\n]s", val);
    tsize = strlen(val);
    frames();
    trans();
    sort();
}

void frames()
{
    int ch;
    total = 0;
    printf("\nSegmented Frames and Transmitting order at Sender:\n");

    while (total < tsize)
    {
        n[count].seq = count + 1;
        size = rand() % 10 + 1;
        n[count].len = size;
        n[count].flag = 0;
        j = 0;
        if ((total + size) < tsize)
        {
            for (i = total, j = 0; i < total + size, j < size; i++, j++)
                n[count].data[j] = val[i];
            n[count].data[j] = '\0';
        }
        else
        {
            n[count].len = tsize - total;
            j = 0;
            while (total < tsize)
            {
                n[count].data[j++] = val[total];
                total++;
            }
            n[count].data[j] = '\0';
        }
        total += size;
        count++;
    }
    printf("\nFSeq No.   FLen   Flag   FData\n");
    for (i = 0; i < count; i++)
    {
        printf("  %d\t    %d\t    %d\t", n[i].seq, n[i].len, n[i].flag);
        for (j = 0; j < n[i].len; j++)
        {
            printf("%c", n[i].data[j]);
        }
        printf("\n");
    }
    num = count;
    printf("\nEnter 1/0 to continue: ");
    scanf("%d", &ch);
    if (ch == 0)
    {
        exit(0);
    }
}

void trans()
{
    int ch;
    count = 0;
    printf("\nBegins: \n");
    while (count < num)
    {
        i = rand() % num;
        if (n[i].flag == 0)
        {
            m[count++] = n[i];
        }
        n[i].flag = 1;
    }
    printf("\nThe order of frames received at receiving terminal:\n");
    printf("\nFSeq No.   FLen   Flag   FData\n");
    for (i = 0; i < count; i++)
    {
        printf("   %d\t   %d\t   %d\t", m[i].seq, m[i].len, m[i].flag);
        for (j = 0; j < m[i].len; j++)
        {
            printf("%c", m[i].data[j]);
        }
        printf("\n");
    }
    printf("\nTotal no. of fames: %d\n", count);
    printf("Enter 1/0 to continue: ");
    scanf("%d", &ch);
    if (ch == 0)
    {
        exit(0);
    }
}

void sort()
{
    for (i = 0; i < count; i++)
    {
        for (j = i + 1; j < count; j++)
        {
            if (m[i].seq > m[j].seq)
            {
                temp = m[i];
                m[i] = m[j];
                m[j] = temp;
            }
        }
    }
    printf("\nSorted Frames at Receiving Terminal:\n");
    printf("\nFSeq No.   FLen   Flag   FData\n");
    for (i = 0; i < count; i++)
    {
        printf("   %d\t   %d\t   %d\t", m[i].seq, m[i].len, m[i].flag);

        for (j = 0; j < m[i].len; j++)
        {
            printf("%c", m[i].data[j]);
        }
        printf("\n");
    }
}
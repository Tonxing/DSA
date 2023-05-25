#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct
{
    int seq;
    int len;
    int flag;
    char data[10];
} n[20], m[20], temp;
int count = 0;

void frames(char str[100])
{
    int i, j, s, size;
    s = strlen(str);
    for (i = 0; i < s;)
    {

        size = rand() % 10 + 1;
        n[count].seq = count + 1;
        n[count].len = size;
        n[count].flag = 0;

        for (j = 0; j < size && i < s; j++)
            n[count].data[j] = str[i + j];
        i += j;
        count++;
    }

    printf("Show the packets : \n");
    for (i = 0; i < count; i++)
        printf("\t%d : %d –> %s\n", n[i].seq, n[i].len, n[i].data);
}

void trans()
{
    int i, j;
    int c = 0;
    while (c < count)
    {
        i = rand() % count;
        if (n[i].flag == 0)
        {
            m[c++] = n[i];
            n[i].flag = 1;
        }
    }
    printf("Show the random packets : \n");

    for (i = 0; i < count; i++)
        printf("\t%d : %d –> %s\n", m[i].seq, m[i].len, m[i].data);
}
void sort()
{
    int i, j;
    for (i = 0; i < count; i++)
        for (j = i + 1; j < count; j++)
            if (m[i].seq > m[j].seq)
            {
                temp = m[i];
                m[i] = m[j];
                m[j] = temp;
            }
    printf("Show the sequenced packets : \n");
    for (i = 0; i < count; i++)
        printf("\t%d : %d –> %s\n", m[i].seq, m[i].len, m[i].data);
}

int main()
{
    char str[100];
    printf("Enter the data : ");
    scanf("%s", str);
    frames(str);
    trans();
    sort();
    return 0;
}
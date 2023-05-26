#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int *A;
    int size;
    int length;
};

struct Array arr1;
struct Array arr2;
struct Array *arr3;

int i, j, k;

void Display(struct Array arr)
{
    printf("Elements are\n");
    for (i = 0; i < arr.length; i++)
    {
        printf("%d ", arr.A[i]);
    }
}

struct Array *Union(struct Array *arr1, struct Array *arr2)
{
    i = j = k = 0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
    printf("Enter size of the union array: ");
    scanf("%d", &arr3->size);

    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else if (arr2->A[j] < arr1->A[i])
            arr3->A[k++] = arr2->A[j++];
        else
        {
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
    }
    for (; i < arr1->length; i++)
        arr3->A[k++] = arr1->A[i];
    for (; j < arr2->length; j++)
        arr3->A[k++] = arr2->A[j];

    arr3->length = k;

    return arr3;
}

struct Array *Intersection(struct Array *arr1, struct Array *arr2)
{
    i = j = k = 0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
    printf("Enter size of the intersection array: ");
    scanf("%d", &arr3->size);

    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
            i++;
        else if (arr2->A[j] < arr1->A[i])
            j++;
        else if (arr1->A[i] == arr2->A[j])
        {
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
    }

    arr3->length = k;

    return arr3;
}

struct Array *Difference(struct Array *arr1, struct Array *arr2)
{
    i = j = k = 0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
    printf("Enter size of the difference array: ");
    scanf("%d", &arr3->size);

    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else if (arr2->A[j] < arr1->A[i])
            j++;
        else
        {
            i++;
            j++;
        }
    }
    for (; i < arr1->length; i++)
        arr3->A[k++] = arr1->A[i];

    arr3->length = k;

    return arr3;
}

int main()
{
    int n, m, s;
    char choice;

    printf("Enter the size of the first array: ");
    scanf("%d", &arr1.size);

    arr1.A = (int *)malloc(arr1.size * sizeof(int));

    printf("Enter length: ");
    scanf("%d", &n);
    arr1.length = n;

    printf("Enter all Elements\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr1.A[i]);
    }

    printf("Enter the size of the second array: ");
    scanf("%d", &arr2.size);

    arr2.A = (int *)malloc(arr2.size * sizeof(int));

    printf("Enter length: ");
    scanf("%d", &m);
    arr2.length = m;

    printf("Enter all Elements\n");
    for (i = 0; i < m; i++)
    {
        scanf("%d", &arr2.A[i]);
    }

    do
    {
        printf("\n1. Perform Union.");
        printf("\n2. Perform Intersection.");
        printf("\n3. Perform Difference.");

        printf("\nChoose your preference: ");
        scanf("%d", &s);

        switch (s)
        {
        case 1:
            arr3 = Union(&arr1, &arr2);
            Display(*arr3);
            break;

        case 2:
            arr3 = Intersection(&arr1, &arr2);
            Display(*arr3);
            break;

        case 3:
            arr3 = Difference(&arr1, &arr2);
            Display(*arr3);
            break;

        default:
            printf("\nInvalid preference.");
        }
        printf("\nDo you wish to continue? Y/N:\n");
        scanf(" %c", &choice);
    } while (choice == 'Y' || choice == 'y');

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int *A;
    int size;
    int length;
};

struct Array arr;

int i;

void Display(struct Array arr)
{
    int i;
    printf("Elements are\n");
    for (i = 0; i < arr.length; i++)
    {
        printf("%d ", arr.A[i]);
    }
}

void Append(struct Array *arr, int x)
{
    if (arr->length < arr->size)
        arr->A[arr->length++] = x;
}

void Insert(struct Array *arr, int index, int x)
{
    if (index >= 0 && index <= arr->length)
    {
        for (i = arr->length; i > index; i--)
            arr->A[i] = arr->A[i - 1];
        arr->A[index] = x;
        arr->length++;
    }
}

int Delete(struct Array *arr, int index)
{
    int x = 0;
    if (index >= 0 && index < arr->length)
    {
        x = arr->A[index];
        for (i = index; i < arr->length - 1; i++)
        {
            arr->A[i] = arr->A[i + 1];
        }
        arr->length--;
        return x;
    }
}

int LinearSearch(struct Array arr, int key)
{
    int i;
    for (i = 0; i < arr.length; i++)
    {
        if (key == arr.A[i])
        {
            return i;
        }
    }
    return -1;
}

int BinarySearch(struct Array arr, int key)
{
    int l, mid, h;
    l = 0;
    h = arr.length - 1;

    while (l <= h)
    {
        mid = (l + h) / 2;
        if (key == arr.A[mid])
            return mid;
        else if (key < arr.A[mid])
            h = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
}

int main()
{
    int n, s, element, index;
    char choice;

    printf("Enter size of an array: ");
    scanf("%d", &arr.size);
    arr.A = (int *)malloc(arr.size * sizeof(int));
    arr.length = 0;

    printf("Enter length: ");
    scanf("%d", &n);

    printf("Enter all Elements\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr.A[i]);
    }
    arr.length = n;

    do
    {
        printf("\n1. Display elements.");
        printf("\n2. Append element.");
        printf("\n3. Insert element.");
        printf("\n4. Delete element.");
        printf("\n5. Search element using LinearSearch.");
        printf("\n6. Search element using BinarySearch.");
        printf("\nEnter choice: ");
        scanf("%d", &s);

        switch (s)
        {
        case 1:
        {
            Display(arr);
            break;
        }

        case 2:
            printf("Enter the element to append: ");
            scanf("%d", &element);
            Append(&arr, element);
            break;

        case 3:
            printf("Enter the index to insert element: ");
            scanf("%d", &index);
            printf("Enter the element to insert: ");
            scanf("%d", &element);
            Insert(&arr, index, element);
            break;

        case 4:
            printf("Enter the index to delete the element: ");
            scanf("%d", &index);
            Delete(&arr, index);
            break;

        case 5:
            printf("Enter the element to search: ");
            scanf("%d", &element);
            index = LinearSearch(arr, element);
            printf("Element is found at index %d", index);
            break;

        case 6:
            printf("Enter the element to search: ");
            scanf("%d", &element);
            index = BinarySearch(arr, element);
            printf("Element is found at index %d", index);
            break;

        default:
            printf("\nWrong choice.");
        }

        printf("\nDo you wish to continue? Y/N:\n");
        scanf(" %c", &choice);
    } while (choice == 'Y' || choice == 'y');
    printf("changes made");
    return 0;
}
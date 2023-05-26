#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int *A;
    int size;
    int length;
};

struct Array arr;
struct Array newarr;
struct Array *mergedarr;

int i, j, k;

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

int Get(struct Array arr, int index)
{
    if (index >= 0 && index < arr.length)
        return arr.A[index];
    return -1;
}

void Set(struct Array arr, int index, int x)
{
    if (index >= 0 && index < arr.length)
    {
        arr.A[index] = x;
    }
}

int Max(struct Array arr)
{
    int max = arr.A[0];
    for (i = 1; i < arr.length; i++)
    {
        if (arr.A[i] > max)
            max = arr.A[i];
    }
    return max;
}

int Min(struct Array arr)
{
    int min = arr.A[0];
    for (i = 1; i < arr.length; i++)
    {
        if (arr.A[i] < min)
            min = arr.A[i];
    }
    return min;
}

int Sum(struct Array arr)
{
    int total = 0;
    for (i = 0; i < arr.length; i++)
    {
        total += arr.A[i];
    }
    return total;
}

float Avg(struct Array arr)
{
    int total = Sum(arr);
    return (float)total / arr.length;
}

void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void ReverseUsingDublicate(struct Array *arr)
{
    int *B;
    B = (int *)malloc(arr->length * sizeof(int));
    for (i = arr->length - 1, j = 0; i >= 0; i--, j++)
        B[j] = arr->A[i];
    for (i = 0; i < arr->length; i++)
        arr->A[i] = B[i];
}

void ReverseUsingSwap(struct Array *arr)
{
    for (i = 0, j = arr->length - 1; i < j; i++, j--)
        swap(&arr->A[i], &arr->A[j]);
}

void LeftShift(struct Array *arr)
{
    for (i = 0; i < arr->length - 1; i++)
    {
        arr->A[i] = arr->A[i + 1];
    }
    arr->A[arr->length - 1] = 0;
}

void LeftRotate(struct Array *arr)
{
    int x = arr->A[0];
    for (i = 0; i < arr->length - 1; i++)
    {
        arr->A[i] = arr->A[i + 1];
    }
    arr->A[arr->length - 1] = x;
}

void RightShift(struct Array *arr)
{
    for (i = arr->length - 1; i > 0; i--)
    {
        arr->A[i] = arr->A[i - 1];
    }
    arr->A[0] = 0;
}

void RightRotate(struct Array *arr)
{
    int x = arr->A[arr->length - 1];
    for (i = arr->length - 1; i > 0; i--)
    {
        arr->A[i] = arr->A[i - 1];
    }
    arr->A[0] = x;
}

int isSorted(struct Array arr)
{
    for (i = 0; i < arr.length - 1; i++)
    {
        if (arr.A[i] > arr.A[i + 1])
        {
            return 0;
        }
    }
    return 1;
}

void SortArray(struct Array *arr)
{
    for (i = 0; i < arr->length - 1; i++)
    {
        for (j = 0; j < arr->length - i - 1; j++)
        {
            if (arr->A[j] > arr->A[j + 1])
            {
                swap(&arr->A[j], &arr->A[j + 1]);
            }
        }
    }
}

void SortnInsert(struct Array *arr, int x)
{
    if (arr->length == arr->size)
    {
        printf("Array is already full.");
        return;
    }

    if (isSorted(*arr) == 0)
    {
        SortArray(arr);
    }

    i = arr->length - 1;
    while (arr->A[i] > x)
    {
        arr->A[i + 1] = arr->A[i];
        i--;
    }
    arr->A[i + 1] = x;
    arr->length++;
}

void Separation(struct Array *arr)
{
    i = 0;
    j = arr->length - 1;

    while (i < j)
    {
        while (arr->A[i] < 0)
            i++;
        while (arr->A[j] >= 0)
            j--;
        if (i < j)
            swap(&arr->A[i], &arr->A[j]);
    }
}

struct Array *Merge(struct Array *arr, struct Array *newarr)
{
    i = 0, j = 0, k = 0;

    struct Array *mergedarr = (struct Array *)malloc(sizeof(struct Array));
    printf("Enter size of the merged array: ");
    scanf("%d", &mergedarr->size);

    if (isSorted(*arr) == 0)
    {
        SortArray(arr);
    }

    if (isSorted(*newarr) == 0)
    {
        SortArray(newarr);
    }

    while (i < arr->length && j < newarr->length)
    {
        if (arr->A[i] < newarr->A[j])
            mergedarr->A[k++] = arr->A[i++];
        else
            mergedarr->A[k++] = newarr->A[j++];
    }
    for (; i < arr->length; i++)
        mergedarr->A[k++] = arr->A[i];
    for (; j < newarr->length; j++)
        mergedarr->A[k++] = newarr->A[j];
    mergedarr->length = arr->length + newarr->length;
}

int main()
{
    int n, m, s, element, index;
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
        printf("\n7. Get element at a particular index.");
        printf("\n8. Set element at a particular index.");
        printf("\n9. Get maximum element.");
        printf("\n10. Get minimum element.");
        printf("\n11. Get sum of all elements.");
        printf("\n12. Get average.");
        printf("\n13. Reverse using dublicate array.");
        printf("\n14. Reverse using swapping.");
        printf("\n15. Left Shift.");
        printf("\n16. Left Rotate.");
        printf("\n17. Right Shift.");
        printf("\n18. Right Rotate.");
        printf("\n19. Check if elements are sorted.");
        printf("\n20. Insert element by sorting it first if not yet sorted.");
        printf("\n21. Separate/Group negative from positive elements.");
        printf("\n22. Merge Array.");

        printf("\nEnter choice: ");
        scanf("%d", &s);

        switch (s)
        {
        case 1:
            Display(arr);
            break;

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

        case 7:
            printf("Enter the index to get element: ");
            scanf("%d", &index);
            element = Get(arr, index);
            printf("Element found is %d", element);
            break;

        case 8:
            printf("Enter the index and element to set : ");
            scanf("%d%d", &index, &element);
            Set(arr, index, element);
            printf("Element is set at index %d", index);
            break;

        case 9:
            element = Max(arr);
            printf("Maximum element is %d", element);
            break;

        case 10:
            element = Min(arr);
            printf("Minimum element is %d", element);
            break;

        case 11:
            element = Sum(arr);
            printf("Sum of all elements is %d", element);
            break;

        case 12:
            printf("Average of all the elements: %.2f", Avg(arr));
            break;

        case 13:
            ReverseUsingDublicate(&arr);
            break;

        case 14:
            ReverseUsingSwap(&arr);
            break;

        case 15:
            LeftShift(&arr);
            break;

        case 16:
            LeftRotate(&arr);
            break;

        case 17:
            RightShift(&arr);
            break;

        case 18:
            RightRotate(&arr);
            break;

        case 19:
            if (isSorted(arr) == 1)
                printf("The elements are sorted.");
            else
                printf("The elements are not sorted.");
            break;

        case 20:
            printf("Enter the element to insert: ");
            scanf("%d", &element);
            SortnInsert(&arr, element);
            break;

        case 21:
            Separation(&arr);
            break;

        case 22:

            printf("For th second array:\n");
            printf("Enter size of the array: ");
            scanf("%d", &newarr.size);
            newarr.A = (int *)malloc(newarr.size * sizeof(int));
            newarr.length = 0;

            printf("Enter length: ");
            scanf("%d", &m);

            printf("Enter all Elements\n");
            for (i = 0; i < m; i++)
            {
                scanf("%d", &newarr.A[i]);
            }
            newarr.length = m;

            mergedarr = Merge(&arr, &newarr);
            Display(*mergedarr);
            break;

        default:
            printf("\nWrong choice.");
        }

        printf("\nDo you wish to continue? Y/N:\n");
        scanf(" %c", &choice);
    } while (choice == 'Y' || choice == 'y');
    return 0;
}
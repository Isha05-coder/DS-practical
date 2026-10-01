#include <stdio.h>

// Bubble Sort function
void bubbleSort(int arr[], int n)
{
    int i, j, temp;

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Merge function
void merge(int arr[], int low, int mid, int high)
{
    int temp[100];
    int i = low;
    int j = mid + 1;
    int k = 0;

    while (i <= mid && j <= high)
    {
        if (arr[i] <= arr[j])
        {
            temp[k] = arr[i];
            i++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }

    while (i <= mid)
    {
        temp[k] = arr[i];
        i++;
        k++;
    }

    while (j <= high)
    {
        temp[k] = arr[j];
        j++;
        k++;
    }

    for (i = low, k = 0; i <= high; i++, k++)
    {
        arr[i] = temp[k];
    }
}

// Merge Sort function
void mergeSort(int arr[], int low, int high)
{
    int mid;

    if (low < high)
    {
        mid = (low + high) / 2;

        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);

        merge(arr, low, mid, high);
    }
}

// Display array
void display(int arr[], int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

// Copy array
void copyArray(int source[], int destination[], int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        destination[i] = source[i];
    }
}

int main()
{
    int original[100], arr[100];
    int n, i, choice;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &original[i]);
    }

    do
    {
        printf("\n========== MENU ==========\n");
        printf("1. Bubble Sort\n");
        printf("2. Merge Sort\n");
        printf("3. Exit\n");
        printf("===========================\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                copyArray(original, arr, n);

                bubbleSort(arr, n);

                printf("\nArray after Bubble Sort:\n");
                display(arr, n);
                break;

            case 2:
                copyArray(original, arr, n);

                mergeSort(arr, 0, n - 1);

                printf("\nArray after Merge Sort:\n");
                display(arr, n);
                break;

            case 3:
                printf("\nProgram terminated.\n");
                break;

            default:
                printf("\nInvalid choice! Please enter 1, 2, or 3.\n");
        }

    } while (choice != 3);

    return 0;
}

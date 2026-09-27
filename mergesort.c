#include <stdio.h>

struct Package
{
    int id;
    int weight;
};

int comparisons = 0;

void merge(struct Package a[], int low, int mid, int high)
{
    struct Package temp[20];

    int i = low;
    int j = mid + 1;
    int k = 0;

    while (i <= mid && j <= high)
    {
        comparisons++;

        /* <= makes Merge Sort stable */
        if (a[i].weight <= a[j].weight)
        {
            temp[k] = a[i];
            i++;
        }
        else
        {
            temp[k] = a[j];
            j++;
        }

        k++;
    }

    while (i <= mid)
    {
        temp[k] = a[i];
        i++;
        k++;
    }

    while (j <= high)
    {
        temp[k] = a[j];
        j++;
        k++;
    }

    for (i = low, k = 0; i <= high; i++, k++)
    {
        a[i] = temp[k];
    }
}

void mergeSort(struct Package a[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;

        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);

        merge(a, low, mid, high);
    }
}

void display(struct Package a[], int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        printf("P%d(%d) ", a[i].id, a[i].weight);
    }

    printf("\n");
}

int main()
{
    struct Package a[] =
    {
        {1, 20},
        {2, 15},
        {3, 20},
        {4, 10},
        {5, 15},
        {6, 20},
        {7, 25},
        {8, 10}
    };

    int n = 8;

    printf("Original order:\n");
    display(a, n);

    mergeSort(a, 0, n - 1);

    printf("\nSorted order:\n");
    display(a, n);

    printf("\nNumber of comparisons: %d\n", comparisons);

    return 0;
}
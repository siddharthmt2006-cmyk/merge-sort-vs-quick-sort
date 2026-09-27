#include <stdio.h>

struct Package
{
    int id;
    int weight;
};

int comparisons = 0;

void swap(struct Package *a, struct Package *b)
{
    struct Package temp = *a;
    *a = *b;
    *b = temp;
}

int partition(struct Package a[], int low, int high)
{
    int pivot = a[high].weight;
    int i = low - 1;
    int j;

    for (j = low; j < high; j++)
    {
        comparisons++;

        if (a[j].weight <= pivot)
        {
            i++;
            swap(&a[i], &a[j]);
        }
    }

    swap(&a[i + 1], &a[high]);

    return i + 1;
}

void quickSort(struct Package a[], int low, int high)
{
    if (low < high)
    {
        int p = partition(a, low, high);

        quickSort(a, low, p - 1);
        quickSort(a, p + 1, high);
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

    quickSort(a, 0, n - 1);

    printf("\nSorted order:\n");
    display(a, n);

    printf("\nNumber of comparisons: %d\n", comparisons);

    return 0;
}
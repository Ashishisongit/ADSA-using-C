#include <stdio.h>

void mergeSort(int arr[], int lb, int ub);
void merge(int arr[], int lb, int mid, int ub);
void display(int arr[], int n);

void merge(int arr[], int lb, int mid, int ub)
{
    int i = lb;
    int j = mid + 1;
    int k = lb;

    int temp[100];  

   
    while (i <= mid && j <= ub)
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

   
    while (j <= ub)
    {
        temp[k] = arr[j];
        j++;
        k++;
    }

    
    for (i = lb; i <= ub; i++)
    {
        arr[i] = temp[i];
    }
}


void mergeSort(int arr[], int lb, int ub)
{
    if (lb < ub)
    {
        int mid = (lb + ub) / 2;

        mergeSort(arr, lb, mid);     
        mergeSort(arr, mid + 1, ub);  

        merge(arr, lb, mid, ub);    
    }
}


void display(int arr[], int n)
{
    int i;

    printf("\nSorted Array:\n");

    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

int main()
{
    int n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements:\n", n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    mergeSort(arr, 0, n - 1);

    display(arr, n);

    return 0;
}

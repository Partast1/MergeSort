#include <stdio.h>
#include <stdlib.h>

static int amountNumbers = 100000;

/**< Bruges til at udskrive et array */
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
/**< Bruges til at generere X antal tilfældige nummere */
int * ManyNumbers(){
   static int mNumbers[100000];
     for(int i = 0; i<amountNumbers; i++)
        mNumbers[i] = rand();
        return mNumbers;

}
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    /* create temp arrays */
    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];


    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
    are any */
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
    are any */
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

}

/**< 1000 tal = 0,072 | 10000 tal = 0,458 | 100000 tal =  3,557 */
int * sort(int arr[], int l, int r)
{
    if (l < r) {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l + (r - l) / 2;

        // Sort first and second halves
        sort(arr, l, m);
        sort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
    return arr;
}
int main()
{
        //variabler og pointervariabler
    int *numbers, *sortedNumbers;

    numbers = ManyNumbers();
    sortedNumbers = sort(numbers, 1 , amountNumbers -1);
    printArray(sortedNumbers, amountNumbers);

    return 0;
}

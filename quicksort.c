// NAME: JOSHUA DAVID
// ADM NO: EB3/67259/23

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* 
   swap()
   Exchanges two integer values in memory.
   Used throughout sorting whenever two elements need to change position.
*/
static void swap(int *a, int *b) {
    int t = *a;      /* Store first value temporarily */
    *a = *b;         /* Copy second value into first */
    *b = t;          /* Put temporary value into second */
}

/*
   insertionSort()
   Used for small subarrays (size <= 16).
   Efficient for small data because it reduces overhead of recursion.

   Since we want DESCENDING order:
   We shift elements that are SMALLER than the key.
*/
void insertionSort(int arr[], int left, int right) {
    int i, j, key;

    for (i = left + 1; i <= right; i++) {
        key = arr[i];      /* Element to be inserted */
        j = i - 1;

        /* 
           Move elements that are smaller than key
           one position ahead
        */
        while (j >= left && arr[j] < key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;  /* Place key in correct position */
    }
}

/*
   heapify()
   Maintains heap property for descending order.

   We build a MIN-HEAP so that larger elements move forward
   when extracted (for descending arrangement).
*/
void heapify(int arr[], int n, int i, int offset) {
    int smallest, l, r;

    while (1) {
        smallest = i;
        l = 2*i + 1;   /* Left child index */
        r = 2*i + 2;   /* Right child index */

        /* 
           Find smallest among root and children
           (because we want descending final order)
        */
        if (l < n && arr[offset + l] < arr[offset + smallest])
            smallest = l;

        if (r < n && arr[offset + r] < arr[offset + smallest])
            smallest = r;

        /* 
           If smallest is not root, swap and continue
        */
        if (smallest != i) {
            swap(&arr[offset + i], &arr[offset + smallest]);
            i = smallest;
        } else {
            break;
        }
    }
}

/*
   heapSort()
   Called if QuickSort recursion becomes too deep.
   Guarantees O(n log n) worst-case performance.
*/
void heapSort(int arr[], int left, int right) {
    int n, i;

    n = right - left + 1;

    /* Build heap */
    for (i = n/2 - 1; i >= 0; i--)
        heapify(arr, n, i, left);

    /* Extract elements one by one */
    for (i = n - 1; i > 0; i--) {
        swap(&arr[left], &arr[left + i]);
        heapify(arr, i, 0, left);
    }
}

/*
   medianOfThree()
   Improves pivot selection.

   Instead of choosing first or last element,
   we pick median of:
      first, middle, last

   This reduces chances of worst-case partition.
*/
int medianOfThree(int arr[], int a, int b, int c) {
    if ((arr[a] < arr[b]) != (arr[a] < arr[c])) return a;
    if ((arr[b] < arr[a]) != (arr[b] < arr[c])) return b;
    return c;
}

/*
   partition()
   Core of QuickSort.

   Rearranges elements so that:
   - Elements >= pivot go left
   - Elements < pivot go right
   (Because we want descending order)
*/
int partition(int arr[], int low, int high) {
    int mid, pivotIndex, pivot, i, j;

    mid = low + (high - low) / 2;

    /* Choose better pivot */
    pivotIndex = medianOfThree(arr, low, mid, high);
    pivot = arr[pivotIndex];

    /* Move pivot to end */
    swap(&arr[pivotIndex], &arr[high]);

    i = low - 1;

    for (j = low; j < high; j++) {
        if (arr[j] >= pivot) {   /* DESCENDING condition */
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    /* Place pivot in correct position */
    swap(&arr[i + 1], &arr[high]);

    return i + 1;   /* Return pivot index */
}

/*
   introSortUtil()
   Main recursive function.

   1. If partition is small ? use insertion sort.
   2. If recursion too deep ? switch to heap sort.
   3. Otherwise ? continue QuickSort.
*/
void introSortUtil(int arr[], int low, int high, int depthLimit) {
    int p;

    while (high - low > 16) {

        /* If recursion depth exhausted ? use heap sort */
        if (depthLimit == 0) {
            heapSort(arr, low, high);
            return;
        }

        /* Partition array */
        p = partition(arr, low, high);
        depthLimit--;

        /* 
           Recurse on smaller partition first
           This prevents stack overflow for very large arrays
        */
        if (p - low < high - p) {
            introSortUtil(arr, low, p - 1, depthLimit);
            low = p + 1;
        } else {
            introSortUtil(arr, p + 1, high, depthLimit);
            high = p - 1;
        }
    }

    /* Final small partition handled by insertion sort */
    insertionSort(arr, low, high);
}

/*
   introSort()
   Wrapper function.

   Calculates depth limit:
   depthLimit = 2 * log2(n)

   This ensures worst-case time remains O(n log n)
*/
void introSort(int arr[], int n) {
    int depthLimit;

    depthLimit = 2 * (int)(log((double)n) / log(2.0));
    introSortUtil(arr, 0, n - 1, depthLimit);
}

/*
   main()
   1. Takes input size from user
   2. Dynamically allocates memory
   3. Reads elements
   4. Sorts in descending order
   5. Prints first 50 elements
*/
int main() {
    int n, i, limit;
    int *arr;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid size\n");
        return 0;
    }

    arr = (int*) malloc(sizeof(int) * n);
    if (!arr) {
        printf("Memory allocation failed!\n");
        return 0;
    }

    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    introSort(arr, n);

    printf("\nSorted output in descending order (first 50 max):\n");

    limit = (n < 50) ? n : 50;

    for (i = 0; i < limit; i++)
        printf("%d ", arr[i]);

    if (n > 50)
        printf(" ...");

    printf("\n");

    free(arr);
    return 0;
}


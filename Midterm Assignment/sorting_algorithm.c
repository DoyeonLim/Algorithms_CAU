#include <stdio.h>
#include <time.h>
#include <math.h>

void bubbleSort(int arr[], int n)
{
    int temp;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
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

void insertionSort(int arr[], int n)
{
    int j, temp;

    for (int i = 1; i < n; i++)
    {
        temp = arr[i];

        for (j = i - 1; j >= 0 && arr[j] > temp; j--)
        {
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = temp;
    }
}

void merge(int arr[], int p, int q, int r)
{
    int i = p, j = q + 1, k = p;
    int temp[10000];

    while (i <= q && j <= r)
    {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while (i <= q)
        temp[k++] = arr[i++];
    while (j <= r)
        temp[k++] = arr[j++];

    for (int a = p; a <= r; a++)
        arr[a] = temp[a];
}

void mergeSort(int arr[], int p, int r)
{
    int q;

    if (p < r)
    {
        q = (p + r) / 2;

        mergeSort(arr, p, q);
        mergeSort(arr, q + 1, r);
        merge(arr, p, q, r);
    }
}

void swap(int* a, int* b)
{
    int temp = *a; *a = *b; *b = temp;
}

void quickSort(int arr[], int start, int end)
{
    if (start >= end) return;

    int nPivot = arr[start];

    int i = start, j = end;

    while (i < j)
    {
        while (nPivot < arr[j]) j--;
        while (i < j && nPivot >= arr[i]) i++;

        swap(arr + i, arr + j);
    }

    swap(arr + start, arr + j);

    quickSort(arr, start, j - 1);
    quickSort(arr, j + 1, end);
}

void radixSort(int *arr, int n)
{
	int result[10001];
	int maxValue = 0;
	int exp = 1;

	for (int i = 0; i < n; i++)
    {
		if (arr[i] > maxValue)
            maxValue = arr[i];
	}

	while (maxValue / exp > 0)
	{
		int bucket[10] = { 0 };

		for (int i = 0; i < n; i++)
        {
            bucket[arr[i] / exp % 10]++;
        }

		for (int i = 1; i < 10; i++)
        {
            bucket[i] += bucket[i - 1];
        }

		for(int i=n-1; i>=0;i--)
		{
			result[--bucket[arr[i] / exp % 10]] = arr[i];
		}

		for (int i = 0; i < n; i++)
        {
            arr[i] = result[i];
        }

		exp *= 10;
	}
}

int bu_arr[501][10001];

void bucketSort(int arr[], int n, int size)
{

    int num, mid=0;
    int count[size + 1];

    for (int i = 0; i < size+1; i++)
    {
        count[i] = 0;
    }

    int k = 0;

    for (int i = 0; i < n; i++)
    {
        mid = n / size;
        num = arr[i] / mid;
        bu_arr[num][count[num]++] = arr[i];
    }

    for (int i = 0; i < size+1; i++)
    {
        if (count[i] != 0)
        {
            quickSort(bu_arr[i], 0, count[i] - 1);
        }
    }

    for (int i = 0; i < size+1; i++)
    {
        for (int j = 0; j < count[i]; j++)
        {
            if (bu_arr[i][j] != 0) {
                arr[k++] = bu_arr[i][j];
            }
        }
    }
}

void random_array(int arr[], int n)
{
    srand(time(NULL));

    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % n + 1;
    }
}

void sorting_show(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n\n");
}

clock_t result[3][6];

void time_bu(int n)
{
    int arr[n];
    int i=0;
    clock_t start, end;

    if (n == 1000)
    {
        i = 0;;
    }
    else if (n == 5000)
    {
        i = 1;;
    }
    else if (n == 10000)
    {
        i = 2;;
    }

    printf("<Bubble Sort>\n\n");
    random_array(arr, n);
    sorting_show(arr, n);
    start = clock();

    bubbleSort(arr, n);
    end = clock();
    sorting_show(arr, n);
    //result = end - start;
    //printf("%d", result);
    result[i][0] = end - start;
    printf("\n---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
}

void time_in(int n)
{
    int arr[n];
    int i=0;
    clock_t start, end;

    if (n == 1000)
    {
        i = 0;;
    }
    else if (n == 5000)
    {
        i = 1;;
    }
    else if (n == 10000)
    {
        i = 2;;
    }

    printf("<Insertion Sort>\n\n");
    random_array(arr, n);
    sorting_show(arr, n);
    start = clock();

    insertionSort(arr, n);
    end = clock();
    sorting_show(arr, n);
    //result = end - start;
    //printf("%d", result);
    result[i][1] = end - start;
    printf("\n---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
}

void time_me(int n)
{
    int arr[n];
    int i=0;
    clock_t start, end;

    if (n == 1000)
    {
        i = 0;;
    }
    else if (n == 5000)
    {
        i = 1;;
    }
    else if (n == 10000)
    {
        i = 2;;
    }
    printf("<Merge Sort>\n\n");
    random_array(arr, n);
    sorting_show(arr, n);
    start = clock();

    mergeSort(arr, 1, n);
    end = clock();
    sorting_show(arr, n);
    //result = end - start;
    //printf("%d", result);
    result[i][2] = end - start;
    printf("\n---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
}

void time_qu(int n)
{
    int arr[n];
    int i=0;
    clock_t start, end;

    if (n == 1000)
    {
        i = 0;;
    }
    else if (n == 5000)
    {
        i = 1;;
    }
    else if (n == 10000)
    {
        i = 2;;
    }

    printf("<Quick Sort>\n\n");
    random_array(arr, n);
    sorting_show(arr, n);
    start = clock();

    quickSort(arr, 1, n);
    end = clock();
    sorting_show(arr, n);
    //result = end - start;
    //printf("%d", result);
    result[i][3] = end - start;
    printf("\n---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
}

void time_ra(int n)
{
    int arr[n];
    int i=0;
    clock_t start, end;

    if (n == 1000)
    {
        i = 0;;
    }
    else if (n == 5000)
    {
        i = 1;;
    }
    else if (n == 10000)
    {
        i = 2;;
    }

    printf("<Radix Sort>\n\n");
    random_array(arr, n);
    sorting_show(arr, n);
    start = clock();

    radixSort(arr, n);
    end = clock();
    sorting_show(arr, n);
    //result = end - start;
    //printf("%d", result);
    result[i][4] = end - start;
    printf("\n---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
}

void time_bk(int n)
{
    int arr[n];
    int size, i=0;
    clock_t start, end;

    if (n == 1000)
    {
        i = 0; size = 50;
    }
    else if (n == 5000)
    {
        i = 1; size = 250;
    }
    else if (n == 10000)
    {
        i = 2; size = 500;
    }

    printf("<Bucket Sort>\n\n");
    random_array(arr, n);
    sorting_show(arr, n);
    start = clock();

    bucketSort(arr, n, size);
    end = clock();
    sorting_show(arr, n);
    //result = end - start;
    //printf("%d", result);
    result[i][5] = end - start;
    printf("\n---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
}

int main()
{
    int n = 0;

    printf("N = 1000\n\n");

    n = 1000;
    time_bu(n);
    time_in(n);
    time_me(n);
    time_qu(n);
    time_ra(n);
    time_bk(n);

    printf("N = 5000\n\n");

    n = 5000;
    time_bu(n);
    time_in(n);
    time_me(n);
    time_qu(n);
    time_ra(n);
    time_bk(n);

    printf("N = 10000\n\n");

    n = 10000;
    time_bu(n);
    time_in(n);
    time_me(n);
    time_qu(n);
    time_ra(n);
    time_bk(n);

    char sorting_name[6][15] = {"Bubble Sort", "Insertion Sort", "Merge Sort", "Quick Sort", "Radix Sort", "Bucket Sort"};

    printf("<Total execution times (in millisecond) for each sorting algorithms>\n\n");
    printf("   N numbers   n = 1000    n = 5000   n = 10000\n");
    printf("===============================================\n");

    for(int i = 0;i < 6; i++)
    {
        printf("%16s    %5ld      %5ld      %5ld\n", sorting_name[i], result[0][i], result[1][i], result[2][i]);
    }

    return 0;
}



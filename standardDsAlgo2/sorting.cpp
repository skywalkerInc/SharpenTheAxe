#include<stdio.h>
#include <time.h>

typedef struct array_item {
    int item;
}ArrayItem;

int Compare(ArrayItem item1, ArrayItem item2) {
    if (item1.item > item2.item) {
        return 1;
    } 
    else if(item1.item < item2.item) {
        return -1;
    }
    else {
        return 0;
    }
}

void Assign(ArrayItem *item1, ArrayItem *item2) {
    item1->item = item2->item;
}

void Swap(ArrayItem *array, unsigned int index1, unsigned int index2) 
{
    ArrayItem temp;
    temp.item = array[index1].item;
    array[index1].item = array[index2].item;
    array[index2].item = temp.item;
}

void PrintArray(char *tag, ArrayItem *array, unsigned int array_size)
{
    printf("%s", tag);
    for (unsigned int iter=0; iter < array_size; iter++) 
    {
        printf("%d", array[iter].item);
    }
    printf("\n");
}

/*******************BUBBLE SORT******************************/
void BubbleSort(ArrayItem *array, unsigned int array_size)
{
    ArrayItem temp;
    for(unsigned int iter1=0; iter1 < array_size-1; iter1++) 
    {
        for(unsigned int iter2=0; iter2 < array_size-iter1-1; iter2++) 
        {
            if (Compare(array[iter2], array[iter2+1]) > 0) {
                Swap(array, iter2, iter2+1);
            }
        }
    }
}
/******************BUBBLE SORT END***************************/

/********************MERGE SORT*****************************/
// 34152
//341 , 
//34
//3


void Merge(ArrayItem *array, unsigned int left, unsigned int mid, unsigned int right)
{
    //create temporary array to contain right - left element in sorted order
    unsigned int nleft = mid - left + 1;
    unsigned int nright = right - mid;
    ArrayItem temp_left[nleft];
    ArrayItem temp_right[nright];
    
    //Assign array elements in temporary array
    for (unsigned int left_index = 0; left_index < nleft; left_index++)
    {
        temp_left[left_index] = array[left + left_index];
    }
    
    for (unsigned int right_index = 0; right_index < nright; right_index++) 
    {
        temp_right[right_index] = array[mid + 1 + right_index];
    }
    
    //Compare temporary arrays and fill in main array
    unsigned int left_index = 0;
    unsigned int right_index = 0;
    unsigned int array_index = left;
    
    while (left_index < nleft && right_index < nright) {
        if (Compare(temp_left[left_index], temp_right[right_index]) <= 0) {
            array[array_index] = temp_left[left_index];
            left_index++;
        } else {
            array[array_index] = temp_right[right_index];
            right_index++;
        }
        array_index++;
    }
    
    //elements left in temp_left
    while(left_index < nleft) {
        array[array_index] = temp_left[left_index];
        left_index++;
        array_index++;
    }
    
    //elements left in temp_right
    while(right_index < nright) {
        array[array_index] = temp_right[right_index];
        right_index++;
        array_index++;
    }
    
}

void MergeSort(ArrayItem *array, unsigned int left, unsigned int right)
{
    if (left >= right) {
        return;
    }
    
    unsigned int mid = left + (right - left)/2;
    
    MergeSort(array, left, mid);
    MergeSort(array, mid+1, right);
    
    Merge(array, left, mid, right);
}

/********************MERGE SORT END************************/

/********************Quick Sort****************************/
/* This function takes last element as pivot, places the pivot element at its correct position in sorted array, and places all smaller (smaller than pivot) to left of pivot and all greater elements to right of pivot */
unsigned int Partition(ArrayItem *array, unsigned int low, unsigned int high) {
    ArrayItem pivot = array[high];
    unsigned int hook = low - 1;
    for (unsigned int move = low; move < high; move++) {
        if (Compare(array[move], pivot) < 0) {
            hook++;
            Swap(array, move, hook);
        }
    }
    Swap(array, hook+1, high);
    return hook+1;
}

void QuickSort(ArrayItem *array, int low, int high) {
    if (low < high) {
        unsigned int pi = Partition(array, low, high);
        QuickSort(array, low, pi-1);
        QuickSort(array, pi+1, high);
    }
}

void OptimizedQuickSort(ArrayItem *array, int low, int high) {
    while (low < high) {
        unsigned int pi = Partition(array, low, high);
        
        if (pi-low < high - pi) {
            OptimizedQuickSort(array, low, pi-1);
            low = pi +1;
        } else {
            OptimizedQuickSort(array, pi+1, high);
            high = pi - 1;
        }
    }
    
}

/*******************Quick Sort End*************************/
/******************Heap Sort*******************************/
void Heapify(ArrayItem *array, int root_index, unsigned int size) {
    //make max heap, assume child are already heapified
    int ilargest = root_index;
    int ileft = 2*root_index + 1;
    int iright = 2*root_index + 2;
    
    if (ileft < size && Compare(array[ileft], array[ilargest]) > 0) {
        ilargest = ileft;
    }
    if (iright < size && Compare(array[iright], array[ilargest]) > 0) {
        ilargest = iright;
    }
    
    if (ilargest != root_index) {
        Swap(array, ilargest, root_index);
        Heapify(array, ilargest, size);
    }
}

void HeapSort(ArrayItem *array, unsigned int size) {
    // this will bring maximum at the top (heapify all parent roots)
    for(int i = size/2 -1; i >=0 ; i--) {
        Heapify(array, i, size);
    }
    
    
    for(unsigned int i = size -1; i>0; i--) {
        Swap(array, i, 0);
        Heapify(array, 0, i);
    }
}
/*****************Heap Sort End**************************/

int main(void) {
    ArrayItem temp = {5};
    ArrayItem array[7] = {{3},{8},{1},{6},{2}, {-1}, {3}};
    PrintArray("input: ",array, sizeof(array)/sizeof(ArrayItem));
    // BubbleSort(array, sizeof(array)/sizeof(ArrayItem));
    // PrintArray("bubblesort: ", array, sizeof(array)/sizeof(ArrayItem));
    // MergeSort(array, 0, sizeof(array)/sizeof(ArrayItem) -1);
    // PrintArray("mergesort: ", array, sizeof(array)/sizeof(ArrayItem));
    // OptimizedQuickSort(array, 0, sizeof(array)/sizeof(ArrayItem) - 1);
    // PrintArray("Quicksort: ", array, sizeof(array)/sizeof(ArrayItem));
    HeapSort(array, sizeof(array)/sizeof(ArrayItem));
    PrintArray("HeapSort: ", array, sizeof(array)/sizeof(ArrayItem));
    return 0;
 }
#include <stdio.h>
#include <stdlib.h>
int b[20];
void printList(int *nums, int size);
void merge(int *nums, int low, int mid, int high);
void sort(int *nums, int low, int high);
int main()
{

    int nums[20] = {7,6,8,9,1,2,4,3,5,10, 12, 13, 14, 11, 19, 18, 15, 17, 16, 20};
    printList(nums, 20);
    sort(nums, 0, 20);
    printList(nums, 20);
    return 0;

}

void printList(int *nums, int size)
{

    int i;
    for(i = 0; i < size; i++) {printf("%d ", nums[i]);}
    printf("\n\n");

}

void merge(int *nums, int low, int mid, int high)
{

    int l1, l2, i;
    l1 = low; l2 = mid + 1;
    i = low;
    while(i <= high)
    {

           if(l1 > mid) {b[i++] = nums[l2++];}
           else if(l2 > high) {b[i++] = nums[l1++];}
           else if(nums[l1] > nums[l2]) {b[i++] = nums[l2++];}
           else {b[i++] = nums[l1++];}

    }

    for(i = low; i <= high; i++) {nums[i] = b[i];}

}

void sort(int *nums, int low, int high)
{

    if(low < high)
    {
        int mid = (low + high) / 2;
        sort(nums, low, mid);
        sort(nums, mid + 1, high);
        merge(nums, low, mid, high);

    } else{return;}

}

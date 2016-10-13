#include <stdio.h>
#include <stdlib.h>

void printList(int *nums, int size);
int partition(int *nums, int low, int high);
void sort(int *nums, int low, int high);
int main()
{

    int nums[20] = {7,6,8,9,1,2,4,3,5,10, 12, 13, 14, 11, 19, 18, 15, 17, 16, 20};
    printList(nums, 20);
    sort(nums, 0, 19);
    printList(nums, 20);
    return 0;

}

void printList(int *nums, int size)
{

    int i;
    for(i = 0; i < size; i++) {printf("%d ", nums[i]);}
    printf("\n\n");

}

int partition(int *nums, int low, int high)
{
    int temp;
    int left = low; int right = high;
    int pivot = nums[low];
    while(1)
    {


        while(nums[left] <= pivot && left < high) {left++;}

        while(nums[right] > pivot) {right--;}

        if(left >= right) {break;}
        temp = nums[right]; nums[right] = nums[left]; nums[left] = temp;

    }

    temp = nums[right]; nums[right] = nums[low]; nums[low] = temp;
    return right;
}

void sort(int *nums, int low, int high)
{

    if(low < high)
    {

      int j = partition(nums, low, high);
      sort(nums, low, j - 1);
      sort(nums, j + 1, high);

    } else {return;}


}

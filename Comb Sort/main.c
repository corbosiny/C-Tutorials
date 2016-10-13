#include <stdio.h>
#include <stdlib.h>


void printList(int *nums, int size);
void sort(int *nums, int size);
int main()
{

    int nums[10] = {1,10, 2, 9, 3, 8, 4, 7, 5, 6};
    printList(nums, 10);
    sort(nums, 10);
    printList(nums, 10);
    return 0;

}

void printList(int *nums, int size)
{

    int i;
    for(i = 0; i < size; i++) {printf("%d ", nums[i]);}
    printf("\n\n");

}

void sort(int *nums, int size)
{

    float gap = (size / 1.3);
    int swapped = 1;
    while(gap > 1 || swapped)
    {

        swapped = 0;
        if(gap < 1) {gap = 1;}
        int igap = (int) gap;

        int i;
        for(i = 0; i + igap < size; i++)
        {
            if(nums[i] > nums[i + igap])
            {int temp = nums[i]; nums[i] = nums[i + igap]; nums[i + igap] = temp; swapped = 1;}
        }
        gap /= 1.3;
    }

}

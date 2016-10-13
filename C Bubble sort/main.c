#include <stdio.h>
#include <stdlib.h>
void printList(int *nums, int size);
void swapValues(int *nums, int index1, int index2);
void sort(int *nums, int size);

int main()
{
    int nums[] = {2,6,5,4,7,3,9,8};
    int size = sizeof(nums) / sizeof(nums[0]);
    printList(nums, size);
    sort(nums, size);
    printList(nums, size);

    return 0;
}

void printList(int *nums, int size)
{

    int i;
    for(i = 0; i < size; i++) {printf("%d ", nums[i]);}
    printf("\n\n");

}

void swapValues(int *nums, int index1, int index2)
{

    int temp = nums[index1];
    nums[index1] = nums[index2];
    nums[index2] = temp;

}

void sort(int *nums, int size)
{


    int i;
    for(i = 0; i < size; i++)
    {

        int numSwaps = 0;
        int j;
        for(j = 1; j < size; j++)
        {

            if(nums[j] < nums[j - 1])
            {
                printf("%d is larger than %d, switching index %d with index %d\n", nums[j - 1], nums[j], j - 1, j);
                swapValues(nums, j, j - 1);
                numSwaps++;
                printList(nums, size);
            } else {printf("%d is not larger than %d, moving on\n", nums[j-1], nums[j]); printList(nums, size);}

        }

        if(numSwaps == 0) {printf("List sorted early\n"); printList(nums, size);break;}

    }

}

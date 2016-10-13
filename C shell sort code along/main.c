#include <stdio.h>
#include <stdlib.h>

void printList(int *nums, int size);
void sort(int *nums, int size);

int main()
{
    int nums[20] = {7,6,8,9,1,2,4,3,5,10, 12, 13, 14, 11, 19, 18, 15, 17, 16, 20};
    printList(nums, 20);
    sort(nums, 20);
    printList(nums, 20);
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

    int interval = 1;

    while(interval < size / 3) {interval = interval * 3 + 1;}

    while(interval > 0)
    {

        int inner, outer, valToSwap;
        for(outer = interval; outer < size; outer++)
        {

            inner = outer;
            valToSwap = nums[inner];

            while(inner > interval - 1 && nums[inner - interval] > valToSwap)
            {

                nums[inner] = nums[inner - interval];
                inner -= interval;

            }

            nums[inner] = valToSwap;

        }

        interval = (interval - 1) / 3;

    }


}

#include <stdio.h>
#include <stdlib.h>

void printList(int *nums);
void sort(int *nums);

int stepsTaken;
int main()
{
    int nums[20] = {7,6,8,9,1,2,4,3,5,10, 12, 13, 14, 11, 19, 18, 15, 17, 16, 20};
    printList(nums);
    sort(nums);
    printList(nums);
    printf("Steps Taken: %d", stepsTaken);
    return 0;

}


void printList(int *nums)
{

    int size = 20;
    int i;
    for(i = 0; i < size; i++) {printf("%d ", nums[i]);}
    printf("\n\n");

}

void sort(int *nums)
{

    int size = 20;

    int i, val1, val2;
    for(i = 0; i < size; i++)
    {
        val1 = nums[i];

        while(val1 > nums[i + 1])
        {
            stepsTaken++;
            printf("%d is greater than %d, switching index %d with %d\n", val1, nums[i + 1], i, i+1);
            printList(nums);

            nums[i] = nums[i + 1];
            val2 = nums[i];
            int j;
            for(j = i; j >= 0; j--)
            {
                stepsTaken++;
                if(j == 0)
                {
                    nums[0] = val2;
                    printf("putting %d at the beginning of the list\n", val2); printList(nums);
                }
                else if(val2 < nums[j-1])
                {
                    printf("%d is less than %d, switching %d with %d\n", val2, nums[j-1], j, j-1);
                    printList(nums);
                    nums[j] = nums[j-1];
                }
                else
                {
                    printf("Putting %d in index %d\n", val2, j);
                    printList(nums);
                    nums[j] = val2;
                    break;
                }

            }

            i++;

        }

        printf("Putting %d at index %d\n", val1, i);
        printList(nums);
        nums[i] = val1;

    }

}



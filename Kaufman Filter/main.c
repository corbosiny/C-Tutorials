#include <stdio.h>
#include <stdlib.h>

int **calcCovarMatrix(int dataMatrix[][100]);
int **transpose(int matrix[][3]);

int main()
{
    int data1[] = {};
    int data2[] = {};
    int matrix1[][3] = {{1,2,3}, {4,5,6}, {7,8,9}};
    int **matrix2 = transpose(matrix1);
    printf("%d", matrix2[0][0]);
    int i, j;
    for(i = 0; i < 3; i++)
    {
        printf("\n");
        //for(j = 0; j < 3; j++) {printf("%d ", matrix2[i][j]);}

    }
    //int matrix[] = calcCovarMatrix(data1, data2);
    return 0;
}

int **transpose(int matrix[][3])
{

    int transpose[3][3] = {{1,2,3}, {4,5,6}, {7,8,9}};
//    int i, j;
//    for(i = 0; i < 3; i++)
//    {
//
//        for(j = 0; j < 3; j++)
//        {
//
//            transpose[i][j] = matrix[j][i];
//            printf("%d ", transpose[i][j]);
//        }
//
//        printf("\n");
//    }

    return transpose;

}

int **calcCovarMatrix(int dataMatrix[][100])
{

    int size = 100;

    int averageData[2];
    int i;
    for(i = 0; i < 2; i++)
    {

        averageData[i] = 0;
        int j;
        for(j = 0; j < size; j++) {averageData[i] += dataMatrix[i][j];}
        averageData[i] /= size;

    }

    for(i = 0; i < 2; i++)
    {
        int j;
        for(j = 0; j < size; j++) {dataMatrix[i][j] -= averageData[i];}

    }

  //int tranpose[][] = transpose(dataMatrix)

  //return covarMatrix;

}

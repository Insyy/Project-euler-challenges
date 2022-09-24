#include<stdio.h>

#define N 1001
#define N2 N*N

int main(int argc, char const *argv[])
{
    int arr[N2];

    for (size_t i = 1; i <= N2; i++)
    {
        arr[i-1] = (int) i;
        //printf("%d\n", arr[i]);
    }

    int index = 0, 
    currIndex, 
    sum = 1, 
    diff = 2;
    for (size_t i = 0; i < N/2; i++)
    {
        for (size_t j = 1; j <= 4; j++)
        {
            currIndex = index + j*diff;
            //printf("%d\n", arr[currIndex]);
            sum += arr[currIndex];
        }
        index = currIndex;
        diff += 2;
    }
    printf("The sum of the numbers on the diagonals in a %d by %d spiral is %d\n", N, N, sum);
    // 0 2 4 6 8 12 16 20 24
    return 0;
}

#include <stdio.h>
#include <stdbool.h>
#define COL 10
#define ARRSIZE (COL*(COL+1))/2
#define CHECK 29

typedef struct
{
    int neighbours[8];
    int n_neighbours;
} neighbours_result_t;

bool isPrime(int number)
{
    for (int i = 2; i < number; i++)
    {
        if (number % i == 0 && i != number)
            return false;
    }
    return true;
}

void printNeighbours(neighbours_result_t neighbours)
{
    printf("\nNeighbours are: ");
    for (size_t i = 0; i < neighbours.n_neighbours; i++)
    {
        printf("%d ", neighbours.neighbours[i]);
    }
    printf("\n");
}

neighbours_result_t getNeighbours(int arr[], int rowIndex, int rowSize, int currIndex)
{

    int res[8];

    neighbours_result_t result;
    result.n_neighbours = 0;

    if (rowSize > 1)
    {
        // TOP LEFT
        if (rowIndex > 0 && rowSize > 0)
        {
        printf(" TL %d ", arr[currIndex - rowSize]);
            result.neighbours[result.n_neighbours] = arr[currIndex - rowSize];
            result.n_neighbours++;
        }
        // TOP
        if (rowIndex + 1 != rowSize)
        {
        printf(" T %d ", arr[currIndex - rowSize + 1]);
            result.neighbours[result.n_neighbours] = arr[currIndex - rowSize + 1];
            result.n_neighbours++;        }
        // TOP RIGHT
        if (rowIndex < rowSize - 1)
        {
        printf(" TR %d ", arr[currIndex - rowSize + 2]);
            result.neighbours[result.n_neighbours] = arr[currIndex - rowSize + 2];
            result.n_neighbours++;
        }
    }

    // LEFT
    if (rowIndex > 0)
    {
        printf(" L %d ", arr[currIndex - 1]);
        result.neighbours[result.n_neighbours] = arr[currIndex - 1];
        result.n_neighbours++;
    }

    // RIGHT
    if (rowIndex < rowSize - 1)
    {
        printf(" R %d ", arr[currIndex + 1]);
        result.neighbours[result.n_neighbours] = arr[currIndex + 1];
        result.n_neighbours++;
    }

    if (rowSize < COL)
    {
        // BOTTOM LEFT
        if (rowIndex > 0)
        {
        printf(" BL %d ", arr[currIndex + rowSize - 1]);
            result.neighbours[result.n_neighbours] = arr[currIndex + rowSize - 1];
            result.n_neighbours++;
        }

        // BOTTOM
        result.neighbours[result.n_neighbours] = arr[currIndex + rowSize];
        result.n_neighbours++;
        
        //BOTTOM RIGHT
        result.neighbours[result.n_neighbours] = arr[currIndex + rowSize + 1];
        result.n_neighbours++;
    }

    

    return result;
}

int main(int argc, char const *argv[])
{
    int array[ARRSIZE];
    for (size_t i = 0; i < ARRSIZE; i++)
    {
        array[i] = i + 1;
    }

    int index = 0, rowSize = 1;

    for (size_t colIndex = 0; colIndex < COL; colIndex++)
    {
        for (int rowIndex = 0; rowIndex < rowSize; rowIndex++)
        {
            /* if (!(index < SIZE))
                return 0; */

            printf("%d ", array[index]);
            if (array[index] == CHECK)
            {
                neighbours_result_t neighbours = getNeighbours(array, rowIndex, rowSize, index);
                printNeighbours(neighbours);
            }

            index++;
        }
        printf("\n");
        rowSize++;
    }

    return 0;
}

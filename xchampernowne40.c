#include <stdio.h>
#include<stdbool.h>
#include <stdlib.h>
#include<string.h>

int main(int argc, char const *argv[])
{
    bool found = false;
    int remainingProducts = 6, target = 10;
    int result = 1;
    int index = 2, currNumber = 2;

    while (!found)
    {

        if (remainingProducts == 0)
        {
            found = true;
            continue;
        }
        

        char myStr[20];
        int currLen;

        if (sprintf(myStr, "%d", currNumber) < 0)
        {
            //fprintf(stderr, "Error: could not convert %d to a string.", currNumber);
            return -1;
        }
        
        currLen = strlen(myStr);

        //printf("Current number %s of len %d\n", myStr, currLen);

        for (int i = index; i < index + currLen; i++)
        {
            int d = myStr[i - index] - '0';
            //printf("Digit index %d: %d\n", i, d);
            if (i == target)
            {
                //printf("Found target index %d\n", target);
                result *= d;
                remainingProducts--;
                target *= 10;
            }
            
        }
        
        currNumber++;
        index += currLen;
    }
    
    printf("FINAL RESULT: %d\n", result);

    return 0;
}

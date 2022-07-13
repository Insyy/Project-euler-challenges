#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void getPeterDicePossibleCombinations()
{
  int colin_dices_expected_value = 21;
  double nCombinations = pow(4, 9);
  int validCombinations = 0;
  int nFaces = 4;
  int nDices = 9;
  printf("%lf combinations are possible for nine four-sided dices. \n", nCombinations);
  for (size_t a = 1; a <= nFaces; a++)
  {
    for (size_t b = 1; b <= nFaces; b++)
    {
      for (size_t c = 1; c <= nFaces; c++)
      {
        for (size_t d = 1; d <= nFaces; d++)
        {
          for (size_t e = 1; e <= nFaces; e++)
          {
            for (size_t f = 1; f <= nFaces; f++)
            {
              for (size_t g = 1; g <= nFaces; g++)
              {
                for (size_t h = 1; h <= nFaces; h++)
                {
                  for (size_t i = 1; i <= nFaces; i++)
                  {
                    if ((a + b + c + d + e + f + g + h + i) > colin_dices_expected_value)
                    {
                      validCombinations++;
                      printf("Combination %ld%ld%ld%ld%ld%ld%ld%ld%ld found\n",a,b,c,d,e,f,g,h,i);
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  printf("%d valid combinations have been found of a total %lf possible combinations.\n Therefore, the probability that Pyramidal Pete beats Cubic Colin is %.8lf",
    validCombinations, nCombinations, validCombinations * 1.0 / nCombinations);
}

int main(int argc, char const *argv[])
{
  getPeterDicePossibleCombinations();
  return 0;
}

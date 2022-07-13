#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

typedef struct
{
  int number;
  int turnsInMemory;
  int turnsNoCall;
} calledNumber;

typedef struct
{
  int score;
  int nRemembered;
  calledNumber memory[5];
} player;

void insertNumberInMemory(player *player, int number, int numberIndex)
{
  calledNumber numberInserted = {number, 0, 0};
  player->memory[numberIndex] = numberInserted;
}

void playLarry(player *larry, int numberCalled)
{
  int remembers = 0;
  int numberIndex;
  for (numberIndex = 0; numberIndex < larry->nRemembered; numberIndex++)
  {
    if (larry->memory[numberIndex].number == numberCalled)
    {
      remembers++;
      larry->score++;
      larry->memory[numberIndex].turnsNoCall = 0;
    }
    else
      larry->memory[numberIndex].turnsNoCall++;
  }
  if (!remembers)
  {
    int maxCall = 0;
    int maxCallIndex;
    if (larry->nRemembered == 5)
    {
      for (numberIndex = 0; numberIndex < larry->nRemembered; numberIndex++)
      {
        if (larry->memory[numberIndex].turnsNoCall > maxCall)
        {
          maxCallIndex = numberIndex;
          maxCall = larry->memory[numberIndex].turnsNoCall;
        }
      }
      insertNumberInMemory(larry, numberCalled, maxCallIndex);
    }
    else
    {
      insertNumberInMemory(larry, numberCalled, larry->nRemembered);
      larry->nRemembered++;
    }
  }
}
void printPlayerMemory(const player player)
{
  for (int numberIndex = 0; numberIndex < player.nRemembered; numberIndex++)
    printf(" %d", player.memory[numberIndex].number);
  printf("\n");
}
void playRobin(player *robin, int numberCalled)
{
  int remembers = 0;
  int numberIndex;
  for (numberIndex = 0; numberIndex < robin->nRemembered; numberIndex++)
  {
    if (robin->memory[numberIndex].number == numberCalled)
    {
      remembers++;
      robin->score++;
    }
    else
      robin->memory[numberIndex].turnsInMemory++;
  }
  if (!remembers)
  {
    int maxMem = 0;
    int maxMemIndex;
    if (robin->nRemembered == 5)
    {
      for (numberIndex = 0; numberIndex < robin->nRemembered; numberIndex++)
      {
        if (robin->memory[numberIndex].turnsInMemory > maxMem)
        {
          maxMemIndex = numberIndex;
          maxMem = robin->memory[numberIndex].turnsInMemory;
        }
      }
      insertNumberInMemory(robin, numberCalled, maxMemIndex);
    }
    else
    {
      insertNumberInMemory(robin, numberCalled, robin->nRemembered);
      robin->nRemembered++;
    }
  }
}

int getDifferenceFromNturns(int n, player larry, player robin)
{
  int difference = 0;
  int numberCalled;
  for (int turn = 1; turn <= n; turn++)
  {
    numberCalled = (rand() % 10) + 1;
    playLarry(&larry, numberCalled);
    playRobin(&robin, numberCalled);
    /*printf("Larry's memory at turn %d: ", turn);
    printPlayerMemory(larry);
    printf("Robin's memory at turn %d: ", turn);
    printPlayerMemory(robin);*/
  }
  return abs(larry.score - robin.score);
}

int playPredefinedTurns(int numberList[], int n)
{
  player larry = {
      0,
      0,
  };
  player robin = {
      0,
      0,
  };
  int numberCalled;
  for (int nTurns = 0; nTurns < n; nTurns++)
  {
    /*printf("\nTurn %d:\n", nTurns);*/
    numberCalled = numberList[nTurns];
    playLarry(&larry, numberCalled);
    playRobin(&robin, numberCalled);
    /*printf("\tLarry's memory: ");
    printPlayerMemory(larry);
    printf("\tRobin's memory: ");
    printPlayerMemory(robin);*/
  }
  /*printf("Larry's score: %d    Robin' score: %d\n", larry.score, robin.score);*/
}

double getMeanFromNTurnsAndPrecision(int nTurns, int precision)
{
  int differencesSum = 0, iterations, difference;
  int indexToCheck = precision + 1, stabilizationCount = 0;
  char meanStr[500];
  char lastseen = '0';

  for (iterations = 1; stabilizationCount < 1000; iterations++)
  {

    player larry = {
        0,
        0,
    };
    player robin = {
        0,
        0,
    };
    difference = getDifferenceFromNturns(nTurns, larry, robin);
    differencesSum += difference;
    sprintf(meanStr, "%0.8lf", differencesSum * 1.0 / iterations);
    if (meanStr[indexToCheck] == lastseen && meanStr[indexToCheck - 1] != '0')
      stabilizationCount++;
    else
    {
      stabilizationCount = 0;
      lastseen = meanStr[indexToCheck];
    }
    printf("The expected value of |L-R| after %d turns and %d iterations is %s\n",
           nTurns, iterations, meanStr);
  }
  printf("The expected value of |L-R| after %d iterations is %s\n",
         iterations, meanStr);
  return atof(meanStr);
}

int main(int argc, char const *argv[])
{
  if (argc != 3)
  {
    fprintf(stderr, "Utilisation: ./selectiveAmnesia298.exe [turnsForEachIteration] [precision]\n");
    return 1;
  }
  srand(time(0));
  getMeanFromNTurnsAndPrecision(atoi(argv[1]), atoi(argv[2]));
  return 0;
}

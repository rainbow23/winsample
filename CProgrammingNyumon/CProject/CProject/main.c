#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warining(disable : 4996)
#define BUFFER_LENGTH 20

typedef struct LS {
  struct LS *Previous;
  char String [BUFFER_LENGTH];
}LinkedString;

int main()
{
  char input[BUFFER_LENGTH];
  int lineCount = 0;
  LinkedString *ls, *previous = NULL;

  while (NULL != gets(input) && lineCount < 4)
  {
    ls = (LinkedString*)malloc(sizeof(LinkedString));
    ls->Previous = previous;
    strcpy(ls->String, input);
    previous = ls;
    lineCount++;
  }

  LinkedString **allData;
  allData = (LinkedString **)malloc(sizeof(LinkedString *) * lineCount);

  for (int i = lineCount - 1; i >= 0; i--)
  {
    allData[i] = ls;
    ls = ls->Previous;
  }

  for (int i = 0; i < lineCount; i++)
  {
    for (int j = i + 1; j < lineCount; j++)
    {
      if (0 < strcmp(allData[i]->String, allData[j]->String))
      {
        printf("strcmp \nallData[%i] %s\nallData[%i] %s\n", i, allData[i]->String, j, allData[j]->String);

        LinkedString *buff = allData[i];
        allData[i] = allData[j];
        allData[j] = buff;
      }

    }
  }
  printf("\n");

  for (int i = 0; i < lineCount; i++)
    printf("allData[%i] %s\n", i, allData[i]->String);
}
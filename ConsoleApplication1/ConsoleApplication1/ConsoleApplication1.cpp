// ConsoleApplication1.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>


void is_Correct_ip(char *ps);
//int segmentIsCorrect(char *ipAddr, int min, int max);
int cnt = 0;

DWORD WINAPI segmentIsCorrect(void* data) 
{
  // Do stuff.  This will be the first function called on the new thread.
  // When this function returns, the thread goes away.  See MSDN for more details.
  char *sepIp;
  sepIp = strtok((char*)data, ".");

  while (sepIp != NULL)
  {
    int num = atoi(sepIp);
    if (num)
    {

      if (num >= 1 && num <= 100)
        cnt++;
    }
    sepIp = strtok(NULL, ".");
  }
    return 0;
}

  int main(void) {
    char ipNumStr[10];

    fgets(ipNumStr, sizeof(ipNumStr), stdin);
    int ipNum = atoi(ipNumStr);
    if (ipNum)
    {
      char ipAddrs[1024];
      ipAddrs[0] = '\0';

      for (int i = 0; i<ipNum; i++)
      {
        char ipaddr[100];
        for (int i = 0; i < 100; i++)
        ipaddr[i] = '\0';

      fgets(ipaddr, sizeof(ipaddr), stdin);
      //printf("%s", ipaddr);

      for (int i = 0; i < 100; i++)
        if (ipaddr[i] == '\n') {
          ipaddr[i] = ',';
        }
      strcat_s(ipAddrs, sizeof(ipAddrs), ipaddr);
    }

    //hantei
    is_Correct_ip(ipAddrs);
  }

  return 0;
}

struct args {
  char * buff;
  int * count;
};


//correct returns 1, wrong returns 0
void is_Correct_ip(char *ipAddr)
{
    char *eachIpAddr;
    eachIpAddr = strtok(ipAddr, ",");

    while (eachIpAddr != NULL)
    {
      char buff[1024];
      for (int i=0; i < 1024; i++)
        buff[i] = '\0';

      strcpy_s(buff,eachIpAddr);
      /*
      args aa;
      aa.buff = buff;
      aa.count = cnt;
      */
      HANDLE thread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)segmentIsCorrect, &buff, 0, NULL);
      Sleep(1000);
        if (cnt == 4)
        {
          printf("true\n");
        }
        else
        {
          printf("false\n");
        }

/*
      if (WaitForSingleObject(thread, INFINITE))
      {
        if (cnt == 4)
        {
          printf("true\n");
        }
        else
        {
          printf("false\n");
        }
      }
*/
      eachIpAddr = strtok(NULL, ",");
    }
}
/*
DWORD WINAPI segmentIsCorrect(void* data)//(char *ipAddr, int min, int max)
{
    char *sepIp;
    sepIp = strtok((char*)data, ".");

    while (sepIp != NULL)
    {
      int num = atoi(sepIp);
      if (num) 
      {
        
        if (num >= 1&& num <= 100)
          cnt++;
      }
      sepIp = strtok(NULL, ".");
    }
    return 0;
}*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <pthread.h>

void error(char *msg)
{
		fprintf(stderr, "%s:%s\n", msg, strerror(errno));
		exit(1);
}

void is_Correct_ip(char *ps);
void* segmentRangeIsMatch(void* ipAddr); 

int main(void) 
{
    char ipNumStr[10];

    fgets(ipNumStr, sizeof(ipNumStr), stdin);
    int ipNum = atoi(ipNumStr);
    if (ipNum)
    {
      char ipAddrs[1024];
      ipAddrs[0] = '\0';

      for (int i = 0; i<ipNum; i++)
      {
					char eachIpAddr[100];
					for (int i = 0; i < 100; i++)
						eachIpAddr[i] = '\0';

					fgets(eachIpAddr, sizeof(eachIpAddr), stdin);
					//printf("%s", ipaddr);

					for (int i = 0; i < 100; i++)
					{
						if (eachIpAddr[i] == '\n') 
						{
							eachIpAddr[i] = ',';
							break;
						}
					}
					
					strcat(ipAddrs, eachIpAddr);
				}

    //hantei
		printf("ipAddrs%s\n", ipAddrs);
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

			printf("eachIpAddr2 %s\n", eachIpAddr);
      eachIpAddr = strtok(NULL, ",");
			printf("eachIpAddr3 %s\n", eachIpAddr);
/*
    while (eachIpAddr != NULL)
    {
      char buff[1024];
      for (int i=0; i < 1024; i++)
        buff[i] = '\0';

      strcpy(buff,eachIpAddr);

			printf("eachIpAddr1 %s\n", eachIpAddr);
			pthread_t t0;
			long matchIpAddNum;
			if(pthread_create(&t0, NULL, segmentRangeIsMatch, (void*)buff) == -1)
			{
				error("can't create thread0");
			}

			//thread return match num
			void* result;
			if(pthread_join(t0, &result) == -1) 
			{
				error("can't join thread0");
			}
			
			printf("result %lo\n",(long)result);

			if ((long)result == 4)
			{
				printf("true\n");
			}
			else
			{
				printf("false\n");
			}
			printf("eachIpAddr2 %s\n", eachIpAddr);
      eachIpAddr = strtok(NULL, ",");
			printf("eachIpAddr3 %s\n", eachIpAddr);
    }
*/
}

void* segmentRangeIsMatch(void* ipAddr) 
{
	long cnt = 0;
  char *sepIp;
  sepIp = strtok((char*)ipAddr, ".");

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
    return (void*)cnt;
}

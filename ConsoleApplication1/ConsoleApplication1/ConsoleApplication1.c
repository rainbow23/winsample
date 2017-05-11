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

int is_Correct_ip(char *ipAddr);
int segmentRangeIsMatch(int segNum); 

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

//correct returns 1, wrong returns 0
int is_Correct_ip(char *ipAddr)
{
    char *eachIpAddr[50];
		int cnt = 0;
		for(eachIpAddr[cnt] = strtok(ipAddr, ","); eachIpAddr[cnt] != NULL; eachIpAddr[++cnt] = strtok(NULL, ","))
		{
			printf("eachIpAddr[%i] %s\n", cnt, eachIpAddr[cnt]);
		}
		cnt--;

    /*
    char *eachWord[100];
    int m = 0; //reference ref struct pointer
    int cnt = 0;

    for (eachWord[cnt] = strtok(ref[m], "."); m < n; eachWord[++cnt] = strtok(ref[++m], "."))
    {
      for (; eachWord[cnt] != NULL; eachWord[++cnt] = strtok(NULL, "."))
      {
        printf("eachWord[%i] %s\n", cnt, eachWord[cnt]);
      }

      cnt--;//delete null value
      printf("\n");
    }
    */
		int correctSegNum  = 0;
		char *segIpNum[50];
		int i=0;
		int cnt2 =0;
		for(segIpNum[cnt2] = strtok(eachIpAddr[i], "."), i < cnt; segIpNum[++cnt2] = strtok(eachIpAddr[++i], ".");)
		{
			for(; segIpNum[cnt2] != NULL; segIpNum[++cnt2] = strtok(NULL, "."))
			{
        correctSegNum += segmentRangeIsMatch((int)eachIpAddr[cnt2]);
			}
      cnt2=0;

      if (correctSegNum == 4)
      {
        printf("true\n");
        return 1;
      }
      else
      {
        printf("false\n");
        return 0;
      }
      printf("\n");
		}
}

//return 0 or 1
int segmentRangeIsMatch(int segNum) 
{
		int cnt;
		if (segNum >= 1 && segNum <= 100)
		{
        return 1;
    }
    return 0;
}

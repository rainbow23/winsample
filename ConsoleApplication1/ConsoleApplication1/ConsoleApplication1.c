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
int charPointToInt(char *pChar);

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
			for (int i = 0; i < 100; i++){ eachIpAddr[i] = '\0'; }
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
	printf("ipAddrs %s\n", ipAddrs);
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
	
	printf("cnt %d\n", cnt);

	int correctSegNum  = 0;
	char *segIpNum[50];
	int cnt2 =0;
	int i=0;
	for(segIpNum[cnt2] = strtok(eachIpAddr[i], "."); 
		i < cnt; 
		segIpNum[++cnt2] = strtok(eachIpAddr[++i], "."))
	{
		correctSegNum =0;

		for(; segIpNum[cnt2] != NULL; segIpNum[++cnt2] = strtok(NULL, "."))
		{
			correctSegNum += segmentRangeIsMatch(atoi(segIpNum[cnt2]));
		}

		printf("cnt2 %d\n", cnt2);
		cnt2--;//NULL代入を消す

		if (correctSegNum == 4)
		{
			printf("true\n");
		}
		else
		{
			printf("false\n");
		}

		printf("\n");
	}

	for(int i=0; i < cnt2; i++)
	{
		//printf("segIpNum[%i] %s\n", i, segIpNum[i]);
	}

	return 0;
}

//return 0 or 1
int segmentRangeIsMatch(int segNum) 
{
	int cnt;
	printf("segNum %d\n", segNum);
	if (segNum >= 1 && segNum <= 100)
	{
        return 1;
    }
    return 0;
}

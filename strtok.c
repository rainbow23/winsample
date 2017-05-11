#include <stdio.h>
#include <string.h>

int main(void) 
{
	/*
	int i,j;
	char str[] ="abc.def,ghi.jkl,mnopq.r,kkk.bbb";
	char *a[100],*b,*c;

	for( i=0,a[0] = strtok(str,",\n"); (a[i]) && (i < 100); a[++i] = strtok(NULL,",\n")) {;}
		for( j = 0; j < i; j++) 
		{
			b=strtok(a[j],".");
			c=strtok(NULL,".");
			printf("b=%s\n",b);
				printf("c=%s\n",c);
		}
	*/

	char moji[] = "aaa.bbb,ccc.ddd,eee.fff.ggg,hhh.iii.jjj.kkk,zz.zz.zz";
	printf("%s\n", moji);
	char *ref[128];

	int n=0;
	ref[0] = strtok(moji, ",\n");
	while(ref[n] && n < 128)
	{
			//printf("%s\n", ref[n]);
			ref[++n] = strtok(NULL,",\n");
	}
	//aaa.bbb
	//ccc.ddd
	//eee.fff.ggg
	//hhh.iii.jjj.kkk
	//zz.zz.zz.zz

	char *eachWord[100];
	int m = 0; //reference ref struct pointer
	int cnt = 0;

	for(eachWord[cnt] = strtok(ref[m], "."); m < n; eachWord[++cnt] = strtok(ref[++m], "."))
	{
		for(; eachWord[cnt] != NULL; eachWord[++cnt] = strtok(NULL, "."))
		{
			printf("eachWord[%i] %s\n", cnt, eachWord[cnt]);
		}

		cnt--;//delete null value
		printf("\n");
	}

	return 0;
}


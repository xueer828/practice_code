#ifndef _TEST_
#define _TEST_

#include <cstdio>
using namespace std;


char maping[26]={
	'2','2','2',
	'3','3','3',
	'4','4','4',
	'5','5','5',
	'6','6','6',
	'7',' '/*Q*/,'7','7',
	'8','8','8',
	'9','9','9',' '/*Z*/
};

unsigned bundle[10000000]={0};

void solve()
{
	int num;
	scanf("%d\n",&num);
	char str[7]={0};
	int val=0;
	while(num--)
	{
		int phone=0;
		while((val=getchar())!='\n')
		{
			if(val != '-' && val != 'Q' && val != 'Z')
			{
				if(val <= '9' && val >= '0')
				{
					phone = phone*10 + val - '0';
				}else{
					phone = phone*10 + maping[val-'A'] - '0';
				}
			}
		}
		//printf("%d ###\n",phone);
		++bundle[phone];
	}

	bool fExist=false;
	for(int i=0;i<10000000;++i)
	{
		if(bundle[i]>1)
		{
			if(i<10)
				printf("000-000%d",i);
			else if(i<100)
				printf("000-00%d",i);
			else if(i<1000)
				printf("000-0%d",i);
			else if(i<10000)
				printf("000-%d",i);
			else if(i<100000)
				printf("00%d-%d",i/10000,i%10000);
			else if(i<1000000)
				printf("0%d-%d",i/10000,i%10000);
			else
				printf("%d-%d",i/10000,i%10000);

			printf(" %d\n",bundle[i]);
			fExist = true;
		}
	}

	if(!fExist)
		printf("No duplicates.");

}
#endif
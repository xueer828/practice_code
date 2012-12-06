#include "stdio.h"

/************************************************************************/
/* hdu 1003 Max Sum
/* http://acm.hdu.edu.cn/showproblem.php?pid=1003
/* 数组序列，计算最大的子序列和（子序列是连续的），例如给定(6,-1,5,4,-7）最大的子序列和为
/* 6+ -1 + 5 + 4 = 14
/* 给定T,T个测试用例，然后是每行不大于1000000的序列，每个数都在-1000到1000之间
/* 输出3 个数， 最大和，子序列的开始和结束位置
/************************************************************************/

const int maxN=1000000;

short data[maxN]={0};
short startp[maxN]={0};
int len,start,end;

int main(int argc, char* argv[])
{
	int T,idx=0;
	scanf("%d",&T);
	while((++idx)<=T)
	{
		int sumi=0,sum=-1001;
		start=end=0;

		scanf("%d",&len);
		for(int i=0;i<len;++i)
			scanf("%d",&data[i]);

		//最大子序列和：先算出以i结尾的序列的最大和，然后得出整个序列的最大和
		//以i结尾的序列和最大和=max{以i-1为尾的最大子段和|if 和>0,否则就是去当前i的值}

		//首先赋初值,以防所有的数均为负数
		sumi = sum = data[0];
		startp[0]=1;
		start = end = 1; //这里start和end都要进行初始化
		for(int i=1;i<len;++i)
		{
			if(sumi >= 0)
			{
				sumi += data[i];
				startp[i]=startp[i-1];
			}
			else
			{
				sumi = data[i];
				startp[i]=i+1;
			}

			if(sum < sumi)
			{
				sum = sumi;
				end = i+1;
				start = startp[i];
			}
		}

		printf("Case %d:\n",idx);
		printf("%d %d %d\n",sum,start,end);
		if(idx < T) printf("\n");
	}
	return 0;
}


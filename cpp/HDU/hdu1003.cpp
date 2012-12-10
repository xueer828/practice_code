#include "stdio.h"

/************************************************************************/
/* hdu 1003 Max Sum
/* http://acm.hdu.edu.cn/showproblem.php?pid=1003
/* �������У��������������кͣ��������������ģ����������(6,-1,5,4,-7�����������к�Ϊ
/* 6+ -1 + 5 + 4 = 14
/* ����T,T������������Ȼ����ÿ�в�����1000000�����У�ÿ��������-1000��1000֮��
/* ���3 ������ ���ͣ������еĿ�ʼ�ͽ���λ��
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

		//��������кͣ��������i��β�����е����ͣ�Ȼ��ó��������е�����
		//��i��β�����к�����=max{��i-1Ϊβ������Ӷκ�|if ��>0,�������ȥ��ǰi��ֵ}

		//���ȸ���ֵ,�Է����е�����Ϊ����
		sumi = sum = data[0];
		startp[0]=1;
		start = end = 1; //����start��end��Ҫ���г�ʼ��
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


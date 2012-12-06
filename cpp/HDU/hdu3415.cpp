#include "stdio.h"
#include "stdlib.h"

/************************************************************************/
/* hdu 3415 Max Sum of Max-K-sub-sequence (Circle sequence ) 注意有循环的子序列
/* 数组序列，计算最大的子序列和（子序列是连续的）,且序列为最长为K的子序列，例如给定(6,-1,5,4,-7）最大的子序列和为
/* 6+ -1 + 5 + 4 = 14
/* 给定T,T个测试用例，然后是每行不大于1000000的序列，每个数都在-1000到1000之间
/* 输出3 个数， 最大和，子序列的开始和结束位置
/************************************************************************/

/************************************************************************/
/* 算法：令S[i]=a[1..i]的和，然后所求的以i结尾的最大子段和sum(i)=S[i]-min{S[j]},
这里i-k=<j<i,然后所有的sum(i)中的最大值就是最大子段和。本题因为涉及到转圈，需要将数组double连接起来
/************************************************************************/
const int maxN=1000010;

int data[maxN*2];
int sum[maxN*2];
typedef struct SQ{
	int idx;
	int val;
	SQ():idx(0),val(0){}
	SQ(int i,int v):idx(i),val(v){}
}SQ;

SQ sq[maxN];



int main(int argc, char* argv[])
{
	int T,K,len;
	scanf("%d",&T);
	while(T--)
	{
		int sumi(-1001),rsum(-1001);
		scanf("%d %d",&len,&K);
		int j=0;
		//求和
		for(;j<len;++j)
		{
			scanf("%d",&data[j]);
			sum[j]=sum[j-1]+data[j];
		}
		for(;j<len*2;++j)
		{
			sum[j]=sum[j-1]+data[j-len];
		}

		//最大子序列和：先算出以i结尾的序列的最大和，然后得出整个序列的最大和
		//求以i结尾的最大子序列和=sum[i]-min{sum[j]} (i-k =<j<i,必须满足 i-k+1 到 i中只有k个数的窗口这个条件)
		//那么和最小就需要用到了单调递增队列了
		//当然这里需要有个小技巧，必须在队列最开始设定一个和为0，以防所有的数都是正数，不需要减值的情况

		//设置end为最后一个元素的位置
		int beg(0),end(0),rbeg(0),rend(0);
		sq[end] = SQ(-1,0); 

		for(int i=0;i<2*len;++i)
		{
			//先求i的最大值，然后再把i放入到队列中
			//printf("最小值：[%d]=%d\n",sq[beg].idx,sq[beg].val);
			
			//此时的头部即为满足K窗口的最小和			
			if(sum[i]-sq[beg].val > rsum)
			{
				rsum = sum[i]-sq[beg].val;
				rbeg = (sq[beg].idx+1)%len + 1; //这里队列里面维护的idx是被剪掉的值，所以开始位置应该+1
				rend = i%len + 1;
			}

			//顺次插入和到相应的队列中,因为要保证start值最小，那么等于不替换
			while(beg <= end && sum[i] <= sq[end].val)
			{
				//弹出尾部
				--end;
			}

			//剔除头部不符合k大小窗口的元素
			while(beg <= end && i-sq[beg].idx >= K)
			{
				++beg;
			}

			//在此新的end处，填上当前的新的i值，用于后面的i+1次计算
			sq[++end] = SQ(i,sum[i]);
		}

		printf("%d %d %d\n",rsum,rbeg,rend);
	}
	//system("pause");
	return 0;
}


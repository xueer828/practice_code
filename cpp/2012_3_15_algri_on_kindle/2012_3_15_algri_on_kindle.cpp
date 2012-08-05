// 2012_3_15_algri_on_kindle.cpp : Defines the entry point for the console application.
//

#include "..\CommonHeader.h"



int _count=0;

set<vector<char> > mytest;

//[klip] 
//递归和分治策略

/************************************************************************/
/*例1，全排列问题，递归求解
/*思路，令集合R(n)={r[1],r[2]...r[n]},求集合的全排列perm(R(n))
/*分解子问题，令R[i]=R(n)-r[i],设r[i]perm(R[i])是把r[i]放在R(i)的全排列前补r[i]
/*那么perm(R(n))就是由r[1]perm(R[1]),r[2]perm(R[2])....r[n]perm(R[n])所构成的集合
/* r[]表示排列,k表示当前处理到第k位，m为总长度
/************************************************************************/
template<class T>
void ex1_Perm(vector<T>& r,int k,int m)
{
	if(k==m-1)
	{
		cout<<++_count<<":";
		//递归结束条件,输出
		for_each(r.begin(),r.end(),out<T>);
		
		if(mytest.find(r)==mytest.end())
			mytest.insert(r);
		else
			cout<<" dup";
		cout<<endl;
	}else{
		//从当前k位置往后依次取出r[i],构成新排列
		for(int i=k;i<m;++i)
		{
			_swap(r[i],r[k]);
			ex1_Perm(r,k+1,m); //取出第i个元素后，求后面k+1个元素的全排列
			_swap(r[i],r[k]); //复位，取下一个i+1元素
		}
	}
}

/************************************************************************/
/* 例2， 整数划分问题，把正整数n划分成一系列正整数之和
/* n=n[1]+n[2]+...n[k],其中n[1]>=n[2]>=n[3]...>=n[k]
/* 求n的不同的划分个数
/* 思路：显然n的划分中包含某个子问题的一个划分，在n的所有不同划分中，将
/* 其中最大的加数n[1]不大于m的划分个数记为q(n,m),则q(n,n)即为题解
/* 当n<1 或者m<1 时, q(n,m)=0
/* 当m=1时，只有一种就是n=1+1+1.....+1, 则q(n,1)=1
/* 当n=1时，也只有一种划分,则q(1,m)=1
/* 当n<m时，因为m不可能大于n，所以q(n,m)=q(n,n)
/* 当n=m时，q(n,n)为n的所有划分数之和，由n[1]<=n-1的划分和 与 n[1]=n的划分组成
/*			 那么q(n,n)=q(n,n-1)+1; n[1]=n只有一种
/*           
/* 同理，当n>m>1时，那么结果等于n[1]<=m-1 和 n[1] =m 的划分之和
		（这里，最大的数n[1]<=m-1,则这一部分的划分为q(n,m-1),
		 另外一部分最大的数为m，则剩余的和为n-m,那么划分数就变成了求和为n-m且最大的数只能为m的划分数，）
			则q(n,n)=q(n,m-1)+q(n-m,m)
/************************************************************************/
//n为和，m为加数中最大的数n[1]
int ex2_devid_1(int n, int m)
{
	if(n<1 || m<1) return 0;
	else if(n==1 || m==1) return 1;
	else if(n<m) return ex2_devid_1(n,n);
	else if(n==m) return ex2_devid_1(n,m-1)+1;
	else return ex2_devid_1(n,m-1)+ex2_devid_1(n-m,m);
}

//利用数组保存已经计算过的数据，优化
int stored[100][100]={0};
int ex2_devid_2(int n, int m)
{
	if(stored[n][m]!=-1)
	{
		//cout<<n<<":"<<m<<endl;
		return stored[n][m];
	}
	if(n<1 || m<1) {
		stored[n][m]=0;
		return 0;
	}
	else if(n==1 || m==1) 
	{
		stored[n][m]=1;
		return 1;
	}
	else if(n<m) {
		stored[n][m]=ex2_devid_2(n,n);
		return stored[n][m];
	}
	else if(n==m) {
		stored[n][m]=ex2_devid_2(n,m-1)+1;
		return stored[n][m];
	}
	else {
		stored[n][m]=ex2_devid_2(n,m-1)+ex2_devid_2(n-m,m);
		return stored[n][m];
	}
}

/************************************************************************/
/* 例2.2,求正整数K的连续整数之和
/* 思路，令连续序列为m到n，可以从m=1开始往后连续直到和为所求的数K，
/*		继续往后加，如果这时候连续和大于所求的数K，则m++往后移动，探测是否和满足情况，否则继续往后移动
/* 结束条件，(如果考虑 15 = 15 也是一种求解的话，则n需要探测到K，否则只需要探测到K/2的情况，即可，因为
/* 至少两个连续的数的和，那么这个两个数必然只会一个数大于K的一半，一个数小于K的一半)
/************************************************************************/
void ex2_2_Sum_Of_Continueous_Num(int sum)
{
	assert(sum>0);
	int m=1,n=1;
	while(m<=n && n<=sum)
	{
		int tmp_sum=(n-m+1)*(n+m)/2;
		if(tmp_sum == sum){
			cout<<sum<<"="<<m<<"->"<<n<<endl;
			++n;
		}
		else if(tmp_sum < sum)
			++n; //如果和小了，则n往后移
		else
			++m; //如果和大了，则m往后移
	}
}

/************************************************************************/
/* 例3，线性时间选择问题，给定n个元素，a[0...n]，在线性时间内找出第k小的元素
/* 思路：任选一个元素作为枢轴，对数组做划分，小于在前，大于在后，然后判断第k小元素
/* 应该在前面还是在后面，然后在对相应的数组部分做划分，递归求解
/* 注意：k以0为最开始
/************************************************************************/
//递归版本，需要记牢
template<class T>
T& ex3_nth_element_1(T t[], int beg, int end, int k)
{
	assert(t&&(beg<=end&&k>=beg&&k<=end));
	int base=(beg+end)/2;
	if(base!=beg)
		_swap(t[beg],t[base]); //枢轴取最中间的数
	
	int i=beg,j=end;
	T tmp=t[beg];

	while(i<j){
		while(i<j && t[j]>tmp) --j; //先从后往前找一个不大于枢轴的数,交换枢轴
		if(i<j) t[i++]=t[j];
		while(i<j && t[i]<tmp) ++i; //从前往后找一个大于枢轴的数，交换
		if(i<j) t[j--]=t[i];
	}
	
	t[i]=tmp; //最后填上枢轴

	for_each(t,t+9,out<int>);
	cout<<"\n"<<tmp<<",i="<<i<<endl;
	
	if(i==k) return t[k];
	else if(i<k){
		return ex3_nth_element_1(t,i+1,end,k);
	}else{
		return ex3_nth_element_1(t,beg,i-1,k);
	}
}

//ex3 非递归版本，需要记牢
template<class T>
T& ex3_nth_element_2(T t[],int beg, int end, int k)
{
	assert(t&&beg<=end&&k>=beg&&k<=end);
	for(;beg<=end;)
	{	
		int i=beg, j=end;
		T tmp=t[i];
		while(i<j){
			while(i<j && t[j] > tmp) --j;
			if(i<j) t[i++]=t[j];
			while(i<j && t[i] < tmp) ++i;
			if(i<j) t[j--]=t[i];
		}
		t[i]=tmp;
		if(i==k) return t[i];
		else if(i<k) beg = i+1;
		else end = i-1;
	}
}


int main(int argc, char* argv[])
{
	/* 
	//ex1
	char tmp[]={'a','b','c','d'};

	vector<char> v;
	for (int i=0;i<sizeof(tmp);++i)
		v.push_back(tmp[i]);
	ex1_Perm(v,0,sizeof(tmp));
	*/

	/*
	//ex2
	for(int i=0;i<100;i++)
		for(int j=0;j<100;j++)
			stored[i][j]=-1;
	cout<<cal_time()<<endl;
	cout<<"4的划分数="<<ex2_devid_1(80,80)<<" used time:";
	cout<<cal_time()<<endl;
	cout<<"4的划分数="<<ex2_devid_2(80,80)<<" used time:";
	cout<<cal_time()<<endl;
	*/

	/*
	//ex2.2
	ex2_2_Sum_Of_Continueous_Num(15);
	*/

	/*
	//ex3,
	int v[]={9,8,7,6,5,4,3,2,1};
	cout<<ex3_nth_element_1(v,0,sizeof(v)/sizeof(int)-1,7)<<endl;	
	cout<<ex3_nth_element_2(v,0,sizeof(v)/sizeof(int)-1,7)<<endl;
	//中位数
	cout<<ex3_nth_element_1(v,0,sizeof(v)/sizeof(int)-1,sizeof(v)/sizeof(int)/2)<<endl;
	cout<<ex3_nth_element_2(v,0,sizeof(v)/sizeof(int)-1,sizeof(v)/sizeof(int)/2)<<endl;
	*/
	
	char ss[10]={0};
	cin.getline(ss,3);
	string s;
	cin>>s;
	cout<<s;

	return 0;
}


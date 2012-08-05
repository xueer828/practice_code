// 2012_3_15_algri_on_kindle.cpp : Defines the entry point for the console application.
//

#include "..\CommonHeader.h"



int _count=0;

set<vector<char> > mytest;

//[klip] 
//�ݹ�ͷ��β���

/************************************************************************/
/*��1��ȫ�������⣬�ݹ����
/*˼·�����R(n)={r[1],r[2]...r[n]},�󼯺ϵ�ȫ����perm(R(n))
/*�ֽ������⣬��R[i]=R(n)-r[i],��r[i]perm(R[i])�ǰ�r[i]����R(i)��ȫ����ǰ��r[i]
/*��ôperm(R(n))������r[1]perm(R[1]),r[2]perm(R[2])....r[n]perm(R[n])�����ɵļ���
/* r[]��ʾ����,k��ʾ��ǰ������kλ��mΪ�ܳ���
/************************************************************************/
template<class T>
void ex1_Perm(vector<T>& r,int k,int m)
{
	if(k==m-1)
	{
		cout<<++_count<<":";
		//�ݹ��������,���
		for_each(r.begin(),r.end(),out<T>);
		
		if(mytest.find(r)==mytest.end())
			mytest.insert(r);
		else
			cout<<" dup";
		cout<<endl;
	}else{
		//�ӵ�ǰkλ����������ȡ��r[i],����������
		for(int i=k;i<m;++i)
		{
			_swap(r[i],r[k]);
			ex1_Perm(r,k+1,m); //ȡ����i��Ԫ�غ������k+1��Ԫ�ص�ȫ����
			_swap(r[i],r[k]); //��λ��ȡ��һ��i+1Ԫ��
		}
	}
}

/************************************************************************/
/* ��2�� �����������⣬��������n���ֳ�һϵ��������֮��
/* n=n[1]+n[2]+...n[k],����n[1]>=n[2]>=n[3]...>=n[k]
/* ��n�Ĳ�ͬ�Ļ��ָ���
/* ˼·����Ȼn�Ļ����а���ĳ���������һ�����֣���n�����в�ͬ�����У���
/* �������ļ���n[1]������m�Ļ��ָ�����Ϊq(n,m),��q(n,n)��Ϊ���
/* ��n<1 ����m<1 ʱ, q(n,m)=0
/* ��m=1ʱ��ֻ��һ�־���n=1+1+1.....+1, ��q(n,1)=1
/* ��n=1ʱ��Ҳֻ��һ�ֻ���,��q(1,m)=1
/* ��n<mʱ����Ϊm�����ܴ���n������q(n,m)=q(n,n)
/* ��n=mʱ��q(n,n)Ϊn�����л�����֮�ͣ���n[1]<=n-1�Ļ��ֺ� �� n[1]=n�Ļ������
/*			 ��ôq(n,n)=q(n,n-1)+1; n[1]=nֻ��һ��
/*           
/* ͬ����n>m>1ʱ����ô�������n[1]<=m-1 �� n[1] =m �Ļ���֮��
		�����������n[1]<=m-1,����һ���ֵĻ���Ϊq(n,m-1),
		 ����һ����������Ϊm����ʣ��ĺ�Ϊn-m,��ô�������ͱ�������Ϊn-m��������ֻ��Ϊm�Ļ���������
			��q(n,n)=q(n,m-1)+q(n-m,m)
/************************************************************************/
//nΪ�ͣ�mΪ������������n[1]
int ex2_devid_1(int n, int m)
{
	if(n<1 || m<1) return 0;
	else if(n==1 || m==1) return 1;
	else if(n<m) return ex2_devid_1(n,n);
	else if(n==m) return ex2_devid_1(n,m-1)+1;
	else return ex2_devid_1(n,m-1)+ex2_devid_1(n-m,m);
}

//�������鱣���Ѿ�����������ݣ��Ż�
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
/* ��2.2,��������K����������֮��
/* ˼·������������Ϊm��n�����Դ�m=1��ʼ��������ֱ����Ϊ�������K��
/*		��������ӣ������ʱ�������ʹ����������K����m++�����ƶ���̽���Ƿ�����������������������ƶ�
/* ����������(������� 15 = 15 Ҳ��һ�����Ļ�����n��Ҫ̽�⵽K������ֻ��Ҫ̽�⵽K/2����������ɣ���Ϊ
/* �����������������ĺͣ���ô�����������Ȼֻ��һ��������K��һ�룬һ����С��K��һ��)
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
			++n; //�����С�ˣ���n������
		else
			++m; //����ʹ��ˣ���m������
	}
}

/************************************************************************/
/* ��3������ʱ��ѡ�����⣬����n��Ԫ�أ�a[0...n]��������ʱ�����ҳ���kС��Ԫ��
/* ˼·����ѡһ��Ԫ����Ϊ���ᣬ�����������֣�С����ǰ�������ں�Ȼ���жϵ�kСԪ��
/* Ӧ����ǰ�滹���ں��棬Ȼ���ڶ���Ӧ�����鲿�������֣��ݹ����
/* ע�⣺k��0Ϊ�ʼ
/************************************************************************/
//�ݹ�汾����Ҫ����
template<class T>
T& ex3_nth_element_1(T t[], int beg, int end, int k)
{
	assert(t&&(beg<=end&&k>=beg&&k<=end));
	int base=(beg+end)/2;
	if(base!=beg)
		_swap(t[beg],t[base]); //����ȡ���м����
	
	int i=beg,j=end;
	T tmp=t[beg];

	while(i<j){
		while(i<j && t[j]>tmp) --j; //�ȴӺ���ǰ��һ���������������,��������
		if(i<j) t[i++]=t[j];
		while(i<j && t[i]<tmp) ++i; //��ǰ������һ�������������������
		if(i<j) t[j--]=t[i];
	}
	
	t[i]=tmp; //�����������

	for_each(t,t+9,out<int>);
	cout<<"\n"<<tmp<<",i="<<i<<endl;
	
	if(i==k) return t[k];
	else if(i<k){
		return ex3_nth_element_1(t,i+1,end,k);
	}else{
		return ex3_nth_element_1(t,beg,i-1,k);
	}
}

//ex3 �ǵݹ�汾����Ҫ����
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
	cout<<"4�Ļ�����="<<ex2_devid_1(80,80)<<" used time:";
	cout<<cal_time()<<endl;
	cout<<"4�Ļ�����="<<ex2_devid_2(80,80)<<" used time:";
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
	//��λ��
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


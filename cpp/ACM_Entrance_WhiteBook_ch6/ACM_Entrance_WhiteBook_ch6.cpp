// ACM_Entrance_WhiteBook_ch6.cpp : Defines the entry point for the console application.
//
/************************************************************************/
/* ch6 ���ݽṹ����
/************************************************************************/
#include <stack>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

//eg.6.1.2 ���죬 ��A���ʱ����1��nΪ��ţ����ܷ񾭹�һ����תվC����B���򣬰��ո����ı��
//��ʵ����˳��1~n�ܷ�ͨ��һ��ջ����ɸ�����˳�����

void eg_6_1_2_stack_squence()
{
	int n, tmp, idx;
	vector<int> v;

	while (cin>>n)
	{
		stack<int> st;
		v.clear();
		int count=0;	
		idx = 0;
		while(idx++<n)
		{
			cin>>tmp;
			v.push_back(tmp);
		}

		idx = 1;
		int i;
		for(i=0;i<n;)
		{
			if(idx <= n && (st.empty() || st.top()!=v[i]))
				st.push(idx++);
			else if(st.top()==v[i])
			{
				st.pop();
				i++;
			}
			else
			{
				cout<<"No\n";
				break;
			}
		}

		if(i==n)
			cout<<"Yes\n";
		
	}
}



int main(int argc, char* argv[])
{
	eg_6_1_2_stack_squence();
	return 0;
}


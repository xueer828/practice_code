// ACM_Entrance_WhiteBook_ch6.cpp : Defines the entry point for the console application.
//
/************************************************************************/
/* ch6 数据结构基础
/************************************************************************/
#include <stack>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

//eg.6.1.2 铁轨， 从A入的时候按照1到n为编号，问能否经过一个中转站C，到B方向，按照给定的编号
//其实就是顺序1~n能否通过一个栈，变成给定的顺序输出

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


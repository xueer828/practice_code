#ifndef _TEST_
#define _TEST_

// longest_valid_parentheses
// Copyright (c) 2013/01/07 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
*/

/*
˼·: ����ջ,������,����ѹջ,������,����ջ������ƥ��,������ջ��,��ƥ������������
*/

/*
Run Status: Accepted!
Program Runtime: 44 milli secs
Progress: 229/229 test cases passed.
 */

#include <cstdio>
#include <iostream>
#include <fstream>
#include <cassert>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <cstdlib>
using namespace std;

struct Node{
	char ch;
	int start;
	Node(char c,int s=0):ch(c),start(s){};
};

class Solution {
public:
	int longestValidParentheses(string s) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		int sz=s.length(); 
		if(sz <=0 ) return 0;
		stack<Node> st;
		st.push(Node('#',-1)); //ѹ��һ�������ڵĽڵ��ֹ�����,ͬʱ���ڼ���

		int max_cnt(0),cnt(0);
		for(int i=0;i<sz;++i)
		{
			if(s[i]=='(')
			{
				st.push(Node(s[i],i));
			}
			else{ //�����')'
				Node t=st.top();
				if(t.ch == '(') //ջ��ƥ��
				{
					st.pop();
					
					//����ջ�����,һ�㶼����ʱδ����������,��ô�Ӹղ�������λ�õ�δ������λ���м����е�����,��Ϊ�Ѿ�ƥ����ȥ��������Ŀ
					max_cnt = max(max_cnt,i-st.top().start); //����������Եõ�����λ��ʱ,�����ȥ��������
				}else{ //ջ���� ')' ���, ����ѹջ
					st.push(Node(s[i],i));
				}
			}
		}
		return max_cnt;
	}
};

void solve()
{
	Solution s;
	cout<<s.longestValidParentheses(")()())");
}

#endif
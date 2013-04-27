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
思路: 利用栈,左括号,进行压栈,右括号,就与栈顶进行匹配,并弹出栈顶,不匹配则丢弃此括号
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
		st.push(Node('#',-1)); //压入一个不存在的节点防止下溢出,同时便于计算

		int max_cnt(0),cnt(0);
		for(int i=0;i<sz;++i)
		{
			if(s[i]=='(')
			{
				st.push(Node(s[i],i));
			}
			else{ //如果是')'
				Node t=st.top();
				if(t.ch == '(') //栈顶匹配
				{
					st.pop();
					
					//留在栈里面的,一般都是暂时未消掉的括号,那么从刚才消掉的位置到未消掉的位置中间所有的括号,均为已经匹配消去的括号数目
					max_cnt = max(max_cnt,i-st.top().start); //所以这里可以得到到此位置时,最长的消去的括号数
				}else{ //栈顶是 ')' 或空, 继续压栈
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
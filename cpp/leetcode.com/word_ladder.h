#ifndef _TEST_
#define _TEST_

// word_ladder
// Copyright (c) 2013/05/08 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
Given two words (start and end), and a dictionary, find the length of shortest transformation sequence from start to end, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the dictionary
For example,

Given:
start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]

As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Note:

Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
*/

/*方法1:
类似图的思想,一个单词可以看做是一个节点,求某一个节点(起点)到另外一个节点(终点)的最短路径

小数据过了,大数据内存超限,真是奇了~~ 说明方法不够好,不过回顾了一下Dijkstra算法,也算不虚
Run Status: Memory Limit Exceeded
*/

/*
方法2: dfs解空间搜索树
小数据轻松过,大数据超时,尝试剪枝试试

Run Status: Time Limit Exceeded
*/

/*
方法3: 因为是求解空间树的最小高度,所以应该用BFS搜索更好,而且不用递归,直接用队列

还应该直接替换string,而不是进行比较,这样可以省很多的时间

Run Status: Accepted!
Program Runtime: 1996 milli secs
Progress: 37/37 test cases passed.
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
#include <unordered_set>
#include <unordered_map>
#include <climits>
using namespace std;

class Solution1 {
	const static int MAX_INT=0x7fffffff;
	int get_edge(const string& s1, const string& s2)
	{
		if(s1 == s2)
			return MAX_INT;

		int i=s1.length();
		int cnt=0;
		while(i>=0)
		{
			if(s1[i]!=s2[i])
				++cnt;
			--i;
		}

		if(cnt <= 1)
			return 1;
		else
			return MAX_INT;
	}

	int dijkstra(vector<vector<int> >& v,vector<int>& pre, int nstart, int nend)
	{
		int sz = v.size();
		vector<bool> b(sz,false); //保存节点是否已经计算完毕
		vector<int> dis(sz,MAX_INT); //保存从start节点到i节点的距离

		//加入第一个start节点
		b[nstart] = true;

		for(int i=0;i<sz;++i)
		{
			if(v[nstart][i]!=MAX_INT) //初始化距离
			{
				dis[i]=v[nstart][i];
				pre[i]=nstart;
			}
		}

		for(int i=0;i<sz;++i)
		{
			if(i==nstart) //跳过开始节点
				continue;

			int min_dis=0x7fffffff,min_node=-1;

			//得到当前最小的距离的节点
			for(int j=0;j<sz;++j)
			{
				if(!b[j] && min_dis > dis[j])
				{
					min_dis = dis[j];
					min_node = j;
				}
			}

			//如果已经得出start 到 end的结果,则返回
			if(b[nend])
				return dis[nend]+1;
			else if(min_node == -1)
				return 0; //不具备

			//将min_node加入已处理的最小集合中
			b[min_node] = true;

			for(int k=0;k<sz;++k)
			{
				if(!b[k] && v[min_node][k]!=MAX_INT) //最小节点到未处理集合中的节点k的是联通的
				{
					if(dis[k] > v[min_node][k] + dis[min_node]) //如果通过min_node能够得到更小的距离,则更新dis数组
					{
						dis[k] = v[min_node][k] + dis[min_node];
						pre[k] = min_node;
					}
				}
			}
		}

		if(b[nend])
			return dis[nend]+1;
		else
			return 0;
	}
public:
	int ladderLength(string start, string end, unordered_set<string> &dict) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if(start == end)
			return 2;

		int sz = dict.size();
		if(sz <= 0)
			return false;

		unordered_set<string> mdict(dict);
		mdict.insert(start);
		mdict.insert(end);

		//sz为start和end加入集合之后
		sz = mdict.size();

		vector<vector<int> > matrix(sz,vector<int>(sz,-1)); //初始化二维数组

		int nCount=0;

		//添加start 和end 进入
		int nstart,nend;
		//预处理
		unordered_set<string>::iterator i(mdict.begin()),j(i);
		int ii,jj;
		for(ii=0,i=mdict.begin();i!=mdict.end();++i,++ii)
		{
			if(*i==start)
				nstart = ii;
			if(*i==end)
				nend = ii;

			for(jj=0,j=mdict.begin();j!=mdict.end();++j,++jj)
			{
				matrix[ii][jj]=get_edge(*i,*j);
			}
		}

		
		//dijkstra算法
		vector<int> pre(sz,-1);
		return dijkstra(matrix,pre,nstart,nend);
	}
};

//dfs
class Solution2 {
	bool one_char_diff(const string& s1,const string& s2)
	{
		int l=s1.length(),cnt(0);
		while(l--)
		{
			if(s1[l]!=s2[l])
				++cnt;
		}

		if(cnt > 1)
			return false;
		else
			return true;
	}

	bool dfs(const string& s,const string& e,unordered_map<string,bool>& b, 
		unordered_set<string>& dict, int curLen, int& minLen)
	{
		if(curLen +1 >= minLen) //已经超越了,就不再继续了
			return false;

		if(one_char_diff(s,e))
		{
			if(minLen > curLen+2)
				minLen = curLen + 2;
			return true;
		}

		unordered_set<string>::iterator i=dict.begin();
		bool ret=false;
		for(;i!=dict.end();++i)
		{
			if((b.count(*i) == 0 || !b[*i]) && one_char_diff(s,*i)) //可以向前递归
			{
				b[*i]=true;
				ret |= dfs(*i,e,b,dict,curLen+1,minLen);
				b[*i]=false; //restore
			}
		}

		return ret;
	}
public:
	int ladderLength(string start, string end, unordered_set<string> &dict) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		int sz=dict.size();
		if(sz <=0) return 0;

		int mn=0x7fffffff;
		unordered_map<string,bool> b;
		if(dfs(start,end,b,dict,0,mn))
			return mn;
		else
			return 0;

	}
};


//BFS, 对字符串中的每个字符进行替换,O(26*N), 不要去比较所有字符串的长度,这样就变成了O(M*N),就会超时了

class Solution {
public:
	int ladderLength(string start, string end, unordered_set<string> &dict) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		int sz=dict.size();
		if(sz <=0) return 0;

		queue<string> sq;
		unordered_set<string> processed;

		sq.push(start);
		processed.insert(start);
		

		int lv1(1),lv2(0),lv_cnt(0);

		while(!sq.empty())
		{
			string s=sq.front();
			sq.pop();
			--lv1; //当前层次的数目

			for(int i=0;i<s.length();++i)
			{
				for(int j=0;j<26;++j)
				{
					string t(s);
					t[i]='a'+j;
					
					if(t == s) continue; //跳过相等的处理

					if(t==end)
					{
						return lv_cnt + 2;
					}else if(processed.count(t) <= 0 && dict.count(t)) //存在
					{
						processed.insert(t); //保证此种情况没有被处理过
						sq.push(t);
						++lv2; //下一层次(子层)的节点数目
					}
				}
			}
			

			if(lv1==0) //代表当前层完毕
			{
				++lv_cnt; //层次加1了
				lv1=lv2; //进行层次切换
				lv2=0;
			}
		}

		return 0;
	}
};

void solve()
{
	unordered_set<string> us;
	us.insert("ted");
	us.insert("tex");
	us.insert("red");
	us.insert("tax");
	us.insert("tad");
	us.insert("den");
	us.insert("rex");
	us.insert("pee");

	Solution s;
	cout<<s.ladderLength("red","tax",us)<<endl;
}

#endif
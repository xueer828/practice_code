#ifndef _TEST_
#define _TEST_

// simplify_path
// Copyright (c) 2013/05/08 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"

Corner Cases:
Did you consider the case where path = "/../"?
In this case, you should return "/".
Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
In this case, you should ignore redundant slashes and return "/home/foo".
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


class Solution {
public:
	string simplifyPath(string path) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if(path.length()==0) return path;

		//i为读指针,j为写指针
		int i=0,j=0;
		string path2;
		path2.resize(path.length());
		for(;i<path.length();)
		{
			if(path[i]=='/') //一段一段处理
			{
				if(i+2 < path.length() && path[i+1]=='.' && path[i+2]=='.') // meet '/..'
				{
					while(j >= 0 && path2[j]!='/') --j; //到前一个'/'
					if(j <=0) { j=0;}
					i += 3;
				}else if(i+1 < path.length() && path[i+1] == '.') // meet '/.'
				{
					//nothing to do
					i += 2;
				}else if(i+1 < path.length() && path[i+1] == '/') // meet '//'
				{
					//path[j]=path[i];
					++i; //跳过1个/
				}else{
					path2[j]=path[i];
					++j,++i;
				}
			}else{
				path2[j++]=path[i++];
			}
		}

		if(j<=0)
			path2[j]='/';
		path2.resize(j);
		return path2;
	}
};


void solve()
{
	Solution s;
	cout<<s.simplifyPath("/a/./b/../../c/")<<endl;
}

#endif
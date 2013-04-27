#ifndef _TEST_
#define _TEST_

// maximal_rectangle
// Copyright (c) 2013/4/25 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing all ones and return its area.
 */

//��ԭʼ���㷨: ѡȡһ��(x,y)��Ϊ���Ͻ�,ѡȡ����һ��(m,n)��Ϊ���½�,̽�⹹�ɵľ����Ƿ�ȫ��1����; �㷨���Ӷ�O(m^3*n^3)

/*
��õķ���: �����ѭ��������,�ڱ������ڲ�,�̶���,Ȼ������ת��Ϊhistogramֱ��ͼ���������������
 */

/*
һ����AC, ֱ��ͼ������,���õ���ջ
Run Status: Accepted!
Program Runtime: 68 milli secs
Progress: 57/57 test cases passed.
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
	struct gram 
	{
		int h,s;
		gram():h(0),s(0){};
		gram(int nh,int ns):h(nh),s(ns){};
	};
	int max_histogram(vector<int>& arr)
	{
		int mx_area=0;
		stack<gram> sg;
		sg.push(gram(0,0));

		int i=0;
		for(;i<arr.size();++i)
		{
			//����ѹ��
			if(arr[i] > sg.top().h)
			{
				sg.push(gram(arr[i],i));
				continue;
			}

			//����,����
			if(arr[i]==sg.top().h)
				continue;

			//С��,����,�������,֪����С��Ϊֹ
			int start_point = i;
			while(arr[i] < sg.top().h)
			{
				gram tmp=sg.top();
				sg.pop();

				int area=(i-tmp.s)*tmp.h;
				if(area > mx_area)
					mx_area = area;

				start_point = tmp.s; //����start_point
			}

			//��ʱ����ѹ���µĽڵ���
			sg.push(gram(arr[i],start_point));
		}

		//��󵯳�����ջ������,�����м���
		while(sg.size()>0)
		{
			gram tmp=sg.top();
			sg.pop();

			int area=(i-tmp.s)*tmp.h; //��ʱiΪֱ��ͼ��ĩβ���
			if(area > mx_area)
				mx_area = area;
		}

		return mx_area;
	}
public:
	int maximalRectangle(vector<vector<char> > &matrix) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function

		int row_sz=matrix.size();
		if(row_sz <=0) return 0;

		int col_sz=matrix[0].size();
		if(col_sz <=0) return 0;

		vector<vector<int> > arr;
		arr.resize(row_sz);
		for(int i=0;i<row_sz;++i)
			arr[i].resize(col_sz,0); //ȫ����ʼ��Ϊ0

		//����һ��
		for(int i=0;i<col_sz;++i)
			arr[0][i]=matrix[0][i]-'0';

		for(int i=1;i<row_sz;++i)
			for(int j=0;j<col_sz;++j)
				//�������Ϊ0,��ֵΪ0,������Ϊ1,����һ��Ϊ0,�򱾸�Ϊ1,������Ϊ0,��һ������0,�򱾸�Ϊ��һ��ֵ��1
				arr[i][j]=(matrix[i][j]=='1')?arr[i-1][j]+1:0; 
		
		//�������

		int mx_area=0;
		
		for(int i=0;i<row_sz;++i)
		{
			int area=max_histogram(arr[i]);
			if(area > mx_area)
				mx_area = area;
		}

		return mx_area;
	}
};

void solve()
{
}

#endif 
#ifndef _TEST_
#define _TEST_

// integer_to_roman
// Copyright (c) 2013/01/05 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
Given an integer, convert it to a roman numeral.

Input is guaranteed to be within the range from 1 to 3999.
*/

//˼·: 
/*
�������� I II III IV V VI VII VIII IX X
        1 2   3  4  5 6   7  8    9  10
		XL   L    XC  XCIX  C   CI   CXCIX  CC    CCC
		40   50   90   99   100  101  199   200   300
		CD   D    DCLXVI   M      MM     MMMMCMXCIX
		400  500  666      1000   2000   4999

�������ֹ���7������I(1)��V(5)��X(10)��L(50)��C(100)��D(500)��M(1000)


(1)�������֢�X ��C �е��κ�һ�����������ù�����Ŀ�����߷��ڴ������ұ����ù�����Ŀ�������ܳ������������ڴ��������ֻ����һ����
����(2)���ܰѻ�������V ��L ��D �е��κ�һ����ΪС�����ڴ�������߲�������ķ���������Ŀ�����ڴ������ұ߲�����ӵķ�ʽ������Ŀ��ֻ��ʹ��һ����
  ����(3)V ��X ��ߵ�С����ֻ���â�
	����(4)L ��C ��ߵ�С����ֻ����X��
	  ����(5)D ��M ��ߵ�С����ֻ����C��

�������Ͽ�֪
��λ 

ʮλ X XL  L  XC C    CD  D   CM    M 
    10 40 50 90 100  400 500  900 1000
*/

/*
���,ˮ��
Run Status: Accepted!
Program Runtime: 132 milli secs
Progress: 3999/3999 test cases passed.
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

//��ʵ���԰�����������������ֵĽ�������


string dig_c[]={
	"I","IV","V","IX","X",
	"XL","L","XC","C","CD",
	"D","CM","M"
};
int dig_v[]={
	1,4,5,9,10,
	40,50,90,100,400,
	500,900,1000};
int sz=sizeof(dig_c)/sizeof(dig_c[0]);

class Solution {
	string repeat_ch(string c, int n)
	{
		string tmp("");
		while(n--) tmp += c;
		return tmp;
	}
public:
	string intToRoman(int num) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function    

		string rst("");

		int idx=sz;
		while (idx--)
		{
			if(num/dig_v[idx] > 0)
			{
				rst += repeat_ch(dig_c[idx],num/dig_v[idx]);
				num %=dig_v[idx];
			}
		}
		return rst;
	}
};


void solve()
{
	Solution s;
	s.intToRoman(1);
}

#endif
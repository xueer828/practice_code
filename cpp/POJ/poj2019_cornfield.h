#ifndef _TEST_
#define _TEST_

// poj2019_cornfield
// Copyright (c) 2013/5/14 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
http://poj.org/problem?id=2019
 */

/*
涉及到这种一次处理,多次query的问题,都可以往RMQ问题上来想,毕竟O(1)的查询效率不是盖的
这一题是二维的RMQ问题,ST算法可以求解, F[k][i][j] 来表示(i,j)为左上角,2^k为宽度的正方形的最大值和最小值

因为窗口是固定的,所以也可以简化用带窗口的单调队列来解决这个问题
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


void solve()
{
}

#endif 
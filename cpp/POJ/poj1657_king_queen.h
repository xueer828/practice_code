#ifndef _TEST_
#define _TEST_

// poj1657_king_queen
// Copyright (c) 2013/7/7 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
http://poj.org/problem?id=1657
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

/*
�����õ���BFS,��������,������ʶ����BFS����DFS������
 */

#define WH 8

struct pos{
	int x,y;
	pos(string s):x(s[0]-'a'),y(s[1]-'1'){};
	pos(int ni,int nj):x(ni),y(nj){};
	friend bool operator==(const pos& p1, const pos& p2)
	{
		return p1.x==p2.x && p1.y==p2.y;
	}
};

//BFS����,һ�ν����п��Ե����λ�÷��������,�������Ŀ��ڵ�,�򷵻�,���򲻿ɴ�
int get_min_king(const pos& cur, const pos& target)
{
	if(cur == target)
		return 0;

	int chess[WH][WH];
	
	for(int i=0;i<WH;++i)
		for(int j=0;j<WH;++j)
			chess[i][j]=-1;

	queue<pos> q;
	int cnt_cur=1,cnt_next=0,steps=0;
	//ѹ�뵱ǰ�ڵ�
	q.push(cur);
	chess[cur.x][cur.y]=steps;
	while(!q.empty())
	{
		pos p=q.front();
		--cnt_cur;
		q.pop();
		
		for(int i=(p.x==0?0:p.x-1);i<=(p.x+1<WH?p.x+1:WH-1);++i)
			for(int j=(p.y==0?0:p.y-1);j<=(p.y+1<WH?p.y+1:WH-1);++j)
			{
				if(chess[i][j]<0) //���Ե���
				{
					q.push(pos(i,j));
					++cnt_next;

					chess[i][j]=steps+1;
					if(i==target.x && j==target.y)
					{
						return chess[i][j];
					}
				}
			}

		if(cnt_cur == 0)
		{
			cnt_cur = cnt_next;
			cnt_next = 0;
			++steps; //����+1
		}
		
	}

	return -1; //���ɴ�
}

int get_min_queen(const pos& cur, const pos&target)
{
	if(cur == target)
		return 0;
	int chess[WH][WH];

	for(int i=0;i<WH;++i)
		for(int j=0;j<WH;++j)
			chess[i][j]=-1;

	queue<pos> q;
	q.push(cur);
	
	int cnt_cur(1),cnt_next(0),steps(0);
	chess[cur.x][cur.y]=steps;
	while(!q.empty())
	{
		pos tmp=q.front();
		q.pop();
		--cnt_cur;

		//������������к����Լ��Խ���,���ܲ�������
		//��
		for(int i=0;i<WH;++i)
		{
			if(chess[tmp.x][i]<0)
			{
				q.push(pos(tmp.x,i));
				++cnt_next;

				chess[tmp.x][i]=steps+1;

				if(tmp.x==target.x && i==target.y)
				{
					return chess[tmp.x][i];
				}
			}
		}

		//��
		for(int i=0;i<WH;++i)
		{
			if(chess[i][tmp.y]<0)
			{
				q.push(pos(i,tmp.y));
				++cnt_next;

				chess[i][tmp.y]=steps+1;

				if(i==target.x&&tmp.y==target.y)
					return chess[target.x][target.y];
			}
		}

		//��б��
		int start_x(tmp.x),start_y(tmp.y);

		while(start_x >= 0 && start_y >= 0)
		{
			if(chess[start_x][start_y]<0)
			{
				q.push(pos(start_x,start_y));
				++cnt_next;

				chess[start_x][start_y] = steps+1;
				if(start_x==target.x && start_y==target.y)
					return chess[target.x][target.y];
			}
			--start_x,--start_y;
		}

		start_x=tmp.x,start_y=tmp.y;

		while(start_x >=0 && start_y < WH)
		{
			if(chess[start_x][start_y]<0)
			{
				q.push(pos(start_x,start_y));
				++cnt_next;

				chess[start_x][start_y] = steps+1;
				if(start_x==target.x && start_y==target.y)
					return chess[target.x][target.y];
			}
			--start_x,++start_y;
		}

		start_x=tmp.x,start_y=tmp.y;

		while(start_x <WH && start_y < WH)
		{
			if(chess[start_x][start_y]<0)
			{
				q.push(pos(start_x,start_y));
				++cnt_next;

				chess[start_x][start_y] = steps+1;
				if(start_x==target.x && start_y==target.y)
					return chess[target.x][target.y];
			}
			++start_x,++start_y;
		}

		start_x=tmp.x,start_y=tmp.y;

		while(start_x <WH && start_y >=0)
		{
			if(chess[start_x][start_y]<0)
			{
				q.push(pos(start_x,start_y));
				++cnt_next;

				chess[start_x][start_y] = steps+1;
				if(start_x==target.x && start_y==target.y)
					return chess[target.x][target.y];
			}
			++start_x,--start_y;
		}


		if(cnt_cur == 0)
		{
			cnt_cur = cnt_next;
			cnt_next = 0;
			++steps;
		}
	}

	return -1;
	
}

int get_min_car(const pos& cur, const pos&target)
{
	if(cur == target)
		return 0;
	int chess[WH][WH];

	for(int i=0;i<WH;++i)
		for(int j=0;j<WH;++j)
			chess[i][j]=-1;

	queue<pos> q;
	q.push(cur);
	
	int cnt_cur(1),cnt_next(0),steps(0);
	chess[cur.x][cur.y]=steps;
	while(!q.empty())
	{
		pos tmp=q.front();
		q.pop();
		--cnt_cur;

		//�����������к���
		//��
		for(int i=0;i<WH;++i)
		{
			if(chess[tmp.x][i]<0)
			{
				q.push(pos(tmp.x,i));
				++cnt_next;

				chess[tmp.x][i]=steps+1;

				if(tmp.x==target.x && i==target.y)
				{
					return chess[tmp.x][i];
				}
			}
		}

		//��
		for(int i=0;i<WH;++i)
		{
			if(chess[i][tmp.y]<0)
			{
				q.push(pos(i,tmp.y));
				++cnt_next;

				chess[i][tmp.y]=steps+1;

				if(i==target.x&&tmp.y==target.y)
					return chess[target.x][target.y];
			}
		}

		if(cnt_cur == 0)
		{
			cnt_cur = cnt_next;
			cnt_next = 0;
			++steps;
		}
	}

	return -1;
}

int get_min_elephone(const pos& cur, const pos& target)
{
	if(cur == target)
		return 0;
	int chess[WH][WH];

	for(int i=0;i<WH;++i)
		for(int j=0;j<WH;++j)
			chess[i][j]=-1;

	queue<pos> q;
	q.push(cur);
	
	int cnt_cur(1),cnt_next(0),steps(0);
	chess[cur.x][cur.y]=steps;
	while(!q.empty())
	{
		pos tmp=q.front();
		q.pop();
		--cnt_cur;

		//���е�б��
		int start_x(tmp.x),start_y(tmp.y);

		while(start_x >= 0 && start_y >= 0)
		{
			if(chess[start_x][start_y]<0)
			{
				q.push(pos(start_x,start_y));
				++cnt_next;

				chess[start_x][start_y] = steps+1;
				if(start_x==target.x && start_y==target.y)
					return chess[target.x][target.y];
			}
			--start_x,--start_y;
		}

		start_x=tmp.x,start_y=tmp.y;

		while(start_x >=0 && start_y < WH)
		{
			if(chess[start_x][start_y]<0)
			{
				q.push(pos(start_x,start_y));
				++cnt_next;

				chess[start_x][start_y] = steps+1;
				if(start_x==target.x && start_y==target.y)
					return chess[target.x][target.y];
			}
			--start_x,++start_y;
		}

		start_x=tmp.x,start_y=tmp.y;

		while(start_x <WH && start_y < WH)
		{
			if(chess[start_x][start_y]<0)
			{
				q.push(pos(start_x,start_y));
				++cnt_next;

				chess[start_x][start_y] = steps+1;
				if(start_x==target.x && start_y==target.y)
					return chess[target.x][target.y];
			}
			++start_x,++start_y;
		}

		start_x=tmp.x,start_y=tmp.y;

		while(start_x <WH && start_y >=0)
		{
			if(chess[start_x][start_y]<0)
			{
				q.push(pos(start_x,start_y));
				++cnt_next;

				chess[start_x][start_y] = steps+1;
				if(start_x==target.x && start_y==target.y)
					return chess[target.x][target.y];
			}
			++start_x,--start_y;
		}


		if(cnt_cur == 0)
		{
			cnt_cur = cnt_next;
			cnt_next = 0;
			++steps;
		}
	}

	return -1;
}

void solve()
{
	int n;
	cin>>n;
	while(n--)
	{
		string s1,s2;
		cin>>s1>>s2;
		pos p1(s1),p2(s2);
		int king=get_min_king(p1,p2);
		int queen=get_min_queen(p1,p2);
		int car=get_min_car(p1,p2);
		int elephone=get_min_elephone(p1,p2);

		if(king >= 0)
			cout<<king<<" ";
		else
			cout<<"Inf"<<" ";
		
		if(queen >= 0)
			cout<<queen<<" ";
		else
			cout<<"Inf"<<" ";

		if(car >= 0)
			cout<<car<<" ";
		else
			cout<<"Inf"<<" ";

		if(elephone >= 0)
			cout<<elephone<<endl;
		else
			cout<<"Inf"<<endl;
	
	}
}

#endif 
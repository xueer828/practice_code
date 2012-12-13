#ifndef _TEST_
#define _TEST_

// poj1009
// Copyright (c) 2012/12/13 
// Author: xdutaotao (xdutaotao@gmail.com)
// Edge Detection ±ß¼ì²â

#include <cstdio>
#include <iostream>
#include <fstream>
#include <cassert>
using namespace std;

#define CPos(x,y,w,h) (((x)<0 || (y)<0 || (x)>=(w) || (y)>=(h))? -1 : (y)*(w)+(x))

#define DIFF(v1,v2) ((v1)>=(v2)? (v1)-(v2) : (v2)-(v1))

#define Xpos(p,w) ((p)%(w))
#define Ypos(p,w) ((p)/(w))

const int MAXN=1010;
unsigned char arr_v[MAXN]={0};
unsigned int arr_n[MAXN]={0};

inline int search_idx(unsigned int arr[],int beg, int end, const int& pos)
{
	if(end==0 || beg==end-1)
		return end;

	int mid=(beg+end)>>1;
	if(arr[mid]<pos)
		beg = mid;
	else
		end = mid;

	return search_idx(arr,beg,end,pos);
}

void solve()
{
	unsigned int arr[]={3,7,9,14,16,24,52};

	int k;
	while(cin>>k)
		cout<<search_idx(arr,0,sizeof(arr)/sizeof(int),k)<<endl;
}

//2-matrix to 1-array
inline int M2A(const int& x, const int& y, const int&w, const int&h, const int&count)
{
	if(x <0 || y< 0 || x>= w || y >= h)
		return -1;
	
	int pos=y*w+x;

	//¶þ·ÖËÑË÷
	int idx;

}

inline unsigned char get_val(const int& p, const int& cp, bool forward)
{
	if(p < 0)
		return 0;

	int pos_idx=cp,pos;
	int ans_idx;
	
	if(forward)
	{
		do{
			ans_idx = pos_idx;
		}while(pos_idx >= 0 && pos<arr_n[pos_idx++]);
	}else{
		do{
			ans_idx = pos_idx;
		}while(arr_n[pos_idx]!=0 && pos<arr_n[pos_idx--]);
	}

	return arr_v[ans_idx];
	

}

void solve1()
{
	int width=0,n,height=0;
	while(1)
	{
		cin>>width;
		
		if(!width) //exit
			break;

		memset(arr_v,0,sizeof(arr_v));
		memset(arr_n,0,sizeof(arr_n));

		for(int i=0;i<width;++i)
		{
			scanf("%d %d",&arr_v[i],&n);
			if(n==0)
				break; //grid over
			
			arr_n[i]=(i>0?arr_n[i-1]+n:n-1);
			height = (arr_n[i]+1)/width;
		}

		cout<<width<<" *** "<<height<<endl;
		
		int idx=0,cur_id=0,prev_diff=-1,cumulated=0;
		while(arr_n[cur_id]>0)
		{
			unsigned char cur_val=arr_v[cur_id];
			unsigned char tmp_v,tmp_diff;
			while(idx <= arr_n[cur_id])
			{
				unsigned char maxd= 0;

				//int pos=CPos(x-1,y-1,width,height);
				
				
				

				if(prev_diff == maxd)
				{
					++cumulated; //
				}else{
					cout<<prev_diff<<" "<<cumulated<<endl;
					prev_diff = maxd;
					cumulated = 1;
				}
				++idx; //goto next
			}
			++cur_id; //goto next element
		}
		cout<<"0 0"<<endl;
	}


}

#endif
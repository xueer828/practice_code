#ifndef _TEST_
#define _TEST_

// poj1009
// Copyright (c) 2012/12/13
// Author: xdutaotao (xdutaotao@gmail.com)
// Edge Detection �߼��

#include <cstdio>
#include <iostream>
#include <fstream>
#include <cassert>
#include <cstring>
using namespace std;


const int MAXN=1010;
unsigned char arr_v[MAXN]={0};
unsigned int arr_n[MAXN]={0};


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

inline unsigned char get_todo_val(int todo_pos, int& arr_todo_idx, int arr_pos_idx, bool forwarded)
{
    arr_todo_idx = arr_pos_idx;
    if(forwarded)
    {
        while(todo_pos > arr_n[arr_todo_idx]) ++arr_todo_idx; //��ǰ�ҵ���Ӧ�ĵ�һ��С��todo_pos��idx
    }else{
        while(arr_todo_idx>0 && todo_pos <= arr_n[arr_todo_idx-1]) --arr_todo_idx; //����,�ҵ���һ������todo_pos��idx
    }

    return arr_v[arr_todo_idx];
}

void solve()
{
	int width=0,n,height=0;
	while(1)
	{
		cin>>width;

		if(!width) //exit
			break;
		
		printf("%d\n",width);

		memset(arr_v,0,sizeof(arr_v));
		memset(arr_n,0,sizeof(arr_n));

		int sum=0;
		for(int i=0;1;++i)
		{
			scanf("%d %d",&arr_v[i],&n);
			if(n==0)
				break; //grid over

			arr_n[i]=sum=(i>0?arr_n[i-1]+n:n-1);
		}
		height = (sum+1)/width;

		//cout<<width<<" *** "<<height<<endl;

		int max_len=width*height;


		int old_pos_idx=0,cur_pos_idx=0;
		unsigned char old_value(0);
		int counter(0);
		int last_mark=0;

		for(int pos=0;pos<max_len;++pos)
        {
			if(pos==0 && arr_n[0] - width -1 >= 0)
			{
				old_value = 0;
				counter = arr_n[0] - width;
				pos = arr_n[0] - width -1;
				continue;
			}
            //�ж�ÿһ�� ����
            int x=pos/width,y=pos%width;

            int cur_pos_idx;
            unsigned char cur_val = get_todo_val(pos,cur_pos_idx,old_pos_idx,true); //��õ�ǰ��val��idx
			if(old_pos_idx !=cur_pos_idx)
            {
				last_mark = arr_n[old_pos_idx];
				old_pos_idx = cur_pos_idx; //��¼������һ�μ����µ�cur_todo_idx
			}

			//���⴦��,������ظ������ݴ�width+1��ʼ��length-width-1����,��Щ���ݵĲ�ֵ��Ϊ0
			if(pos>last_mark+width+1 && pos < arr_n[cur_pos_idx]-width -1)
			{
				if(old_value !=0) //��ӡǰ�治Ϊ0�ĸ���
				{
					printf("%d %d\n",old_value,counter);
					old_value=0;
					counter=0;
				}

				counter += (arr_n[cur_pos_idx]-width-2) - (last_mark+width+2) + 1;
				pos=arr_n[cur_pos_idx]-width-2;
				continue;
			}

            int todo_pos=-1,todo_idx;
            unsigned char todo_val(0),todo_diff(0),max_diff(0);

            //11��λ��
            if(x>0 && y>0)
            {
                todo_pos=(x-1)*width+y-1;
                todo_val = get_todo_val(todo_pos,todo_idx,cur_pos_idx,false); //0��λ����ǰ

                todo_diff=(todo_val>cur_val?todo_val-cur_val:cur_val-todo_val);

                if(todo_diff > max_diff)
                    max_diff=todo_diff;
            }

            //0��λ��
            if(x > 0)
            {
                todo_pos=(x-1)*width+y;
                todo_val = get_todo_val(todo_pos,todo_idx,cur_pos_idx,false);

                todo_diff=(todo_val>cur_val?todo_val-cur_val:cur_val-todo_val);

                if(todo_diff > max_diff)
                    max_diff=todo_diff;
            }

            //2��λ��
            if(x>0 && y<width-1)
            {
                todo_pos=(x-1)*width+y+1;
                todo_val = get_todo_val(todo_pos,todo_idx,cur_pos_idx,false); //0��λ����ǰ

                todo_diff=(todo_val>cur_val?todo_val-cur_val:cur_val-todo_val);

                if(todo_diff > max_diff)
                    max_diff=todo_diff;
            }

            //9��λ��
            if(y > 0)
            {
                todo_pos=(x)*width+y-1;
                todo_val = get_todo_val(todo_pos,todo_idx,cur_pos_idx,false);

                todo_diff=(todo_val>cur_val?todo_val-cur_val:cur_val-todo_val);

                if(todo_diff > max_diff)
                    max_diff=todo_diff;
            }

            //3��λ��
            if(y<width-1)
            {
                todo_pos=(x)*width+y+1;
                todo_val = get_todo_val(todo_pos,todo_idx,cur_pos_idx,true);

                todo_diff=(todo_val>cur_val?todo_val-cur_val:cur_val-todo_val);

                if(todo_diff > max_diff)
                    max_diff=todo_diff;
            }

            //7��λ��
            if(x<height-1 && y>0)
            {
                todo_pos=(x+1)*width+y-1;
                todo_val = get_todo_val(todo_pos,todo_idx,cur_pos_idx,true);

                todo_diff=(todo_val>cur_val?todo_val-cur_val:cur_val-todo_val);

                if(todo_diff > max_diff)
                    max_diff=todo_diff;
            }

            //6��λ��
            if(x<height-1)
            {
                todo_pos=(x+1)*width+y;
                todo_val = get_todo_val(todo_pos,todo_idx,cur_pos_idx,true);

                todo_diff=(todo_val>cur_val?todo_val-cur_val:cur_val-todo_val);

                if(todo_diff > max_diff)
                    max_diff=todo_diff;
            }

            //4��λ��
            if(x<height-1 && y<width-1)
            {
                todo_pos=(x+1)*width+y+1;
                todo_val = get_todo_val(todo_pos,todo_idx,cur_pos_idx,true);

                todo_diff=(todo_val>cur_val?todo_val-cur_val:cur_val-todo_val);

                if(todo_diff > max_diff)
                    max_diff=todo_diff;
            }


            //printf("%d,%d %d\n",x,y,max_diff);

			if(pos==0)
				old_value=max_diff;

			if(max_diff != old_value)
			{
				printf("%d %d\n",old_value,counter);
				old_value=max_diff;
				counter=1;
			}else if(pos == max_len-1){
				++counter;
				printf("%d %d\n",old_value,counter);
			}else{ //old_value == max_diff
				++counter;
			}
        }

		printf("0 0\n");

	}


}

#endif

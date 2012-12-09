#ifndef _TEST_
#define _TEST_

// poj1018
// Copyright (c) 2012/12/08 
// Author: xdutaotao (xdutaotao@gmail.com)
// Communication System
// 1<=1<=100 设备数量，1<=mi<=100 制造商数量，制造商的带宽和价格，求整体的最大的B/P （带宽/价格）

//错误方法：DP公式: f(n)=max{(B(n-1)+Bn)/(P(n-1)+Pn)}

//正确思路：因为B和P为相互制约的两个量，需要"暂时固定"某一个量，然后求在这种情况下另一个变量的极值问题
//限定 + 枚举 , 水题

#include <cstdio>
#include <iostream>
#include <fstream>
#include <cassert>
#include <vector>
#include <cstdlib>
using namespace std;

typedef struct DV{
	int b,p;
}DV;

//dv[i][j], i为设备号，j为设备
DV dv[100][100]={0};
int n_dv[100]={0};

int sorted_band[100000]={0};
int band_idx=0;

int compare1(const void* d1,const void* d2)
{
	DV* da=(DV*)d1;
	DV* db=(DV*)d2;
	if (da->p < db->p || (da->p == db->p && da->b < db->b))
		return -1;
	else if(da->p == db->p && da->b == db->b)
		return 0;
	else
		return 1;
}

int compare2(const void* d1, const void* d2)
{
	return (*((int*)d1) - *((int*)d2));
}

void solve()
{
	int ct_cases,ct_dvs;
	cin>>ct_cases;
	while(ct_cases--)
	{
		cin>>ct_dvs;

		int idx=0;
		while(idx < ct_dvs)
		{
			cin>>n_dv[idx];
			int max_band_4_dv=0;
			for(int i=0;i<n_dv[idx];++i)
			{
				cin>>dv[idx][i].b>>dv[idx][i].p;
				sorted_band[band_idx++]=dv[idx][i].b;
				assert(band_idx<100000);
			}
			++idx;
		}

		//对每一设备，按照先价格，后带宽进行排序
		for(int i=0;i<ct_dvs;++i)
			qsort(&(dv[i]),n_dv[i],sizeof(dv[0][0]),compare1);

		qsort(sorted_band,band_idx,sizeof(sorted_band[0]),compare2);

#if 0
		cout<<"-------------------\n";
		for(int q=0;q<band_idx;++q)
			cout<<sorted_band[q]<<" ";
		cout<<endl;

		cout<<"-------------------\n";

#endif

		//band去重
		int band_id=0,tmp_id=0;
		sorted_band[band_id]=sorted_band[tmp_id++];
		while(tmp_id < band_idx)
		{
			if(sorted_band[band_id]!=sorted_band[tmp_id])
				sorted_band[++band_id] = sorted_band[tmp_id];
			++tmp_id;
		}

#if 0
		for(int q=0;q<=band_id;++q)
			cout<<sorted_band[q]<<" ";
		cout<<endl;

		cout<<"-------------------\n";

#endif

		double total=0;
		//开始从最小带宽到最大带宽，进行枚举
		for(int k=0;k<=band_id;++k)
		{
			int total_band,total_price;
			int w = sorted_band[k];
			total_price = total_band = 0;
			for(int i=0;i<ct_dvs;++i) //选取每项设备中满足带宽(>=当前查询带宽)中price最小
			{
				int tmpi=0;
				while(tmpi < n_dv[i])
				{
					if(dv[i][tmpi].b >= w)
						break;
					++tmpi;
				}

				if(tmpi == n_dv[i])
				{
					total_price = 0;
#if 0
					cout<<w<<endl;
#endif
					break;
				}

				total_price += dv[i][tmpi].p;
#if 0
				cout<<"["<<dv[i][tmpi].p<<"] ";
#endif
			}

			if(total_price>0 && total < w*1.0/total_price)
			{
				total = w*1.0/total_price;
#if 0
				cout<<w<<":"<<total_price<<endl;
#endif
			}

		}

		printf("%.3lf\n",total);

		band_idx = 0;
		memset(n_dv,0,sizeof(n_dv));

	}
}


#if 0
//错误的DP思路
typedef struct dv_sum
{
	int band;
	int price;
	double b_p;
	dv_sum(){band=price=0;}
	dv_sum(const int &b,const int &p){band=b;price=p;b_p=1.0*band/price;}
} dv_sum;

dv_sum dvs[100];
dv_sum cdvs[100];

void solve()
{
	int ct_case,ct_dv;
	cin>>ct_case;
	while(ct_case--) //测试case数
	{
		cin>>ct_dv;
		int num=0,old=0,b,p;
		double total_max=0;
		for(int i=0;i<ct_dv;++i) //设备数，最后一个设备判断效费比
		{
			old = num; //上一次的制造商数
			cin>>num;
			for(int j=0;j<num;++j) //计算以当前j设备为最后节点的最大的效费比
			{
				cin>>b>>p;
				double tmp_max=0; 
				dv_sum tmp_dv(b,p);
				for(int k=0;k<old;++k) //取前一设备的最大效费比+本设备求出最大效费比
				{
					int tmp_b,tmp_p;
					tmp_b = b < dvs[k].band ? b:dvs[k].band;
					tmp_p = dvs[k].price + p;
					double tmp=tmp_b*1.0/tmp_p;
					if(tmp_max <  tmp|| (tmp_max==tmp && tmp_b > tmp_dv.band))
					{
						tmp_max = tmp;
						tmp_dv.band = tmp_b;
						tmp_dv.price = tmp_p;
						tmp_dv.b_p = tmp_max;
					}
				}

				//此时得出设备j对应的最大的效费比
				cdvs[j]=tmp_dv;				
			}

			//将计算出的设备j转到原dvs数组中
			for(int m=0;m<num;++m)
			{
				dvs[m]=cdvs[m];
				if(i==ct_dv-1 && total_max < dvs[m].b_p)
					total_max = dvs[m].b_p;
			}
		}

		printf("%.3f\n",total_max);
		total_max = 0;
		memset(dvs,0,sizeof(dvs));
		memset(cdvs,0,sizeof(cdvs));
	}
}
#endif

#endif
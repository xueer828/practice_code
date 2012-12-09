#ifndef _TEST_
#define _TEST_

// poj1018
// Copyright (c) 2012/12/08 
// Author: xdutaotao (xdutaotao@gmail.com)
// Communication System
// 1<=1<=100 �豸������1<=mi<=100 �����������������̵Ĵ���ͼ۸������������B/P ������/�۸�

//���󷽷���DP��ʽ: f(n)=max{(B(n-1)+Bn)/(P(n-1)+Pn)}

//��ȷ˼·����ΪB��PΪ�໥��Լ������������Ҫ"��ʱ�̶�"ĳһ������Ȼ�����������������һ�������ļ�ֵ����
//�޶� + ö�� , ˮ��

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

//dv[i][j], iΪ�豸�ţ�jΪ�豸
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

		//��ÿһ�豸�������ȼ۸񣬺�����������
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

		//bandȥ��
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
		//��ʼ����С��������������ö��
		for(int k=0;k<=band_id;++k)
		{
			int total_band,total_price;
			int w = sorted_band[k];
			total_price = total_band = 0;
			for(int i=0;i<ct_dvs;++i) //ѡȡÿ���豸���������(>=��ǰ��ѯ����)��price��С
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
//�����DP˼·
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
	while(ct_case--) //����case��
	{
		cin>>ct_dv;
		int num=0,old=0,b,p;
		double total_max=0;
		for(int i=0;i<ct_dv;++i) //�豸�������һ���豸�ж�Ч�ѱ�
		{
			old = num; //��һ�ε���������
			cin>>num;
			for(int j=0;j<num;++j) //�����Ե�ǰj�豸Ϊ���ڵ������Ч�ѱ�
			{
				cin>>b>>p;
				double tmp_max=0; 
				dv_sum tmp_dv(b,p);
				for(int k=0;k<old;++k) //ȡǰһ�豸�����Ч�ѱ�+���豸������Ч�ѱ�
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

				//��ʱ�ó��豸j��Ӧ������Ч�ѱ�
				cdvs[j]=tmp_dv;				
			}

			//����������豸jת��ԭdvs������
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
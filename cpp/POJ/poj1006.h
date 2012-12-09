#ifndef _TEST_
#define _TEST_

// poj1006
// Copyright (c) 2012/12/07 
// Author: xdutaotao (xdutaotao@gmail.com)
// ��������
//��������к��������ڷֱ�Ϊ23�죬28���33�죬�ָ�����ÿ�����ָ߷�����ڣ�����һ�γ���3�θ߷������
// p+23x == e + 28y == i + 33z


#include <cstdio>
#include <iostream>
#include <fstream>
#include <cassert>
using namespace std;

const unsigned maxDay=21252;

void solve()
{
	int nextp(0),nexte(0),nexti(0),d;
	int count=0;
	while(1)
	{
		++count;
		cin>>nextp>>nexte>>nexti>>d;
		if(nextp == -1)
			break;

		while(1)
		{
			if(nextp == nexte && nexte == nexti)
			{
				if(nextp-d <= maxDay && nextp > d)
				{
					printf("Case %d: the next triple peak occurs in %d days.\n",count,nextp-d);
					break; //���㣬������һ��
				}
				else if(nextp % 21252  > d)
				{
					printf("Case %d: the next triple peak occurs in %d days.\n",count,nextp%21252 -d);
					break; //���㣬������һ��
				}				
			}

			if(nextp <= nexte && nextp <= nexti) //nextp ��С
				nextp += 23;
			else if(nexte <= nextp && nexte <= nexti) //nexte��С
				nexte += 28;
			else if(nexti <= nextp && nexti <= nexte) //nexti��С
				nexti += 33;
		}

	}
}

#endif
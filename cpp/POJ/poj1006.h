#ifndef _TEST_
#define _TEST_

// poj1006
// Copyright (c) 2012/12/07 
// Author: xdutaotao (xdutaotao@gmail.com)
// 生理周期
//体力，情感和智力周期分别为23天，28天和33天，现给定了每个出现高峰的日期，求下一次出现3次高峰的日期
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
					break; //满足，计算下一组
				}
				else if(nextp % 21252  > d)
				{
					printf("Case %d: the next triple peak occurs in %d days.\n",count,nextp%21252 -d);
					break; //满足，计算下一组
				}				
			}

			if(nextp <= nexte && nextp <= nexti) //nextp 最小
				nextp += 23;
			else if(nexte <= nextp && nexte <= nexti) //nexte最小
				nexte += 28;
			else if(nexti <= nextp && nexti <= nexte) //nexti最小
				nexti += 33;
		}

	}
}

#endif
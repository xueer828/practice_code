#ifndef _TEST_
#define _TEST_

// poj1008
// Copyright (c) 2012/12/08 
// Author: xdutaotao (xdutaotao@gmail.com)
// 玛雅历

#include <cstdio>
#include <iostream>
#include <fstream>
#include <cassert>
#include <cstring>
using namespace std;

const char haab[][10]={
	"pop","no","zip","zotz","tzec","xul",
	"yoxkin","mol","chen","yax","zac","ceh",
	"mac","kankin","muan","pax","koyab","cumhu","uayet"
};

const char holly[][10]={
	"imix","ik","akbal","kan","chicchan",
	"cimi","manik","lamat","muluk","ok",
	"chuen","eb","ben","ix","mem",
	"cib","caban","eznab","canac","ahau"
}; 

void solve()
{
	int count;
	scanf("%d",&count);
	printf("%d\n",count);
	int day,year;
	char mon[10];

	int idx=0;
	while(idx++ < count)
	{
		scanf("%d. %s %d",&day,&mon,&year);

		int mon_idx=0;
		while(mon_idx < sizeof(haab)/sizeof(haab[0]))
		{
			if(0 == strcmp(mon,haab[mon_idx]))
			{
				break;
			}
			++mon_idx;
		}


		//haab历法，一年365天
		int days=365*year + mon_idx*20 + day ;

		

		//holly历法，一年13*20=260天
		year = days/(13*20);

		int day1=days%(13*20)%13+1;
		int day2=days%(13*20)%20;

		printf("%d %s %d\n",day1,holly[day2],year);
	}
}

#endif
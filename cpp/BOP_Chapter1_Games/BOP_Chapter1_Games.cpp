// BOP_Chapter1_Games.cpp : 编程之美第一章，游戏之乐
//

#include "..\CommonHeader.h"

typedef void (*func)();

#define _F(x) x, #x

struct type_func
{
	func f;
	char* str_f;
};

void exit_n()
{
	exit(0);
}


//----------------------------------------
//1.1, 让CPU占用率曲线听你的指挥
/************************************************************************
 1） 让CPU占用率固定在50%，为一条直线
 2） 让占有率固定在某个值，为一条直线
 3）让CPU占有率为一条正弦曲线
 思路：首先需要获得CPU的频率，例如CPU为2GHZ, 那么一秒就会计算2*10^9次，那么只需要将计算时间进行分段
 一部分时间用于计算，另外一部分时间用于sleep不计算，则可以得出CPU曲线
 GetTickCount()用于计算启动到现在所经历的毫秒值
/************************************************************************/
#include <windows.h>
void cpu_rate_control()
{
	unsigned long sleep_duration, work_duration, total_duration;

	unsigned long rate=50;

	const double pi=3.1415926;

	bool pi_rate=false;
	unsigned long nWork[500]={0};
	unsigned long nCount=0;

	cout<<"Input the work+sleep duration:\n";
	cin>>total_duration;
	cout<<"Input % of number:\n";
	cin>>rate;

	if(rate > 100){
		work_duration = total_duration;
		sleep_duration = 0;
		rate = 100;
	}
	else if(rate == 0) {//pi rate
		pi_rate = true;
		//
		//正弦曲线 y=Asin(x), 因为x每2pi进行一次循环，
		//所以将2pi长度的时间划分成时间等分，然后求出每个等分的work和sleep对应的rate值
		//因为CPU利用率曲线横轴以秒为单位，那么一个循环周期为2pi秒即6285.1852毫秒
		//那么我们可以将每个等分时间控制在50毫秒内，那么就需要划分125.7即126个等划分内

		total_duration = 50;
		nCount =(unsigned long)( pi*2*1000.0/total_duration + 1 );
		
		for(int i=0;i<nCount;++i)
		{
			nWork[i]=(unsigned long) (total_duration/2.0 * (1 + sin(i*pi*2.0/nCount)));
			//cout<<nWork[i]<<" "<<endl;
		}

		//cout<<"total:"<<total_duration<<endl;
		//cout<<"nCount:"<<nCount<<endl;

	}
	else //fixed rate
	{
		work_duration = total_duration * rate /100.0f;
		sleep_duration = total_duration - work_duration;
	}

	
	int idx=0;
	while(1){
		unsigned long startTime=GetTickCount();
		unsigned long currentTime;
		//cout<<"-"<<startTime<<"\n";

		if(pi_rate)
		{			
			work_duration = nWork[idx++];
			sleep_duration = total_duration - work_duration;
			if(idx % nCount == 0)
				idx = 0;
		}
		do{
			currentTime = GetTickCount();
			//cout<<"+"<<currentTime<<"\n";
		}
		while(currentTime-startTime<=work_duration) ;

		Sleep(sleep_duration);
	}
}

//----------------------------------------
//1.2中国象棋将帅问题
//将帅A，B分别被限制在各自3×3的方格内，输出所有A，B的合法位置
//A，B在同一纵向的直线上为不合法位置，其他为合法位置
//要求，只能用1个变量
//思路，用1个变量，来表示A，B当前查询位置，进行遍历判断

//3×3,可以用一个int，高4位表示A，低4位表示B，同时4位所表示的数对3整除
//商为横轴，余数为纵轴坐标

#define getAx(NUM) ((NUM & 0x0f)/3)
#define getAy(NUM) ((NUM & 0x0f)%3)

#define getBx(NUM) (((NUM >>4)&0x0f)/3)
#define getBy(NUM) (((NUM >>4)&0x0f)%3)

void out_possibles()
{
	//初始值为0x0808,每次减1，进行判断
	unsigned int state=0x88;
	int count=0;
	while(state)
	{
		if(getAx(state)!=getBx(state))
		{
			//打印可能性
			cout<<"("<<getAx(state)<<","<<getAy(state)<<"),("<<getBx(state)<<","<<getBy(state)<<")"<<endl;
			++count;
		}
		--state;
		if((state&0x0f)==0x0f)
			state=state&0xf8;
	}
	cout<<"In total:"<<count<<endl;
}



type_func FUNC[]={
	_F(exit_n),
	_F(cpu_rate_control),
	_F(out_possibles),
};

int main(int argc, char* argv[])
{
	int num;
	while(1)
	{
		cout<<"\n--------------------------\nEnter test func:"<<endl;
		for(int i=0;i<sizeof(FUNC)/sizeof(FUNC[0]);++i)
			cout<<i<<":"<<FUNC[i].str_f<<endl;
		cin>>num;
		if(num==0)
			break;
		FUNC[num].f();
	}
	return 0;
}


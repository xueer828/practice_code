// BOP_Chapter1_Games.cpp : ���֮����һ�£���Ϸ֮��
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
//1.1, ��CPUռ�������������ָ��
/************************************************************************
 1�� ��CPUռ���ʹ̶���50%��Ϊһ��ֱ��
 2�� ��ռ���ʹ̶���ĳ��ֵ��Ϊһ��ֱ��
 3����CPUռ����Ϊһ����������
 ˼·��������Ҫ���CPU��Ƶ�ʣ�����CPUΪ2GHZ, ��ôһ��ͻ����2*10^9�Σ���ôֻ��Ҫ������ʱ����зֶ�
 һ����ʱ�����ڼ��㣬����һ����ʱ������sleep�����㣬����Եó�CPU����
 GetTickCount()���ڼ��������������������ĺ���ֵ
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
		//�������� y=Asin(x), ��Ϊxÿ2pi����һ��ѭ����
		//���Խ�2pi���ȵ�ʱ�仮�ֳ�ʱ��ȷ֣�Ȼ�����ÿ���ȷֵ�work��sleep��Ӧ��rateֵ
		//��ΪCPU���������ߺ�������Ϊ��λ����ôһ��ѭ������Ϊ2pi�뼴6285.1852����
		//��ô���ǿ��Խ�ÿ���ȷ�ʱ�������50�����ڣ���ô����Ҫ����125.7��126���Ȼ�����

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
//1.2�й����彫˧����
//��˧A��B�ֱ������ڸ���3��3�ķ����ڣ��������A��B�ĺϷ�λ��
//A��B��ͬһ�����ֱ����Ϊ���Ϸ�λ�ã�����Ϊ�Ϸ�λ��
//Ҫ��ֻ����1������
//˼·����1������������ʾA��B��ǰ��ѯλ�ã����б����ж�

//3��3,������һ��int����4λ��ʾA����4λ��ʾB��ͬʱ4λ����ʾ������3����
//��Ϊ���ᣬ����Ϊ��������

#define getAx(NUM) ((NUM & 0x0f)/3)
#define getAy(NUM) ((NUM & 0x0f)%3)

#define getBx(NUM) (((NUM >>4)&0x0f)/3)
#define getBy(NUM) (((NUM >>4)&0x0f)%3)

void out_possibles()
{
	//��ʼֵΪ0x0808,ÿ�μ�1�������ж�
	unsigned int state=0x88;
	int count=0;
	while(state)
	{
		if(getAx(state)!=getBx(state))
		{
			//��ӡ������
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


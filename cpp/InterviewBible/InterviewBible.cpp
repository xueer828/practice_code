// InterviewBible.cpp : �������̨Ӧ�ó������ڵ㡣
//
#include "..\CommonHeader.h"

//8.3���
//----------------------------------------
//����һ��10��������10ǹ�������90���Ŀ�����
void gun_trial(int n, int lost, int& total)
{
	//û���ܹ���ʧ�Ļ�������һ�ֳɹ���ֱ�ӷ���
	if (lost == 0) 
	{
		//success
		++total;
		return;
	}else if(n==10) //�Ѿ��ǵ�10ǹ�ˣ����Ƕ��Ļ�������
	{
		return;
	}


	//for N, will lost point from 0 to 10 for trial
	for(int i=0;i<=10;++i)
	{
		if(lost-i>=0)
			gun_trial(n+1,lost-i,total);
		else
			break;
	}
	
}

void ch_8_3_1_gun()
{
	int total=0;
	gun_trial(0,10,total);
	cout<<total<<endl;
}
//----------------------------------------
//8.4 �ַ���
//���ַ����������ַ����ĸ��������ʽȫ����ʾ����������˳��
//���磺hart�� ha ��har�ǲ�ͬ��ϣ�����ha��ah������ͬ���

//���
void put_n_char_componets(int n, const string& in, string out, bool dict[])
{
	if(n>=in.size())
	{
		if(out.size()>0)
			cout<<out<<endl;
		return;
	}
	if(dict[in[n]]) //����ַ�ǰ���Ѿ�����������
		put_n_char_componets(n+1,in,out,dict);

	
	dict[in[n]]=true;
	put_n_char_componets(n+1,in,out+in[n],dict);
	//����,��ѡ������ַ�
	//out[out.size()-1]='\0';
	//dict[in[n]]=false;
	put_n_char_componets(n+1,in,out,dict);
	dict[in[n]]=false; //���ݣ�����ָ�
}

//����,�͵�����
void put_n_char_part(int n, string in)
{
	if(n>=in.size())
	{
		cout<<in<<endl;
		return;
	}

	//���ȹ̶���n���ַ����Ե�n+1�Ժ���ַ�����ȫ����
	put_n_char_part(n+1,in);
	//���ν���n�ַ��������ÿ���ַ����н�����Ȼ�����ȫ����
	for(int i=n+1;i<in.size();++i)
	{
		//������Լ�һ���жϣ���������ַ�һ�������Բ�����,ȥ����ͬ����µ�������
		//if(in[n]==in[i]) continue;
		_swap(in[n],in[i]);
		put_n_char_part(n+1,in);
		_swap(in[n],in[i]); //�ָ���������һ�ν���
	}
}

void ch_8_4_1_chars_component()
{
	string tmp="hart";
	string out;
	bool dict[255]={false};
	cout<<"���:\n";
	put_n_char_componets(0,tmp,out,dict);
	cout<<"����:\n";
	put_n_char_part(0,tmp);
}

//----------------------------------------
void exit_n()
{
	exit(0);
}

typedef void (*func)();

func FUNC[]={
	exit_n,
	ch_8_3_1_gun,
	ch_8_4_1_chars_component,
};

int main(int argc, char* argv[])
{
	cout<<"Enter test func:";
	int num;
	while(cin>>num)
	{
		FUNC[num]();
	}
	return 0;
}


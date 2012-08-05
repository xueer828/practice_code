// InterviewBible.cpp : 定义控制台应用程序的入口点。
//
#include "..\CommonHeader.h"

//8.3打靶
//----------------------------------------
//靶上一共10环，连开10枪，求打中90环的可能性
void gun_trial(int n, int lost, int& total)
{
	//没有能够丢失的环数，是一种成功，直接返回
	if (lost == 0) 
	{
		//success
		++total;
		return;
	}else if(n==10) //已经是第10枪了，可是丢的环数不够
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
//8.4 字符串
//把字符串中所有字符串的各种组合形式全部显示出来，不论顺序
//例如：hart， ha 和har是不同组合，但是ha和ah则是相同组合

//组合
void put_n_char_componets(int n, const string& in, string out, bool dict[])
{
	if(n>=in.size())
	{
		if(out.size()>0)
			cout<<out<<endl;
		return;
	}
	if(dict[in[n]]) //如果字符前面已经处理，则跳过
		put_n_char_componets(n+1,in,out,dict);

	
	dict[in[n]]=true;
	put_n_char_componets(n+1,in,out+in[n],dict);
	//回溯,不选择这个字符
	//out[out.size()-1]='\0';
	//dict[in[n]]=false;
	put_n_char_componets(n+1,in,out,dict);
	dict[in[n]]=false; //回溯，必须恢复
}

//排列,就地排列
void put_n_char_part(int n, string in)
{
	if(n>=in.size())
	{
		cout<<in<<endl;
		return;
	}

	//首先固定第n个字符，对第n+1以后的字符进行全排列
	put_n_char_part(n+1,in);
	//依次将第n字符跟后面的每个字符进行交换，然后进行全排列
	for(int i=n+1;i<in.size();++i)
	{
		//这里可以加一个判断，如果交换字符一样，可以不排列,去除相同情况下的排列数
		//if(in[n]==in[i]) continue;
		_swap(in[n],in[i]);
		put_n_char_part(n+1,in);
		_swap(in[n],in[i]); //恢复，进行下一次交换
	}
}

void ch_8_4_1_chars_component()
{
	string tmp="hart";
	string out;
	bool dict[255]={false};
	cout<<"组合:\n";
	put_n_char_componets(0,tmp,out,dict);
	cout<<"排列:\n";
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


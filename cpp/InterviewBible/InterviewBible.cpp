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
//8.6 0-1��������
//����������m��n��������1,2,3,4....n������ȡ��������ʹ���Ϊm��Ҫ��
//�ó����п��ܵ����
void packed_M(const int& m, const int& n, int idx, vector<int>& arr, int sum)
{
	if (idx > n)
		return;

	if(sum == m)
	{
		//������
		for_each(arr.begin(),arr.end(),out<int>);
		cout<<endl;
		return;
	}
	
	//ѡ��idx
	arr.push_back(idx);
	packed_M(m,n,idx+1,arr,sum+idx);
	//��ѡ��idx
	arr.pop_back();
	packed_M(m,n,idx+1,arr,sum);
}

void ch_8_6_package_MN()
{
	vector<int> a;
	packed_M(26,17,1,a,0); //��ʼ
}

//----------------------------------------
//��������룺
//һ������40�������룬������������ĵ�4�飬��������������ͬ��
//������4�������ܹ�����ƽ�ϳƳ�1��40��֮�����������������������
//�����Ŀ�������������Ƕ���

//��������٣���ռ����ޣ���࣬40^3
//��ֱ�Ϊa,b,c,d����4�飬��a<b<c<d,�һ�����ȣ��������Լ��ٽ�ռ��ظ�

void ch_non_40bund()
{
	for(int a=1;a<=40;++a)
		for(int b=a+1;b<=40-a;++b)
			for(int c=b+1;c<=40-a-b;++c)
				{
					int d=40-a-b-c;
					if(d<=0)
						continue;
					//�жϣ�a b c d��ϵĿ�����

					//����ƽ���Կ�֪������ÿ��a b c d,����3�ֿ��ܣ�
					//�������������������ã��������ã���������
					//��������ܳƵ���������Ȼ��ÿ��������ȡ����ȡ������0�Ľ��
					bool arr[41]={0};
					for(int ia=-1;ia<=1;++ia)
						for(int ib=-1;ib<=1;++ib)
							for(int ic=-1;ic<=1;++ic)
								for(int id=-1;id<=1;++id)
								{
									int height=ia*a+ib*b+ic*c+id*d;
									if(height > 0)
										arr[ia*a+ib*b+ic*c+id*d]=1;
									
								}
					int i=1;
					for(i=1;i<=40;++i)
					{
						if(arr[i]==0)
							break;
					}
					if(i==41)
					{
						//�Ѿ��õ�һ��⣬����
						cout<<"(a,b,c,d)="<<a<<","<<b<<","<<c<<","<<d<<endl;
						return;
					}
				}
	cout<<"No result!"<<endl;
}

//----------------------------------------
//����24������
//����Ļ������1��10��Χ���ڵ�4�������������ظ��������ǽ���+-*/��������
//���Լ������޶���������ȼ������ǲ��ܸı��ĸ�����˳��Ѱ�����н��Ϊ24��������ʽ
//����˼·��
//1> ���Ȳ�����+-*/�ĸ����㣬�ȿ��Ǽ����ŵ����ȼ�����,��4�����ֱ�ΪA B C D,���������ȼ�ģʽ����һ�¼���
/*
	((A B) C) D
	(A (B C)) D
	A ((B C) D)
	A (B (C D))
	(A B) (C D)
*/
//2> �ٿ���A B C D֮���������ţ�+-*/

enum op{
	_ADD=0,
	_SUB,
	_MUL,
	_DIV
};

bool dividebyzero=false;

inline float cal_op(float d1, float d2, op x)
{
	switch (x)
	{
	case _ADD:	return d1+d2;break;
	case _SUB:	return d1-d2;break;
	case _MUL:	return d1*d2;break;
	case _DIV:	return d1/d2;break; //��Ϊ��float�������ǳ��������������int����Ҫ���ǣ��쳣�������??
	}
}

char opchar[]={
	'+','-','*','/'
};

inline char getop(int x)
{
	return opchar[x];
}

inline float cal_pattern1(float a, float b, float c, float d, op x, op y, op z)
{
	return cal_op(cal_op(cal_op(a,b,x),c,y),d,z);	//��(A B) C) D
}

inline float cal_pattern2(float a, float b, float c, float d, op x, op y, op z)
{
	return cal_op(cal_op(a,cal_op(b,c,y),x),d,z);	//��A (B C)) D
}

inline float cal_pattern3(float a, float b, float c, float d, op x, op y, op z)
{
	return cal_op(a,cal_op(cal_op(b,c,y),d,z),x);	//A ((B C) D)
}

inline float cal_pattern4(float a, float b, float c, float d, op x, op y, op z)
{
	return cal_op(a,cal_op(b,cal_op(c,d,z),y),z);	//A (B (C D))
}

inline float cal_pattern5(float a, float b, float c, float d, op x, op y, op z)
{
	return cal_op(cal_op(a,b,x),cal_op(c,d,z),y);	//(A B) (C D)
}

typedef float (*cal_pattern)(float,float,float,float,op,op,op);

cal_pattern cp[] = {
	cal_pattern1,
	cal_pattern2,
	cal_pattern3,
	cal_pattern4,
	cal_pattern5
};

char* print_pattern[]={
	"((%d %c %d) %c %d) %c %d = 24\n",
	"(%d %c (%d %c %d)) %c %d = 24\n",
	"%d %c ((%d %c %d) %c %d) = 24\n",
	"%d %c (%d %c (%d %c %d)) = 24\n",
	"(%d %c %d) %c (%d %c %d) = 24\n",
};

void ch_non_24sum()
{
	int va,vb,vc,vd;
	cin>>va>>vb>>vc>>vd;

	bool result=false;

	for(int o=_ADD;o<=_DIV;o=o+1)
		for(int p=_ADD;p<=_DIV;p=p+1)
			for(int q=_ADD;q<=_DIV;q=q+1)
				for(int i=0;i<sizeof(cp)/sizeof(cal_pattern);++i)
				{
					if(cp[i](va,vb,vc,vd,(op)o,(op)p,(op)q)==24)
					{
						result = true;
						printf(print_pattern[i],va,getop(o),vb,getop(p),vc,getop(q),vd);
					}
				}

	if(!result)
		printf("No expression equal to 24!\n");
}


//----------------------------------------
void exit_n()
{
	exit(0);
}

typedef void (*func)();

#define _F(x) x, #x

struct type_func
{
	func f;
	char* str_f;
};

type_func FUNC[]={
	_F(exit_n),
	_F(ch_8_3_1_gun),
	_F(ch_8_4_1_chars_component),
	_F(ch_8_6_package_MN),
	_F(ch_non_40bund),
	_F(ch_non_24sum)
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


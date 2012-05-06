// STL.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "vector"
#include "list"
#include "iostream"

using namespace std;

struct test{
	test(int){};
	test(){};
};

template<class T>
struct spec{
	T operator()(T& a){
		cout<<"T operator\n";
		return 0;
	}

	
};

template<>
double spec<double>::operator()(double& a)
{
	cout<<"Double operator\n";
	return 0.0;
}

int g=1;
template<class T>
int foo_func()
{
	static int val=g++;
	return val;
}


//1������ػ�

//����
template<class T, class K>
struct My
{
	My(){cout<<"General Version\n";}
	void test();
};

template<class T,class K>
void My<T,K>::test()
{
	cout<<"General Version: Test()\n";
}

//��ȫ�ػ�
template<>
struct My<int, double>
{
	My(){cout<<"Total Special Version\n";}
	void test();
};

//template<>
void My<int,double>::test()
{
	cout<<"Total Special Version: Test()\n";
}

//ƫ�ػ�
template<class T>
struct My<T,double>
{
	My(){cout<<"Partial Special Version\n";}
	void test();
};

template<class T>
void My<T,double>::test()
{
	cout<<"Partial Special Version: Test()\n";
}

template<class T, class K>
struct Me
{
	void We();
};

template<class T,class K>
void Me<T,K>::We(){cout<<"Member: General Version\n";}

//��Ա��������ƫ�ػ�
//�ϸ����˵������ģ�岢��֧��ƫ�ػ��������ڿ��ԶԺ����������أ����Կ��Դﵽ��������ģ��ƫ�ػ���Ч��
//template<class T>
//void Me<T,double>::We(){cout<<"Member: Partial Special Version\n";}

template<>
void Me<int,double>::We(){cout<<"Member: Total Special Version\n";}


//a)һ����ģ��
template<class T>
void foofunc(T){cout<<"a.Invoke T\n";}

//b)һ����ģ�壬������a),����ģ�岻�ܱ�ƫ�ػ�������ֻ��������������
template<class T>
void foofunc(T*){cout<<"b.Invoke T*\n";}
/*
//c������һ��b)�ģ���ʾ���ػ�
template<>
void foofunc<int>(int*){cout<<"c.Invoke int*\n";}
*/
//d�����Ƕ�ģ��a)��(��ʾ)�ػ�
template<>
void foofunc<int*>(int*){cout<<"d.Invoke <int*>\n";}

/*
����˳��1����ͨ������2����ģ�����ƥ����õģ�3����ģ���ػ���õ�
*/


int main(int argc, _TCHAR* argv[])
{
	//cout<<foo_func<int>()<<foo_func<bool>()<<foo_func<double>()<<foo_func<int>()<<foo_func<int>()<<foo_func<int>()<<endl;

	/*
	My<short,int> a;
	My<short,double> b;
	My<int,double> c;

	a.test();
	b.test();
	c.test();

	Me<short,int> e;
	Me<short,double> f;
	Me<int,double> g;

	e.We();
	f.We();
	g.We();
	*/

	int p=0;
	foofunc(&p);


	return 0;
}


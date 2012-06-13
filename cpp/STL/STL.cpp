// STL.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include "vector"
#include "list"
#include "iostream"

using namespace std;

template <typename T>
class SetAVL
{
template <typename T> class Node;
public:
	int getHeight()
	{
		return getHeight(root);
	}

	int getHeight(const Node<T> *subtree)
	{
		// If we are at a leaf
		if (subtree == NULL)
			return 0;

		return 1 + max(getHeight(subtree->left), getHeight(subtree->right));
	}

	void add(Node<T> *item)
	{
		Node<T> *t = new Node<T>(item);
		insert(root, t);
	}

	void insert(Node<T> *root, Node<T> *t)
	{
		if (root == NULL)
			root = t;
		else
		{
			if (t->item < root->item)
				insert(root->left, t);
			else if (t->item != root->item)
				insert(root->right, t);
			else
				delete t;
		}
	}

protected:
	template <typename T>
	class Node
	{
	public:
		T item;
		Node *left;
		Node *right;
		int height;

		Node(T item)
		{
			this->item = item;
			this->left = NULL;
			this->right = NULL;
			this->height = 0;
		}
	};

	Node<T> *root;
	int treeSize;

};


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


//1）类的特化

//泛化
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

//完全特化
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

//偏特化
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

//成员函数不能偏特化
//严格的来说，函数模板并不支持偏特化，但由于可以对函数进行重载，所以可以达到类似于类模板偏特化的效果
//template<class T>
//void Me<T,double>::We(){cout<<"Member: Partial Special Version\n";}

template<>
void Me<int,double>::We(){cout<<"Member: Total Special Version\n";}


//a)一个主模板
template<class T>
void foofunc(T){cout<<"a.Invoke T\n";}

//b)一个主模板，重载了a),函数模板不能被偏特化，所以只能用重载来代替
template<class T>
void foofunc(T*){cout<<"b.Invoke T*\n";}
/*
//c）这是一个b)的（显示）特化
template<>
void foofunc<int>(int*){cout<<"c.Invoke int*\n";}
*/
//d）这是对模板a)的(显示)特化
template<>
void foofunc<int*>(int*){cout<<"d.Invoke <int*>\n";}

/*
决断顺序：1）普通函数，2）主模板参数匹配最好的，3）主模板特化最好的
*/


int main(int argc, char* argv[])
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
	//foofunc(&p);

	printf("%.3f\n",1/3.0);
	printf("%.3lf\n",1/3.0);


	return 0;
}




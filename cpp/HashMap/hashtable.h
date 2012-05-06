#pragma once

#include <vector>
using namespace std;


template<class T,class V>
struct _pair
{
	T first;
	V second;
};

//node for hashtable
template<class T>
struct hash_table_node
{
	hash_table_node* next;
	T value;
};

//预先声明
template<class key, class value, class hashfcn, class getkey, class equalkey, class alloc>
struct hash_table;

//iterator defination
template<class key, class value, class hashfcn, class getkey, class equalkey, class alloc>
struct hash_table_iterator
{
	typedef value* pointer;
	typedef value& reference;
	typedef value	value_type;

	typedef hash_table_iterator<key,value,hashfcn,getkey,equalkey,alloc> _iterator;
	typedef hash_table<key,value,hashfcn,getkey,equalkey,alloc> hash_table;
	typedef hash_table_node<value> node;

	//两个指针来表示迭代器
	hash_table* ht; //表示当前bucket
	node*	cur;	//表示当前指向的节点

	//构造函数
	hash_table_iterator(hash_table* tab,node* n):ht(ht),cur(n){};
	hash_table_iterator(){};

	reference operator*(){ return cur->value;	}
	pointer operator->(){return &(operator*());}

	//hash表只能往后++
	_iterator operator++();
	_iterator operator++(int);

	bool operator==(const _iterator& it){return cur == it.cur;}
	bool operator!=(const _iterator& it){return cur != it.cur;}

};

template<class key, class value, class hashfcn, class getkey, class equalkey, class alloc>
typename hash_table_iterator<key,value,hashfcn,getkey,equalkey,alloc> 
hash_table_iterator<key,value,hashfcn,getkey,equalkey,alloc>::operator++()
{
	const node* old=cur;
	cur = cur->next;
	if(!cur)
	{
		size_type bucket_n=ht->bucket_num(old->value);
		while(!cur && ++bucket_n < buckets.SIZE())
			cur = buckets[bucket_n];
	}

	return *this;
}

template<class key, class value, class hashfcn, class getkey, class equalkey, class alloc>
struct hash_table
{
	
	typedef key key_type;
	typedef value value_type;
	typedef value* pointer;
	typedef value& reference;

	typedef hashfcn hasher;
	typedef equalkey key_equal;

	typedef size_t size_type;

private:
	//函数对象
	hasher hash;
	getkey get_key;
	equalkey equals;

	typedef hash_table_node<value> node;

	vector<node*> buckets;	//桶，用来存储节点起始节点
	size_type num_elements;	//节点计数

	size_type bucket_num_key(const key& k)
	{
		return hasher(key) % buckets.size();
	}

	size_type bucket_num(const value& v)
	{
		return bucket_num_key(get_key(v));
	}

public:

	typedef hash_table_iterator<key,value,hashfcn,getkey,equalkey,alloc> iterator;

	//构造函数，没有默认构造函数
	hash_table(size_type n,const hashfcn& h, const equalkey& e, const getkey& g)
		:hasher(h),equals(e),get_key(g),num_elements(0)
	{
		init_hash_table(n);
	}

	//拷贝构造函数
	hash_table(const hash_table& ht)
		:hasher(ht.hasher),equals(ht.equals),get_key(ht.get_key),num_elements(0)
	{
		//copy_ht(ht); 
	}

	//赋值
	hash_table& operator=(hash_table& ht)
	{
		if(this != &ht)
		{
			clear(); //先清理
			hasher=ht.hasher;
			equals=ht.equals;
			get_key=ht.get_key;

			//copy_ht(ht);
		}
		return *this;
	}

	~hash_table()
	{
		clear();
	}

	size_type size(){return num_elements;}
	bool empty(){return num_elements == 0;}

	//迭代器，end
	iterator end()
	{
		return iterator(this,0);
	}
	//迭代器，起始
	iterator begin()
	{
		for(size_type n=0;n<buckets.size();++n)
		{
			if(buckets[n]) //如果不空，则返回
				return iterator(this,bucket[n]);
		}
		return end(); //未找到则返回end
	}

	size_type buckets_size(){return buckets.size();}
	size_type elements_in_bucket(size_type n)
	{
		size_type res=0;
		for(node* cur=buckets[n];cur,cur=cur->next)
			++res;
		return res;
	}

public:
	//允许重复的插入操作
	iterator insert_equal(value& v)
	{
		resize(num_elements+1);
		return insert_noresize_equal(v);
	}

	//不允许重复的插入,注意返回值pair
	_pair<iterator,bool> insert_unique(value& v)
	{
		resize(num_elements+1);
		return insert_noresize_unique(v);
	}

	iterator insert_noresize_equal(value& v);
	pair<iterator,bool> insert_noresize_unique(value& v);

	reference find_and_insert(value& v);
	iterator find(key& k);
	size_type count(key& k);

	//删除key的节点，返回删除个数
	size_type erase(const key& k);
	//删除it对应的节点
	void erase(const iterator& it);

	void clear();

	void resize(size_type s);

private:
	void init_hash_table(size_type n)
	{
		//预留n个buckets，同时全部填0
		buckets.reserve(n);
		buckets.insert(buckets.end(),n,(node*)0);
		num_elements = 0;
	}

	node* new_node(const value& v)
	{
		node* n=new node();
		n->value=v; //value类型需要定义=操作
		n->next = 0;
		return n;
	}

	void del_node(node* n)
	{
		if(n)
			delete n;
		n = 0;
	}
};

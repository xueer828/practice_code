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

//Ԥ������
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

	//����ָ������ʾ������
	hash_table* ht; //��ʾ��ǰbucket
	node*	cur;	//��ʾ��ǰָ��Ľڵ�

	//���캯��
	hash_table_iterator(hash_table* tab,node* n):ht(ht),cur(n){};
	hash_table_iterator(){};

	reference operator*(){ return cur->value;	}
	pointer operator->(){return &(operator*());}

	//hash��ֻ������++
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
	//��������
	hasher hash;
	getkey get_key;
	equalkey equals;

	typedef hash_table_node<value> node;

	vector<node*> buckets;	//Ͱ�������洢�ڵ���ʼ�ڵ�
	size_type num_elements;	//�ڵ����

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

	//���캯����û��Ĭ�Ϲ��캯��
	hash_table(size_type n,const hashfcn& h, const equalkey& e, const getkey& g)
		:hasher(h),equals(e),get_key(g),num_elements(0)
	{
		init_hash_table(n);
	}

	//�������캯��
	hash_table(const hash_table& ht)
		:hasher(ht.hasher),equals(ht.equals),get_key(ht.get_key),num_elements(0)
	{
		//copy_ht(ht); 
	}

	//��ֵ
	hash_table& operator=(hash_table& ht)
	{
		if(this != &ht)
		{
			clear(); //������
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

	//��������end
	iterator end()
	{
		return iterator(this,0);
	}
	//����������ʼ
	iterator begin()
	{
		for(size_type n=0;n<buckets.size();++n)
		{
			if(buckets[n]) //������գ��򷵻�
				return iterator(this,bucket[n]);
		}
		return end(); //δ�ҵ��򷵻�end
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
	//�����ظ��Ĳ������
	iterator insert_equal(value& v)
	{
		resize(num_elements+1);
		return insert_noresize_equal(v);
	}

	//�������ظ��Ĳ���,ע�ⷵ��ֵpair
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

	//ɾ��key�Ľڵ㣬����ɾ������
	size_type erase(const key& k);
	//ɾ��it��Ӧ�Ľڵ�
	void erase(const iterator& it);

	void clear();

	void resize(size_type s);

private:
	void init_hash_table(size_type n)
	{
		//Ԥ��n��buckets��ͬʱȫ����0
		buckets.reserve(n);
		buckets.insert(buckets.end(),n,(node*)0);
		num_elements = 0;
	}

	node* new_node(const value& v)
	{
		node* n=new node();
		n->value=v; //value������Ҫ����=����
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

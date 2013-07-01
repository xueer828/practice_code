#count how many words in one line

import os, sys

def count_word(w):
	sz=len(w)
	count=0
	for x in xrange(sz):
		if x==0 and w[x]!=' ':
			count += 1
		elif x > 0 and w[x-1]==' ' and w[x]!=' ':
			count += 1

	return count

def combin_string(w,v):

	if len(w) <= 0:
		print v;
		return

	combin_string(w[1:],v);
	v += w[0]
	combin_string(w[1:],v)
	v = v[:-1]

def permutate_string(w):
	
	if len(w)<=0:
		print w

	for x in xrange(len(w)):
		(w[0],w[x])=(w[x],w[0])
		permutate_string(w)
		(w[0],w[x])=(w[x],w[0])




if __name__ == '__main__':
	print count_word("    shit  this m is my ta    st   ")

	v=""
	combin_string("abc", v)

	a=4
	b=5

	print (a,b)

	a,b=b,a

	print (a,b)

	str="abc"
	str[0],str[1] = str[1],str[0]

	print str

	permutate_string("abc")


import sys,os

def merge_sort(data,beg,end):
	if beg >= end:
		return

	#print beg,",",end,"|",

	mid = (beg + end) >> 1

	merge_sort(data,beg,mid)
	merge_sort(data,mid+1,end)

	tmp=[0]*(end-beg+1)

	a1=beg
	a2=mid+1
	cnt=0
	while (a1 <= mid and a2 <= end):
		if(data[a1] <= data[a2]):
			tmp[cnt] = data[a1]
			a1 += 1
		else:
			tmp[cnt] = data[a2]
			a2 += 1
		cnt += 1
		

	while(a1 <= mid):
		tmp[cnt] = data[a1]
		cnt += 1
		a1 += 1

	while(a2 <= end):
		tmp[cnt] = data[a2]
		cnt += 1
		a2 += 1

	#back to data
	for x in xrange(end-beg+1):
		data[beg+x] = tmp[x]

	return


if __name__ == '__main__':
	t=[1,3,5,2,4,6,8,1,2,4,5,60,-2]
	l=len(t)
	merge_sort(t,0,l-1);
	print t
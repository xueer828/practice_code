#find max and min of array

import os,sys

#devided way

def find_max_min(data,beg,end):
	if beg>= end:
		return(data[beg],data[beg])
		
	mx=mn=data[beg]
	if(beg == end -1):
		if(data[beg] < data[end]):
			mx = data[end]
			mn = data[beg]
		else:
			mx = data[beg]
			mn = data[end]

		return (mx,mn)

	mid = beg + (end-beg)/2

	(lmx,lmn)=find_max_min(data, beg, mid)
	(rmx,rmn)=find_max_min(data, mid+1, end)

	if(lmx > rmx):
		mx = lmx
	else:
		mx = rmx

	if(lmn < rmn):
		mn = lmn
	else:
		mn = rmn


	return(mx,mn)


if __name__ == '__main__':
	d=[2,3,4,2,6,9]
	print find_max_min(d, 0, len(d)-1)
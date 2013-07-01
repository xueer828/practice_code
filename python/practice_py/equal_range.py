import os,sys

def equal(data,n):
	beg = 0
	end = len(data)-1
	mid = -1
	while(beg <= end):
		mid = beg + (end-beg)/2
		if(data[mid]<n):
			beg = mid + 1
		elif data[mid] > n:
			end = mid - 1
		else:
			break

	return mid

def equal_1st(data,n):

	beg=0
	end=len(data)-1
	last=-1

	while(beg <= end):
		mid = beg + (end-beg)/2
		if data[mid] < n:
			beg = mid + 1
		elif data[mid] > n:
			end = mid - 1
		else:
			last = mid
			end = mid -1

	return last

def equal_last(data,n):
	beg = 0
	end = len(data)-1
	last = -1
	while(beg <= end):
		mid = beg + (end-beg)/2
		if(data[mid]>n):
			end = mid -1
		elif(data[mid]<n):
			beg = mid + 1
		else:
			last = mid
			beg = mid + 1

	return last

if __name__ == '__main__':
	d=[1,2,3,3,3,3,5,5,6,7,7,7,7,7,7,9,9,10]

	print equal(d, 3)
	print equal(d, 1)
	print equal(d, 2)
	print equal(d, 7)
	print equal(d, 9)
	print equal(d, 10)
	print equal(d, 22)

	print "------------"

	print equal_1st(d, 3)
	print equal_1st(d, 1)
	print equal_1st(d, 2)
	print equal_1st(d, 7)
	print equal_1st(d, 9)
	print equal_1st(d, 10)
	print equal_1st(d, 22)

	print "------------"

	print equal_last(d, 3)
	print equal_last(d, 1)
	print equal_last(d, 2)
	print equal_last(d, 9)
	print equal_last(d, 7)
	print equal_last(d, 10)
	print equal_last(d, 22)
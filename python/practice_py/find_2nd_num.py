#find the 2nd largest number

def find_2nd(data):
	if(len(data)<=1):
		return -1

	mx=data[0]
	scd=-1

	for x in xrange(1,len(data)):
		if(data[x] > mx):
			scd = mx
			mx = data[x]

		elif data[x] > scd:
			scd = data[x]

	return scd

if __name__ == '__main__':
	d=[9,3]

	print find_2nd(d)
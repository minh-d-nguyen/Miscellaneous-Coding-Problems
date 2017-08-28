#!/bin/python

import sys

def max_score(a, b, max_val):
	n = len(a)
	m = len(b)

	curr_b_ind = 0

	curr_sum = 0
	max_num_coin = 0

	for i in range(m):
		if curr_sum + b[i] <= max_val:
			curr_sum += b[i]
			curr_b_ind = i + 1
			max_num_coin += 1
		else:
			break

	for i in range(n):
		print "a index:" , i
		print "b index:", curr_b_ind - 1
		print "curr sum:", curr_sum
		print "max num coin:", max_num_coin
		print '\n'
		if curr_sum + a[i] <= max_val:
			curr_sum += a[i]
			if curr_b_ind + i + 1 > max_num_coin:
				max_num_coin = curr_b_ind + i + 1
		else:
			while curr_sum + a[i] > max_val and curr_b_ind > 0:
				curr_sum -= b[curr_b_ind - 1]
				curr_b_ind -= 1

			if curr_b_ind == 0 and curr_sum + a[i] > max_val:
				return max_num_coin
			else:
				curr_sum += a[i]
				if curr_b_ind + i + 1 > max_num_coin:
					max_num_coin = curr_b_ind + i + 1

	return max_num_coin

g = int(raw_input().strip())
for a0 in xrange(g):
    n,m,x = raw_input().strip().split(' ')
    n,m,x = [int(n),int(m),int(x)]
    a = map(int, raw_input().strip().split(' '))
    b = map(int, raw_input().strip().split(' '))

    # your code goes here
    print max_score(a, b, x)
from __future__ import print_function
import sys

n = raw_input().strip()
n = int(n)

gene = raw_input().strip()

num_a = 0
num_c = 0
num_g = 0
num_t = 0

for i in range(n):
	if gene[i] == 'A':
		num_a += 1
	elif gene[i] == 'C':
		num_c += 1
	elif gene[i] == 'T':
		num_t += 1
	elif gene[i] == 'G':
		num_g += 1

goal = n/4
num_a_needed = num_a - goal
num_c_needed = num_c - goal
num_g_needed = num_g - goal
num_t_needed = num_t - goal

print('%s %s %s %s' % (num_a_needed, num_c_needed, num_g_needed, num_t_needed))

if (
	num_a_needed == 0 and
	num_c_needed == 0 and
	num_g_needed == 0 and
	num_t_needed == 0
):
	print(0)
else:
	begin = 0
	end = 0
	num_a_curr = 0
	num_c_curr = 0
	num_t_curr = 0
	num_g_curr = 0
	curr_min_ss_len = n

	for i in range(n):
		if (
			num_a_curr >= num_a_needed and
			num_c_curr >= num_c_needed and
			num_g_curr >= num_g_needed and
			num_t_curr >= num_t_needed
		):
			ss_len = end - begin + 1
			if ss_len < curr_min_ss_len:
				curr_min_ss_len = ss_len
		end = i
		if gene[i] == 'A':
			num_a_curr += 1
		elif gene[i] == 'C':
			num_c_curr += 1
		elif gene[i] == 'T':
			num_t_curr += 1
		elif gene[i] == 'G':
			num_g_curr += 1

		if (
			num_a_curr >= num_a_needed and
			num_c_curr >= num_c_needed and
			num_g_curr >= num_g_needed and
			num_t_curr >= num_t_needed
		):
			ss_len = end - begin + 1
			if ss_len < curr_min_ss_len:
				curr_min_ss_len = ss_len
			# print('%s %s' % (begin, end))
			# print('Len: %s %s' % (ss_len, curr_min_ss_len))

		if (
			num_a_curr > num_a_needed or
			num_c_curr > num_c_needed or
			num_g_curr > num_g_needed or
			num_t_curr > num_t_needed
		):
			# Try to move begin if possible
			while (
				begin <= end and
				((gene[begin] == 'A' and num_a_curr > num_a_needed) or
				(gene[begin] == 'C' and num_c_curr > num_c_needed) or
				(gene[begin] == 'G' and num_g_curr > num_g_needed) or
				(gene[begin] == 'T' and num_t_curr > num_t_needed))
			):
				if gene[begin] == 'A':
					num_a_curr -= 1
				elif gene[begin] == 'C':
					num_c_curr -= 1
				elif gene[begin] == 'G':
					num_g_curr -= 1
				elif gene[begin] == 'T':
					num_t_curr -= 1

				begin += 1

	print(curr_min_ss_len)
	# num_a_curr = 0
	# num_c_curr = 0
	# num_t_curr = 0
	# num_g_curr = 0

	# min_substring_len = n

	# for i in range(n):
	# 	num_a_curr = 0
	# 	num_c_curr = 0
	# 	num_t_curr = 0
	# 	num_g_curr = 0
	# 	found = False
	# 	for j in range(i, n):
	# 		if not found:
	# 			if gene[j] == 'A':
	# 				num_a_curr += 1
	# 			elif gene[j] == 'C':
	# 				num_c_curr += 1
	# 			elif gene[j] == 'T':
	# 				num_t_curr += 1
	# 			elif gene[j] == 'G':
	# 				num_g_curr += 1
	# 			if (
	# 				num_a_curr >= num_a_needed and
	# 				num_c_curr >= num_c_needed and
	# 				num_g_curr >= num_g_needed and
	# 				num_t_curr >= num_t_needed
	# 			):
	# 				found = True
	# 				ss_len = j - i + 1
	# 				if ss_len < min_substring_len:
	# 					min_substring_len = ss_len

	# print(min_substring_len)


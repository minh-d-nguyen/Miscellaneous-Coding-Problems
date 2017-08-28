import sys

num_cases = raw_input().strip()
num_cases = int(num_cases)

for i in range(num_cases):
	s1 = raw_input().strip()
	s2 = raw_input().strip()
	curr_1 = 0
	curr_2 = 0
	result = ""

	while (
		curr_1 != len(s1) or
		curr_2 != len(s2)
	):
		if curr_1 == len(s1):
			result += s2[curr_2]
			curr_2 += 1
		elif curr_2 == len(s2):
			result += s1[curr_1]
			curr_1 += 1
		else:
			if s1[curr_1] < s2[curr_2]:
				result += s1[curr_1]
				curr_1 += 1
			elif s1[curr_1] > s2[curr_2]:
				result += s2[curr_2]
				curr_2 += 1
			else:
				iter_1 = curr_1
				iter_2 = curr_2
				to_add = 1
				found = False

				while not found and iter_1 < len(s1) and iter_2 < len(s2):
					iter_1 += 1
					iter_2 += 1

					if iter_1 == len(s1):
						to_add = 2
						found = True
					elif iter_2 == len(s2):
						to_add = 1
						found = True
					elif s1[iter_1] < s2[iter_2]:
						to_add = 1
						found = True
					elif s1[iter_1] > s2[iter_2]:
						to_add = 2
						found = True

				if to_add == 1:
					result += s1[curr_1]
					curr_1 += 1
				else:
					result += s2[curr_2]
					curr_2 += 1

	print(result)
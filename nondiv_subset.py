from __future__ import print_function
import sys

n,k = raw_input().strip().split(' ')
n,k = [int(n),int(k)]

all_num = raw_input().strip().split(' ')

for i in range(len(all_num)):
	all_num[i] = int(all_num[i])

div_count = []

for i in range(k):
	div_count.append(0)

for i in range(len(all_num)):
	div_count[all_num[i] % k] += 1

subset_card = 0

if div_count[0] > 0:
	subset_card += 1

if k % 2 == 0:
	if div_count[k/2] > 0:
		subset_card += 1
	for i in range(1, k/2):
		subset_card += max(div_count[i], div_count[k - i])
else:
	for i in range(1, k/2 + 1):
		subset_card += max(div_count[i], div_count[k - i])

print(subset_card)


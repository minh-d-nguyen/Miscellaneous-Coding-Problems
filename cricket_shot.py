import sys

class Node():
	def __init__(self, data, max_right):
		self.data = data
		self.left = None
		self.right = None
		self.max_right = max_right

def make_subtree(val, begin, end):
	if len(val) == 0 or begin > end:
		return None
	if begin == end:
		return Node(val[begin], val[begin][1])

	root = Node(val[(begin + end)/2], 0)
	root.left = make_subtree(val, begin, (begin + end)/2 - 1)
	root.right = make_subtree(val, (begin + end)/2 + 1, end)
	root.max_right = root.data[1]
	if root.left != None and root.left.max_right > root.max_right:
		root.max_right = root.left.max_right
	if root.right != None and root.right.max_right > root.max_right:
		root.max_right = root.right.max_right
	return root

def make_tree(ranges):
	left_endpoints = []
	for i in range(len(ranges)):
		left_endpoints.append((ranges[i][0], ranges[i][1]))

	left_endpoints.sort(key=lambda x: x[0])
	range_tree = None
	return make_subtree(left_endpoints, 0, len(left_endpoints) - 1)

def overlap(intrv, l, r):
	if intrv[0] > r or intrv[1] < l:
		return False
	return True

def def_power(l, r, root):
	if root == None or l > r:
		return 0

	curr_power = 0
	root_range = root.data
	if (overlap(root_range, l, r)):
		# print "Overlap: (%s, %s) %s" % (l, r, root_range)
		curr_power += 1

	if l > root.max_right:
		return curr_power

	if root.left == None or l > root.left.max_right:
		return curr_power + def_power(l, r, root.right)

	if root.right == None or r < root.data[0]:
		return curr_power + def_power(l, r, root.left)

	return curr_power + def_power(l, r, root.right) + def_power(l, r, root.left)

n,m = raw_input().strip().split(' ')
n,m = [int(n),int(m)]
ranges = []

for i in range(n):
	left, right = raw_input().strip().split(' ')
	ranges.append((int(left), int(right)))

range_tree = make_tree(ranges)

power_sum = 0

for i in range(m):
	left, right = raw_input().strip().split(' ')
	left, right = [int(left), int(right)]
	power_sum += def_power(left, right, range_tree)

print power_sum
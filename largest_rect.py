import sys

def largestRectangle(h):
    curr_max = 0
    for i in range(len(h)):
    	num_building = 1
    	curr = i - 1
    	while curr >= 0 and h[curr] >= h[i]:
    		num_building += 1
    		curr -= 1

    	curr = i + 1
    	while curr < len(h) and h[curr] >= h[i]:
    		num_building += 1
    		curr += 1

    	area = num_building * h[i]
    	if area > curr_max:
    		curr_max = area

    return curr_max

if __name__ == "__main__":
    n = int(raw_input().strip())
    h = map(int, raw_input().strip().split(' '))
    result = largestRectangle(h)
    print result
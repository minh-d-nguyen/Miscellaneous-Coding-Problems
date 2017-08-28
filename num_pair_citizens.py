import sys
from collections import deque

def num_citizens(adj_list):
    n = len(adj_list)
    citizens = []
    queue = deque([])
    visited = []
    for i in range(n):
        visited.append(False)
        
    for i in range(n):
        if not visited[i]:
            total_citizens = 1
            visited[i] = True
            queue.append(i)
            while len(queue) > 0:
                person = queue.popleft()
                for j in adj_list[person]:
                    if not visited[j]:
                        visited[j] = True
                        queue.append(j)
                        total_citizens += 1
            citizens.append(total_citizens)
            
    return citizens

# Enter your code here. Read input from STDIN. Print output to STDOUT
N,l = map(int,raw_input().split())
adj_list = []
for i in range(N):
    adj_list.append([])

for i in xrange(l):
    a,b = map(int,raw_input().split())
    # Store a and b in an appropriate data structure
    adj_list[a].append(b)
    adj_list[b].append(a)
    
result = 0
# Compute the final result using the inputs from above
citizens = num_citizens(adj_list)
for i in range(len(citizens)):
    for j in range(i):
        result += citizens[i]*citizens[j]
        print result
            
print result

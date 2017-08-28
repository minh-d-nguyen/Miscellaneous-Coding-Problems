#!/bin/python

import sys

def commonChild(s1, s2):
    # Complete this function
    lcs_len = 0
    n = len(s1)
    lcs_board = []
    row = 0
    for i in range(2):
    	lcs_row = []
    	for j in range(n):
    		lcs_row.append(0)
    	lcs_board.append(lcs_row)

    if (s1[0] == s2[0]):
    	lcs_board[0][0] = 1

    for i in range(1, n):

    	if s2[0] == s1[i]:
    		lcs_board[0][i] = 1
    	else:
    		lcs_board[0][i] = lcs_board[0][i - 1]

    for i in range(1, n):
    	row = i % 2
    	if  s2[i] == s1[0]:
    		lcs_board[row][0] = 1
    	else:
    		lcs_board[row][0] = lcs_board[(row - 1) % 2][0]

    	for j in range(1, n):
    		if s1[j] == s2[i]:
    			lcs_board[row][j] = lcs_board[(row - 1) % 2][j - 1] + 1
    		else:
    			lcs_board[row][j]  = max(
    				lcs_board[(row - 1) % 2][j],
    				lcs_board[row][j - 1]
    			)

    return lcs_board[row][n - 1]

s1 = raw_input().strip()
s2 = raw_input().strip()
result = commonChild(s1, s2)
print(result)

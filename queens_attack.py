from __future__ import print_function
import sys

n,k = raw_input().strip().split(' ')
n,k = [int(n),int(k)]
rQueen,cQueen = raw_input().strip().split(' ')
rQueen,cQueen = [int(rQueen),int(cQueen)]

# Calculate the bound cell that the queen can attack if
# there is no obstacle

# Max cell in the same row
rMaxRow = rQueen
cMaxRow = n

# Min cell in the same row
rMinRow = rQueen
cMinRow = 1

# Max cell in the same col
rMaxCol = n
cMaxCol = cQueen

# Min cell in the same col
rMinCol = 1
cMinCol = cQueen

if rQueen > cQueen:
	# Max cell in the same 1st diagonal
	rMaxFirstDiag = n
	cMaxFirstDiag = n - (rQueen - cQueen)

	# Min cell in the same 1st diagonal
	rMinFirstDiag = 1 + (rQueen - cQueen)
	cMinFirstDiag = 1
else:
	# Max cell in the same 1st diagonal
	rMaxFirstDiag = n - (cQueen - rQueen)
	cMaxFirstDiag = n

	# Min cell in the same 1st diagonal
	cMinFirstDiag = 1 + (cQueen - rQueen)
	rMinFirstDiag = 1

if cQueen - 1 < n - rQueen:
	rSecondDiag_first = rQueen + cQueen - 1
	cSecondDiag_first = 1
else:
	cSecondDiag_first = rQueen + cQueen - n
	rSecondDiag_first = n

if rQueen - 1 < n - cQueen:
	cSecondDiag_sec = rQueen + cQueen - 1
	rSecondDiag_sec = 1
else:
	rSecondDiag_sec = rQueen + cQueen - n
	cSecondDiag_sec = n

# print("%s %s" %(rMaxRow, cMaxRow))
# print("%s %s" %(rMinRow, cMinRow))
# print("%s %s" %(rMaxCol, cMaxCol))
# print("%s %s" %(rMinCol, cMinCol))
# print("%s %s" %(rMaxFirstDiag, cMaxFirstDiag))
# print("%s %s" %(rMinFirstDiag, cMinFirstDiag))
# print("%s %s" %(rSecondDiag_first, cSecondDiag_first))
# print("%s %s" %(rSecondDiag_sec, cSecondDiag_sec))

for a0 in xrange(k):
    rObstacle,cObstacle = raw_input().strip().split(' ')
    rObstacle,cObstacle = [int(rObstacle),int(cObstacle)]

    # If obstacle is in the same 1st diagonal
    if (rObstacle - cObstacle) == (rQueen - cQueen):
		if rObstacle <= rMaxFirstDiag and rObstacle > rQueen:
			rMaxFirstDiag = rObstacle - 1
			cMaxFirstDiag = cObstacle - 1
		elif rObstacle >= rMinFirstDiag and rObstacle < rQueen:
			rMinFirstDiag = rObstacle + 1
			cMinFirstDiag = cObstacle + 1

	# If obstacle is in the same 2nd diagonal
    if (rObstacle + cObstacle) == (rQueen + cQueen):
		if rObstacle <= rSecondDiag_first and rObstacle > rQueen:
			rSecondDiag_first = rObstacle - 1
			cSecondDiag_first = cObstacle - 1
		elif rObstacle >= rSecondDiag_first and rObstacle < rQueen:
			rSecondDiag_first = rObstacle + 1
			cSecondDiag_first = cObstacle + 1

		if rObstacle <= rSecondDiag_sec and rObstacle > rQueen:
			rSecondDiag_sec = rObstacle - 1
			cSecondDiag_sec = cObstacle - 1
		elif rObstacle >= rSecondDiag_sec and rObstacle < rQueen:
			rSecondDiag_sec = rObstacle + 1
			cSecondDiag_sec = cObstacle + 1

    # If obstacle is in the same row
    if rObstacle == rQueen:
    	if cObstacle <= cMaxRow and cObstacle > cQueen:
    		cMaxRow = cObstacle - 1
    	elif cObstacle >= cMinRow and cObstacle < cQueen:
    		cMinRow = cObstacle + 1

    # If obstacle is in the same column
    if cObstacle == cQueen:
    	if rObstacle <= rMaxCol and rObstacle > rQueen:
    		rMaxCol = rObstacle - 1
    	elif rObstacle >= rMinCol and rObstacle < rQueen:
    		rMinCol = rObstacle + 1

num_att_cells = 0

num_att_cells += cMaxRow - cMinRow
num_att_cells += rMaxCol - rMinCol
num_att_cells += rMaxFirstDiag - rMinFirstDiag
num_att_cells += abs(rSecondDiag_first - rSecondDiag_sec)

print(num_att_cells)
# print('\n')

# for i in range(cQueen + 1, cMaxRow + 1):
# 	print("%s %s" % (rQueen, i))

# for i in range(cQueen - 1, cMinRow - 1, -1):
# 	print("%s %s" % (rQueen, i))

# for i in range(rQueen + 1, rMaxCol + 1):
# 	print("%s %s" % (i, cQueen))

# for i in range(rQueen - 1, rMinCol - 1, -1):
# 	print("%s %s" % (i, cQueen))

# for i in range(rQueen + 1, rMaxFirstDiag + 1):
# 	print("%s %s" % (i, i + (cQueen - rQueen)))

# for i in range(rQueen - 1, rMinFirstDiag - 1, -1):
# 	print("%s %s" % (i, i + (cQueen - rQueen)))

# if rQueen < rSecondDiag_first:
# 	for i in range(rQueen + 1, rSecondDiag_first + 1):
# 		print("%s %s" % (i, rQueen + cQueen - i))
# else:
# 	for i in range(rQueen - 1, rSecondDiag_first - 1, -1):
# 		print("%s %s" % (i, rQueen + cQueen - i))

# if rQueen < rSecondDiag_sec:
# 	for i in range(rQueen + 1, rSecondDiag_sec + 1):
# 		print("%s %s" % (i, rQueen + cQueen - i))
# else:
# 	for i in range(rQueen - 1, rSecondDiag_sec - 1, -1):
# 		print("%s %s" % (i, rQueen + cQueen - i))
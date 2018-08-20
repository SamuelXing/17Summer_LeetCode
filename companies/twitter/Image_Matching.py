# # Solution #1
# def countMatches(grid1, grid2):
# 	regions1 = findRegions(grid1)
# 	regions2 = findRegions(grid2)

# 	count = 0
# 	for r1 in regions1:
# 		for r2 in regions2:
# 			if r1 == r2:
# 				count += 1
# 	return count


# def findRegions(grid):
# 	if not any(grid): return

# 	grid =[[c for c in line] for line in grid]

# 	n = len(grid)
# 	regions = []

# 	def sink(i, j, region):
# 		if 0 <= i < n and 0 <= j < n and grid[i][j] == '1':
# 			grid[i][j] = '0'
# 			sink(i+1, j, region)
# 			sink(i-1, j, region)
# 			sink(i, j+1, region)
# 			sink(i, j-1, region)
# 			region += (i, j),
# 			return region
# 		return region

# 	for i in range(n):
# 		for j in range(n):
# 			region = sink(i, j, [])
# 			if region:
# 				regions += region,

# 	return regions

# Solution #2
def countMatches(grid1, grid2):
	if not any(grid1) or not any(grid2):
		return 0
	if len(grid1) != len(grid2):
		return 0

	grid1 =[[c for c in line] for line in grid1]
	grid2 =[[c for c in line] for line in grid2]

	n = len(grid1)
	cnt = 0
	def count(i, j, flag):
		if 0 <= i < n and 0 <= j < n and grid2[i][j] == '1':
			if flag:
				return 0
			if grid1[i][j] == '0':
				flag = True
			grid1[i][j] = '0'
			grid2[i][j] = '0'
			count(i+1, j, flag)
			count(i-1, j, flag)
			count(i, j+1, flag)
			count(i, j-1, flag)
			return 1
		return 0

	flag = False
	for i in range(n):
		for j in range(n):
			t = count(i, j, flag)
			if not flag and t == 1:
				cnt += 1

	return cnt

# grid1 = ['0100', '1001', '0011', '0011']
# grid2 = ['0101', '1001', '0011', '0011']

grid1 = ['001','011','100']
grid2 = ['001','011','101']

# regions1 = findRegions(grid1)
# regions2 = findRegions(grid2)
# print(regions1)
# print(regions2)
ret = countMatches(grid1, grid2)
print(ret)





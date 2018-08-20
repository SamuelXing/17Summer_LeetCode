def missingWords(s, t):
	ret = []
	if not t or not s:
		return ret
	s = s.strip().split(' ')
	t = t.strip().split(' ')

	ptr_t, ptr_s = 0, 0
	while ptr_t < len(t):
		while s[ptr_s] != t[ptr_t] and ptr_s < len(s):
			ret += s[ptr_s],
			ptr_s+= 1
		ptr_s += 1
		ptr_t += 1

	if ptr_s < len(s):
		ret += s[ptr_s:]
	return ret

# test case 1
s = '   I like Cheese '
t = ' like '

# test case 2
s1 = 'I am using HackerRank to improve programming'
t1 = 'am HackerRank to improve'

ret = missingWords(s1, t1)
print(ret)
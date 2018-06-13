# my wrong idea:
# 1, thinking about in-place, choose to use backtracking

# Here is another idea that focus on 'L' and 'R'.
# 'R......R' => 'RRRRRRRR'
# 'R......L' => 'RRRRLLLL' or 'RRRR.LLLL'
# 'L......R' => 'L......R'
# 'L......L' => 'LLLLLLLL'
class Solution:
    def pushDominoes(self, d):
        d = 'L' + d + 'R'
        res = []
        i = 0
        for j in range(1, len(d)):
            if d[j] == '.': continue
            middleLength = j - i - 1
            if i: res.append(d[i])
            if d[i] == d[j]: res.append(d[i] * middleLength)
            elif d[i] == 'L' and d[j] == 'R': res.append('.' * middleLength)
            else: res.append('R' * (middleLength // 2) + '.' * (middleLength % 2) + 'L' * (middleLength // 2))
            i = j
        return ''.join(res)
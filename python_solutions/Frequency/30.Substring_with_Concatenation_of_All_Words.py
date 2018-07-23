class Solution:
    def findSubstring(self, s, words):
        """
        :type s: str
        :type words: List[str]
        :rtype: List[int]
        """
        ret = []
        if len(words) == 0:
            return ret
        
        m = collections.defaultdict(int)
        for w in words:
            m[w] += 1
        
        wSize = len(words[0])
        for i in range(wSize):
            win = collections.defaultdict(int)
            wCnt = 0
            for j in range(i, len(s)-wSize+1, wSize):
                curWord = s[j:j+wSize]
                if curWord not in m:
                    win.clear()
                    wCnt = 0
                else:
                    win[curWord] += 1
                    wCnt += 1
                    
                    # --> right
                    while win[curWord] > m[curWord]:
                        idx = j-(wCnt-1)*wSize  # rightest word
                        rmvWord = s[idx :  idx+wSize]
                        win[rmvWord] -= 1
                        wCnt -= 1
                if wCnt == len(words):
                    ret += j-(wCnt-1)*wSize,
            
        return ret
                        
        
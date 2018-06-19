class Solution:
    def generateAbbreviations(self, word):
        """
        :type word: str
        :rtype: List[str]
        """
        self.ret = []
        self.dfs(word, 0, '', 0)
        return self.ret
    
    def dfs(self, word, pos, temp, count):
        if pos == len(word):
            if count > 0: temp += str(count)
            self.ret.append(temp)
            return
        
        self.dfs(word, pos+1, temp, count+1)
        self.dfs(word, pos+1, temp + str(count) + word[pos] if count > 0 else temp+ word[pos], 0)

class Solution:
    def generateAbbreviations(self, word):
        self.ret = []
        self.helper(word, '', False)
        return self.ret
        
    def helper(self, word, temp, flag):
        if not word:
            self.ret.append(temp)
            return
        
        self.helper(word[1:], temp+word[:1], False)
        if not flag:
            for i in range(1, len(word)+1):
                self.helper(word[i:], temp+str(len(word[:i])), True)
        
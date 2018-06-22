class Solution(object): 
    def ladderLength(self, beginWord, endWord, wordList):
        """
        :type beginWord: str
        :type endWord: str
        :type wordList: List[str]
        :rtype: int
        """
        if endWord not in wordList:
            return 0
        if beginWord == endWord:
            return 1
        
        wordList = set(wordList)
        queue = [(beginWord, 1)]
        while queue:
            cur, level = queue.pop(0)
            if cur == endWord:
                return level
            
            for i in range(len(cur)):
                for c in string.ascii_lowercase:
                    nextWord = cur[:i] + c + cur[i+1:]
                    if nextWord in wordList:
                        wordList.remove(nextWord)
                        queue.append((nextWord, level+1))    
        return 0
                

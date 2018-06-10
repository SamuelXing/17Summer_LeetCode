class Solution:
    def replaceWords(self, dict, sentence):
        """
        :type dict: List[str]
        :type sentence: str
        :rtype: str
        """
        
        roots = set(dict)
        
        def replace(word):
            for i in range(len(word)):
                if word[:i] in roots:
                    return word[:i]
            return word
        
        return ' '.join(map(replace, sentence.split()))
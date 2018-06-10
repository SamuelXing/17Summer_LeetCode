class Solution:
    def findDuplicate(self, paths):
        """
        :type paths: List[str]
        :rtype: List[List[str]]
        """
        hashMap = collections.defaultdict(list)
        
        for path in paths:
            data = path.split()
            root = data[0]
            for file in data[1:]:
                name, _, content = file.partition('(')
                hashMap[content].append(root+'/'+name)
        
        return [x for x in hashMap.values() if len(x) > 1]
            
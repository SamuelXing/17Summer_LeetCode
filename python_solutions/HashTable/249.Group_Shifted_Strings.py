class Solution:
    # thinking about what is key, what is value if using hash table!
    def groupStrings(self, strings):
        groups = collections.defaultdict(list)
        for s in strings:
            groups[tuple((ord(c) - ord(s[0])) % 26 for c in s)] += s,
        return list(groups.values())
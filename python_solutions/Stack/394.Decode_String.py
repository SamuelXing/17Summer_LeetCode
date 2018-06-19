class Solution:
    def decodeString(self, s):
        """
        :type s: str
        :rtype: str
        """
        stack, cur, num = [], '', 0
        
        for c in s:
            # '10[ab]'
            if c.isdigit():
                num = num*10 + int(c)
            elif c == '[':
                stack.append(cur)
                stack.append(num)
                cur, num = '', 0
            elif c == ']':
                count = stack.pop()
                prev = stack.pop()
                cur = prev + count*cur
            else:
                cur += c
        
        return cur
        
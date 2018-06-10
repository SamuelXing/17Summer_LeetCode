class Solution:
    def getHint(self, secret, guess):
        """
        :type secret: str
        :type guess: str
        :rtype: str
        """
        bulls, cows = 0, 0
        nums = [0]*10
        
        for i in range(len(secret)):
            if secret[i] == guess[i]:
                bulls += 1
            else:
                if nums[ord(secret[i]) - ord('0')] < 0:
                    cows += 1
                if nums[ord(guess[i]) - ord('0')] > 0:
                    cows += 1
                nums[ord(secret[i]) - ord('0')] += 1
                nums[ord(guess[i]) - ord('0')] -= 1
        
        return str(bulls)+'A'+str(cows)+'B'
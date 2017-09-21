/*
* A message containing letters from A-Z is being encoded to numbers using the following mapping:

* 'A' -> 1
* 'B' -> 2
* ...
* 'Z' -> 26
* Given an encoded message containing digits, determine the total number of ways to decode it.
*
**/

// Solution #1
class Solution {
public:
    /**
     * @param s a string,  encoded message
     * @return an integer, the number of ways decoding
     */
    int numDecodings(string& s) {
        // Write your code here
        if (s.size() == 0)
            return 0;
        else if (s.size() == 1)
            return s[0] != '0' ? 1 : 0;  
          
        int* dp = new int[s.size()];  
        dp[0] = s[0] != '0' ? 1 : 0;  
        dp[1] = (s[0] != '0' && s[1] != '0'? 1 : 0) +
        ((s[0] != '0' && (toInt(s[0]) * 10 + toInt(s[1])) <= 26) ? 1 : 0);  
          
        for (int i = 2; i < s.size(); ++i) {  
            dp[i] = 0;  
            if(s[i] != '0')
                dp[i] += dp[i-1];
            if(s[i-1] != '0' && (toInt(s[i-1]) * 10 + toInt(s[i])) <= 26){  
                dp[i] += dp[i-2];  
            }  
        }  
          
        return dp[s.size() - 1];  
    }

    int toInt(char c){  
        return c - '0';
    }
};


// Solution #2
class Solution {
public:
    /*
     * @param s: a string,  encoded message
     * @return: an integer, the number of ways decoding
     */
    int numDecodings(string &s) {
    	int len = s.length();
    	if(len == 0) return 0;

    	vector<int> f(len + 1);
    	f[0] = 1;

    	for(int i=0; i< len; i++){
    		f[i+1] = 0;
    		if(s[i] != '0')
    			f[i+1] += f[i];
    		if(i>=1 && s[i-1]!='0' && (s[i-1] - '0')*10 + s[i]-'0'<=26)
    			f[i+1] += f[i-1];  		
    	}
    	return f[len];
    }
        
};



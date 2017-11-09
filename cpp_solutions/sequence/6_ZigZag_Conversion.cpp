/*

class Solution {
public:
    string longestPalindrome(string s) {
        string str = "", ans ="";
        int maxLen = -1, cnt;
        
        for(int i=0; i< s.length(); i++)
        {
            str += "*";
            str += s[i];
        }
        str += "*";
        
        for(int i=1; i<str.length(); i++)
        {
            cnt = 0;
            while((i-cnt>=0) && (i+cnt < str.length()) && (str[i-cnt] == str[i+cnt]))
                cnt ++;
            cnt -- ;
            if(maxLen < cnt)
            {
                maxLen = cnt;
                ans = s.substr((i-cnt)/2, (i+cnt)/2-(i-cnt)/2);
            }
        }
        return ans;
    }
};

*/

/**
* 本参考程序来自九章算法，由 @九章算法 提供。版权所有，转发请注明出处。
* - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
* - 现有的面试培训课程包括：九章算法班，系统设计班，算法强化班，Java入门与基础算法班，Android 项目实战班，
* - Big Data 项目实战班，算法面试高频题班, 动态规划专题班
* - 更多详情请见官方网站：http://www.jiuzhang.com/?source=code
*/ 

public class Solution {
    public String convert(String s, int nRows) {
        int length = s.length();
        if (length <= nRows || nRows == 1) return s;
        char[] chars = new char[length];
        int step = 2 * (nRows - 1);
        int count = 0;
	    for (int i = 0; i < nRows; i++){
    		int interval = step - 2 * i;
    		for (int j = i; j < length; j += step){
    		   	chars[count] = s.charAt(j);
    			count++;
    			if (interval < step && interval > 0 
    && j + interval < length && count <  length){
    				chars[count] = s.charAt(j + interval);
    				count++;
    			}
    		}
    	}
        return new String(chars);
    }
}


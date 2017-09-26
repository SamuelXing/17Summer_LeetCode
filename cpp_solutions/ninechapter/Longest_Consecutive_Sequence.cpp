/*
* Given an unsorted array of integers, 
* find the length of the longest consecutive elements sequence.
*/
class Solution {
public:
    /*
     * @param num: A list of integers
     * @return: An integer
     */
    int longestConsecutive(vector<int> &num) {
        // write your code here
        unordered_set<int> map(num.begin(), num.end());
        int ans = 0;
        for(int i=0; i<num.size(); i++){
        	map.erase(num[i]);
        	int pre = num[i]-1;
        	int next = num[i]+1;
        	while(map.find(pre) != map.end()){
        		map.erase(pre);
        		pre--;
        	}
        	while(map.find(next) != map.end()){
        		map.erase(next);
        		next++;
        	}
        	ans = max(ans, next-pre-1);
        }
        return ans;
    }
};
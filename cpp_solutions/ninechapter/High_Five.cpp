/*

There are two properties in the node student id and scores, 
to ensure that each student will have at least 5 points, find the average of 5 highest scores for each person.

Example
Given results = [[1,91],[1,92],[2,93],[2,99],[2,98],[2,97],[1,60],[1,58],[2,100],[1,61]]

Return 

*/

/**
 * Definition for a Record
 * class Record {
 * public:
 *   int id, score;
 *   Record(int id, int score) {
 *     this->id = id;
 *     this->score = score;
 *   }
 * };
 */
// algorithm simulated
class Solution {
public:
    /**
     * @param results a list of <student_id, score>
     * @return find the average of 5 highest scores for each person
     * map<int, double> (student_id, average_score)
     */
    map<int, double> highFive(vector<Record>& results) {
        // Write your code here
    	unordered_map<int,vector<int>> hashMap;
    	for(auto item: results){
    		if(hashMap.find(item.id)==hashMap.end())
    			hashMap[item.id] = vector<int>();
    		if(hashMap[item.id].size() < 5)
    			hashMap[item.id].push_back(item.score);
    		else
    		{
    			// find the lowest score, replace it with the current one
    			int index = 0;
    			for(int i=1; i<hashMap[item.id].size(); i++)
    				if(hashMap[item.id][i] < hashMap[item.id][index])
    					index = i;
    			if(hashMap[item.id][index] < item.score)
    				hashMap[item.id][index] = item.score;
    		}
    	}

    	map<int, double> rst;
    	for(auto it = hashMap.begin(); it!= hashMap.end(); it++){
    		int id = it->first;
    		vector<int> scores = it->second;
    		double avg = 0;
    		for(int i=0; i< 5; i++){
    			avg += scores[i];
    		}
    		avg/=5.0;
    		rst[id] = avg;
    	}
    	return rst;
    }
};
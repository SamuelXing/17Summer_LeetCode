/*
There are a total of n courses you have to take, labeled from 0 to n - 1.

Some courses may have prerequisites, 
for example to take course 0 you have to first take course 1,
 which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, 
return the ordering of courses you should take to finish all courses.

There may be multiple correct orders, 
you just need to return one of them. 
If it is impossible to finish all courses, return an empty array.

Example
Given n = 2, prerequisites = [[1,0]]
Return [0,1]

Given n = 4, prerequisites = [1,0],[2,0],[3,1],[3,2]]
Return [0,1,2,3] or [0,2,1,3]

*/

class Solution {
public:
    /*
     * @param numCourses: a total of n courses
     * @param prerequisites: a list of prerequisite pairs
     * @return: the course order
     */
    vector<int> findOrder(int numCourses, vector<pair<int, int>> &prerequisites) {
        // write your code here
        vector<vector<int>> edges(numCourses);
        unordered_map<int, int> hashMap;
        
        // initialize hashMap
        for(int i=0; i<numCourses; i++){
            hashMap[i] = 0;
        }

        for(int i=0; i<prerequisites.size(); i++){
        	edges[prerequisites[i].second].push_back(prerequisites[i].first);
        	hashMap[prerequisites[i].first]++;
        }

        queue<int> q;
        for(auto it = hashMap.begin(); it!= hashMap.end(); it++){
        	if(it->second == 0)
        		q.push(it->first);
        }

        vector<int> rst;
        while(!q.empty()){
        	int accessed = q.front(); q.pop();
        	rst.push_back(accessed);
        	for(int i=0; i<edges[accessed].size(); i++){
        		hashMap[edges[accessed][i]]--;
        		if(hashMap[edges[accessed][i]] == 0)
        			q.push(edges[accessed][i]);
        	}
        }

        if(rst.size() == numCourses)
        	return rst;
        return vector<int>();
    }
};
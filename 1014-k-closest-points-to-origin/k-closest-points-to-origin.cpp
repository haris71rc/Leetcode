class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double, vector<int>>,vector<pair<double, vector<int>>>,greater<pair<double, vector<int>>>> pq;

        for(auto element: points){
            double distance = sqrt((element[0]*element[0]) + (element[1]*element[1]));
            pq.push({distance,element});
        }

        vector<vector<int>> ans;

        while(k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
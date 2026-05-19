class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>>> pq;

        for(auto element: arr){
            int diff = abs(element-x);

            pq.push({diff,element});
        }

        vector<int> ans;
        while(k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }

        sort(ans.begin(),ans.end());
        return ans;
    }
};
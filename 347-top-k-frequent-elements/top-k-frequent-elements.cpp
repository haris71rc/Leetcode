class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;

        for(auto element: nums){
            m[element]++;
        }

        vector<vector<int>> bucket(nums.size()+1);
        vector<int> ans;

        for(auto element: m){
            int number = element.first;
            int freq = element.second;

            bucket[freq].push_back(number);
        }

        for(int i=bucket.size()-1;i>=0;i--){
            for(auto element: bucket[i]){
                ans.push_back(element);
                if(ans.size()==k){
                    return ans;
                }
            }
        }
        return ans;

    }
};
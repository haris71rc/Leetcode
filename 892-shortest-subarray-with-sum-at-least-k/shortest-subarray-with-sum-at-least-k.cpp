class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n=nums.size();
        vector<long long> v(n+1,0);

        for(int i=0;i<n;i++){
            v[i+1] = v[i]+nums[i];
        }

        deque<int>dq;
        int maxLen=n+1;

        for(int i=0;i<=n;i++){

            while(!dq.empty() && v[i] - v[dq.front()] >= k){
                maxLen = min(maxLen, i-dq.front());
                dq.pop_front();
            }

            while(!dq.empty() && v[i] <= v[dq.back()]){
                dq.pop_back();
            }

            dq.push_back(i);
        }

        return maxLen == n+1 ? -1: maxLen;

    }
};
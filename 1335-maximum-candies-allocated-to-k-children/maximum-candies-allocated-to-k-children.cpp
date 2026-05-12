class Solution {
private:
    long long solve(vector<int>& candies, int m){
        long long ans=0;
        for(int i=0;i<candies.size();i++){
            ans+=candies[i]/m;
        }
        return ans;
    }
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int low=1,end=*max_element(candies.begin(), candies.end());
        long long ans=0;

        while(low<=end){
            int mid=low+(end-low)/2;
            long long sol = solve(candies,mid);
            if(sol >= k){
                low=mid+1;
                ans=mid;
            }
            else{
                end=mid-1;
            }
        }
        return ans;
    }
};
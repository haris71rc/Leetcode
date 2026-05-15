class Solution {
private: 
    int bouqueMade(vector<int>& bloomDay, int k, int mid){
        int count=0,bouque=0;

        for(auto day: bloomDay){
            if(day<mid){
                count++;
                if(count==k){
                    bouque++;
                    count=0;
                }
            }
            else{
                count=0;
            }
        }
        return bouque;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if(bloomDay.size()<(long long)m*k) return -1;
        int low = *min_element(bloomDay.begin(),bloomDay.end());
        int end = *max_element(bloomDay.begin(),bloomDay.end());
        int ans;

        while(low<=end){
            int mid = low + (end-low)/2;

            if(bouqueMade(bloomDay, k, mid) < m){
                ans=mid;
                low = mid+1;
            }
            else{
                end=mid-1;
            }
        }
        return ans;
    }
};
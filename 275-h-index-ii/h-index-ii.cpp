class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n=citations.size();
        int left=0,right=n-1;
        int ans=0;
        
        while(left<=right){
            int mid= left+(right-left)/2;
            int h= n-mid;
            if(citations[mid]>=h){
                ans=h;
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        return ans;
    }
};
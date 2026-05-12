class Solution {
private:
    int calculateHours(vector<int>& piles, int mid){
        int hours=0;
        for(int i=0;i<piles.size();i++){
            hours += ceil((double)piles[i] / mid);
        }
        cout<<"for the hour "<<mid<<" the sum is "<<hours<<"\n";
        return hours;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1,end=INT_MIN;
        for(int i=0;i<piles.size();i++){
            low=min(low,piles[i]);
            end=max(end,piles[i]);
        }

        while(low<end){
            int mid=low+(end-low)/2;
            int t= calculateHours(piles,mid);
            if(t>h){
                low=mid+1;
            }
            else{
                 end=mid;
            }
        }
        return low;
    }
};
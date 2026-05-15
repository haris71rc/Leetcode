class Solution {
private:
    bool canShip(vector<int>& weights, int days, int capacity){
        int curr=0,currDays=1;
        for(auto w: weights){
            if(curr+w > capacity){
                currDays++;
                curr=w;
            }
            else{
                curr+=w;
            }
        }
        return currDays<=days;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int minWeight = INT_MIN, maxWeight=0,ans=0;
        for(auto weight: weights){
            maxWeight+= weight;
            minWeight = max(minWeight,weight);
        }

        while(minWeight <= maxWeight){
            int midWeight = minWeight + (maxWeight - minWeight)/2;

            if(canShip(weights, days, midWeight)){
                maxWeight=midWeight-1;
                ans = midWeight;
            }
            else{
                minWeight = midWeight+1;
            }
        }
        return ans;
    }
};
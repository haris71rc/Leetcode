class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minProfit=prices[0];
        int maxProfit=0;

        for(int i=1;i<prices.size();i++){
            maxProfit=max(maxProfit,prices[i]-minProfit);
            minProfit=min(minProfit,prices[i]);
        }
        return maxProfit;
    }
};
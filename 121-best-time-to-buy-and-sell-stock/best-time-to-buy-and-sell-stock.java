class Solution {
    public int maxProfit(int[] prices) {
        int smallest = prices[0];
        int profit = 0;
        for(int i=1;i<prices.length;i++){
            profit = Math.max(prices[i]-smallest,profit);
            smallest = Math.min(smallest,prices[i]);
        }
        return profit>0? profit:0;
    }
}
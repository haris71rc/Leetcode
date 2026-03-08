class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int leftIndex=INT_MAX, rightIndex=INT_MIN;
        stack<int> st;

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()] < nums[i]){
                rightIndex= max(rightIndex,st.top());
                st.pop();
            }
            st.push(i);
        }

     st = stack<int>(); 

        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()] > nums[i]){
                leftIndex= min(leftIndex,st.top());
                st.pop();
            }
            st.push(i);
        }

        if(leftIndex==INT_MAX) return 0;

        return (rightIndex-leftIndex+1);

    }
};
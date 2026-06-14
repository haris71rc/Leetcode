class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        stack<int> st;
        int ans=0;

        for(int i=0;i<=n;i++){
            while(!st.empty() && (i==n || heights[st.top()] >= heights[i] )){
                int height = heights[st.top()];
                st.pop();

                int right = i;
                int left = st.empty() ? -1:st.top();
                int width = right-left-1;
                int area = width*height;
                ans= max(ans,area);
            }
            st.push(i);
        }
        return ans;
    }
};
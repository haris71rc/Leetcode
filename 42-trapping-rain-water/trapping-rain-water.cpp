class Solution {
private:
    void fillRight(vector<int>& right,stack<int>s,vector<int>& height,int n){
        for(int i=n-1;i>=0;i--){
            int curr=height[i];
            while(curr>=s.top()){
                s.pop();
            }
            right[i]=s.top();
            s.push(curr);
        }
    }
    void fillLeft(vector<int>& left,stack<int>s,vector<int>& height,int n){
        for(int i=0;i<n;i++){
            int curr=height[i];
            while(curr>=s.top()){
                s.pop();
            }
            left[i]=s.top();
            s.push(curr);
        }
    }
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> left(n);
        vector<int> right(n);

        left[0]=height[0];
        for(int i=1;i<n;i++){
            left[i]=max(left[i-1],height[i]);
        }

        right[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--){
            right[i]=max(right[i+1],height[i]);
        }

        int ans=0;
        for(int i=0;i<n;i++){
            ans+=min(left[i],right[i])-height[i];
        }
        return ans;
    }
};
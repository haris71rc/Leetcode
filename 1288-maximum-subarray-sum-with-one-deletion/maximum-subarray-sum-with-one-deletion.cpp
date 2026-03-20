class Solution {
public:
    int maximumSum(vector<int>& arr) {
        if(arr.size()==1) return arr[0];
        int noDeletion=arr[0];
        int oneDeletion=arr[0];
        int prevNoDeletion=arr[0];
        int ans=INT_MIN;

        for(int i=1;i<arr.size();i++){
            prevNoDeletion = noDeletion;
            noDeletion = max(arr[i],noDeletion+arr[i]);
            oneDeletion = max(oneDeletion+arr[i],prevNoDeletion);
            ans = max({ans,noDeletion,oneDeletion});
        }
        return ans;
    }
};
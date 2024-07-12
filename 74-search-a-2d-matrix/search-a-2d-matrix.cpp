class Solution {
private:
    bool binarySearch(int i,vector<vector<int>>& matrix,int target){
        int start=0;
        int end=matrix[0].size()-1;
        while(start<=end){
            int mid = start + (end-start)/2;
            if(matrix[i][mid]>target){
                end=mid-1;
            }
            else if(matrix[i][mid]<target){
                start=mid+1;
            }
            else{
                return true;
            }
        }
        return false;
    }   
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        bool ans=false;
        for(int i=0;i<n;i++){
            if(matrix[i][0]<=target && matrix[i][m-1]>=target){
                cout<<i;
                ans=binarySearch(i,matrix,target);
            }
        }
        return ans;
    }
};
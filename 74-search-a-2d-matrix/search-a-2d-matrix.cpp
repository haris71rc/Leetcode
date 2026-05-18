class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
       int n = matrix.size(), m = matrix[0].size();
       int left=0, right=n*m-1;

       while(left<=right){
        int mid = left + (right-left)/2;
        int midValue = matrix[mid/m][mid%m];

        if(midValue<target){
            left = mid+1;
        }
        else if(midValue>target){
            right = mid-1;
        }
        else{
            return true;
        }
       }
       return false;
    }
};
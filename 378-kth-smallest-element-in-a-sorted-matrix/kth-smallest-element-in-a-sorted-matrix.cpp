class Solution {
private:
    int solve(vector<vector<int>>& matrix, int mid){
        int row=0,col=matrix.size()-1;
        int count=0;

        while(row<=matrix.size()-1 && col>=0){
            if(matrix[row][col] <= mid){
                count+=col+1;
                row++;
            }
            else{
                col--;
            }
        }
        return count;
    }
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        int left=matrix[0][0],high=matrix[n-1][n-1];

        while(left<high){
            int mid = left + (high-left)/2;

            if(solve(matrix,mid)<k){
                left=mid+1;
            }
            else{
                high=mid;
            }
        }
        return left;
    }
};
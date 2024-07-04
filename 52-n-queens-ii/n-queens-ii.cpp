class Solution {
private:
    bool isSafe(int col,int row,vector<vector<int>>& board,int n){
        //current position se left me koi queen na ho
        int x=row;
        int y=col;
        while(y>=0){
            if(board[x][y]==1){
                return false;
            }
            y--;
        }
        //current position se down me koi queen na ho
        x=row;
	    y=col;
        while(x<n &&y>=0){
            if(board[x][y]==1)
            return false;
            x++;
            y--;
        }
        //current position se diagonally upar me koi queen na ho
         x=row;
         y=col;
        while(y>=0 && x>=0){
            if(board[x][y]==1){
                return false;
            }
            y--;
            x--;
        }
        
        return true;
        
    }

    void solve(vector<vector<int>>& board,int n,int col,int &ans){
        if(col>=n){
            ans = ans+1;
            return;
        }
        for(int row=0;row<n;row++){
            if(isSafe(col,row,board,n)){
                board[row][col]=1;
                solve(board,n,col+1,ans);
                //backtracking
                board[row][col]=0;
            }
        }
    }    
public:
    int totalNQueens(int n) {
        vector<vector<int>> board(n,vector<int>(n,0));
        int ans=0;
        solve(board,n,0,ans);
        return ans;
    }
};
class Solution {
private:
    int countNumberOnes(vector<vector<int>>& board,int i,int j){
        int count=0;
        int n=board.size();
        int m=board[0].size();
        //up
        if(i-1>=0 && board[i-1][j]==1) count++;
        //down
        if(i+1<n && board[i+1][j]==1) count++;
        //left
        if(j-1>=0 && board[i][j-1]==1) count++;
        //right
        if(j+1<m && board[i][j+1]==1) count++;
        //up-left
        if(i-1>=0 && j-1>=0 && board[i-1][j-1]==1) count++;
        //up-right
        if(i-1>=0 && j+1<m && board[i-1][j+1]==1) count++;
        //down-left
        if(i+1<n && j-1>=0 && board[i+1][j-1]==1) count++;
        //down-right
        if(i+1<n && j+1<m && board[i+1][j+1]==1) count++;

        return count;
    }    
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>> newBoard(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int oneCount = countNumberOnes(board,i,j);
                if(board[i][j]==0){
                    if(oneCount==3) newBoard[i][j]=1;
                }
                else{
                    if(oneCount==3 || oneCount==2) newBoard[i][j]=1;
                }
            }
        }
        board=newBoard;
    }
};
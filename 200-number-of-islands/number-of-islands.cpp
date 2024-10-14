class Solution {
private:
    void bfs(int i,int j,vector<vector<int>>& visited,vector<vector<char>>& grid){
        queue<pair<int,int>>q;
        q.push(make_pair(i,j));
        visited[i][j]=1;
        int row=grid.size();
        int col=grid[0].size();

        while(!q.empty()){
            pair<int,int>p = q.front();
            q.pop();

            //left me
            if((p.second-1>=0) && (grid[p.first][p.second-1] == '1') && (!visited[p.first][p.second-1])){
                q.push(make_pair(p.first,p.second-1));
                visited[p.first][p.second-1]=1;
            }

            //right me
            if((p.second+1<col) && (grid[p.first][p.second+1] == '1') && (!visited[p.first][p.second+1])){
                q.push(make_pair(p.first,p.second+1));
                visited[p.first][p.second+1]=1;
            }
            //down me
            if((p.first+1<row) && (grid[p.first+1][p.second]=='1') && (!visited[p.first+1][p.second])){
                q.push(make_pair(p.first+1,p.second));
                visited[p.first+1][p.second]=1;
            }

            //up me
            if((p.first-1>=0) && (grid[p.first-1][p.second]=='1') && (!visited[p.first-1][p.second])){
                q.push(make_pair(p.first-1,p.second));
                visited[p.first-1][p.second]=1;
            }
        }
    } 
public:
    int numIslands(vector<vector<char>>& grid) {
        int row=grid.size();
        int col=grid[0].size();

        vector<vector<int>>visited(row,vector<int>(col,0));
        int ans=0;

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]=='1' && !visited[i][j]){
                    ans=ans+1;
                    bfs(i,j,visited,grid);
                }
            }
        }
        return ans;
    }
};
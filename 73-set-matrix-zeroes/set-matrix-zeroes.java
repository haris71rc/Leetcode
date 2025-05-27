class Solution {
    public void makeZero(int x,int y,int[][] matrix,int n,int m){
        for(int i=0;i<m;i++){
            matrix[x][i]=0;
        }
        for(int j=0;j<n;j++){
            matrix[j][y]=0;
        }
        
    }
    public void setZeroes(int[][] matrix) {
        int n=matrix.length;
        int m=matrix[0].length;
        Map<Integer,Pair<Integer,Integer>>map = new HashMap<>();
        int count=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    map.put(count,new Pair<>(i,j));
                    count+=1;
                }
            }
        }
        for(Map.Entry<Integer,Pair<Integer,Integer>> e:map.entrySet()){
            makeZero(e.getValue().getKey(),e.getValue().getValue(),matrix,n,m);
        }



    }
}
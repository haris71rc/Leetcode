class Solution {
    public List<Integer> generateRow(int row){
        List<Integer> temp = new ArrayList<>();
        int ans=1;
        temp.add(1);
        for(int i=1;i<row;i++){
            ans = ans*(row-i);
            ans = ans/i;
            temp.add(ans);
        }
        return temp;
    }
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> ans = new ArrayList<>();
        for(int i=1;i<=numRows;i++){
            ans.add(generateRow(i));
        }
        return ans;
    }
}
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1) return s;
        vector<vector<char>> arr(numRows);

        int row=0,d=1;;
        for(int i=0;i<s.size();i++){
            arr[row].push_back(s[i]);
            if(row==numRows-1){
                d=-1;
            }
            else if(row==0){
                d=1;
            }
            row+=d;
        }
        string ans="";
        for(auto row: arr){
            for(auto c: row){
                ans+=c;
            }
        }        
        return ans;
    }
};
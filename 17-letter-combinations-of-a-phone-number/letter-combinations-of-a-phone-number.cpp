class Solution {
private:
    void solve(int index,string output,vector<string> &ans,string arr[],string digits){
        if(index>=digits.length()){
            ans.push_back(output);
            return;
        }
        int num = digits[index]-'0';
        string value=arr[num];
        for(int i=0;i<value.length();i++){
            output.push_back(value[i]);
            solve(index+1,output,ans,arr,digits);
            output.pop_back();
        }

    }    
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;

        if(digits.length()==0) return ans;

        int index=0;
        string output="";
        string arr[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        solve(0,output,ans,arr,digits);
        return ans;
    }
};
class Solution {
public:
    string addBinary(string a, string b) {
        string ans="";
        int i=a.length()-1,j=b.length()-1;
        int carry=0;
        while(i>=0 || j>=0){
            int result = carry;
            if(i>=0) result+=a[i--]-'0';
            if(j>=0) result+=b[j--]-'0';
            carry=result>1 ? 1:0;
            ans+=to_string(result%2);
        }
        if(carry) ans+=to_string(carry);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
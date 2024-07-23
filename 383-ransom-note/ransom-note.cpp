class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char,int> mega;
        for(int i=0;i<magazine.size();i++){
            mega[magazine[i]]++;
        }
        for(int i=0;i<ransomNote.size();i++){
            if(mega.find(ransomNote[i])!=mega.end() && mega[ransomNote[i]]>0){
                mega[ransomNote[i]]--;
            }
            else{
                return false;
            }
        }
        return true;
    }
};
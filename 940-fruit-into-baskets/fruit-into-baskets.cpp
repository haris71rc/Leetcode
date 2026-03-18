class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        map<int,int> count;
        int i=0,j=0,len=0;;
        while(j<fruits.size()){
            count[fruits[j]]++;
            while(count.size()>2){
                count[fruits[i]]--;
                
                if(count[fruits[i]] == 0){
                    count.erase(fruits[i]);
                }
                i++;
            }
            len = max(len, j-i+1);
            j++;
        }
       
        return len;
    }
};
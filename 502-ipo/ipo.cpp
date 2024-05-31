class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        
        vector<pair<int,int>> vec;
        for(int i=0;i<profits.size();i++){
            vec.push_back({capital[i],profits[i]});
        }
        sort(vec.begin(), vec.end(), []( pair<int, int> &a,  pair<int, int> &b) {
        return a.first < b.first;
        });

        priority_queue<int> pq;
        int i=0,n=profits.size();
        while(k--){
            while(i<n&& vec[i].first<=w){
                pq.push(vec[i].second);
                i++;
            }
            if(!pq.empty()){
                w+=pq.top();
                pq.pop();
            }
            
        }

return w;
    }
};
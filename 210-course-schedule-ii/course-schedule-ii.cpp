class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, list<int>> adj;
        vector<int> inDegree(numCourses, 0);
        vector<int>ans;

        // Build the graph
        for(int i = 0; i < prerequisites.size(); i++) {
            int u = prerequisites[i][1];
            int v = prerequisites[i][0];
            adj[u].push_back(v);
            inDegree[v]++;
        }

        // Initialize queue with nodes having in-degree 0
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
                ans.push_back(i);
            }
        }

        // Perform BFS (Kahn's Algorithm)
        int count = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            count++;

            // Traverse neighbors and reduce in-degree
            for (auto neighbor : adj[node]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) {
                    q.push(neighbor);
                    ans.push_back(neighbor);
                }
            }
        }

        // If count matches numCourses, it means we can finish all courses
        if(count == numCourses)return ans;
        else return {};
    }
};
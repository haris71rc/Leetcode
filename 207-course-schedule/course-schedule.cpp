class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // Create adjacency list and in-degree array
        unordered_map<int, list<int>> adj;
        vector<int> inDegree(numCourses, 0);

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
                }
            }
        }

        // If count matches numCourses, it means we can finish all courses
        return count == numCourses;
    }
};

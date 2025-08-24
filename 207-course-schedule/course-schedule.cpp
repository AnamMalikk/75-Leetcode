class Solution {
public:
    bool canFinish(int v, vector<vector<int>>& edges) {
        vector<vector<int>> adj(v);
        vector<int> indegree(v,0);

        for (auto& e : edges) {
            adj[e[1]].push_back(e[0]); indegree[e[0]]++;
        }

        queue<int> q;

        for (int i=0; i<v; ++i) {
            if (indegree[i]==0) q.push(i);
        }

        int cnt=0;

        while (!q.empty()) {
            int node = q.front();
            q.pop(); ++cnt;

            for (int num : adj[node]) {
                indegree[num]--;
                if (indegree[num]==0) q.push(num);
            }
        }

        return cnt==v;
    }
};
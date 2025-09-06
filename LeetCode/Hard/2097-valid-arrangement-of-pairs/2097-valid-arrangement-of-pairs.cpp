class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        //Step-1 Build adjacency list - Graph
        unordered_map<int, vector<int>> adj;
        //build  indegree and outdegree
        unordered_map<int, int> indegree, outdegree;
        //key - node
        //value - indegree/outdegree
        for(auto& edge : pairs) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v); //u --> v
            outdegree[u]++;
            indegree[v]++;
        }
        //Find the startNode of the Euler Path
        int startNode = pairs[0][0];
        for(auto &it :  adj) {
            int node = it.first;
            if(outdegree[node] - indegree[node] == 1) {
                startNode = node;
                break;
            }
        }
        //DFS
        vector<int> EulerPath; //to store my eulerpath
        stack<int> st; //to perform dfs
        st.push(startNode);

        while(!st.empty()) {
            int curr = st.top();
            if(!adj[curr].empty()) {
                int ngbr = adj[curr].back();
                adj[curr].pop_back();
                st.push(ngbr);
            } else {
                EulerPath.push_back(curr);
                st.pop();
            }
        }
        reverse(begin(EulerPath), end(EulerPath));
        vector<vector<int>> result;
        for(int i = 0; i < EulerPath.size()-1; i++) {
            result.push_back({EulerPath[i], EulerPath[i+1]});
        }

        return result;
    }
};
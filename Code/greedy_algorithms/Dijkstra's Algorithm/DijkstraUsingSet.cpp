// Dijkstra's Shortest Path Algorithm using Set
#include <bits/stdc++.h>
using namespace std;

vector <int> dijkstra(int V, vector<vector<int>> adj[], int S){
    set<pair<int,int>> st;
    vector<int> dist(V, 1e9);

    st.insert({0, S});
    dist[S] = 0;

    while(!st.empty()) {
        auto it = *(st.begin());
        int node = it.second;
        int dis = it.first;
        st.erase(it);

        for(auto it : adj[node]) {
            int adjNode = it[0];
            int edgW = it[1];

            if(dis + edgW < dist[adjNode]) {
                // erase if it existed
                if(dist[adjNode] != 1e9)
                    st.erase({dist[adjNode], adjNode});

                dist[adjNode] = dis + edgW;
                st.insert({dist[adjNode], adjNode});
            }
        }
    }
    return dist;
}

int main() {
    int V = 3; // No of Nodes
    int E = 3;  // No. of edges
    int src = 2; // source - from which shortest distance is calculated
    vector<vector<int>> adj[] = {{{1, 1}, {2, 6}}, {{2, 3}, {0, 1}}, {{1, 3}, {0, 6}}};

    vector<int> result = dijkstra(V, adj, src);

    cout<<"Distance of every node from source "<<src<<"\n";

    for(int i=0;i<result.size();i++){
        cout<<i<<" : "<<result[i]<<"\n";
    }

    return 0;
}
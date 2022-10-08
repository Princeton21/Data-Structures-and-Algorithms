// Dijkstra's Shortest Path Algorithm using Priority Queue
#include <bits/stdc++.h>
using namespace std;

vector <int> dijkstra(int V, vector<vector<int>> adj[], int S){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<int> dist(V, 1e9);
    
    dist[S] = 0;
    pq.push({0,S});
    
    while(!pq.empty()) {
        int dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        
        for(auto it : adj[node]) {
            int edgeWeight = it[1];
            int adjNode = it[0];
            
            if(dis + edgeWeight < dist[adjNode]) {
                dist[adjNode] = dis + edgeWeight;
                pq.push({dist[adjNode], adjNode});
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
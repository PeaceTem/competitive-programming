#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj; // graph represented as an adjacency list
int n; // number of vertices

vector<bool> visited;

void dfs(int v) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u])
            dfs(u);
    }
}

void dfs(int v){
    visited[v]=true;
    for(auto node : adj[v]){
        if(!visited[node]) dfs(node);
    }
}


void dfs(int v){
    visited[v]=true;
    for(int u : adj[v]){
        if(!visited[u]) dfs(u);
    }
}

// compute the entry and exit time of each vertex of the graph
vector<vector<int>> adj; // graph represented as an adjacency list
int n; // number of vertices

vector<int> color;

vector<int> time_in, time_out;
int dfs_timer = 0;

void dfs(int v) {
    time_in[v] = dfs_timer++;
    color[v] = 1;
    for (int u : adj[v])
        if (color[u] == 0)
            dfs(u);
    color[v] = 2;
    time_out[v] = dfs_timer++;
}
//---------------------------
// BFS Shortest Path in an Unweighted Graph
// Given an unweighted graph, find the shortest path between two nodes using BFS.
//---------------------------

vector<int> bfs_shortest_path(int n, vector<vector<int>>& adj, int src, int dest) {
    vector<int> dist(n, -1), parent(n, -1);
    queue<int> q;

    dist[src] = 0;
    q.push(src);

    while(!q.empty()) {
        int u = q.front(); q.pop();
        if(u == dest) break;

        for(int v : adj[u]) {
            if(dist[v] == -1) {
                dist[v] = dist[u] + 1;
                parent[v] = u;
                q.push(v);
            }
        }
    }

    // Reconstruct path
    if(dist[dest] == -1) return {}; // no path

    vector<int> path;
    for(int cur = dest; cur != -1; cur = parent[cur])
        path.push_back(cur);

    reverse(path.begin(), path.end());
    return path;
}

//---------------------------
// Multi-Source BFS Shortest Paths
// Given multiple source nodes in an unweighted graph, find the shortest distance from any source to all other nodes.
//---------------------------
vector<int> multi_source_bfs(int n, vector<vector<int>>& adj, vector<int>& sources) {
    vector<int> dist(n, -1);
    queue<int> q;

    for(int s : sources) {
        dist[s] = 0;
        q.push(s);
    }

    while(!q.empty()) {
        int u = q.front(); q.pop();

        for(int v : adj[u]) {
            if(dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    return dist;  // distance to nearest source
}


//---------------------------
// 0-1 BFS for Graphs with Edge Weights 0 or 1
// Given a graph where edges have weights of either 0 or 1, find the shortest path from a source to all other nodes.
//---------------------------
vector<int> zero_one_bfs(int n, vector<vector<pair<int,int>>>& adj, int src) {
    // adj[u] = { {v, w}, ... } where w ∈ {0,1}
    const int INF = 1e9;
    vector<int> dist(n, INF);
    deque<int> dq;

    dist[src] = 0;
    dq.push_front(src);

    while(!dq.empty()) {
        int u = dq.front(); dq.pop_front();

        for(auto& [v, w] : adj[u]) {
            if(dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;

                if(w == 0) dq.push_front(v);
                else       dq.push_back(v);
            }
        }
    }
    return dist;
}


//---------------------------
// Dijkstra's Algorithm for Weighted Graphs
// Given a weighted graph with non-negative weights, find the shortest path from a source to all other nodes.
//---------------------------
vector<int> dijkstra_path(int n, vector<vector<pair<int,int>>>& adj, int src, int dest) {
    // adj[u] = vector of {v, w} meaning u -> v with weight w (w > 0)

    const long long INF = 1e18;

    // dist[i] = shortest distance from src to i
    vector<long long> dist(n, INF);

    // parent[i] = previous node on shortest path (for reconstruction)
    vector<int> parent(n, -1);

    // Min-heap: stores {distance, node}
    priority_queue<
        pair<long long,int>,
        vector<pair<long long,int>>,
        greater<pair<long long,int>>
    > pq;

    // Distance to source is 0
    dist[src] = 0;
    pq.push({0, src});

    while(!pq.empty()) {
        auto [d, u] = pq.top(); 
        pq.pop();

        // Ignore outdated entries (lazy deletion)
        if(d != dist[u]) continue;

        // Optional speed-up: stop early if destination reached
        if(u == dest) break;

        // Relax all edges u -> v
        for(auto& [v, w] : adj[u]) {
            // If a shorter path to v is found
            if(dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;            // track how we reached v
                pq.push({dist[v], v});    // push new best distance
            }
        }
    }

    // If destination is unreachable
    if(dist[dest] == INF) 
        return {};

    // Reconstruct path from dest back to src
    vector<int> path;
    for(int cur = dest; cur != -1; cur = parent[cur])
        path.push_back(cur);

    reverse(path.begin(), path.end());
    return path;   // shortest path from src → dest
}

long long kruskal(int n, vector<array<int,3>>& edges) {
    // edges: {w, u, v}
    sort(edges.begin(), edges.end());  // sort by w

    DSU dsu(n);
    long long mst_cost = 0;

    for(auto &e : edges) {
        auto [w, u, v] = e;
        if(dsu.unite(u,v)) {
            mst_cost += w;
        }
    }
    return mst_cost;
}

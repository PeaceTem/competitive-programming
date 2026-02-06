vector<int> mergeKSorted(const vector<vector<int>>& a) {
    int k = a.size();
    using T = pair<int, pair<int,int>>; 
    // (value, (list index, index inside list))

    priority_queue<T, vector<T>, greater<T>> pq;

    // push the first element of each list
    for(int i = 0; i < k; i++){
        if(!a[i].empty()) pq.push({a[i][0], {i, 0}});
    }

    vector<int> res;

    while(!pq.empty()){
        auto [val, info] = pq.top(); pq.pop();
        auto [i, j] = info;
        res.push_back(val);

        // push next element of that list
        if(j + 1 < a[i].size())
            pq.push({a[i][j+1], {i, j+1}});
    }
    return res;
}

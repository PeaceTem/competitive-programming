// Container With Most Water

long long maxArea(const vector<long long>& h) {
    int l = 0, r = (int)h.size() - 1;
    long long best = 0;
    while(l < r){
        long long area = (long long)(r - l) * min(h[l], h[r]);
        best = max(best, area);
        if(h[l] < h[r]) l++;
        else r--;
    }
    return best;
}


// Count inversions in an array using merge sort

long long merge_count(vector<int>& a, int l, int r) {
    if (l >= r) return 0;
    int m = (l + r) / 2;
    long long inv = merge_count(a, l, m) + merge_count(a, m+1, r);

    vector<int> temp;
    int i = l, j = m+1;

    while (i <= m && j <= r) {
        if (a[i] <= a[j]) temp.push_back(a[i++]);
        else {
            temp.push_back(a[j++]);
            inv += (m - i + 1); // inversion count
        }
    }

    while (i <= m) temp.push_back(a[i++]);
    while (j <= r) temp.push_back(a[j++]);

    for (int k = l; k <= r; k++)
        a[k] = temp[k - l];

    return inv;
}

long long inversions = merge_count(a, 0, a.size() - 1);

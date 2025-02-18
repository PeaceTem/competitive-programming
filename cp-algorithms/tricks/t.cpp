#include <bits/stdc++.h>

using namespace std;


# using vector as a map
vector<int> a(n);
for (int &x : a) cin >> x;

vector<int> freq(n + 1);
for (int x : a) freq[x]++;

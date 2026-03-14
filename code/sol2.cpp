#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

void solve(){
    int n; 
    cin >> n;

    vector<double> c(n), p(n);

    for(int i = 0; i < n; i++)
        cin >> c[i] >> p[i];

    double dp = 0;

    for(int i = n - 1; i >= 0; i--){
        double f = 1.0 - p[i] / 100.0;
        dp = max(dp, c[i] + f * dp);
    }

    cout << fixed << setprecision(10) << dp << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--)
        solve();
}
#include <bits/stdc++.h>
using namespace std;
// #define ll long long
#define ull unsigned long long
#define pb push_back
// #define mp make_pair
#define F first
#define S second
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define lb lower_bound
#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>
// #define MOD 1000000007
#define INF 1000000000000000000
#define MAXN 1000005
#define ld long double
#define eps 1e-9

void solve(){
    int n, m, k; cin >> n >> m >> k;
    vector<int> a(n), b(m); string s;

    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];
    cin >> s;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    unordered_map<int, int> vpos;

    vpos[0] = 0;
    int min_pos = 0, max_pos = 0, pos = 0;
    int cnt = 0;
    for(int i = 0; i < k; i++){
        if(s[i] == 'L') pos--;
        else pos++;

        if(min_pos <= pos && pos <= max_pos) continue;
        min_pos = min(pos, min_pos);
        max_pos = max(pos, max_pos);

        vpos[pos] = ++cnt;
    }

    unordered_map<int, int> mvp;

    for(int i = 0; i < n; i++){
        int idx = upper_bound(b.begin(), b.end(), a[i]) - b.begin();
        int left = idx - 1;

        if(left >= 0 && idx < m){
            int kk = b[left] - a[i];
            int j = b[idx] - a[i];

            if(vpos.count(kk) && vpos.count(j)){
                if(vpos[kk] < vpos[j]) mvp[kk]++;
                else mvp[j]++;
            } else if(vpos.count(kk)) mvp[kk]++;
            else if(vpos.count(j)) mvp[j]++;
        } else if(left >= 0){
            int kk = b[left] - a[i];
            if(vpos.count(kk)) mvp[kk]++;
        } else if(idx < m){
            int j = b[idx] - a[i];
            if(vpos.count(j)) mvp[j]++;
        }
    }

    min_pos = 0, max_pos = 0, pos = 0;
    int ans = n;
    for(int i = 0; i < k; i++){
        if(s[i] == 'L') pos--;
        else pos++;
        // cout << "pos " << pos << endl;
        if(min_pos <= pos && pos <= max_pos){
            cout << ans << " ";
            continue;
        }

        min_pos = min(pos, min_pos);
        max_pos = max(pos, max_pos);

        if(mvp.count(pos)) ans -= mvp[pos];

        cout << ans << " ";
    }

    cout << endl;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);
    int t = 1; 
    cin >> t;

    while(t-->0){
        solve();
    }
    return 0;
}


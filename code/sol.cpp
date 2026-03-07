#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define int long long

int n, k, x; 
vector<int> a;
int maxn = 1e9;

bool check(int mid){
    int cnt = 0;

    int st = 0;
    while(cnt < k && st <= x){
        int ind = upper_bound(all(a), st) - a.begin();

        if(ind != 0){
            if(st - a[ind - 1] < mid){
                st = a[ind - 1] + mid;
                continue;
            }
        }

        if(ind != n){
            if(a[ind] - st < mid){
                st = a[ind] + mid;
                continue;
            }
        }

        cnt++;
        st++;
    }

    return cnt >= k;
}

vector<int> ans;
void regen(int l){
    int st = 0, cnt = 0;

    while(cnt < k){
        int ind = upper_bound(all(a), st) - a.begin();

        if(ind != 0){
            if(st - a[ind - 1] < l){
                st = a[ind - 1] + l; continue;
            }
        }

        if(ind != n){
            if(a[ind] - st < l){
                st = a[ind] + l; continue;
            }
        }

        ans[cnt] = st;
        cnt++;
        st++;
    }
}

void solve(){
    cin >> n >> k >> x;

    a.resize(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    sort(all(a));

    int l = 0, r = 1e9 + 19;

    while(l + 1 < r){
        int mid = l + (r - l) / 2;

        if(check(mid)) l = mid;
        else r = mid;
    }

    ans.resize(k);
    regen(l);

    for(int i = 0; i < k; i++) cout << ans[i] << " ";
    cout << endl;
}


int32_t main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t = 1; 
    cin >> t;
    while(t-->0){
        solve();
    }
    return 0;
}


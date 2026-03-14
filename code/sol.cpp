#include <bits/stdc++.h>
using namespace std;
// #define endl '\n'
#define all(x) (x).begin(), (x).end()
#define int long long

void solve(){
    int n; cin >> n;

    vector<int> a(2*n, -1);
    a[0] = 0;
    bool t = true;
    while(t){
        vector<int> k;
        t = false;
        int pos = -1;
        for(int i = 0; i < 2*n; i++){
            if(a[i] == 0) k.push_back(i + 1);
            else if(a[i] == -1){
                k.push_back(i + 1);
                t = true;
                pos = i;
                break;
            }
        }

        if(t){
            cout << "? " << k.size() << " ";

            for(int i = 0; i < (int) k.size(); i++){
                cout << k[i] << " ";
            }

            cout << endl;
            int p;
            cin >> p;
            if(p == -1) exit(0);

            a[pos] = p;
        }
    }   

    vector<int> kk;

    for(int i = 0; i < 2*n; i++){
        if(a[i] != 0) kk.push_back(i + 1);
    }

    for(int i = 0; i < 2*n; i++){
        if(a[i] == 0){
            cout << "? " << 1 + (int) kk.size() << " " << i + 1 << " ";

            for(int& x : kk) cout << x << " ";

            cout << endl;

            int p;
            cin >> p;
            if(p == -1) exit(0);
            a[i] = p;
        }
    }

    cout << "! ";

    for(int& x : a) cout << x << " ";

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
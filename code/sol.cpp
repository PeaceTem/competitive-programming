#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define int long long

void solve(){
    int r, g, b; cin >> r >> g >> b;
    char first, second, third;
    int fi, se, th;
    if(r >= g && r >= b){
        first = 'R';
        fi = r;
        if(g >= b){
            second = 'G';
            third = 'B';
            se = g;
            th = b;
        } else {
            second = 'B';
            third = 'G';
            se = b;
            th = g;
        }
    } else if(g >= r && g >= b){
        first = 'G';
        fi = g;
        if(r >= b){
            second = 'R';
            third = 'B';
            se = r;
            th = b;
        } else {
            second = 'B';
            third = 'R';
            se = b;
            th = r;
        }
    } else if(b >= r && b >= g){
        first = 'B';
        fi = b;
        if(r >= g){
            second = 'R';
            third = 'G';
            se = r;
            th = g;
        } else {
            second = 'G';
            third = 'R';
            se = g;
            th = r;
        }
    }

    bool k = fi >= (se + th);
    bool kk = fi % 2 == 0;
    bool f = true;
    while(fi > 0 && se > 0){
        if(f){
            if(k) cout << first << second;
            else cout << second << first;
            fi--;
            se--;
            if(th > 0) f = !f;
        } else if(th > 0){
            if(k) cout << first << third;
            else cout << third << first;
            f = !f;
            fi--;
            th--;
        }
    }

    if(k) cout << first;
    else {
        
        while(se > 0 && th > 0){
            if(kk) cout << third << second;
            else cout << second << third;
            se--; th--;
        }

        if(se > 0) cout << second;
        if(th > 0) cout << third;
    }

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
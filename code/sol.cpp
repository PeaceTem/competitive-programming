#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define int long long

void solve(){
    int n, q; cin >> n >> q;

    // int row = 1LL << n;
    while(q--){
        string s; cin >> s;
        int k = 1LL << (n * 2);
        int row = 1LL << n;
        int col = 1LL << n;
        int d = 0;

        if(s == "->"){
            int r, c; cin >> r >> c;
            while(true){
                if(k == 1){
                  cout << d + 1 << endl;
                  break;  
                }
                int mask = 0;

                if(r > row / 2) mask |= 1LL << 1;
                if(c > col / 2) mask |= 1LL;

                if(mask == 0){
                    
                } else if(mask == 1){
                    d +=  3 * (k / 4);
                    c -= col / 2;
                } else if(mask == 2){
                    d += 2 * (k / 4);
                    r -= row / 2;
                } else if(mask == 3){
                    d += k / 4;
                    r -= row / 2;
                    c -= col / 2;
                }

                row >>= 1;
                col >>= 1;
                k >>= 2;
            }

        } else {
            int pos; cin >> pos;

            int r = 1, c = 1;
            while(true){
                if(k == 1){
                    cout << r << " " << c << "\n";
                    break;
                }
                if(pos > 3 * (k / 4)){
                    c += col / 2;
                    pos -= 3 * (k / 4);
                } else if(pos > k / 2){
                    r += row / 2;
                    pos -=  k / 2;
                } else if(pos > k / 4){
                    r += row / 2;
                    c += row / 2;
                    pos -= k / 4;
                }

                col >>= 1;
                row >>= 1;
                k >>= 2;
            }
        }
    }

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


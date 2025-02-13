#include <bits/stdc++.h>

using i64 = long long;
using namespace std;


int check_fib(vector<int>& vec){

    int fib = 0, ffib=0;
    for(int j=0; j<3; j++){
        if(vec[j+2] == vec[j+1] + vec[j]){
            fib++;
        }
    }

    return fib;
}



void solve() {
    vector<int> a, b, c; int x;
    for(int i=0; i<4; i++){
        cin >> x;

        if(i==2){
            a.push_back(x - a[1]);
        }
        a.push_back(x); b.push_back(x); c.push_back(x);
        if(i==1) b.push_back(b[0] + b[1]);

        if(i==3){
            auto it = c.begin() + 2;
            c.insert(it, c[3] - c[2]);
        }

    }


    int _a = check_fib(a), _b = check_fib(b), _c = check_fib(c);
    int output = max({_a, _b, _c});
    cout << output << "\n";
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;

    while (t--) {
        solve();
    }
}
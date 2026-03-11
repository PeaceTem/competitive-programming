#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define int long long

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    int mn = 0, mx = 0;
    string ss = s;

    for(int i = 0; i < n; i++){

        if(s[i] == '0'){
            if((i - 1 >= 0 && s[i - 1] == '1') && (i + 1 < n && s[i + 1] == '1') && (i + 2 < n && s[i + 2] == '1')){
                s[i] = '1';
                s[i + 1] = '0';
            }
        }
    }

    for(int i = 0; i < n; i++){
        if(s[i] == '1'){
            if((i - 1 >= 0 && s[i - 1] == '1') && (i + 1 < n && s[i + 1] == '1')) s[i] = '0';
            else mn++;
        }
    }

    // s = ss;
    // for(int i = n - 1; i >= 0; i--){

    //     if(s[i] == '0'){
    //         if((i + 1 < n && s[i + 1] == '1') && (i - 1 >= 0 && s[i - 1] == '1') && (i - 2 >= 0 && s[i - 2] == '1')){
    //             s[i] = '1';
    //             s[i - 1] = '0';
    //         }
    //     }
    // }
    // int mn1 = 0;
    // for(int i = 0; i < n; i++){
    //     if(s[i] == '1'){
    //         if((i - 1 >= 0 && s[i - 1] == '1') && (i + 1 < n && s[i + 1] == '1')) s[i] = '0';
    //         else mn1++;
    //     }
    // }

    // mn = min(mn, mn1);
    // s = ss;

    // for(int i = n - 1; i >= 0; i--){
        
    //     if(s[i] == '1'){
    //         if((i + 1 < n && s[i + 1] == '1') && (i - 1 >= 0 && s[i - 1] == '0') && (i - 2 >= 0 && s[i - 2] == '1')){
    //             s[i] = '0';
    //             s[i - 1] = '1';
    //         }
    //     }
    // }

    // int mx1 = 0;
    // for(int i = 0; i < n; i++){
    //     if(s[i] == '0'){
    //         if((i-1 >= 0 && s[i-1] == '1') && (i+1 < n && s[i+1] == '1')){
    //             mx1++;
    //             s[i] = '1';
    //         }
    //     } else mx1++;
    // }

    // for(int i = 0; i < n; i++){
        
    //     if(ss[i] == '1'){
    //         if((i - 1 >= 0 && ss[i - 1] == '1') && (i + 1 < n && ss[i + 1] == '0') && (i + 2 < n && ss[i + 2] == '1')){
    //             ss[i] = '0';
    //             ss[i + 1] = '1';
    //         }
    //     }
    // }

    for(int i = 0; i < n; i++){
        if(ss[i] == '0'){
            if((i-1 >= 0 && ss[i-1] == '1') && (i+1 < n && ss[i+1] == '1')){
                mx++;
                ss[i] = '1';
            }
        } else mx++;
    }

    mx = max(mx, mx1);
    // testing
    cout << mn << " " << mx << endl;
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
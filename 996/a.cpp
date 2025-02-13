#include <bits/stdc++.h>


using namespace std;
int main(){

    int t, n, a, b; cin >> t;

    while(t--){
        cin>>n>>a>>b;
        if(abs(a-b) % 2 == 0) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
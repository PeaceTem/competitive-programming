#include <bits/stdc++.h>
using namespace std;
typedef long long ll;



void solve(){
    int n; cin>>n;
    string x; cin>>x;

    // for(int i=0; i<n-2;i++){
    //     if(x[i]=='1' and x[i+1] == '0' and x[i+2] == '0'){
    //         x.erase(i+1,2);
    //     } else if(x[i]=='0' and x[i+1] == '0' and x[i+2] == '1'){
    //         x.erase(i, 2); i++;
    //     }
    // }

    // cout << "Len:  " << x.size() << '\n';
    // cout << x << '\n';


    // int i = count(x.begin(), x.end(), '1');
    // int j = count(x.begin(), x.end(), '0');

    // if(i>=j) cout << "YES\n";
    // else cout << "NO\n";

    if(x[0] == '1' or x[x.size() - 1] == '1'){
        cout << "YES\n"; return;
    }

    for(int i=0; i<n; i++){
        if(x[i] == '1' and x[i+1] == '1'){
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}


int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);
	int t; cin>>t; while(t-->0) solve(); return 0;
}
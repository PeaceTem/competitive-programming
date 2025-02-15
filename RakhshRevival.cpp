#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n,m,k; cin>>n>>m>>k; string num; cin>>num;

    int res=0;
    for(int i=0; i<n; i++){
        if(num[i] == '0'){
            int counter =0;
            for(int j=i;j<n; j++){
                if(num[j] == '1') break;
                counter++;
                if(counter == m){
                    res++;
                    i=j+k-1;
                    break;
                }
                i=j;
            }
        }
    }
    cout << res << '\n';
}


int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t--) solve(); return 0;
}
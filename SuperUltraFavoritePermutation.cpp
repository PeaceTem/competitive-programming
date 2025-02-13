#include <bits/stdc++.h>

using namespace std;


vector<bool> sieve(int n){
    vector<bool> isPrime(n+1, true);
    isPrime[0] = isPrime[1] = false;
    for(int i=2;i*i<n;i++){
        if(isPrime[i]) for(int j=i*i;j<n;j+=i) isPrime[j] = false;
    }

    return isPrime;
}

vector<bool> primes = sieve(400000);
void solve(){
    int n; cin>>n; int m;
    
    vector<int> ans;
    for(int i=1;i<=n;i+=2) if(i&1){
        ans.push_back(i);
    }

    int j=0;
    for(int i=2; i<=n;i+=2){
        if(i%2==0){
            if(!primes[ans.back()+i]){
                ans.push_back(i); j=i;
                break;
            }
        }
    }
    
    if(j==0){
        cout << -1 << '\n';
    }else{
        for(int i=0; i<ans.size(); i++) cout << ans[i] << ' ';
        for(int i=2;i<=n; i+=2){
            if(i!=j) cout << i << ' ';
        }
        cout << '\n';
    }

} 

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t-->0) solve(); return 0;
}
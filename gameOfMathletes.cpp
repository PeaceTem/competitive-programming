#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,k; cin>>n>>k; vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];

    sort(a.begin(), a.end());

    int l=0, r=n-1, counter=0;
    while(l<r){
        if(a[l]+a[r] == k){
            counter++;
            l++;r--;
        } else if(a[l]+a[r] > k) r--;
        else l++;
    }
    
    cout << counter << "\n";
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t-->0) solve(); return 0;
}
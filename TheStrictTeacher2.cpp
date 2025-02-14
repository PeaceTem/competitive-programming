#include <bits/stdc++.h>

using namespace std;
vector<int> bs(vector<int> &arr, int n){
    int low = 0; int high = arr.size()-1;
    bool found = false; int mid = low; vector<int> res;
    while(!found){
        if(arr[mid] == n) found=true, res.push_back(arr[mid]), res.push_back(arr[mid+1]);
        else if(arr[mid+1] == n) found=true, res.push_back(arr[mid]), res.push_back(arr[mid+1]);
        else if(arr[mid] < n && arr[mid+1] > n) found=true, res.push_back(arr[mid]), res.push_back(arr[mid+1]);
        else if(arr[mid] < n) low=mid+1;
        else if(arr[mid]>n) high=mid-1;
        mid = (low+high)/2;
    }

    return res;
}

void solve(){
    int n,m,q; cin>>n>>m>>q; vector<int> nm(m), nq(q);

    for(int i=0;i<m;i++) cin>>nm[i];
    for(int i=0;i<q;i++) cin>>nq[i];
    sort(nm.begin(), nm.end());

    for(int num : nq){
        if(num < nm[0]) cout << nm[0] - 1 << '\n';
        else if(num > nm.back()) cout << n - nm.back() << '\n';
        else{
            vector<int> res = bs(nm, num);
            if(num == res[0] || num==res[1]) cout << 0;
            else cout << (res[1]-res[0])/2 << '\n';
        }
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t-->0) solve(); return 0;
}
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int n,k; cin>>n>>k; vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];

    sort(a.begin(),a.end());

    int l=0, r=n-1, c=0; bool d=false;
    while(l<=r){
        if(l==r) c++,l++,r--;
        if(a[l]<k){
            if(l+1<n){
                if(a[l]+a[l+1]<k){
                    c++;l+=2;r--;
                } else c++,l+=2;
            } else c++, l++;
        } else c++,l++;
    }
    // if(d) cout << c << '\n';
    cout << c-1 << '\n';

}
int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);
	int t; cin>>t; while(t-->0) solve(); return 0;
}
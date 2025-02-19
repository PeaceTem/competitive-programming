#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


vector<int> powers(200000,1);

void calc_pow(int n){
    for(int i=1;i<=n;i++){
        powers[i] = (powers[i-1]*2)%998244353;
    }
}

void solve(){
    
    int n; cin>>n; vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    int f1=0,f2=0,f3=0;
    int l = -1;

    vector<pair<int,int>> st; vector<pair<int,int>> st3; ll ans =0; int ff2=0;
    // for the 
    for(int i=0; i<n;i++){
        if(a[i]==1){
            st.push_back(make_pair(i, ff2));
        } else if(a[i]==3){
            st3.push_back(make_pair(i, ff2));
        }
        else if(a[i]==2){
            ff2++;
        }
    }

    // precompute the values of 2
    for(int i=0;i<st.size();i++){
        for(int j=0;j<st3.size();j++){
            if(st[i].first < st3[j].first){
                int x = st3[j].second - st[i].second;
                ans += powers[x] - 1LL;
                ans %=998244353;
            }
        }
    }

    cout << ans << "\n";
}


int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);
    calc_pow(199998);
	int t; cin>>t; while(t-->0) solve(); return 0;
}
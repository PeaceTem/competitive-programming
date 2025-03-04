#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> cnt(200001,0LL);
vector<ll> a;
int n; ll ps = 0;
void get_max(int i){
	// if(i<0 || i==n) return 0;
	if(a[i] < 0LL){
		if(i-1 < 0LL) cnt[i] = abs(a[i]);
		else cnt[i] = cnt[i-1] + abs(a[i]);
	} else {
		if(i-1 < 0LL ) cnt[i] = a[i];
		else if(a[i-1]<0LL) cnt[i] = a[i]+ps;
		else cnt[i] = a[i] + cnt[i-1];
		ps+=(long long) a[i];
	}
}
void solve(){
    cin>>n; fill(cnt.begin(),cnt.end(),0LL);
	a.resize(n); ps = 0;
	for(auto& it : a) cin>>it;

	for(int i=0;i<n;i++){
		get_max(i);
	}
	ll ng =0;
	for(int i=n-1;i>=0;--i){
		if(a[i]<0LL){
			if(i+1<n){
				if(a[i+1] > 0LL) cnt[i] += ng;
			}
			ng += abs(a[i]);
		}
	}
	ll mx = *max_element(cnt.begin(), cnt.end());

	cout <<mx<<'\n';
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);
	int t; cin>>t; while(t-->0) solve(); return 0;
}
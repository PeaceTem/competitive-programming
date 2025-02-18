#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


long long rem_end(vector<int>& b){
	long long ans = 0;
	for(int i=0;i<b.size();i++){

	}
}
void solve(){
    int n; cin>>n; vector<int> a(n); vector<long long> b(n, 0);

	for(int i=0;i<n;i++){
		cin>>a[i];
	}

	b[0] = abs(a[0]);
	for(int i=1;i<n;i++){
		if((a[i-1] < 0 and a[i] < 0) or (a[i-1]>0 and a[i]<0)){
			b[i] = b[i-1] + abs(a[i]);
		} else if(a[i-1]>0 and a[i]>0){
			b[i]=b[i-1] + abs(a[i]);
		} else if(a[i-1]<0 and a[i]>0){
			b[i] = abs(a[i]);
		}
	}

	auto it = max_element(b.begin(), b.end());
	cout << *it << '\n';
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);
	int t; cin>>t; while(t-->0) solve(); return 0;
}
#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin>>n; vector<int> a(n);
	long long ans=0, anss=0, f=0;

	for(int i=0;i<n;i++){
		cin>>a[i];
	}


	for(int i=0;i<n;i++){
		if(a[i] > 0){ 
			anss += abs(a[i]);
		} else {
			for(int k=i; k<n; k++){
				if(a[k] < 0) anss += abs(a[k]);
				else{
					i=k-1; anss=0; break;
				}
			}
		}
		f = max(anss,f);

	}

	cout << max(f, anss) << '\n';

}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);
	int t; cin>>t; while(t-->0) solve(); return 0;
}
#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,x; cin>>n; vector<int> a(n); map<int, int> d;
	for(int i=0; i<n;i++){
		cin>>x; a[i] = x; d[x]++;
	}
	
	int l=0,lf=0,r=0,rf=0; bool lt = false; int leng=0;
	if(a.size()-d.size() == 0){
		cout << "1 " << n << "\n"; return;
	}else if(d.size() == 1){
		cout << "0\n"; return;
	}

	for(int i=0;i<n;i++){
		if(d[a[i]] ==1){
			if(!lt) l=r=i+1, lt=true;
			else r=i+1; 
			if((r-l)>=(rf-lf)) rf=r,lf=l;
		} else {
			// if((r-l)>=(rf-lf)) rf=r,lf=l;
			//l=r=i+1;
			lt=false;
		}
	}

	if((r-l)>=(rf-lf)) rf=r,lf=l;

	if(lf!=0) cout << lf << ' ' << rf << '\n';
	else cout << "0\n";

}
int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);
	int t; cin>>t; while(t-->0) solve(); return 0;
}
#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin>>n; map<int, int> a; int b;
    for(int i=0;i<n;i++) cin>>b, a[b]++;
    if(a.size() == 1 and n%2 == 0){

        cout<<"YES"<<'\n';
        return;
    }

    for(auto it=a.begin(); it != a.end(); it++){
        auto nit = next(it);

        if(it->second > 1){

            if(it->second > 2){
                if(nit != a.end()){

                if(((it->second-2)%abs(it->first - nit->first))%2==0){
                    nit->second += (it->second-2)/abs(it->first - nit->first);
                    it->second =2;
                } else {
                    if(it->second%2 == 1) break;
                }}
            }
        } else break;
        if(nit == a.end() && it->second%2 == 0){
            cout << "YES" << '\n';
            return;
        }
    }
    cout << "NO" << '\n';
}
int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);
	int t; cin>>t; while(t-->0) solve(); return 0;
}
#include <bits/stdc++.h>
using namespace std;

int mv(int x1,int y1,int x,int y,int k, int t){
    if(x1==x && y1==y) return 0;
    if(t == 0){
        x1 = x1+min(k,x-x1);
        return 1 + mv(x1,y1,x,y,k,1);
    } else {
        y1=y1+min(k, y-y1);
        return 1 + mv(x1,y1,x,y,k,0);
    }
}

void solve(){
    int x,y,k; cin>>x>>y>>k;
    int nm = mv(0,0,x,y,k,0);
    cout << nm << '\n';
   
}
int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);
	int t; cin>>t; while(t-->0) solve(); return 0;
}
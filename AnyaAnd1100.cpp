#include <bits/stdc++.h>
using namespace std;

string x_x; map<int, int> m;
bool query(int &k, char &l){
    k--; // use map
    bool found =false; int index=-1;


    for(int i=k-3;i<=k;i++){
        if(m.count(i)){
            m.erase(i);index=i;break;
        }
    }

    x_x[k]=l;
    for(int i=k-3;i<=k;i++){
        if(x_x[i] == '1' && x_x[i+1] == '1' && x_x[i+2] == '0' && x_x[i+3] == '0'){
            m[i]++;
        }
    }

    return m.size();
}

 void precompute(){
    for(int i=0;i<x_x.length()-3; i++){
        if(x_x[i] == '1' && x_x[i+1] == '1' && x_x[i+2] == '0' && x_x[i+3] == '0'){
            m[i]++;
        }
    }
 }

void solve(){
    string x; cin>>x;
    int n, k; cin>>n; char l; 
    x_x = x; m.clear();
    precompute();

    while(n--){
        cin>>k>>l;
        bool ans = query(k,l);
        cout<<(ans ? "YES" : "NO")<<'\n';
    }

}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);
	int t; std::cin >> t; while (t--) solve(); return 0;
}
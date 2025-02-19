#include <bits/stdc++.h>
using namespace std;

string x_x;
bool query(){
    bool result = false;
    for(int i=0;i<x_x.length()-3; i++){
        if(x_x[i] == '1' && x_x[i+1] == '1' && x_x[i+2] == '0' && x_x[i+3] == '0'){
            result = true; break;
        }
    }

    return result;
}
// use binary search
// store all the indices of 1100<pair<int, int>>; whenever any query coming in is going to change it. remove the pair from the vector
// if the vector is not empty "YES", else "NO"

void solve(){
    string x; cin>>x;
    int n, k; cin>>n; char l; 
    x_x = x;

    while(n--){
        cin>>k>>l;
        x_x[k-1] = l;
        bool ans = query();
        cout<<(ans ? "YES" : "NO")<<endl;
    }

}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);
	int t; std::cin >> t; while (t--) solve(); return 0;
}
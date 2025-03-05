#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin>>n;
    string s; cin>>s; bool p =false,ss=false, ans=true;
    // NO
    // sp if all the elements after p is not .
    bool s_first=false, dot=false;
    if(s[0]=='s') s[0] = '.';
    if(s.back()=='p') s.back() = '.';
    // bool s_first = true;
    unordered_map<char,int> m;
    
    for(int i=0;i<n;i++){
        m[s[i]]++;
    }

    if(m['s']&&m['p']) ans = false;
    // if(s)

    cout << (ans ? "YES" : "NO") << '\n';
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);
	int t; std::cin >> t; while (t--) solve(); return 0;
}
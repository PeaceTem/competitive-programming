#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void shout(ll k, ll len, ll c){
    ll ans = (k/len) + c;
    cout << ans << '\n';
}
void solve(){
    ll n,x,k; cin>>n>>x>>k;
    string st; cin>> st;
    ll x_x = x,k_x = k; ll ins = st.length(), i=0,c=0;
    while(i<ins && k){
        if(st[i]=='L') x_x--;
        else x_x++;

        if(x_x == 0){
            if(c>0){
                ll len = i+1; 
                // call func;
                // if(c==0){
                //     cout << "working" << '\n';
                //     shout(k_x, len, c); return;
                // } else { 
                //     shout(k--, len, c+1); return;
                // }
                k--;
                shout(k+len, len, c); return;

            }
            i=-1; c++;
        }
        i++; k--;
    }
    
    cout << c << '\n';
}
int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);
	int t; cin>>t; while(t-->0) solve(); return 0;
}
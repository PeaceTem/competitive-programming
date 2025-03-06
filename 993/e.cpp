#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long


ll bin_exp(ll a, ll b){
    ll res = 1LL;
    while(b > 0LL){
        if(b & 1LL) res = res * a;
        a *=a;
        b >>= 1LL;
    }
    return res;
}


void solve(){
    ll k, l1,r1,l2,r2; cin>>k>>l1>>r1>>l2>>r2;
    bool g=true;
    ll lf=l1,rf=r1, x=0, nw=0, lb=0;
    for(ll n=0;g;n++){
        x=0; lf=l1; rf=r1; lb=lf;
        ll mid = lb, b;
        while(lf<=rf){
            ll mid = lf + (rf-lf)/2;

            b = mid*bin_exp(k,n);
            if(b<l2){
                lf=mid+1LL;
            } else if(b>r2){
                rf=mid-1LL;
            } else {
                rf=mid-1LL; x=mid;
                // cout << "Say Something!\n";
            }
        }
        
        if(x>0) lb=x;
        else if(b>r2) g=false;
        

        x=0; lf=l1; rf=r1;


        while(lf<=rf){
            ll mid= lf + (rf-lf)/2;
            ll b = mid*bin_exp(k,n);
            if(b>=l2 && b <=r2){
                lf=mid+1LL; x=mid;
            } else if(b<l2){
                lf=mid+1LL;
            } else if(b>r2) rf=mid-1LL;
        }

        if(x>=lb){
            nw += x-lb+1;
        }
    }

    cout << nw << '\n';
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);
	int t; std::cin >> t; while (t--) solve(); return 0;
}
#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,x; cin>>n>>x;
    int temp,i_temp; bool done =false;
    int ans = -1;
    // cout << "What is really going on like wetin dey sup?" << endl;
    if(x%2==0){
        cout << x << ' ';
        for(int i=1;i<n;i++) cout << 0 << ' ';
        cout << '\n'; return;
    }
    for(int i=0;i<min(n,x);i++){
        // cout << "Thank you " << endl;
        if(done){
            break;
        }
        i_temp = i; temp=x;
        // cout << "Starting loop with i = " << i << " and temp = " << temp << endl;
        while(i_temp>0){
            // cout << "Doing Nothing!" << '\n';
            if(i_temp&1){
                if(temp&1){ 
                    i_temp >>= 1; 
                    temp >>= 1;
                } else { 
                    ans=i;
                    done=true;
                    break;
                }

            } else  { i_temp>>=1;temp>>=1;}
            // cout << "i = " << i << ", temp = " << temp << endl;
        }
    }

    if(ans == -1){
        if(n==x){
            if(n==1){
                cout << 1 << '\n';
                return;
            }
            for(int i=0;i<n;i++) cout << i << ' ';
        } else if(n>x){
            for(int i=0;i<=x;i++) cout << i << ' ';
            int diff = n-x;
            for(int i=1;i<diff;i++) cout << 0 << ' ';
        } else if(n<x) {
            int it;
            if(x/2 < n-1){
                it = n-1;
            } else it = x;
            for(int i=0;i<n-1;i++) cout << i << ' ';
            cout << it << ' ';
        }
    } else {
        for(int i=0;i<ans;i++) cout << i << ' ';
        cout << x << ' ';
        int diff = n-ans;
        for(int i=1;i<diff;i++) cout << 0 << ' ';
    }
    cout << '\n';
}


int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);
	int t; cin>>t; while(t-->0) solve(); return 0;
}
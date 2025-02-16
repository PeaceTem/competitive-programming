#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin>>n; vector<int> a(n), b(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];

    // if Alice have the same elements and the element is also present in bob's;
    // if they both have the same elements in the same order.

    // the elements in a are contained in b;
    int l1,l2,r1,r2; l1=l2=0; r1=r2=n-1;
    for(int i=0; i<n; i++){
        if((a[l1] == b[l2] or a[l1] == b[r2]) and (a[r1] == b[r2] or a[r1] == b[l2])){

            if(a[l1] == b[l2]){
                l1++;l2++;
            } else if(a[l1] == b[r2]) l1++, r2--;
            else if(a[r1] == b[r2]) r1--, r2--;
            else if(a[r1] == b[l2]) r1--, l2++;
        }
        else {
            cout << "Alice\n"; return;
        }
    }
    
    cout << "Bob" << "\n";
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t-->0) solve(); return 0;
}
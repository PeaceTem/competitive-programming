#include <bits/stdc++.h>

using namespace std;

int main(){
    short t; cin>>t; int n, a, b, c, total, remainder;

    while(t--){
        cin>>n>>a>>b>>c;
        total = a+b+c;
        remainder = n % total;
        vector<int> vec = {a,b,c};
        int pt = 0;
        if(remainder == 0) cout<<3*(n/total)<<endl;
        else {
            for(int i=0;i<vec.size();i++){
                pt += vec[i];
                if(pt>=remainder){
                    cout<<3*(n/total) + i + 1 << endl;
                    break;
                }
                
            }
        }
    }
    return 0;
}
#include <bits/stdc++.h>


using namespace std;

int main(){
    short t; cin>>t; int a, b, h, m, d, l;
    while(t--){
        cin>>a>>b;
        h = a-1;
        m = b % h;
        d = b / h;

        if(m == 0) l = a * d - 1;
        if(m > 0) l = a * d + m;

        cout << l << endl;
    }
    return 0;
}
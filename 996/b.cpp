#include <bits/stdc++.h>


using namespace std;
int main(){

    int n,m; cin >> n;

    while(n--){
        cin>>m;
        vector<int> a(m);
        vector<int> b(m);
        for(int i=0; i<m; i++) cin >> a[i];
        for(int i=0; i<m; i++) cin >> b[i];
        int max_diff = -999999999, dif_index, diff, diff_count=0, ad=1999999999;
        bool solved=true;

        for(int i=0; i<m; i++){
            diff= a[i] - b[i];
            if(diff<0){
                diff_count++;
                max_diff = max(abs(diff), max_diff);
                if(diff_count > 1){
                    solved = false;
                    break;
                }
            } else {
                ad = (a[i] - b[i]) < ad ? a[i] - b[i] : ad;
            }
            
        }   

        if(solved && (ad < max_diff)) solved = false;

        if(solved) cout << "YES" << endl;
        else cout << "NO" << endl;

    }
    return 0;
}
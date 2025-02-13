#include <bits/stdc++.h>


using namespace std;
int main(){

    short n, m; cin >> n;

    while(n--){
        cin>>m;
        vector<short> a(m);
        for(short i=0; i<m; i++) cin >> a[i];


        // Find the first non-zero element
        auto first = std::find_if(a.begin(), a.end(), [](short x) { return x != 0; });

        // Find the last non-zero element
        auto last = std::find_if(a.rbegin(), a.rend(), [](short x) { return x != 0; }).base();

        // Erase leading and trailing zeros if there are non-zero elements
        if (first < last) {
            a = std::vector<short>(first, last);
        } else {
            a.clear();  // Handle case where vector is all zeros
        }





        short z = count(a.begin(), a.end(), 0);

        if(a.size() == 0) cout << 0 << endl; //passed

        else if(find(a.begin(), a.end(), 0) != a.end()) cout << 2 << endl;
        else cout << 1 << endl;

    }
    return 0;
}
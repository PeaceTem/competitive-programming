#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;

        vector<string> g(n);

        int minx = 1e9, maxx = -1e9;
        int miny = 1e9, maxy = -1e9;
        int mins = 1e9, maxs = -1e9;
        int mind = 1e9, maxd = -1e9;

        bool has = false;

        for(int i=0;i<n;i++){
            cin >> g[i];
            for(int j=0;j<n;j++){
                if(g[i][j]=='#'){
                    has = true;

                    minx = min(minx,i);
                    maxx = max(maxx,i);

                    miny = min(miny,j);
                    maxy = max(maxy,j);

                    mins = min(mins,i+j);
                    maxs = max(maxs,i+j);

                    mind = min(mind,i-j);
                    maxd = max(maxd,i-j);
                }
            }
        }

        bool square = (maxx-minx<=1 && maxy-miny<=1);
        bool diag1 = (maxs-mins<=1);
        bool diag2 = (maxd-mind<=1);

        if(square || diag1 || diag2) cout<<"YES\n";
        else cout<<"NO\n";
    }
}
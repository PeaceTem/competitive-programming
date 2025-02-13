#include <bits/stdc++.h>


using namespace std;
int main(){

    int t, a, b; cin >> t; string path;

    while(t--){
        cin>>a>>b;
        cin>>path;
        int n[a][b];

        for(int i=0; i<a; i++){
            for(int j=0; j<b; j++){
                cin >> n[i][j];
            }
        }

        for(int i=0; i<a; i++){
            for(int j=0; j<b; j++){
                cout << n[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

int main (){
    short t, n;
    cin >> t;

    for(short i = 0; i < t; i++){
        cin >> n;
        vector<short> a(n);
        vector<short> b(n);

        for(short j = 0; j < n; j++){
            cin >> a[j];
        }
        
        for(short j = 0; j < n; j++){
            cin >> b[j];
        }

        short max_diff = a[n - 1];
        short diff = 0;
        for(short j = 0; j < n - 1; j++){
            diff = a[j] - b[j + 1];
            if(diff > 0){
                max_diff = max_diff + diff;
            }
        }

    cout << max_diff << endl;
    }


    return 0;
}
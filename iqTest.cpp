#include <bits/stdc++.h>

using namespace std;

int main(){
    short n; cin >> n; vector<short> arr(n); vector<short> evenness = arr;

    for(short i = 0; i < n; i++){
        cin >> arr[i];
    }

    for(short i = 0; i < n; i++){
        if(arr[i] % 2){
            evenness[i] = 1;
        } else {
            evenness[i] = 0;
        }
    }

    short odd = count(evenness.begin(), evenness.end(), 1);

    if(odd == 1){
        auto it = find(evenness.begin(), evenness.end(), 1);
        short index = distance(evenness.begin(), it) + 1;
        cout << index << endl;
    } else {
        auto it = find(evenness.begin(), evenness.end(), 0);
        short index = distance(evenness.begin(), it) + 1;
        cout << index << endl;
    }
    return 0;
}
#include <bits/stdc++.h>

using namespace std;


int main()
{
    short k,w; int n;

    cin >> k >> n >> w;
    if(w == 0){
        cout << 0 << endl;
    } else if(w == 1){
        cout << (k - n >= 0 ? k - n : 0) << endl;
    } else {
        int price = (k * w *(1 + w)) / 2;
        cout << (price - n >= 0 ? price - n : 0) << endl;
    }
    return 0;
}
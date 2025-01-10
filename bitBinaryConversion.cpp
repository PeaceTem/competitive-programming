#include <bits/stdc++.h>

using namespace std;

int main(){
    int decimal; cin >> decimal;
    short lastBit;
    string binary = "";
    while(decimal > 0){
        lastBit = decimal & 1;
        decimal >>= 1;

        binary = to_string(lastBit) + binary;
    }

    cout << binary << endl;
    return 0;
}
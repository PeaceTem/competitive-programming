#include <iostream>
#include <string>
using namespace std;


int main(){
    string t1, t2, t3;

    cin >> t1 >> t2 >> t3;

    long long n {stoi(t1)}, m {stoi(t2)}, a {stoi(t3)}, k, j;

    if(n % a > 0){
        k = n / a + 1;
    } else {
        k = n / a;
    }

    if(m % a > 0){
        j = m / a + 1;
    } else {
        j = m / a;
    }

    cout << k * j << endl;
    return 0;
}
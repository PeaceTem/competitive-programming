#include <iostream>
#include <string>


using namespace std;

int main(){
    string k;
    cin >> k;
    float investment (stoi(k)); 
    float gain = 0;

    for(int i = 0; i < 4; i++){
        investment = (investment * 1.6);
        gain += investment / 4;

    }
    cout << "Investment: " << investment << " Gain: " << gain << endl;
    return 0;
}
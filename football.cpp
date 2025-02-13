#include <bits/stdc++.h>


using namespace std;
int main(){

    int n; cin >> n; map<string, int> goals; string team, winner;

    while(n--){
        cin>>team;
        goals[team]++;    
    }

    int max = 0;
    for(const auto& pair : goals){
        if(pair.second > max){
            max = pair.second;
            winner = pair.first;
        }
    }

    cout << winner << endl;
    return 0;
}
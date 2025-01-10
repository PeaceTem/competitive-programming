#include <bits/stdc++.h>


using namespace std;

int main(){
    int n; cin >> n; string name; vector<string> names; vector<int> attempts;
    while(n--){
        cin >> name;
        auto it = find(names.begin(), names.end(), name);
        if(it == names.end()){
            names.push_back(name);
            attempts.push_back(0);
            cout << "OK" << endl;
        } else {
            int index = distance(names.begin(), it);
            attempts[index]++;
            cout << name << attempts[index] << endl;
        }
    }
    return 0;
}
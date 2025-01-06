#include <iostream>
#include <string>

using namespace std;


int main(){
    int t, n, m, count, words;
    string s, tp, tp1;

    cin >> tp;
    t = stoi(tp);

    for(int i = 0; i < t; i++){
        cin >> tp >> tp1;
        n = stoi(tp);
        m = stoi(tp1);

        count = 0;
        words = 0;
        for(int j = 0; j < n; j++){
            cin >> s;
            count += s.length();
            // cout << "Count is now: " << count << endl;

            if(count <= m){
                words += 1;
            }
        }

        cout << words << endl;

    }

    return 0;
}
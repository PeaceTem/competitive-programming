#include <iostream>
#include <string>
#include <vector>
#include <numeric>


using namespace std;

// learn how to reference an array in c++

int main(){
    string T, n, w;

    cin >> T;
    int test_cases {stoi(T)};
    for (int i = 0; i < test_cases; i++){
        cin >> n >> w;
        int len_arr {stoi(n)};
        int max_val {stoi(w)};
        vector<int> sequence(len_arr);



        for (int j = 0; j < len_arr; ++j) {
            cin >> sequence[j];
        }

        bool done = false;
        unsigned int op = 0;
        unsigned int total = 0;

        for(int i = len_arr - 1; i > -1; i--){
            if(sequence[i] == sequence[i - 1] && sequence[i] != max_val){
                total = i * max_val + max_val - 1;
                op = i;

                break;
            }
            // else if(sequence[i] == sequence[i - 1]){
            //     continue;
            // }
        }

        if(op > 0 && op < len_arr - 1){
            total = total + accumulate(sequence.begin() + op + 1, sequence.end(), 0);
        } else if(op == 0){
            total = accumulate(sequence.begin(), sequence.end(), 0);
        }

        if(op > 1 && max_val == sequence[0]) op--;

        cout << total << " " << op << endl;
    }
}
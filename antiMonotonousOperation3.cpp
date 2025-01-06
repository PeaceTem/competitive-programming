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
        vector<int> sequence2 = sequence;
        int break_point = 0;
        // identify all break points and do both forward and back pass for each of them recursively
        // the final solution should be in a data structure that can hold all the possible solutions
        // and then return the maximum of them by separating the even and odd position in the string;
        // while (!done) {
        //     done = true;
        bool forward = true;

            // forward pass
            for(int i = 0; i < len_arr - 1; i++){
                if(sequence[i] == sequence[i + 1] && sequence[i] != max_val){
                    sequence[i] = max_val;

                    sequence[i + 1] = i + 1 < len_arr - 1 ? (sequence[i + 2] != max_val ? sequence[i - 2] : max_val - 1) : max_val - 1;
                    op++;

                }
            }

            // backward pass
            for(int i = len_arr - 1; i > - 1; i--){
                if(sequence[i] == sequence[i - 1] && sequence[i] != max_val){
                    sequence[i] = max_val;

                    sequence[i - 1] = i - 1 > 0 ? (sequence[i - 2] != max_val ? sequence[i - 2] : max_val - 1) : max_val - 1;
                    op++;

                }
            }

            if(op > 0){

            }

            // for(int i = 0; i < len_arr - 1; i++){
            //     if(sequence[i] == sequence[i+1] && sequence[i] != max_val){
            //         done = false;
            //     }
            // }
        // }
        cout << accumulate(sequence.begin(), sequence.end(), 0) << " " << op << endl;
    }
}
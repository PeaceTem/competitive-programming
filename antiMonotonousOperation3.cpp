#include <bits/stdc++.h>

using namespace std;

// learn how to reference an array in c++

/*  NEW SOLUTION
use dynamic programming
start from 0 -> n, store the cummulative sum and operation of the part that was optimized;
check if you can optimize both left and right at the same time. ..., 3, 1, 1, 2, ...
TO

..., 3, 3, 2, 2, ... and continue optimizing both ways and choose the solution with the highest total.
-1 , 0, 1 as indicator
return type (index[1,1] will be 1 instead of 0, [-1, 0, 1] direction, sum, operations)
*/


int forward_pass(vector<int> *arr, int *max_val){
    // forward pass
    for(int i = 0; i < arr.size() - 1; i++){
        if(arr[i] == arr[i + 1] && arr[i] != max_val){
            arr[i] = max_val;

            arr[i + 1] = i + 1 < len_arr - 1 ? (arr[i + 2] != max_val ? arr[i - 2] : max_val - 1) : max_val - 1;
            op++;

        }
    }
    return 0;
}



int backward_pass(vector<int> *arr, int *max_val){
    // backward pass
    for(int i = arr.size() - 1; i > - 1; i--){
        if(arr[i] == arr[i - 1] && arr[i] != max_val){
            arr[i] = max_val;

            arr[i - 1] = i - 1 > 0 ? (arr[i - 2] != max_val ? arr[i - 2] : max_val - 1) : max_val - 1;
            op++;

        }
    }
    return 0;
}

int total_pos(vector<int> *arr, int *start, int *end){
    int total = 0;
    for(int i = start; i<= end; i++){
        total += arr[i];
    }
    return total;
}


int main(){
    int T, len_arr, max_val;

    cin >> T;
    while(T--){
        cin >> len_arr >> max_val;
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

            

            if(op > 0){

            }
        cout << accumulate(sequence.begin(), sequence.end(), 0) << " " << op << endl;
    }
}
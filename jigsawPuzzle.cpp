#include <bits/stdc++.h>

using namespace std;

int total_num_squares(short &squares){
    if(squares == 1) return 1;
    short new_squares = squares - 2;
    return squares * 4 - 4 + total_num_squares(new_squares);
}


int main()
{
    short t;
    cin >> t;
    while(t--)
    {
        short days;
        cin >> days;
        vector<short> a(days);

        for(short i = 0; i < days; i++){
            cin >> a[i];
        }

        short num_squares = 1;
        int curr_pieces = 0;
        short happy_days = 0;
        for(short& pieces: a){
            curr_pieces = curr_pieces + pieces;
            if(curr_pieces == total_num_squares(num_squares)){
                happy_days++;
            } 
            while(curr_pieces > total_num_squares(num_squares)){
                num_squares = num_squares + 2;
                if(curr_pieces == total_num_squares(num_squares)) happy_days++;
            }

        }

        cout << happy_days << endl;

    }

    return 0;
}
#include <bits/stdc++.h>

using namespace std;




int main()
{
    short t;
    cin >> t;
    while(t--)
    {
        int n, m;

        cin >> n >> m;


        // Populate the grid with sequential numbers
        // vector<vector<int>> grid(n, vector<int>(m));
        int grid[n][m];
        int count = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                grid[i][j] = count; // Sequential values
                count++;
            }
        }

        long mex = 0; int max = 0; bool inc = false;


        for(int i = 0; i < n; i++) {
            max = 0;
            inc = false;
            for(int j = 0; j < m; j++) {
                if(max < grid[i][j]){
                    mex = mex + max;
                    inc = false;
                    break;
                } else {
                    inc = true;
                    max++;
                }
            }
            if (inc) mex = max + mex;

        }

        for(int i = 0; i < m; i++) {
            max = 0;
            inc = true;
            for(int j = 0; j < n; j++) {
                if(max < grid[j][i]){
                    mex = mex + max;
                    inc = false;
                    break;
                } else {
                    inc = true;
                    max++;
                } 

                
            }
            if(inc) mex = max + mex;
            

        }
        cout << mex << endl;


        }


    return 0;
}
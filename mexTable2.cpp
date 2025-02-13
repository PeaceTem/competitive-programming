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
        int mex = n > m ? 1 + n : 1 + m;
        
        cout << mex << endl;
        }


    return 0;
}
// capacity = 10; get the maximum value from the list of weight and values

#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> vec = {{2,3}, {4,5}, {1,5}, {2,3}, {5,2}};

std::vector<std::vector<int>> arr(vec.size() +1, std::vector<int>(11, 0));
int knapsack(int n, int c){
    int result;
    if(arr[n+1][c] != 0) return arr[n+1][c];
    if(n==-1 || c==0) result = 0;
    else if(vec[n].first > c) result = knapsack(n-1, c);
    else {
        int tmp1 = knapsack(n-1, c);
        int tmp2 = vec[n].second + knapsack(n-1, c - vec[n].first);
        result = max(tmp1, tmp2);
    }
    arr[n+1][c] = result;
    return result;
}

int main(){
    int result = knapsack(vec.size() - 1, 10);
    cout << result << '\n';
}
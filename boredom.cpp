#include <bits/stdc++.h>


using namespace std;


long long result; unordered_map<long long, long long> freq_map; unordered_map<long long, long long> dp;

long long f(long long i){
    if(i == 0) return 0;

    if(i == 1) return freq_map.count(1) ? freq_map.at(1) : 0;


    if(dp.count(i)){
        return dp.at(i);
    }
    
    result = max(f(i - 1), f(i - 2) + (freq_map.count(i) ? freq_map.at(i) : 0) * i);
    dp[i] = result;
    return result;
}

int main(){
    int n; cin >> n; long long num; long long max = 0;

    for(int j = 0; j < n; j++){
        cin >> num; freq_map[num]++; if(num > max) max = num;
    }

    cout << f(max) << endl;

    return 0;
}
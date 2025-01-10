#include <bits/stdc++.h>


using namespace std;


unordered_map<int, int> freq_map; int count_i;

int f(int i){
    count_i = freq_map.count(i) ? freq_map.at(i) : 0;
    if(i == 0) return 0;
    if(i == 1) return count_i;
    return max(f(i - 1), f(i - 2) + count_i * i);
}

int main(){
    int n; cin >> n; int num; int max = 0; 

    for(int j = 0; j < n; j++){
        cin >> num; freq_map[num]++; if(num > max) max = num;
    }
    cout << f(max) << endl;

    return 0;
}
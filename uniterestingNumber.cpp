#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s; cin >> s; int twos=0, threes=0, sum=0;
    for(char i : s){
        if(i == '2') twos++;
        else if(i == '3') threes++;

        sum += i - '0';
    }
    // cout << "Twos: " << twos << " Threes: " << threes << " Sum: " << sum << '\n';
    for(int i=0; i<min(10, twos+1); i++){
        for(int j=0; j<min(10, threes+1); j++){
            if((sum + 2*i + 6*j) % 9 == 0){
                cout << "YES" << '\n';
                return;
            }
        }
    }

    cout << "NO" << '\n';
}
int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);
	int t; std::cin >> t; while (t--) solve(); return 0;
}
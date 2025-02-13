#include <bits/stdc++.h>

using namespace std;

void solve() {
	string n; std::cin >> n;
    vector<int> c; int cur, elem, tmp;
    for(char i : n) c.push_back(i - '0');

    for(int i=0; i<c.size(); i++){
        cur = 0; elem = i;
        for(int j=i; j<c.size() && j<=(i+ 9 - c[i]); j++){
            if(c[j] - c[i] - j + i > cur) elem = j, cur = c[j] - c[i] - j + i;
        }

        if(elem != i){
            tmp = c[elem];
            c.erase(c.begin() + elem);
            c.insert(c.begin() + i, tmp -1 * (elem - i));
        } 
    }

    for(int i : c) std::cout << i;
    cout << '\n';

}
int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);
	int t; std::cin >> t; while (t--) solve(); return 0;
}
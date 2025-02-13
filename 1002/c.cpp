#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin>>n;
    vector<int> arr(n,numeric_limits<int>::max()); int x; set<int> a, b, c;
    int arr[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) cin>>arr[i][j];
    }

    for(int i=n-1; i>=0;i--){
        for(int j=0; j<n; j++){
            if(arr[i][j] == 1) a.insert(j);
        }
        if(a.size() > 0){
            // Compute set difference (A - B)
            std::set_difference(a.begin(), a.end(),
                b.begin(), b.end(),
                std::back_inserter(c));
            if(c.size())

            b = a;
            a.clear();
        } else cout << n-i << '\n';
    }

    int count = 0; bool found = false; vector<int> rem;
    for(int i=n-1; i>=0; i--){
        if(arr[i] > 1){
            count++;
            cout << count << '\n';
            found =true;
            break;
        }
        count++;
    }
    if(!found) cout << count << '\n';
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);
	int t; std::cin >> t; while (t--) solve(); return 0;
}
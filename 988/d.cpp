#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,m,L; cin>>n>>m>>L;
    vector<pair<int, int>> h(n);
    for(int i=0;i<n;i++){
        int x,y; cin>>x>>y;
        h[i] = {x,y};
    }


    vector<pair<int, int>> p(m);
    for(int i=0;i<m;i++){
        int x,y; cin>>x>>y;
        p[i] = {x,y};
    }
    
    sort(p.begin(), p.end(), [&](const pair<int, int>& a, const pair<int, int>& b){
        return a.second > b.second;
    });



    int j = 1, c=0;
    vector<bool> used(m, false);
    for(auto& pp : h){
        if(pp.first == 1 || pp.second == L){
            cout << -1 << '\n'; return;
        }
        int d = pp.second - pp.first + 1;
        if(d >= j){
            //find a new power up
            // int nd = d - j + 1;
            int l=0, r=p.size() - 1;
            for(int k=0;k<m;k++){
                if(used[k]) continue;
                if(p[k].first > pp.first) continue;
                j += p[k].second; c++;
                used[k] = true;
                if(j>d) break;
            }
            if(j<=d){
                cout << -1 << '\n'; return;
            }
        }


    }

    cout << c << '\n';
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);
	int t; std::cin >> t; while (t--) solve(); return 0;
}
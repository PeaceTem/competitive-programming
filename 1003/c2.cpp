#include <bits/stdc++.h>
using namespace std;
vector<int> a, b, c;
bool found =false;

int bs(int l, int r){
    int target = 0;
    int left = 0, right = b.size()-1;
    while(left<=right){
        int  mid = left + (right-left)/2;
        if(b[mid] >= l && b[mid] <= r){
            target = b[mid];
            right = mid - 1;
        } else if(b[mid] < l){
            left = mid+1;
        } else {
            right = mid - 1;
        }
    }

    return target;
}

void solve() {
    a.clear(); b.clear(); c.clear();
    int n,m,x; cin>>n>>m;
    for(int i=0; i<n;i++){
        cin>>x; a.push_back(x);
    }
    for(int i=0; i<m;i++){
        cin>>x; b.push_back(x);
    }

    sort(b.begin(), b.end());
    // for(int i=0; i<m;i++) cout << b[i] << ' ';
    // cout << '\n';
    // run the bs for (1-5)

    if(b[0] < 2*a[0]) c.push_back(b[0]-a[0]);
    else c.push_back(a[0]);
    found = true;
    for(int i=1; i<n;i++){
        // check if l > r;
        int l=c[i-1]+a[i]; int r = 2*a[i];
        if(l>r){
            if(c[i-1] <= a[i]){
                c.push_back(a[i]); continue;
            }
            found = false; break;
        }
        int ans = bs(l, r);
        // cout << "Ai: " << a[i] <<  " l: " << l << " r: " << r << " ans: " << ans << '\n';
        if(ans == 0){
            if(c[i-1] <= a[i]){
                c.push_back(a[i]); continue;
            }
            found = false; break;
        }

        c.push_back(ans-a[i]);
    }
    
    if(found) cout << "YES" << '\n';
    else cout<<"NO"<<'\n';
}


int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);
	int t; std::cin >> t; while (t--) solve(); return 0;
}
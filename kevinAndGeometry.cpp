#include <bits/stdc++.h>
using namespace std;

// sort the array
vector<int> tp(vector<int>& v, int n){
    sort(v.begin(), v.end());
    for(int i=1;i<v.size();i++){
        if(n>abs(v[i] - v[i-1])) return vector<int>{v[i], v[i-1]};
    }
    // int l=0, r=v.size()-1;
    // while(l<=r){
    //     if(l==r){
    //         if(n>abs(v[l] - v[l-1])) return vector<int>{v[l], v[l-1]};
    //         else if(n>abs(v[r] - v[r+1])) return vector<int>{v[r], v[r+1]};
    //         else return vector<int>();
    //     } else{
    //         if(n>abs(v[r] - v[l])) return vector<int>{v[l], v[r]};
    //     }

    //     l++; r--;
    // }

    return vector<int>();
}

void solve(){
    int n; cin>>n; vector<int> a;
    map<int, int, greater<int>> b; int x;

    for(int i=0; i<n; i++){
        cin>>x;
        b[x]++;
    }
    bool found =false; vector<int> ans, tp_ans;int count;
    for(auto& pair : b){
        if(!found && pair.second >=2){
            found = true;
            if(pair.second >= 4){
                for(int i=0;i<4;i++) ans.push_back(pair.first);
                break;
            } else {
                ans.push_back(pair.first); ans.push_back(pair.first); pair.second -=2;
            }
        }
        if(ans.size()>0) break;
    }


    if(!found){
        cout << -1 << '\n';
        return;
    }
    if(ans.size() != 4){

        
        for(auto& pair : b){
            if(pair.second > 1){
                ans.push_back(pair.first); ans.push_back(pair.first); break;
            }
            if(pair.second>0){
                a.push_back(pair.first); pair.second--;
            }
        } 
        // cout << "A: ";
        // for(int num : a) cout << num << ' ';
        // cout << '\n';   
        if(ans.size() < 4) tp_ans = tp(a, ans.front()*2);

        if(tp_ans.size()>0){
            for(int k : tp_ans) ans.push_back(k);
        }
    }

    if(ans.size() == 4){
        for(int i=0; i<4;i++) cout << ans[i] << ' ';
        cout << '\n';
    } else cout << -1 << '\n';


}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t-->0) solve(); return 0;
}
#include <bits/stdc++.h>
using namespace std;




string sxor(const string &i, const string &j){
    string s = "";
    for(int k=0; k<i.length();k++){
        if(i[k]==j[k]) s.push_back('0');
        else s.push_back('1');
    }
    return s;
}

bool sgt(const string &l, const string &r){
    int l_len = l.length(), r_len = r.length();
    if(l_len > r_len) return true;
    else if(r_len>l_len) return false;

    for(int i=0; i<l_len;i++){
        if(l[i] != r[i]){
            if(l[i] == '1') return true;
            else return false;
        }
    }

    return true;
}



void solve(){
    string n; cin>>n; int l = n.length(), m=-1; vector<int> zeroes,ones; // try ordered set;
    for(int i=0;i<l; i++){
        if(n[i] == '0'){
            m=i; break;
        }
    }

    if(m==-1){
        cout << l << ' ' << l << ' ' << 1 << ' ' << l <<'\n'; return;
    }
    int s_len = l-m, l1,r1; string temp = n.substr(m,s_len);
    for(int i=0; i<m;i++){
        string tt = sxor(n.substr(i,s_len), n.substr(m,s_len));
        if(sgt(tt, temp)){
            l1=i+1,r1=i+s_len;
            temp = tt;
        }
    }
    cout << 1 << ' ' << l << ' ' << l1 << ' ' << r1 << '\n'; 
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t-->0) solve(); return 0;
}
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
    string n; cin>>n; int l = n.length(); vector<int> zeroes,ones; // try ordered set;
    for(int i=0;i<l; i++){
        if(n[i] == '0') zeroes.push_back(i+1);
        else ones.push_back(i+1);
    }
    if(zeroes.size()==0){
        cout << l << ' ' << l << ' ' << 1 << ' ' << l <<'\n'; return;
    }
    // iterate over the string from the position of the first zero
    // the lenght of the substring to be taken is the interval between the first 1 and all other subsequent 1s;

    string greatest = "", temp; int s_len; int l1,r1,l2,r2;
    for(int i : ones){// the interval does not necessarily have to be the first 1 - n;
        // it can b any 1 - the current 1;
        s_len = i - ones.front() + 1;
        // add s_len from the first 0 to greatest
        // diff = s_len - greatest.length()
        // add the next diff strings
        if(1+l - zeroes.front() < s_len) break;
        int diff = s_len - greatest.length();
        // greatest = greatest + n.substr(greatest.length(), diff);
        greatest = greatest + n.substr(zeroes.front(), diff);
        // try using the lenght of the zeroes e.g first to second zero;

        // xor 
        for(int i=0; i<=l-s_len; i++){
            temp = sxor(n.substr(i,s_len), n.substr(zeroes.front()-1, s_len));
            if(sgt(temp, greatest)){
                greatest = temp;
                l1 = i+1, r1 = i+s_len, l2=zeroes.front(), r2 = zeroes.front()+s_len-1;
            }
        }
    }

    cout << l1 << ' ' << r1 << ' ' << l2 << ' ' << r2 << '\n';
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t-->0) solve(); return 0;
}
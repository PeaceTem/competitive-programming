#include <bits/stdc++.h>
using namespace std;
// use epsilon for checking for equality;
// lower bound, median, higher bound;


pair<int, int> findTools(double a, double b, int c){
    // don't forget mean can also be a negative number
    double a_a = a; 
    while((abs(a-round(a)) > 1e-9)){
        // if even count is needed; or if odd count is needed;
        a=a_a;
        a *=c;
        c+=2;
    }
    if(c&1) c = max(c, 3);
    else c = max(c, 4);
    return make_pair((int) ceil(a_a*c), c);
}


void solve(){
    double a,b; cin>>a>>b; int count;
    vector<int> l; int total; bool e = floor(b) != b;
    if(a==b){
        cout << 1 << '\n' << a << '\n';
        return;
    }
    if(e){
        l.push_back((int) floor(b)), l.push_back((int) ceil(b)); count = 2;
    } else {
        l.push_back((int) b); count = 1;
    }

    // after getting the total needed;
    // add front and back d times;
    // if the _total is less: add to the largest;
    // else if the _total is greater: remove from the least; 

    pair<int, int> k = findTools(a,b,count); int sum;
    sum = accumulate(l.begin(), l.end(), 0);
    k.second = e ? k.second - 2: k.second -1;
    int d = k.second / 2;
    int left = l.front(), right = l.back();

    for(int i=1;i<=d;i++){
        l.push_back(left), l.push_back(right);
    }

    sum = accumulate(l.begin(), l.end(),0);

    if(sum > k.first){
        if(e) l[2] -= abs(sum-k.first);
        else l[1] -=abs(sum-k.first);
    } else if(sum < k.first){
        if(e) l[3] += abs(sum-k.first);
        else l[2] += abs(sum-k.first);
    }
    
    // cout << l.size() << ' ' << k.first << ' ' << k.second << '\n';
    cout << l.size() << '\n';

    for(int i=0;i<l.size();i++) cout << l[i] << ' ';
    cout << '\n';
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    solve(); return 0;
}
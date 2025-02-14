#include <bits/stdc++.h>
using namespace std;

int t_search(const vector<int>& v, int x){
    int l = 0, r = v.size() - 1, m1, m2;
    while(l<=r){
        if(v[l]==x) return l;
        if(v[r]==x) return r;
        m1 = l + (r-l)/2;
        m2 = r - (r-l)/2;
        if(v[m1]==x) return m1;
        else if(v[m1] > x) r = m1-1;
        else if(v[m1]<x) l=m1+1;
        else if(v[m2]==x) return m2;
        else if(v[m2]<x) l=m2+1;
        else if(v[m2]>x) r=m2-1;
    }

    return -1;
}

int main(){
    vector<int> arr = {1,2,3,4,5,6,7,8,9,10,12,23,45,47,49,52,54,56,58,60,63,64,67,69,74,75,79,84,92,94,96,98,99};
    cout << t_search(arr, 81) << endl;
    return 0;
}
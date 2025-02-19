#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    int l=0, res=0;
    for(int i=100; i<1000; i++){
        for(int j=100; j<1000;j++){
            res = i*j; int left=0,right=5;
            while(left<right){
                int rem1=(res/static_cast<int>(pow(10,left)))%10;
                int rem2=(res/static_cast<int>(pow(10,right)))%10;
                if(rem1 != rem2) break;
                left++; right--;
                if(left>=right) l = max(l,res);
            }
        }
    }
    cout << l;
}
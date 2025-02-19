#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


int main(){
    int sum=50*101, sum_of_squares=0; 
    for(int i=1;i<101;i++){
        sum_of_squares += i*i;
    }
    cout<<sum*sum - sum_of_squares<<endl;
}
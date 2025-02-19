#include <bits/stdc++.h>

using namespace std;

vector<bool> sieve(int n){
    vector<bool> primes(n+1, true); primes[0]=primes[1]=false;
    for(int i=2;i*i<n;i++){
        if(primes[i]){
            for(int j=i*i;j<n;j+=i) primes[j]=false;
        }
    }

    return primes;
}

int main(){
    vector<bool> PRIMES = sieve(200000);
    vector<int> st; st.push_back(2);
    for(int i=3;i<200000;i+=2){
        if(PRIMES[i]) st.push_back(i);
    }

    cout << st.size() << '\n';
    cout << st[10000] << '\n';
}
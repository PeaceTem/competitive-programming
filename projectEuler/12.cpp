#include <bits/stdc++.h>

using namespace std;

vector<bool> sieve(int n){
    vector<bool> primes(n+1, true);
    primes[0]=primes[1]=false;

    for(int i=2;i*i<=n;i++){
        if(primes[i]){
            for(int j=i*i;j<=n;j++) primes[j]=false;
        }
    }
    return primes;
}

int main(){
    vector<bool> primes = sieve(100000);
    vector<int> primes_list;
    
    for(int i=0;i<primes.size();i++){
        if(primes[i]) primes_list.push_back(i);
    }

    long long a = 2;
    bool done = false;
    long long nums;
    long long term,_term;
    vector<int> nums_list,__nums_list;
    int value;
    vector<int> factors;
    while(!done){
        a++; nums=0;
        term = (a*(a+1LL))/2LL; 
        _term = term;
        for(int i=0;primes_list[i]*primes_list[i]<=term; i++){
            factors.clear();
            while(term%primes_list[i]==0){
                nums++; term/=primes_list[i];
                factors.push_back(primes_list[i]);
            }
            nums_list.push_back(nums++);
            nums=0;
        }
        value = accumulate(nums_list.begin(),nums_list.end(), 1, multiplies<int>());
        done = value>4 ? true : false;
        __nums_list = nums_list;
        nums_list.clear();
    }

    cout << value << '\n';
    cout << a << ' ' << _term << '\n';

    for(int num : factors){
        cout << num << ' ';
    }
    cout << '\n';
}
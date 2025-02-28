#include <bits/stdc++.h>

using namespace std;

vector<bool> sieve(int n){
    vector<bool> primes(n+1, true);
    primes[0]=primes[1]=false;

    for(int i=2;i*i<=n;i++){
        if(primes[i]){
            for(int j=i*i;j<=n;j+=i) primes[j]=false;
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

    for(int i=0; i<primes_list.size(); i++) cout << primes_list[i] << ' ';
    cout << '\n';
    long long a = 2, nums, term, _term;
    bool done = false;
    vector<int> nums_list,__nums_list, factors;
    int value;

    while(!done){
        a++; nums=0;
        _term = term = (a*(a+1LL))/2LL; 
        cout << a << ' ' << term << '\n';
        factors.clear();
        for(int i=0; i< primes_list.size() && primes_list[i]*primes_list[i]<=term; i++){
            if(term <=1) break;
            nums=0;
            while(term%primes_list[i]==0 && term > 1){
                nums++; term/=primes_list[i];
                factors.push_back(primes_list[i]); // use map here;
            }
            nums_list.push_back(++nums);
        }
        if(term >1){
            nums_list.push_back(2);
        }
        for(int num : factors) cout << num << ' ';
        cout << '\n';
        // value = accumulate(nums_list.begin(),nums_list.end(), 1, multiplies<int>());
        value = 1;
        for(int num : nums_list){
            value *= num;
        }
        done = value>500 ? true : false;
        __nums_list = nums_list;
        nums_list.clear();
    }

    cout << value << ' ' << _term << '\n';
}
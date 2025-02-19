#include <bits/stdc++.h>

using namespace std;

int manhattan_distance(vector<int> &m){
    int sum =0;
    for(int i=0; i<m.size();i++){
        for(int j=0;j<m.size();j++){
            sum += abs(m[i]-m[j]);
        }
    }

    return sum;
}


int main(){
    string number = "7316717653133062491922511967442657474235534919493496983520312774506326239578318016984801869478851843858615607891129494954595017379583319528532088055111254069874715852386305071569329096329522744304355766896648950445244523161731856403098711121722383113622298934233803081353362766142828064444866452387493035890729629049156044077239071381051585930796086670172427121883998797908792274921901699720888093776657273330010533678812202354218097512545405947522435258490771167055601360483958644670632441572215539753697817977846174064955149290862569321978468622482839722413756570560574902614079729686524145351004748216637048440319989000889524345065854122758866688116427171479924442928230863465674813919123162824586178664583591245665294765456828489128831426076900422421902267105562632111110937054421750694165896040807198403850962455444362981230987879927244284909188845801561660979191338754992005240636899125607176060588611646710940507754100225698315520005593572972571636269561882670428252483600823257530420752963450";
    vector<int> seg;
    vector<pair<int, pair<int,vector<int>>>> ds;
    for(int i=0;i<number.size();i++){
        if(number[i] != '0'){
            if(seg.size() == 13) seg.erase(seg.begin());

            seg.push_back(number[i] - '0');
            if(seg.size() == 13){
                int s = accumulate(seg.begin(), seg.end(), 0);
                int v = manhattan_distance(seg);
                ds.emplace_back(make_pair(s, make_pair(v, seg)));
            }
        } else seg.clear();
    }

    sort(ds.begin(), ds.end(), [&](const pair<int, pair<int, vector<int>>>& a, const pair<int, pair<int, vector<int>>> &b){
        if(a.first != b.first) return a.first > b.first;

        return a.second.first < b.second.first;
    });
    for(int j=0;j<5;j++){

        cout << "Sum: " << ds[j].first << '\n';
        cout << "Manhattan Distance: " << ds[j].second.first << '\n';

        for(int i = 0; i<ds[j].second.second.size(); i++) cout << ds[j].second.second[i] << ' ';
        cout << '\n';

        long long sum=1;
        for(int i = 0; i<ds[j].second.second.size(); i++) sum *= ds[j].second.second[i];
        cout << sum << '\n';
    }
}

// My theorem is not correct
// I tried to get the 13 adjacent digits number that have the greatest product and the value of the product.

// The method that I used
// I tried to get the sum of each 13 adjacent digits that don't include 0;
// I calculated the manhattan distance too.
// So, this is my theory:
// the sequence of digits with the greatest sum will have the greatest column.
// If there are more than 1 sequence, pick the sequence with the least manhattan distance.
// This assumption is not correct. It turns out that the second number is the largest.

// Although, the theorem is incorrect, I'm very happy I could come up with something like that.

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>
#define MOD 1000000007
#define INF 1000000000000000000
#define MAXN 1000005
// #define int long long
#define ld long double
#define eps 1e-9
#define bit(n, b) (((n) >> (b)) & 1)
#define bitcount(n) __builtin_popcountll(n)
#define gcd(a, b) __gcd(a, b)
// #define fileIO freopen("input.txt", "r", stdin); freopen("output.txt", "w


// #include <iostream>

class RotatingInt {
private:
    int value;
    static constexpr int MODULO = 12; // The numbers wrap within [0, 11]

public:
    RotatingInt(int v = 0) : value((v % MODULO + MODULO) % MODULO) {}
    int getValue(){
        return value;
    }
    RotatingInt operator+(int rhs) const {
        return RotatingInt(value + rhs);
    }
    
    RotatingInt operator-(int rhs) const {
        return RotatingInt(value - rhs);
    }
    
    RotatingInt& operator+=(int rhs) {
        value = (value + rhs) % MODULO;
        if (value < 0) value += MODULO;
        return *this;
    }
    
    RotatingInt& operator-=(int rhs) {
        value = (value - rhs) % MODULO;
        if (value < 0) value += MODULO;
        return *this;
    }
    
    bool operator==(const RotatingInt& rhs) const {
        return value == rhs.value;
    }
    friend std::ostream& operator<<(std::ostream& os, const RotatingInt& ri) {
        os << ri.value;
        return os;
    }
};

// int main() {
//     RotatingInt a(10);
//     std::cout << "Initial: " << a << "\n";
    
//     a = a + 3;  // Should wrap around to 1
//     std::cout << "After +3: " << a << "\n";
    
//     a = a - 5;  // Should wrap around to 8
//     std::cout << "After -5: " << a << "\n";
    
//     a += 10;    // Should wrap to 6
//     std::cout << "After +=10: " << a << "\n";
    
//     a -= 20;    // Should wrap to 10
//     std::cout << "After -=20: " << a << "\n";
    
//     return 0;
// }



int getFeb(int year){
    if(year % 4 == 0){
        if(year % 100 == 0){
            if(year % 400 == 0) return true;
            else return false;
        }
        return true;
    }
    return false;
}

void solve(){
    int days = 0;
    int year = 1901;
    vi months = {31,(getFeb(year)? 29 : 28),31,30,31,30,31,31,30,31,30,31};
    RotatingInt month_id(0); int no_of_sun(0);
    while(year <=2000){
        if(year == 2000 and month_id==11) break;
        if(month_id==1) days += (getFeb(year) ? 29 : 28);
        else days += months[month_id.getValue()];
        if((days+1)%7==0) no_of_sun++;
        month_id+=1;
        if(month_id==11) year++;
    }
    cout << no_of_sun << endl;
    cout << "Done!";
}


int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);
    solve(); return 0;
}
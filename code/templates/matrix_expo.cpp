
// Matrix Exponentiation Template (Hard ProfChi problem)
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 5;

vector<vector<ll>> mul(const vector<vector<ll>> &A, const vector<vector<ll>> &B, ll mod) {
    vector<vector<ll>> C(N, vector<ll>(N, 0));
    for(int i = 0; i < N; i++)
        for(int k = 0; k < N; k++)
            if(A[i][k])
                for(int j = 0; j < N; j++)
                    C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % mod;
    return C;
}

vector<vector<ll>> power(vector<vector<ll>> A, ll e, ll mod) {
    vector<vector<ll>> R(N, vector<ll>(N, 0));
    for(int i = 0; i < N; i++) R[i][i] = 1;

    while(e) {
        if(e & 1) R = mul(R, A, mod);
        A = mul(A, A, mod);
        e >>= 1;
    }
    return R;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; 
    cin >> t;
    while(t--) {
        ll n, k, m;
        cin >> n >> k >> m;
        vector<ll> a(3);
        for(int i = 0; i < n; i++) cin >> a[i];

        vector<vector<ll>> T(5, vector<ll>(5, 0));

        // rows defining the updates
        T[0] = {1,0,0,1,0}; // a0' = a0 + s
        T[1] = {1,1,0,1,0}; // a1' = a0 + a1 + s
        T[2] = {1,1,1,1,0}; // a2' = sum + s
        T[3] = {0,0,0,1,1}; // s' = s + 1
        T[4] = {0,0,0,0,1}; // constant

        vector<vector<ll>> Tk = power(T, k, m);

        vector<ll> X = {a[0] % m, a[1] % m, a[2] % m, 1, 1};

        vector<ll> R(5, 0);
        for(int i = 0; i < 5; i++)
            for(int j = 0; j < 5; j++)
                R[i] = (R[i] + Tk[i][j] * X[j]) % m;

        for(int i = 0; i < n; i++)
            cout << R[i] << " ";
        cout << "\n";
    }
}



//---------------------------------------------
//
// Matrix Exponentiation Template
//---------------------------------------------

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Matrix {
    int n; // dimension n × n
    vector<vector<ll>> a;

    Matrix(int n, bool ident = false) : n(n), a(n, vector<ll>(n, 0)) {
        if(ident){
            for(int i = 0; i < n; i++) a[i][i] = 1;
        }
    }

    Matrix operator*(const Matrix& o) const {
        Matrix r(n);
        for(int i = 0; i < n; i++){
            for(int k = 0; k < n; k++){
                if(a[i][k] == 0) continue;      // small optimization
                for(int j = 0; j < n; j++){
                    r.a[i][j] = (r.a[i][j] + a[i][k] * o.a[k][j]);
                    // add modulo here if needed:
                    // r.a[i][j] %= MOD;
                }
            }
        }
        return r;
    }
};

Matrix mat_pow(Matrix base, long long exp){
    Matrix res(base.n, true); // identity
    while(exp > 0){
        if(exp & 1) res = res * base;
        base = base * base;
        exp >>= 1;
    }
    return res;
}

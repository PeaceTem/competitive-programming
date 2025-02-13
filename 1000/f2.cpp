#include <bits/stdc++.h>
 
constexpr int Mod = 998244353;
inline int add (int x, int y) { x += y; return x >= Mod ? x - Mod : x; }
inline int sub (int x, int y) { x -= y; return x < 0 ? x + Mod : x; }
inline int mul (int x, int y) { return 1LL * x * y % Mod; }
inline void updAdd (int &x, int y) { x = add(x, y); }
inline void updSub (int &x, int y) { x = sub(x, y); }
inline void updMul (int &x, int y) { x = mul(x, y); }
int exp (int x, int p) { int r = 1; for (; p; p >>= 1, updMul(x, x)) if (p & 1) updMul(r, x); return r; }
int inverse (int x) { return exp(x, Mod - 2); }
 
constexpr int N = 3e5 + 10;
 
int n;
std::array <int, 2> rng[N];
char str[N << 1];
 
int id[N], who[N << 1];
 
int fac[N << 1], inv[N << 1], inf[N << 1];
int cat[N];
 
int head[N], cnt;
std::array <int, 2> e[N];
 
int fa[N], dep[N], siz[N], son[N];
int dfn[N], idfn[N], top[N], cd;
 
int f[N];
int ans;
 
inline int C (int n, int m) {
	return mul(fac[n], mul(inf[m], inf[n - m]));
}
 
struct Fenwick {
	int n, s[N];
	void prework (int m) { n = m; std::memset(s + 1, 0, n << 2); }
	inline int lowbit (int x) { return x & (-x); }
	void update (int x, int v) { if (x) { for (; x <= n; x += lowbit(x)) s[x] += v; } }
	void update (int l, int r, int v) { update(l, v); update(r + 1, -v); }
	int query (int x) { int r = 0; for (; x; x -= lowbit(x)) r += s[x]; return r; }
	int query (int l, int r) { return query(r) - query(l - 1); }
	int BS (int v) {
		int r = 0, cs = 0;
		for (int i = 19; ~i; -- i) if (r + (1 << i) <= n && cs + s[r + (1 << i)] < v) { r += (1 << i); cs += s[r]; }
		return r + 1;
	}
} f1, f2;
 
void addE (int x, int y) {
	e[++ cnt] = {y, head[x]};
	head[x] = cnt;
}
 
void dfs1 (int x, int par) {
	fa[x] = par;
	dep[x] = dep[fa[x]] + 1;
	siz[x] = 1, son[x] = 0;
	
	for (int i = head[x]; i; i = e[i][1]) {
		int y = e[i][0];
		dfs1(y, x);
		siz[x] += siz[y];
		if (siz[y] > siz[son[x]]) {
			son[x] = y;
		}
	}
}
 
void dfs2 (int x, int tp) {
	dfn[x] = ++ cd;
	idfn[cd] = x;
	top[x] = tp;
	
	if (!son[x]) {
		return;
	}
	
	dfs2(son[x], tp);
	for (int i = head[x]; i; i = e[i][1]) {
		int y = e[i][0];
		if (y != son[x]) {
			dfs2(y, y);
		}
	}
}
 
void Update (int x) {
	const int ox = x;
	const int m = f2.query(dfn[x]);
	
//	std::cerr << m << " " << cat[m] << "\n";
	updMul(ans, cat[(f[x] = m) / 2]);
	
	while (1) {
		if (!f1.query(dfn[top[x]], dfn[x])) {
			f2.update(dfn[top[x]], dfn[x] - (x == ox), -(m + 2));
		} else {
			const int y = idfn[f1.BS(f1.query(1, dfn[x]))];
			f2.update(dfn[y], dfn[x] - (x == ox), -(m + 2));
			
//			std::cerr << "INV " << y << " " << f[y] << " " << cat[f[y] / 2] << "\n";
			updMul(ans, inverse(cat[f[y] / 2]));
			f[y] -= (m + 2);
//			std::cerr << "MUL " << f[y] << " " << cat[f[y] / 2] << "\n";
			updMul(ans, cat[f[y] / 2]);
			
			break;
		}
		
		x = fa[top[x]];
	}
	
	f1.update(dfn[ox], 1);
}
 
void solve () {
	std::cin >> n;
	for (int i = 1; i <= n; ++ i) {
		int l, r;
		std::cin >> l >> r;
		rng[i] = {l, r};
		str[l] = '(';
		str[r] = 'r';
		who[r] = i;
	}
//	std::cin >> (str + 1);
	
	const int root = n + 1;
	std::vector <int> stk{root};
	
	cnt = 0;
	std::memset(head, 0, n + 5 << 2);
	for (int i = 1, c = 0; i <= 2 * n; ++ i) {
		if (str[i] == '(') {
			stk.push_back(++ c);
		} else {
			int x = stk.back();
			stk.pop_back();
			int f = stk.back();
			addE(f, x); 
			
			id[who[i]] = x;
		}
	}
	
	cd = 0;
	dfs1(root, 0);
	dfs2(root, root);
	
	f1.prework(n + 1);
	f2.prework(n + 1);
	f1.update(dfn[root], 1);
	
	for (int i = 1; i <= n; ++ i) {
		int l = rng[i][0], r = rng[i][1];
		f2.update(dfn[id[i]], dfn[id[i]], r - l - 1);
	}
	f2.update(dfn[n + 1], dfn[n + 1], 2 * n);
	
	ans = cat[n];
	f[root] = 2 * n;
	std::cout << ans << " ";
	for (int i = 1; i <= n; ++ i) {
		Update(id[i]);
		std::cout << ans << " \n"[i == n];
	}
//	assert(ans == 1);
}
 
int main () {
	
	std::ios::sync_with_stdio(0);
	std::cin.tie(nullptr);
	
	fac[0] = fac[1] = inv[1] = inf[0] = inf[1] = 1;
	for (int i = 2; i <= 600000; ++ i) {
		fac[i] = mul(fac[i - 1], i);
		inv[i] = sub(0, mul(inv[Mod % i], Mod / i));
		inf[i] = mul(inf[i - 1], inv[i]);
	}
	
	cat[0] = 1;
	for (int i = 1; i <= 300000; ++ i)
		cat[i] = mul(C(2 * i, i), inv[i + 1]);
	
	int t;
	std::cin >> t;
	while (t -- )
		solve();
	
	return 0;
}
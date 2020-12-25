#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define ss(x) (int) x.size()
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)
#define all(x) x.begin(), x.end()
#define ld long double

using namespace std;	

const int N = 311111;
const int P = 5000;
const int T = 1 << 19;

struct nod {
	ll best, sum, pref, suf;
	nod() {
		best = sum = pref = suf = 0;
	}
} t[T + T];


nod merge(const nod &a, const nod &b) {
	nod c;
	c.best = max({a.best, b.best, a.suf + b.pref});
	c.sum = a.sum + b.sum;
	c.pref = max(a.pref, a.sum + b.pref);
	c.suf = max(b.suf, b.sum + a.suf);
	return c;
}

void ustaw(int x, int k) {
	x += T;
	t[x].best = t[x].pref = t[x].suf = max(0, k);
	t[x].sum = k;
	
	for (x /= 2; x; x /= 2)
		t[x] = merge(t[2 * x], t[2 * x + 1]);
}	

int n, q, a[N], c[N];
vector <int> G[N], h, now;
bool heavy[N];
map <pair<int, int>, ll> maps;

void solve() {
	h.clear();
	maps.clear();
	scanf ("%d%d", &n, &q);
	rep(i, 1, n) scanf ("%d", a + i);
	rep(i, 1, n) scanf ("%d", c + i);
	rep(i, 1, n) G[i].clear();
	rep(i, 1, n) G[c[i]].pb(i);
	rep(i, 1, n) {
		heavy[i] = ss(G[i]) >= P;
		if (heavy[i]) h.pb(i);
	}
	for (auto x : h) {
		for (auto u : G[x])
			ustaw(u, a[u]);
		rep(i, 1, n) {
			if (heavy[i]) continue;
			for (auto u : G[i])
				ustaw(u, a[u]);
			maps[{x, i}] = maps[{x, i}] = t[1].best;
			for (auto u : G[i])
				ustaw(u, 0);
		}
		for (auto u : G[x])
			ustaw(u, 0);
	}
	while (q--) {
		int x, y;
		scanf ("%d%d", &x, &y);
		if (maps.find(mp(x, y)) != maps.end()) {
			printf ("%lld\n", maps[mp(x, y)]);			
			continue;
		}
		now.clear();
		merge(all(G[x]), all(G[y]), back_inserter(now));
		ll best = 0, sum = 0, opt = 0;
		for (auto u : now) {
			sum += a[u];
			best = max(best, sum - opt);
			opt = min(opt, sum);
		} 
		printf ("%lld\n", maps[{x, y}] = maps[{y, x}] = best);	
	}
}

int main() {
	int T;
	scanf ("%d", &T);
	while (T--)
		solve();
	
	return 0;
}

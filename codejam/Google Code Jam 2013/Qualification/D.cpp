/**
 * Large Input ?
 * Ain nobody got time foo that
 */

#include <iostream>
#include <sstream>
#include <utility>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <cmath>
#include <functional>
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <stdio.h>
#include <string.h>
using namespace std;

#define FOR(i,a,b)  for(int i=(a),_##i=(b);i<_##i;++i)
#define F(i,a)      FOR(i,0,a)
#define ALL(x)      x.begin(),x.end()
#define PB          push_back
#define MP          make_pair
#define S           size()
typedef long long   LL;

int K, N;
vector<int> type;

int createType(int x) {
	type.PB(x);
	return type.S-1;
}

class Keys {
public:
	vector<LL> v;
	Keys(){
		reset();	
	}
	void reset() {
		v = vector<LL> (8, 0);
	}
	void add(int i, LL x) {
		v[i] |= x;
	}
	void add(int it) {
		add(it/50, 1LL<<(it%50));
	}
	void add(Keys x) {
		F(i, 8) v[i] |= x.v[i];
	}

	void remove(int i, LL x){
		if(v[i] & x) v[i] ^= x;
	}
	void remove(int it) {
		LL aux = 1LL<<(it%50);
		if( v[it/50] & aux )
			v[it/50] ^= aux;
	}
	
	void remove(Keys x) {
		F(i, 8) v[i] ^= x.v[i];
	}

	pair<int, LL> getValidKey(Keys b) {
		F(i, 8) {
			LL x = v[i] & b.v[i];
			if(x) return MP( i, ((x-1)|x)^(x-1) );
		}
		return MP(-1, -1);
	}

	static Keys createFromVector(vector<int> a) {
		Keys ret;
		F(i, a.S) ret.add( createType(a[i]) );
		return ret;
	}
};
Keys keys;

vector<Keys> kindKeys;
void initKindKeys() {
	kindKeys = vector<Keys>(402);
	F(i, type.S) {
		kindKeys[ type[i] ].add( i );
	}
}
// END KEYS

vector<pair<int, Keys> > nodes;
bool vis[201], flag, memo[1<<21];
vector<int> sol;

void dfs(int cont, vector<int> rec, int mask) {
	if(flag) return;
	if(cont == 0) {
		sol = rec;
		flag = true;
		return;
	}
	rec.PB(0);
	F(i, N) {
		if(vis[i]) continue;
		pair<int, LL> x = keys.getValidKey(kindKeys[ nodes[i].first ]);
		if(x.first == -1) continue;
		keys.remove(x.first, x.second);
		vis[i] = true;
		keys.add(nodes[i].second);

		rec[rec.S-1] = i;
		dfs( cont-1, rec, mask);

		keys.add(x.first, x.second);
		vis[i] = false;
		keys.remove(nodes[i].second);
	}
}

void solveIni(int caso) {
	int n, x;
	scanf("%d %d", &K, &N);

	type.clear();
	nodes = vector<pair<int, Keys> > (N);
	keys.reset();

	F(i, K) {
		scanf("%d", &x);
		keys.add( createType(x) );
	}

	F(i, N) {
		scanf("%d %d", &x, &n);
		vector<int> aux(n);
		F(j, n) scanf("%d", &aux[j]);
		nodes[i].first = x;
		nodes[i].second = Keys::createFromVector(aux);
	}
	initKindKeys();

	sol.clear();
	flag = false;
	memset(vis, 0, sizeof(vis));
	dfs(N, sol, 0);

	if(sol.S) {
		printf("Case #%d:", caso);
		F(i, sol.S) {
			printf(" %d", sol[i]+1);
		}
		printf("\n");
	}
	else {
		cout<<"Case #"<<caso<<": IMPOSSIBLE"<< endl;
	}
}

int main(){
	// freopen("a.in.txt", "r", stdin);
	freopen("D-small-attempt1.in", "r", stdin);
	freopen("a.out.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	F(i, T){ solveIni(i+1); }
}

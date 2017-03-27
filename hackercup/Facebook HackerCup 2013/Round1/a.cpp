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

string solve() {
	unsigned long long n, ex, tot;
	int m, chs = 1;
	string s;
	cin >> s >> n;
	ex = m = s.S;
	tot = n;
	while(ex < tot) {
		tot -= ex;
		ex *= LL(m);
		if(ex < 0LL) break;
		chs++;
	}
	vector<int> v(chs, 0);
	string res(chs, s[0]);
	while(tot > 1) {
		ex = 1;
		int i = chs-1;
		while(i) {
			if(tot <= ex*LL(m)) break;
			ex *= LL(m);
			i--;
		}
		tot -= ex;
		v[i]++;
	}
	F(i, v.S) {
		res[i] = s[v[i]];
	}
	return res;
}

int main() {
	freopen("labelmaker.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	for(int cas=1; cas<=T ;cas++) {
		printf("Case #%d: ", cas);
		cout << solve() << endl;
	}
}

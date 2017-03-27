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

bool vis[100000000];

int solve() {
	int N, K, ante = 0, next = 0;
	cin >> N >> K;
	vector< int > v(N);
	F(i, N) {
		cin >> v[i];
		ante += v[i];
	}
	sort(ALL(v));
	int it = 0, num = K;
	memset(vis, 0, sizeof(vis));
	F(i, v.S) {
		if(v[i] == 0)
			it = i+1;
	}

	while(it < N) {
		if(!vis[num] && num >= v[it]) {
			// cout << num << " ";
			v[it++] = num;
			if(num > K)
			for(int i=num; i<100000000; i+=num)
				vis[i] = true;
		}
		num += K;
	}
	// cout << endl;
	F(i, v.S) {
		next += v[i];
		// cout << v[i] << " ";
	}
	// cout << endl;
	return next - ante;
}

int main() {
	freopen("preventing_alzheimers.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	for(int cas=1; cas<=T ;cas++) {
		printf("Case #%d: ", cas);
		cout << solve() << endl;
	}
}

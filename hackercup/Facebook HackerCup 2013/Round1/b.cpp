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

int N, K, C;

int solve() {
	cin >> N >> K >> C;
	int res = K + N, empty, aux;
	FOR(i, 1, N+1) {
		if(i > K) break;
		empty = (N-i >= 0)? N-i : 0;
		if((K/i)*i >= C) {
			aux = C;
		}
		else{
			aux = C + (i-(K%i));
		}
		//cout << empty << " " << aux << endl;
		if(res > aux+empty) {
			res = aux+empty;
		}
	}
	return res;
}

int main() {
	freopen("coins_game.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	for(int cas=1; cas<=T ;cas++) {
		printf("Case #%d: ", cas);
		cout << solve() << endl;
	}
}

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

bool solve() {
	int N, x;
	scanf("%d", &N);
	vector<string> vs(N+1);
	F(i, N) cin >> vs[i];
	F(i, N) {
		F(j, N) {
			if(vs[i][j] == '#') {
				x = 0;
				while(i+x != N && vs[i+x][j] == '#') x++;
				if(j+x > N) return false;
				F(a, x) {
					F(b, x) {
						if(vs[i+a][j+b] != '#') return false;
						vs[i+a][j+b] = '.';
					}
				}
				F(a, N) if(count(ALL(vs[a]), '#')) return false;
				return true;
			}
		}
	}
	return false;
}

int main() {
	//freopen("a.txt", "r", stdin);
	freopen("square_detector.txt", "r", stdin);
	int T;
	scanf("%d", &T);
	for(int cas=1; cas<=T ;cas++) {
		printf("Case #%d: ", cas);
		if(solve()) printf("YES\n");
		else printf("NO\n");
	}
}

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

int N, M;
vector<string> vs;
int memo[501][501], DP[501][501], backDPL[501][501], backDPU[501][501];

int getAllMaxi(int x = 0, int y = 0) {
	if(x >= N || y >= M) return 0;
	if(vs[x][y] == '#') return 0;
	int& r = memo[x][y];
	if(r == -1) r = max(getAllMaxi(x+1, y), getAllMaxi(x, y+1)) + 1;
	return r;
}

int solve() {
	int res, maxi, aux;
	cin >> N >> M;
	vs.resize(N);
	F(i, N) cin >> vs[i];
	memset(memo, -1, sizeof(memo));
	memset(backDPL, 0, sizeof(backDPL));
	memset(backDPU, 0, sizeof(backDPU));
	F(i, N) {
		maxi = 0;
		F(j, M) {
			if(vs[i][j] == '#') {
				maxi = 0;
				continue;
			}
			aux = getAllMaxi(i+1, j) + 1;
			if(maxi < aux) maxi = aux;
			backDPL[i][j] = maxi++;
		}
	}
	F(j, M) {
		maxi = 0;
		F(i, N) {
			if(vs[i][j] == '#') {
				maxi = 0;
				continue;
			}
			aux = getAllMaxi(i, j+1) + 1;
			if(maxi < aux) maxi = aux;
			backDPU[i][j] = maxi++;
		}
	}

	// cout << "backDPL: " << endl;
	// F(i, N) {
	// 	F(j, M) cout << backDPL[i][j] << " ";
	// 	cout << endl;
	// }
	// cout << "backDPU: " << endl;
	// F(i, N) {
	// 	F(j, M) cout << backDPU[i][j] << " ";
	// 	cout << endl;
	// }

	memset(DP, 0, sizeof(DP));
	DP[0][0] = 1;
	res = 1;
	F(i, N) {
		F(j, M) {
			if(i == 0 && j == 0) continue;
			if(vs[i][j] == '#') continue;
			if(i-1 >= 0) {
				if(vs[i-1][j] != '#') {
					DP[i][j] = DP[i-1][j] + 1;
					res = max(res, DP[i-1][j] + backDPL[i][j]);
				}
			}
			if(j-1 >= 0) {
				if(vs[i][j-1] != '#') {
					aux = DP[i][j-1] + 1;
					if(DP[i][j] < aux) DP[i][j] = aux;
					res = max(res, DP[i][j-1] + backDPU[i][j]);
				}
			}
		}
	}
	return res;
}

int main() {
	freopen("aaaaaa.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	for(int cas=1; cas<=T ;cas++) {
		printf("Case #%d: ", cas);
		cout << solve() << endl;
	}
}

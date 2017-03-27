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

LL DP[10000005][16];

void generate(){
	FOR(i, 1, 10000005){
		FOR(j, 1, 15){
			if(i == 1) DP[i][j] = 1LL;
			else DP[i][j] = DP[i-1][j];
			if(j == 1) DP[i][j] += 1LL;
			else DP[i][j] += DP[i][j-1];
			if(DP[i][j] > 10000000LL) break;
			if(DP[ DP[i][j] ][0]) DP[ DP[i][j] ][0] = min(DP[ DP[i][j] ][0], LL(i)+LL(j));
			else DP[ DP[i][j] ][0] = LL(i)+LL(j);
		}
	}
}

int cuad(int x) {
	int r = int(DP[x][0]);
	if(r == 0) return x;
	return r;
}

int solve(int x){
	int m = sqrt(x), r = cuad(x)+1;
	for(int i=2; i<=m ;i++) {
		if(x % i == 0){
			int j = x/i;
			r = min(r, cuad(i)+cuad(j));
		}
	}
	return r;
}

int main(){
	//freopen("a.in", "r", stdin);
	freopen("checkpoint.txt", "r", stdin); freopen("checkpoint.out", "w", stdout);
	generate();
	int r, s;
	scanf("%d", &r);
	F(cas, r){
		scanf("%d", &s);
		printf("Case #%d: %d\n", cas+1, solve(s));
	}
}

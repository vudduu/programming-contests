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
#define S           size()
#define MP          make_pair
typedef long long   LL;

//E (increasing x), N (increasing y), W (decreasing x), S (decreasing y)
LL sumat_memo[10000001];

void solve() {
	string sol = "";
	int x, y, saveX, saveY, it;
	scanf("%d %d", &x, &y);
	saveX = x;
	saveY = y;

	LL dist = abs(x) + abs(y);
	FOR(i, 1, 10000001) if(sumat_memo[i] > dist) {
		if(abs(sumat_memo[i]-dist) > abs(sumat_memo[i-1]-dist) )
			it = i-1;
		else
			it = i;
		break;
	}

	int isForX[it+1];
	for(int i=it; i>0 ;i--) {
		if(abs(x) >= i) {
			if(x < 0) x += i, isForX[i] = 1;
			else x -= i, isForX[i] = 2;
			
		}
		else {
			if(y < 0) y += i, isForX[i] = 3;
			else y -= i, isForX[i] = 4;
		}
	}
	for(int i=1; i<=it; i++) {
		if(isForX[i] <= 2) {
			if(isForX[i] == 1) sol.PB('W'); // decreasing
			else sol.PB('E'); // increasing
		}
		else {
			if(isForX[i] == 3) sol.PB('S'); // decreasing
			else sol.PB('N'); // increasing
		}
	}

	while(x != 0) {
		if(x < 0) { // --
			sol.PB('E'); sol.PB('W');
			x++;
		}
		else { // ++
			sol.PB('W'); sol.PB('E');
			x--;
		}
	}

	while(y != 0) {
		if(y < 0) { // --
			sol.PB('N'); sol.PB('S');
			y++;
		}
		else { // ++
			sol.PB('S'); sol.PB('N');
			y--;
		}
	}
	cout << sol << endl;
}

int main(){
	sumat_memo[1] = 1;
	FOR(i, 2, 10000001) {
		sumat_memo[i] = sumat_memo[i-1] + LL(i);
	}

	// freopen("input.in", "r", stdin);
	freopen("B-small-practice.in", "r", stdin);
	freopen("out.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	for(int cas=1; cas<=T ;cas++) {
		printf("Case #%d: ", cas);
		solve();
	}
}

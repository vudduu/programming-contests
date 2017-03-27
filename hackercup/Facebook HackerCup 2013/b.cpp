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

struct Player {
	string n;
	int sp, h, d, time;
	bool play;
};

bool comp(Player a, Player b) {
	if(a.sp != b.sp) return a.sp > b.sp;
	return a.h > b.h;
}

int outTeam(const vector<Player> &v) {
	int maxi = -10, it = 0;
	F(i, v.S) {
		if(v[i].play) {
			if(v[i].time > maxi) {
				maxi = v[i].time;
				it = i;
			}
			else if(v[i].time == maxi && v[i].d > v[it].d) {
				it = i;
			}
		}
	}
	return it;
}

int inTeam(const vector<Player> &v) {
	int mini = 1000000000, it = 0;
	F(i, v.S) {
		if(!v[i].play) {
			if(v[i].time < mini) {
				mini = v[i].time;
				it = i;
			}
			else if(v[i].time == mini && v[i].d < v[it].d) {
				it = i;
			}
		}
	}
	return it;
}

void addTime(vector<Player>& v){
	F(i, v.S) {
		if(v[i].play)
			v[i].time++;
	}
}

void next(vector<Player> &v, int P) {
	if(v.S <= P) return;
	int a, b;
	addTime(v);
	a = outTeam(v);
	b = inTeam(v);
	v[a].play = false;
	v[b].play = true;
}

void solve() {
	int N, M, P, a, b;
	scanf("%d %d %d", &N, &M, &P);
	vector<Player> v(N);
	F(i, N) {
		cin >> v[i].n >> v[i].sp >> v[i].h;
		v[i].play = false;
	}
	sort(ALL(v), comp);
	vector<Player> team1, team2;
	F(i, N) {
		v[i].d = i;
		if(i < P*2) v[i].play = true;
		if(i&1) team1.PB(v[i]);
		else team2.PB(v[i]);
	}
	F(i, M) {
		next(team1, P);
		next(team2, P);
	}
	
	vector<string> endP;

	F(i, team1.S) {
		if(team1[i].play)
			endP.PB(team1[i].n);
	}
	F(i, team2.S) {
		if(team2[i].play)
			endP.PB(team2[i].n);
	}
	sort(ALL(endP));
	F(i, endP.S) {
		if(i) printf(" ");
		cout << endP[i];
	}
	printf("\n");
}

int main() {
	freopen("basketball_game.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	for(int cas=1; cas<=T ;cas++) {
		printf("Case #%d: ", cas);
		solve();
	}
}

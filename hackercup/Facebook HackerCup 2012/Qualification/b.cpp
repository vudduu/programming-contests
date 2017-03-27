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

int P[10000005];
int W[10000005];

bool gana(int i, int j){
	if(P[i] < P[j] && W[i] <= W[j]) return true;
	if(P[i] <= P[j] && W[i] < W[j]) return true;
	return false;
}

int main(){
	//freopen("a.in", "r", stdin);
	//freopen(".in", "r", stdin); freopen(".out", "r", stdin);
	int t = 10, N, P1, W1, M, K, A, B, C, D;
	//scanf("%d", &t);
	F(cas, t){
		memset(P, 0, sizeof(P));
		memset(W, 0, sizeof(W));
		//cin>>N>>P[1]>>W[1]>>M>>K>>A>>B>>C>>D;
		N = 10000000;
		P[1] = rand()%18 + 1;
		W[1] = rand()%18 + 1;
		M = rand()%118 + 1;
		K = rand()%118 + 1;
		A = rand()%119 + 1;
		B = rand()%10 + 1;
		C = rand()%11 + 1;
		D = rand()%12 + 1;
		FOR(i, 2, N+1){
			if(P[i]){
				break;
			}
			P[i] = ((A*P[i-1] + B) % M) + 1;
		}
		FOR(i, 2, N+1){
			if(W[i]){
				break;
			}
			W[i] = ((C*W[i-1] + D) % K) + 1;
		}
		/*
		FOR(i, 1, N+1) cout<<P[i]<<" "<<W[i]<<endl; cout<<endl;
		int x = 0, y = 0;
		FOR(i, 1, N+1){
			bool flag1 = true;
			bool flag2 = true;
			FOR(j, 1, N+1){
				if(i == j) continue;
				if(gana(j, i)) flag1 = false;
				if(gana(i, j)) flag2 = false;
			}
			if(flag1){
				cout<<P[i]<<" "<<W[i]<<endl;
				x++;
			}
			if(flag2){
				y++;
			}
		}
		printf("Case #%d: %d %d\n", cas+1, y, x);
		*/
	}
}

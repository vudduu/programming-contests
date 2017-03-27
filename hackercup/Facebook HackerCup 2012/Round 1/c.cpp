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

const LL MOD = 4207849484LL;

LL DP[1010];

int stringtoint(string s){
	stringstream ss(s);
	int r;
	ss>>r;
	return r;
}

LL solve(int m, string text){
	F(i, text.S){
		string aux = "";
		for(int j=i; j>=0 ;j--){
			aux = text[j] + aux;
			if(aux.size() >= 4) break;
			if(text[j] != '0'){
				if(stringtoint(aux) <= m){
					if(j == 0) DP[i] = (DP[i] + 1LL) % MOD;
					else DP[i] = (DP[i] + DP[j-1]) % MOD;
				}
			}
		}
	}
	return DP[text.S-1];
}

int main(){
	freopen("a.in", "r", stdin);
	//freopen("squished_status.txt", "r", stdin); freopen("a.out", "w", stdout);
	int n, m;
	string text;
	scanf("%d", &n);
	F(cas, n){
		memset(DP, 0, sizeof(DP));
		cin>>m>>text;
		printf("Case #%d: %lld\n", cas+1, solve(m, text));
	}
}

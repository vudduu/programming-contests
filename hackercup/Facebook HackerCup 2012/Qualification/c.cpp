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

int main(){
	freopen("a.in", "r", stdin);
	//freopen("alphabet_soup.txt", "r", stdin); freopen("a.out", "w", stdout);
	int t;
	scanf("%d", &t);
	string s;
	getline(cin, s, '\n');
	F(cas, t){
		getline(cin, s, '\n');
		int mini = 1<<30;
		string word = "HACKERUP";
		F(i, word.S){
			if(word[i] == 'C') mini = min(mini, int(count(ALL(s), word[i])/2));
			else mini = min(mini, int(count(ALL(s), word[i])));
		}
		printf("Case #%d: %d\n", cas+1, mini);
	}
	
}

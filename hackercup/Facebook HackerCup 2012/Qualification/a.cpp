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

int n, h, w;
vector<int> v;

void lee(){
	v.clear();
	string in, s;
	getline(cin, in, '\n');
	stringstream ss(in);
	ss>>w>>h;
	while(ss>>s) v.PB(s.S);
}

bool oki(int x){
	int auxh = h;
	for(int i=0; i<v.S ;){
		if(v[i]*x > w || auxh < x) return false;
		int tot = v[i++]*x;
		auxh -= x;

		while(tot + x + v[i]*x <= w && i < v.S){
			tot += x + v[i++]*x;
		}
	}
	return true;
}

int main(){
	//freopen("a.in", "r", stdin);
	freopen("billboards.txt", "r", stdin); //freopen("a.out", "w", stdout);
	scanf("%d", &n);
	string s;
	getline(cin, s, '\n');
	F(cas, n){
		lee();
		//F(i, v.S) cout<<v[i]<<" "; cout<<endl;
		int a=0, b=h;
		while(a<b){
			int mid=((a+b)/2)+1;
			if(oki(mid)) a=mid;
			else b=mid-1;
		}
		printf("Case #%d: %d\n", cas+1, a);
	}
}

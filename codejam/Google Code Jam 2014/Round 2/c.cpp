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
#define x          first
#define y          second
typedef long long   LL;

void solve() {
    int W, H, B;
    cin >> W >> H >> B;
    vector<pair<pair<int,int>, pair<int,int> > > v(B);
    F(i, B) {
        cin >> v[i].x.x >> v[i].x.y >> v[i].y.x >> v[i].y.y;
    }
}

int main(){
    freopen("in.txt", "r", stdin);
    // freopen("A-small-attempt0.in", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int T;
    scanf("%d", &T);
    for(int cas=1; cas<=T ;cas++) {
        printf("Case #%d: ", cas);
        solve();
    }
}

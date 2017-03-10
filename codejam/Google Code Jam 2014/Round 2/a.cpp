// There's an old voice in my head that's holding me back
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

void solve() {
    int N, X, res = 0;
    cin >> N >> X;
    vector<int> v(N);
    F(i, N) cin >> v[i];
    sort(ALL(v));
    int x = 0, y = N-1;
    while(x < y) {
        if(v[y]+v[x] <= X)
            x++;
        y--;
        res++;
    }
    if(x==y) res++;
    cout << res << endl;
}

int main(){
    // freopen("in.txt", "r", stdin);
    freopen("A-large.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    int T;
    scanf("%d", &T);
    for(int cas=1; cas<=T ;cas++) {
        printf("Case #%d: ", cas);
        solve();
    }
}

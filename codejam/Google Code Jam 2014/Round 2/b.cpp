// So hold my hand, I'll walk with you, my dear
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

int N;
vector<int> v;
map<int, int> posIni;

int getMaxIt() {
    int maxIt = 0;
    F(i, N)
        if(v[maxIt] < v[i])
            maxIt = i;
    return maxIt;
}

bool isValid() {
    int maxIt = getMaxIt();
    if(maxIt != 0) {
        F(i, maxIt) {
            if(v[i] > v[i+1]) return false;
        }
    }
    if(maxIt != N-1) {
        FOR(i, maxIt, N-1) {
            if(v[i] < v[i+1]) return false;
        }
    }
    return true;
}

int calcMinSwaps() {
    int res = 0;
    F(i, N) {
        // cout << v[i] << " ";
        F(j, i) {
            if(posIni[v[i]] < posIni[v[j]])
                res++;
        }
        //res += abs(posIni[v[i]]-i);
    }
    // cout << endl << res << endl;
    return res;
}

void solve() {
    int res = 1<<30;
    cin >> N;
    v = vector<int> (N);
    posIni.clear();
    F(i, N) {
        cin >> v[i];
        posIni[v[i]] = i;
    }
    sort(ALL(v));
    // do{
    //     if(isValid()) {
    //         // F(i, N) cout << v[i] << " ";
    //         // cout << endl;
    //         int r = calcMinSwaps();
    //         if(res > r) res = r;
    //     }
    // }while(next_permutation(ALL(v)));
    cout << res << endl;
}

int main(){
    // freopen("in.txt", "r", stdin);
    freopen("B-large.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    int T;
    scanf("%d", &T);
    for(int cas=1; cas<=T ;cas++) {
        printf("Case #%d: ", cas);
        solve();
    }
}

#include <iostream>
#include <string>
using namespace std;

#define FOR(i,a,b)  for(int i=(a),_##i=(b);i<_##i;++i)
#define F(i,a)      FOR(i,0,a)
#define S           size()
typedef long long   LL;

string s;
int t[1000001], longToValid[1000001];

void solve() {
	LL r = 0;
	int n, it;
	cin >> s >> n;
	memset(t, 0, sizeof(t));
	bool flag = false;

	for(int i=s.S-1; i>=0 ;i--) {
		if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
			t[i] = 0;
		else
			t[i] = t[i+1]+1; // sum of continuos consonants
		if(t[i] >= n) { // are there n or more continuos consonants ?
			it = i;
			flag = true; // sone solution or more
		}
		if(flag) // there is one or more solutions from here to s.size()
			r += LL(s.S) - LL(i + it-i + n - 1);
	}
	cout << r << endl;
}

int main(){
	freopen("A-large.in", "r", stdin);
	freopen("out.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	for(int cas=1; cas<=T ;cas++) {
		printf("Case #%d: ", cas);
		solve();
	}
}

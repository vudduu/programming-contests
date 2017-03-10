#include <iostream>
using namespace std;

int dist(int x, int y) {
	return (abs(x)+abs(y)) / 2;
}

void solve() {
	int N, X, Y;
	double res = 0;
	scanf("%d %d %d", &N, &X, &Y);

	int n = 0, sum, sumAux, nit = 1;
	while(true) {
		sumAux = (nit*(nit+1))/2;
		if(sumAux > N) break;
		sum = sumAux;
		n++;
		nit += 2;
	}
	if( dist(X, Y) < n ) {
		printf("%0.7lf\n", 1.0);
		return;
	}
	if(sum == N || dist(X, Y) > n) {
		printf("%0.7lf\n", 0.0);
		return;
	}

	N -= sum;
	double total = 0, c = 0;

	for(int i=0; i<(1<<N) ;i++) {
		int left = 0, right = 0;
		for(int j=0; j<N ;j++) {
			if(i&(1<<j)) left++;
			else right++;
		}
		if(left > n*2 || right > n*2) continue;
		if(left >= Y+1) c++;
		total++;
	}
	printf("%0.7lf\n", c/total);
}

int main(){
	int T;
	scanf("%d", &T);
	for(int cas=1; cas<=T ;cas++) {
		printf("Case #%d: ", cas);
		solve();
	}
}

#include <iostream>
#include <vector>
using namespace std;

int dist(int x, int y) {
	return (abs(x)+abs(y)) / 2;
}

int n, Y, N;
vector<vector<double> > memo;

double countAll(int j=0, int left=0, int right=0) {
	if(left > n*2 || right > n*2) return -1.0;

	double &r = memo[j][left];
	if(r == -2) {
		if(j == N) {
			if(left >= Y+1) r = 1.0;
			else r = 0.0;
			return r;
		}
		double aux1, aux2;
		aux1 = countAll(j+1, left+1, right);
		aux2 = countAll(j+1, left, right+1);
		if(aux1 > -1.0) {
			if(aux2 > -1.0)
				aux1 = (aux1 + aux2) / 2.0;
			r = aux1;
			return r;
		}
		if(aux2 > -1.0) r = aux2;
		else r = -1.0;
	}
	return r;
}

void solve() {
	int X;
	double res = 0;
	scanf("%d %d %d", &N, &X, &Y);

	int sum, sumAux, nit = 1;
	n = 0;
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

	memo = vector<vector<double> > (N+1, vector<double> (n*2+1, -2.0));
	double rest = countAll();
	if(rest > -1.0)
		printf("%0.7lf\n", rest);
	else
		printf("0.0\n");
}

int main(){
	int T;
	scanf("%d", &T);
	for(int cas=1; cas<=T ;cas++) {
		printf("Case #%d: ", cas);
		solve();
	}
}
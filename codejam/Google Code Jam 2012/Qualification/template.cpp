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

vector<streamstring> output;
int countThread;

void* main2(int arg){
	cout<<arg;
	F(i, (rand()%30)){
		int maxi = rand() % 3;
		if(maxi) sleep(maxi);
	}
	countThread++;
	return NULL;
}

int main(){
	//freopen("a.in");
	//freopen("A-small-attempt0.in.txt", "r", stdin);
	//freopen("A-large.in.txt", "r", stdin);
	//freopen("a.out");
	countThread = 0;
	pthread_t pth1, pth2, pth3;
	int *i1=0, *i2=1, *i3=2, T;
	scanf("%d", &T);
	pthread_create(&pth1, NULL, main2, 0);
	pthread_create(&pth2, NULL, main2, 1);
	pthread_create(&pth3, NULL, main2, 2);
	while(countThread < T){ sleep(3); }
	pthread_join(pth1, NULL);
	pthread_join(pth2, NULL);
	pthread_join(pth3, NULL);
	string aux;
	F(i, T){
		getline(output, aux, '\n');
		cout<<aux<<endl;
	}
	return 0;
}


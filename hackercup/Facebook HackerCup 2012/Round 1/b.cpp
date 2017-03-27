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

int n, its;
string s;

vector<int> merge(vector<int> arr1, vector<int> arr2){
	vector<int> result;
	int i=0, j=0;
	while(i < arr1.size() && j < arr2.size()) {
		if(arr1[i] < arr2[j]){
		    s.PB('1');
		    result.PB(arr1[i++]);
		}
		else{
			s.PB('2');
		    result.PB(arr2[j++]);
		}
	}
	while(i < arr1.size()) result.PB(arr1[i++]);
	while(j < arr2.size()) result.PB(arr2[j++]);
	return result;
}

vector<int> merge_sort(vector<int> arr){
	int k = arr.size();
	if(k <= 1) return arr;
	int mid = floor(k/2);
	vector<int> first_half, second_half;
	F(i, mid)
		first_half.PB(arr[i]);
	FOR(i, mid, arr.S)
		second_half.PB(arr[i]);
	first_half = merge_sort(first_half);
	second_half = merge_sort(second_half);
	return merge(first_half, second_half);
}

vector<int> merge2(vector<int> arr1, vector<int> arr2){
	vector<int> result;
	int i=0, j=0;
	while(i < arr1.size() && j < arr2.size()) {
		if(s[its] == '1') result.PB(arr1[i++]);
		else result.PB(arr2[j++]);
		its++;
	}
	while(i < arr1.size()) result.PB(arr1[i++]);
	while(j < arr2.size()) result.PB(arr2[j++]);
	return result;
}

vector<int> reverse_sort(vector<int> arr){
	int k = arr.size();
	if(k <= 1) return arr;
	int mid = int(k/2);
	vector<int> first_half, second_half;
	F(i, mid) first_half.PB(arr[i]);
	FOR(i, mid, arr.S) second_half.PB(arr[i]);
	first_half = reverse_sort(first_half);
	second_half = reverse_sort(second_half);
	return merge2(first_half, second_half);
}

int checksum(vector<int> arr) {
    int result = 1;
    for(int i=0; i<arr.size() ;i++)
    	result = (31 * result + arr[i]) % 1000003;
    return result;
}

vector<int> solve(){
	vector<int> v(n), r(n);
	F(i, n) v[i] = i;
	v = reverse_sort(v);
	F(i, n) r[ v[i] ] = i+1;
	return r;
}

int main(){
	//freopen("a.in", "r", stdin);
	freopen("recover_the_sequence.txt", "r", stdin); freopen("a.out", "w", stdout);
	/*vector<int> v, backup, aux;
	FOR(i, 1, 6) v.PB(i);
	do{
		s.clear();
		backup = v;
		aux = merge_sort(v);
		n = aux.S;
		its = 0;
		if(solve() != backup) cout<<"error"<<endl;
	}while(next_permutation(ALL(v)));*/
	int t;
	scanf("%d", &t);
	F(cas, t){
		cin>>n>>s;
		its = 0;
		printf("Case #%d: %d\n", cas+1, checksum(solve()));
	}
}

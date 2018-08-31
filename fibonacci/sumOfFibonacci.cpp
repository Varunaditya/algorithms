#include<iostream>
#include<vector>
using namespace std;

long fibonacciSum(long N, vector<long> series){
	N = (N+2)%60;
	long result = 1;
	for(int i = 2; i <= N; i++){
		series.push_back((series[i-2] + series[i-1]));
	}
	return series.back() - 1;
}

int main(){
	long N; cin >> N;
	vector<long> series {0,1};
	cout << fibonacciSum(N, series) % 10 << endl;
	return 0;
}
// A program that calculates the pisano period of a given number
// Author: Varunaditya Jadwal
// Complexity: O(N + M^2)

#include<iostream>
#include<vector>
using namespace std;

long pisanoSeriesLength(int M){
	long seriesLength = 0, previous = 0, current = 1, tempVar = 0;
	if(!(M^(1/2))){
		return (3*M)/2;
	}
	else if(!(M^(1/5))){
		return 4*M;
	}
	else if(!((M/2)^(1/5))){
		return 6*M;
	}
	else{
		for(int i = 2; i < M^2; i++){
			tempVar = ((previous + current) % M);
			previous = current;
			current = tempVar;
			if (current == 1 && previous == 0){
				seriesLength = i - 1;
				break;
			}
		}
	}
	return seriesLength;
}

long long pisanoSeries(long N, long M, vector<long> series){
	if(N == 0){
		return 0;
	}
	for(int i = 2; i <= N; i++){
		series.push_back((series[i-2] + series[i-1]) % M);
	}
	return series.back();
}

int main(){
	long n,m, seriesLength; cin >> n >> m;
	//assigning the first two elements of the vector as 0 and 1 as the first two numbers in the fibonacci series.
	vector<long> series {0,1};
	if(n == 0){
		cout << 0 << endl;
	}
	else if(n == 1){
		cout << 1 << endl;
	}
	else if(n > 1){
		 seriesLength = pisanoSeriesLength(m);
		 cout << pisanoSeries((n%seriesLength), m, series) << endl;
	}
	return 0;
}
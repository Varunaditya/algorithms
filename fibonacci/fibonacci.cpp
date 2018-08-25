//A program that genrates a fibinacci series till a given number without using recursion. The basic idea is to store
// all the calculations in a vector and just accesing the previous two numbers when required.
// Complexity: O(n)
//Author: Varunaditya Jadwal | Thursday 08.23.2018 1757 HRS

#include<iostream>
#include <vector>
using namespace std;

// a function that takes an int and a vector of int elements, returning a vector of int elements 
vector<int> fibonacci(vector<int> series ,int N){
	
	for(int i = 2; i <= N; i++){
		series.push_back(series[i-2] + series[i-1]);
	}
	return series;
}

int main(){
	int N; cin >> N;
	vector<int> series;
	//assigning the first two elements of the vector as 0 and 1 as the first two numbers in the fibonacci series.
	series.push_back(0);
	series.push_back(1);
	if(N == 0){
		return 0;
	}
	else if(N == 1){
		return 1;
	}
	else if(N > 1){
		 series = fibonacci(series, N);
		 int vecSize = series.size();
		 for(int i = 0; i < vecSize; i++){
		 	cout << series[i] << " ";
		 }
		 cout << endl;
	}

	return 0;
}

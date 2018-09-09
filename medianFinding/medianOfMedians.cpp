#include<iostream>
#include<vector>
using namespace std;

int findMedian(vector<int> &numbers, int medianIndex, int N){
	if(numbers.size() == 1){
		return numbers[0];
	}
	int pivot = numbers[0];
	vector<int> leftSet(N);
	vector<int> rightSet(N);
	for(auto i : numbers){
		if(i < pivot){
			leftSet.push_back(i);
		}
		else{
			rightSet.push_back(i);
		}
	}
	if (leftSet.size() == medianIndex - 1){
		return pivot;
	}
	else if(leftSet.size() > medianIndex - 1){
		findMedian(leftSet, medianIndex, leftSet.size());
	}
	else if(leftSet.size() < medianIndex - 1){
		findMedian(rightSet, medianIndex - leftSet.size() - 1, rightSet.size());
	}
}

int main(){
	int N; cin >> N;
	vector<int> numbers(N);
	int medianIndex;
	for(int i = 0; i < N; i++){
		cin >> numbers[i];
	}
	cout << findMedian(numbers, (N / 2) + 1, N) << endl;
	return 0;
}
#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int> &numbers,vector<int> &sortedList, int low, int high){
	int mid = (low + high) / 2;
	int index = low;
	int left = low;
	int right = mid + 1;
	while (left <= mid && right <= high){
		if(numbers[left] < numbers[right]){
			sortedList[index] = numbers[left];
			left++;
		}
		else{
			sortedList[index] = numbers[right];
			right++;
		}
		index++;
	}
	while (left <= mid){
		sortedList[index] = numbers[left];
		left++;
		index++;
	}
	while (right <= high){
		sortedList[index] = numbers[right];
		right++;
		index++;
	}
	for(int i = low; i < index; i++){
		numbers[i] = sortedList[i];
	}

}

void mergeSort(vector<int> &numbers,vector<int> &sortedList, int low, int high){
	if (low < high){
		int mid = (low + high) / 2;
		mergeSort(numbers, sortedList, low, mid);
		mergeSort(numbers, sortedList, mid + 1, high);
		merge(numbers, sortedList,low, high);
	}
}

int main(){
	int N; cin >> N;
	vector<int> numbers(N);
	vector<int> sortedList(N);
	for(int i = 0; i < N; i++){
		cin >> numbers[i];
	}
	int low = 0;
	int high = (numbers.size() - 1);
	mergeSort(numbers, sortedList, low, high);
	for(auto i : numbers){
		cout << i << " ";
	}
	cout << endl;
	return 0;
}
// A program that sorts a given set of numbers using the merge sort algorithm.
// Author: Varunaditya Jadwal
// Complexity: O(nlogn)

#include<iostream>
#include<vector>
using namespace std;

// function that merges the sorted lists
void merge(vector<int> &numbers, vector<int> &sortedList, int leftStart, int rightEnd){
	int middle = (leftStart + rightEnd) / 2;
	int index = leftStart;
	int left = leftStart;
	int right = (middle + 1);
	while(left <= middle && right <= rightEnd){
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
	// Elements from one of the two halves would not have been added in the new sorted list.
	// This while loop makes sure that the remaining elements gets copied as well.
	while(left <= middle){
		sortedList[index] = numbers[left];
		left++;
		index++;
	}
	while(right <= rightEnd){
		sortedList[index] = numbers[right];
		right++;
		index++;
	}
	// since the program uses recursion, it is better to copy the sorted elemnets to the original vector
	// as soon as tthe operation is completed
	for(int i = leftStart; i < index; i++){
		numbers[i] = sortedList[i];
	}
}

void mergeSort(vector<int> &numbers, vector<int> &sortedList, int leftStart, int rightEnd){
	if (leftStart < rightEnd){
		int middle = (leftStart + rightEnd) / 2;
		// using recursion to divide the list in two halves and sort them seperately
		mergeSort(numbers, sortedList, leftStart, middle);
		mergeSort(numbers, sortedList, middle + 1, rightEnd);
		// merging the two newly sorted lists
		merge(numbers, sortedList, leftStart, rightEnd);
	}
}

int main(){
	int N; cin >> N;
	vector<int> numbers(N);
	vector<int> sortedList(N);
	for(int i = 0; i < N; i++){
		cin >> numbers[i];
	}
	mergeSort(numbers, sortedList, 0, N - 1);
	for(auto i : numbers){
		cout << i << " ";
	}
	cout << endl;
	return 0;
}

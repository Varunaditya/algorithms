//finding the largest two numbers in a given vector with a time complexity of n-2. (where n is the size of the vector)

#include<iostream>
#include<vector>
using namespace std;

int maxPairs(vector<long>& numbers){
	int N = numbers.size();
	long max1 = numbers[0];
	long max2 = numbers[1];
	// traversing the vector; ranging from 2 to the value of N.
	for(int i = 2; i < N; i++){
		// max1 would be swapped only with the new number if the previous value of max1 is smaller than max2 and the  new number.
		//this is how we avoid swapping the second largest number with the largest number. 
		if((numbers[i] > max1) && (max1 < max2)){
			max1 = numbers[i];
		}
		else if(numbers[i] > max2){
			max2 = numbers[i];
		}
	}
	cout << (max1*max2) << endl;
	return 0;
}


int main(){
	int N; cin >> N;
	if (N > 1){
		vector<long> numbers(N);
		for(int i = 0; i < N; i++){
			cin >> numbers[i];
		}
		if (numbers.size() == 2){
			cout << long(numbers[0]*numbers[1]) << endl;
		}
		else{
			maxPairs(numbers);
		}
	}
	else{
		cout << "Enter more than one number.\n";
	}
	return 0;
}
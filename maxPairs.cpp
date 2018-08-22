//finding the largest two numbers in a given vector with a time complexity of n-2. (where n is the size of the vector)

#include<iostream>
#include<vector>
using namespace std;

int maxPairs(vector<long>& numbers){
	int N = numbers.size();
	long max1 = numbers[0];
	long max2 = numbers[1];
	long max3 = numbers[(N/2)];
	long max4 = numbers[(N/2)+1];
	long superMax1 = 0;
	long superMax2 = 0;
	// traversing the first sequence; ranging from 2 to the value of N/2.
	for(int i = 2; i < N/2; i++){
		if((numbers[i] > max1) && (max1 < max2)){
			max1 = numbers[i];
		}
		else if(numbers[i] > max2){
			max2 = numbers[i];
		}
	}
	// traversing the second sequence; ranging from N/2+2 to the value of N.
	for(int i = N/2+2; i < N; i++){
		if((numbers[i] > max3) && (max3 < max4)){
			max3 = numbers[i];
		}
		else if(numbers[i] > max4){
			max4 = numbers[i];
		}
	}
	//assigning the max values from the two sequences to a new vector.
	vector<long> maxNumbers = {max1, max2, max3, max4};
	superMax1 = maxNumbers[0];
	superMax2 = maxNumbers[1];

	for(int i = 2; i < 4; i++){
		if((maxNumbers[i] > superMax1) && (superMax1 < superMax2)){
			superMax1 = maxNumbers[i];
		}
		else if(maxNumbers[i] > superMax2){
			superMax2 = maxNumbers[i];
		}
	}
	cout << (superMax1*superMax2) << endl;
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

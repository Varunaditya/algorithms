// A program that evaluates whether a number is a palindrome or not by just traversing half digits of the number.
// Author: Varunaditya Jadwal
// Complexity: O(logn)

#include<iostream>
using namespace std;

bool isPalindrome(long N){
	if (N <= 0){
		return false;
	}
	long reversedNumber = 0;
	while(N > reversedNumber){
		reversedNumber = (reversedNumber * 10) + (N % 10);
		N /= 10;
	}
	// cout << N << " " << reversedNumber << endl;
	if (N == reversedNumber || N == (reversedNumber/10)){
		return true;
	}
	return false;
}

int main(){
	long N; cin >> N;
	cout << isPalindrome(N) << endl;
	return 0;
}
//A program that calculates the greatest common dividor of two numbers using the Euclidean algorithm
//Euclidean Algorithm: Suppose a' is the remainder when a is divided by b. Then, the gcd d divides a and b iff it divides a' and b as well.
//Author: Varunaditya Jadwal | Thursday 08.23.2018 1325 HRS 

#include<iostream>
using namespace std;

int gcd(int a, int b){
	if (b == 0){
		return a;
	}
	//swaping the position of a and b with b and a' for recursive function.
	gcd(b, (a%b));
}

int main(){
	int N1; int N2;
	cin >> N1 >> N2;
	cout << gcd(N1, N2) << endl;
	return 0;
}
//The goal in this problem is to use a greedy approach to find the minimum number of coins needed to change the input value
//(an integer) into coins with denominations 1, 5, and 10.

#include<bits/stdc++.h>
using namespace std;

void fastInput(long &target){
	bool isNegative = false;
	register int n;
	n = getchar_unlocked();
	if(n == '-'){
		isNegative = true;		
	}
	for(; n > 47 && n < 58; n = getchar_unlocked()){
		target = (target * 10) + (n - 48);
	}
	if (isNegative){
		target *= -1;
	}
}

int changeRequired(long target){
	int change = 0, numberOfCoins = 0;
	while(target){
		if(target < 5){
			numberOfCoins += target;
			target = 0;
		}
		else if(target == 5){
			numberOfCoins += 1;
			target -= 5;
		}
		else if(target > 5 && target < 10){
			target -= 5;
			numberOfCoins++;
		}
		else if(target == 10){
			numberOfCoins++;
			target -= 10;
		}
		else if(target > 10){
			target -= 10;
			numberOfCoins++;
		}
	}
	return numberOfCoins;
}

int main(){
	long target = 0;
	fastInput(target);
	cout << changeRequired(target) << "\n";
	return 0;
}
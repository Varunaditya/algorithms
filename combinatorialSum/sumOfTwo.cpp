// A program that uses the given numbers to return indices of the two numbers such that they add up to a specific target.
// Author: Varunaditya Jadwal
// Complexity: O(n)

#include<iostream>
#include<vector>
#include<map>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    map<int,int> indices;
    vector<int> result;
    for(int i = 0; i < nums.size(); i++){
        indices[nums[i]] = i;            
    }
    for(int i = 0; i < nums.size(); i++){
        int compliment = target - nums[i];
        int temp = indices[compliment];
        if(temp && temp != i){
            return result = {i, temp};
        }
    }
}

int main(){
    int N; cin >> N;
    vector<int> numbers (N);
    vector<int> indices;
    for(int i = 0; i < N; i++){
        cin >> numbers[i]; 
    }
    int target; cin >> target;
    indices = twoSum(numbers, target);
    for(auto i : indices){
        cout << i << " ";
    }
    cout << endl;
    return 0;

}
// Given two non-empty linked lists representing two non-negative integers.
// The digits are stored in reverse order and each of their nodes contain a 
// single digit. Add the two numbers and return it as a linked list.

#include<iostream>
#include<vector>
using namespace std;

struct node {
	int data;
	struct node *next;
};

struct node* createLinkedList(vector<int> &list){
	struct node *first = (struct node *)malloc(sizeof(struct node *));
	first -> data = list[0];
	first -> next = NULL;
	struct node *head = first;
	for(int i = 1; i < list.size(); i++){
		struct node *newNode = (struct node *)malloc(sizeof(struct node *));
		newNode -> data = list[i];
		newNode -> next = NULL;
		first -> next = newNode;
		first = newNode;
	}
	return head;
}

class linkedList{
public:
	void pushSum(struct node *head, int payLoad){
		struct node *tail = head;
		while(tail -> next != NULL){
			tail = tail -> next;
		} 
		struct node *newNode = (struct node *)malloc(sizeof(struct node));
		newNode -> data = payLoad;
		newNode -> next = NULL;
		tail -> next = newNode;
	}

	struct node* addNumbers(struct node *l1, struct node *l2){
		int num1 = 0, num2 = 0;
		while(l1 != NULL){
			num1 = (num1 * 10) + (l1 -> data);
			num2 = (num2 * 10) + (l2 -> data);
			l1 = l1 -> next;
			l2 = l2 -> next;
		}
		int payLoad = num1 + num2;
		struct node *sumStart = (struct node *)malloc(sizeof(struct node));
        sumStart -> data = (payLoad % 10);
        sumStart -> next = NULL;
        payLoad /= 10;
        while(payLoad){
            pushSum(sumStart, (payLoad % 10));
            payLoad /= 10; 
        } 
        return sumStart;
    }

    void printLinkedList(struct node *head){
    	while(head != NULL){
    		cout << head -> data << " ";
    		head = head -> next;
    	}
    	cout << endl;
    }
};

int main(){
	int N; cin >> N;
	vector<int> list1(N);
	vector<int> list2(N);
	for(int i = 0; i < N; i++){
		cin >> list1[i];
	}
	for(int i = 0; i < N; i++){
		cin >> list2[i];
	}
	linkedList obj;
	struct node *l1 = createLinkedList(list1);
	struct node *l2 = createLinkedList(list2);
	struct node *result = obj.addNumbers(l1, l2);
	obj.printLinkedList(result);
	return 0;
}
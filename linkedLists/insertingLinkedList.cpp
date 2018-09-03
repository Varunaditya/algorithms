#include<iostream>
#include<stdlib.h>
using namespace std;

struct node{
	int data;
	struct node *next;
};

void push_back(struct node *head, int payLoad){
	struct node *lastNode = head;
	while(lastNode -> next != NULL){
		lastNode = lastNode -> next;
	}
	struct node *newNode = (struct node *)malloc(sizeof(struct node *));
	newNode -> data = payLoad;
	newNode -> next = NULL;
	lastNode -> next = newNode;
}

void printLinkedList(struct node *head){
	while(head != NULL){
		cout << head -> data << " ";
		head = head -> next;
	}
}

int main(){
	int operation; cin >> operation;
	int N; cin >> N;
	struct node *head = NULL;
	head = (struct node *) malloc (sizeof(struct node *));
	head -> data = 1;
	head -> next = NULL;
	push_back(head, N);
	printLinkedList(head);
	return 0;
}
/*
双向链表
判断最后一个节点的条件：t-next =? nil
*/

#include<iostream>
#include<string.h>
using namespace std;

struct Node{
	int key;
	Node* prev;
	Node* next;
};

Node* nil;

//初始化的时候要malloc啊
void init(){
	nil = (Node *)malloc(sizeof(Node));
	nil->next = nil;
	nil->prev = nil;
}

void printLink(){
	Node *t = nil->next;
	while(t != nil){
		cout << t->key << " ";
		t = t->next;
	}
	cout << "" << endl;
}

void insert(int key){
	Node *t = (Node *)malloc(sizeof(Node));
	t->key = key;
	t->next = nil->next;
	nil->next->prev = t;
	nil->next = t;
	t->prev = nil;
}

Node* searchNode(int key){
	Node *t = nil->next;
	while(t->next != nil){
		if(t->key == key)
			break;
		t = t->next;
	}

	return t;
}

//要先判断是不是头节点，头节点不能删去！！！important！！！！
void deleteNode(Node *t){
	if(t == nil) 
		return;
	t->prev->next = t->next;
	t->next->prev = t->prev;
	free(t);
}

void deleteFirst(){
	deleteNode(nil->next);
}

void deleteLast(){
	deleteNode(nil->prev);
}



int main(){
	int n,key;
	string command;

	cin >> n;

	init();

	for(int i = 0; i < n; i++){
		cin >> command;
		cin >> key;

		if(command == "insert")
			insert(key);
		else if(command == "delete")
			deleteNode(searchNode(key));
		else if(command == "deleteFirst")
			deleteFirst();
		else if(command == "deleteLast")
			deleteLast();

	}

	printLink();

	return 0;
}
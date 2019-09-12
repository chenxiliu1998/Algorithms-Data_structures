/*
双向链表
不知道错在哪了 编译一直segmentation fault：11 救命！
*/

#include<iostream>
#include<string.h>
using namespace std;

static const int MAX = 2000000;

struct CMD{
	string command;
	int key;
};

struct Node{
	int key;
	Node* prev;
	Node* next;
};

Node* nil;

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
	CMD cmd[MAX];
	string command;

	cin >> n;

	init();

	for(int i = 0; i < n; i++){
		cin >> command;
		cin >> key;

		if(cmd[i].command == "insert")
			insert(cmd[i].key);
		else if(cmd[i].command == "delete")
			deleteNode(searchNode(cmd[i].key));
		else if(cmd[i].command == "deleteFirst")
			deleteFirst();
		else if(cmd[i].command == "deleteLast")
			deleteLast();

	}

	printLink();

	return 0;
}
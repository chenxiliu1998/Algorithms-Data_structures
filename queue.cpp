/*
cpu循环调度
*/

#include<iostream>
#include<string.h>
using namespace std;

struct Task{
	int time;
	string name;//用char[]的话第一个task的name会莫名丢掉，就改成string了
};

static const int MAX = 100000;
Task task[MAX];
int tail,head;

//循环加%n
void enqueue(Task t,int n){
	task[tail] = t;
	tail = (tail + 1) % n;
}

Task dequeue(int n){
	Task t = task[head];
	head = (head + 1) % n;
	return t;
}

//不知道怎么区分队列满还是空
//于是加了一个变量count，表示任务结束的个数，当count等于n的时候循环结束
int main(){
	int n,q,total_time,count;
	//Task task[MAX];
	cin >> n >> q;

	for(int i = 0; i < n; i++){
		cin >> task[i].name;
		cin >> task[i].time;
	}

	head = 0;
	tail = 0;
	total_time = 0;//当前时间
	count = 0;//结束任务个数

	while(count < n){
		Task t = dequeue(n);
		if(t.time > q){
			t.time = t.time - q;
			total_time += q;
			enqueue(t,n);
		}
		else{
			total_time += t.time;
			cout << t.name << " " << total_time << endl;
			count += 1;
		}
	}
	return 0;
}
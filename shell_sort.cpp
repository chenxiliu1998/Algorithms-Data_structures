/*
一/原理-G(m)
充分发挥插入排序法的高速算法
1.将数列A写成一行为G[0]个的矩阵
2.对每列进行insertion sort
3.逐行合并成一个数列
4.i+1，回到1

二/伪代码
insertion_sort(A,n,g):
	for i from g to n-1:
		j = i - g
		v = A[i]
		while (j>=0) and (A[j] > v):
			A[j+g] = A[j]
			j -= g
		A[j+g] = v

shell_sort(A,n,m,G):
	for i from 0 to m-1:
		insertion_sort(A,n,G[i])

*/
#include<iostream>
#include<vector>
using namespace std;

static const int MAX = 1000000;
vector<int> G;

int* insertion_sort(int A[], int n, int g){
	for(int i = g; i < n; i++){
		int j = i - g;
		int v = A[i];
		while ((j >= 0) && v < A[j]){
			A[j+g] = A[j];
			j -= g;
		}
		A[j+g] = v;
	}
	return A;
}

//生成shellarray
void shellarray(int n){
	int h = 1;
	while(h <= n){
		G.push_back(h);
		h = 3*h + 1;
	}
}


int main(){
	int n,A[MAX];

	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> A[i];
	}

	//int m = 2;
	shellarray(n);

	for(int i = G.size() - 1; i >= 0; i--){
		insertion_sort(A,n,G[i]);
	}

	cout << G.size() << endl;
	for(int i = G.size() - 1; i >= 0; i--){
		cout << G[i] << " ";
	}
	cout << "" << endl;
	for(int i = 0; i < n; i++){
		cout << A[i] << endl;
	} 


	return 0;
}
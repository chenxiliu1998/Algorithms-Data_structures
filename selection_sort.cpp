/*
一/思路
重复N-1次
1.找出未排序部分最小值的位置minj
2.将minj位置的元素与未排序部分的起始元素进行交换

二/伪代码 A-n
for i from o to n-1:
	minj = i;
	for j from i+1 to n-1:
		if A[j] < A[minj]:
			minj = j
	swap(A[i],A[minj])		 

三/分析
无论什么情况下都需要寻找未排序的最小值——(N-1)+(N-2)+...+1 = (N^2-N)/2 = O(N^2)

四/结论
不稳定排序——相等的元素排序后顺序可能颠倒

*/


#include<iostream>
using namespace std;

static const int MAX = 100;

int main(){
	int n,A[MAX],minj,count,flag;

	//input
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> A[i];
	}

	count = 0;
	
	//Selection sort
	for(int i = 0; i < n; i++){
		minj = i;
		flag = 0;//check if needed to be swap
		for(int j = i+1; j < n; j++){
			if(A[j] < A[minj]){
				minj = j;
				flag = 1;
			}
		}
		if(flag == 1){
			swap(A[i],A[minj]);
			count++;
		}
		
	}

	//print the sorted array
	for(int i = 0; i < n; i++){
		cout << A[i] << " ";
	}
	cout << "" << endl;
	cout << count << endl;



	return 0;
}
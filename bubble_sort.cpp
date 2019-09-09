/*
一/思路
1.从数组末尾开始一次比较相邻两个因素，如果大小关系相反则交换位置

二/伪代码 A-n
flag = 1 //sorted
j = 0
while flag:
	flag = 0
	for i from n-1 to j:
		if A[i] < A[i-1]:
			swap(A[i],A[i-1])
			flag = 1
		j++

三/分析
最坏情况——(N-1)+(N-2)+...+1 = (N^2-N)/2 = O(N^2)

四/提示
此算法的交换次数可称为反序数，体现数列的错乱程度
*/


#include <iostream>
using namespace std;

static const int MAX = 100;

int main(){
	int n, A[MAX], flag, j, count;

	//input
	cin >> n;
	for (int i = 0; i < n; i ++){
		cin >> A[i];
	}

	flag = 1;
	j = 0;
	count = 0;

	//bubble sort
	while(flag){
		flag = 0;
		//注意此处做了优化——没循环一次可确定最前面的一个值，于是每次可少判断一次
		for(int i = n-1; i >= j ;i-- ){
			if(A[i] < A[i-1]){
				swap(A[i],A[i-1]);
				count++;
				flag = 1;
			}
		}
		j++;
	}

	//print the sorted array and the total number of swapping
	for(int i = 0; i < n; i++){
		cout << A[i] << " ";
	}
	cout << "" << endl;
	cout << count;


	return 0;
}
/*
一/思路：
1.取出为排序部分的开头元素赋给变量v
2.在已排序部分，将所有比v大的元素向后移一个单位
3.将以取出的元素v插入空位

二/伪代码：A-n
for i from 1 to n-1:
	v = A[i]
	j = i - 1
	while j > 0 and A[j] > v:
		A[j+1] = A[j]
		j--
	A[j+1] = v	

三/分析：
1.最坏情况：1+2+3+...+n-1 = (n^2-n)/2 = O(n^2)	

四/conclusion：
适合处理相对有序的数据
*/


#include<iostream>

using namespace std;
static const int MAX = 100;

int main(){
	int n,A[MAX];

	//input
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> A[i];
	}

	//insertion sort
	for(int i = 1; i < n; i++){
		int v = A[i];
		int j = i - 1;

		//cout << "v = " << v;
		//cout << "j = " << j;

		while( (j >= 0) && (A[j] > v)){
			A[j+1] = A[j];
			//cout << "j = " << j;
			j--;
		}

		A[j+1] = v;

		//print the current array
		for(int k = 0; k < n; k++){
			cout << A[k] << " ";
		}
		cout << "" << endl;
	}

	return 0;
}
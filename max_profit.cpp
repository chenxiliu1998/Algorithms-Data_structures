/*
input:第一行输入整数n，接下来n行依次给整数Rt赋值
output：输出价值差Rj-Ri(j>i)的最大值
*/

/*
伪代码
minv = R[0]
for j from 1 to n-1:
	maxv = max(maxv,Rj-minv)
	minv = min(minv,Rj)
*/

#include<iostream>
#include<algorithm>
using namespace std;
static const int MAX = 200000;

int main(){
	int R[MAX],n;

	cin >> n; //整数n
	//n个整数的值，存在数组中
	for (int i = 0; i < n ; i++){
		cin >> R[i];
	}

	//初始化maxv和minv
	int maxv = -20000000; //enough small or let maxv = R1 - R0
	int minv = R[0];

	//循环数组，比较大小--肯定要知道目前便利到的数组以前的最小值，然后也要记录最大值（因为可能那就是整个数组的最大值）
	for (int i = 1; i < n ; i++ ){
		maxv = max( maxv , R[i] - minv);
		
		minv = min(R[i], minv);
	}

	cout << maxv << endl;
	return 0;
}
#include<iostream>
using namespace std;

struct Card{
	char suit,value;
};

void print_array(Card C[],int n){
	for(int i = 0; i < n; i++){
		cout << C[i].suit << C[i].value << " ";
	}
	cout << "" << endl;
}

int main(){
	Card C1[100],C2[100];
	int n,flag,j,minj;

	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> C1[i].suit >> C1[i].value;
	}

	//print_array(C1,n);

	for(int i = 0; i < n; i++){
		C2[i].suit = C1[i].suit;
		C2[i].value = C1[i].value;
	}
	//print_array(C2,n);

	flag = 1;
	j = 0;
	while(flag == 1){
		flag = 0;
		for(int i = n-1; i > j; i--){
			if(C2[i].value < C2[i-1].value){
				swap(C2[i],C2[i-1]);
				flag = 1;
			}
		}
		j++;
	}

	print_array(C2,n);
	
	for(int i = 0; i < n; i++){
		C2[i].suit = C1[i].suit;
		C2[i].value = C2[i].value;
	}

	for(int i = 0; i < n; i++){
		minj = i;
		for (int k = i+1; k < n; k++){
			if(C2[k].value < C2[minj].value){
				minj = k;
			}
		}
		swap(C2[i],C2[minj]);
	}

	print_array(C2,n);

	return 0;
}
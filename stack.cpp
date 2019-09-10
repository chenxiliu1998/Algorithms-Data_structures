/*
逆波兰表示法
写了一个半小时-气！
*/

#include<iostream>
using namespace std;

int top,S[1000];

void push(int x){
	S[++top] = x;
}

int pop(){
	top --;
	return S[top+1];
}

int main(){
	int a,b;
	top = 0;
	char s[100];

	//如何判断程序回车技术
	//while(cin >> j) and scanf("%s",s)都不行
	//只有getchar
	while(s[0] = getchar()){
		//回车则结束
		if(s[0] == '\n')
			break;
		//空格不理会
		else if(s[0] == ' ')
			continue;
		else if(s[0] == '+'){
			a = pop();
			b = pop();
			push(a+b);
		}
		//这里注意是b-a！！！！这个该死的bug调了半小时
		//先进后出！！！！！
		else if(s[0] == '-'){
			a = pop();
			b = pop();
			push(b-a);
		}
		else if(s[0] == '*'){
			a = pop();
			b = pop();
			push(a*b);
		}
		else{
			//只有数组才能atoi，所以s定义为数组
			push(atoi(s));
		}
	}

	cout <<pop() << endl;

	return 0;
}
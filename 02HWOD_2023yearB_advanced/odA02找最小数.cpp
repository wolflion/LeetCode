#include "test.h"

//原型Lc402，移掉k位数字

void od_a02_impl(string input, int k) {
	//健壮性
	if (k == 0) {
		cout << input << endl;
	}

	if (input.size() == 0 || k > input.size()) {
		cout << "0" << endl;
	}

	stack<char> res;
	for (int i = 0; i < input.size(); i++) {
		char current = input[i];
		while (!res.empty() && res.top() > current && k>0){
			res.pop();
			k--;
		}
		res.push(current);//lionel，啥时候用呢，这是最小值，要是取最大值呢？
	}

	while (k > 0) {
		res.pop();  //也可以用for，如果还需要移动数目
		k--;  //这个忘记写了，其实可以写成while(k--) res.pop();  这种直接抄代码啊，确实没法看，当然，最开始还写的是for循环呢
	}

	//把栈转成string，并转置一下
	string s;
	while (!res.empty()) {
		s += res.top();
		res.pop();
	}
	reverse(s.begin(), s.end());

	//把转置前面的0给去掉，如果有0的话
	int pos = 0;
	while (pos < s.size() && s[pos] == '0') {
		pos++;
	}
	if (pos == s.size()) {
		cout << "0" << endl;
	}

	cout << s.substr(pos) << endl;  //lionel，substr()的新用法
}

void od_a02() {
	// k表示要移除的位置数目
	string input1{"2615371"};
	int k1 = 4; 
	od_a02_impl(input1, k1);  //131

	string input2{ "5445795045" };
	int k2 = 5;  
	od_a02_impl(input2, k2);  //44045

	string input3{ "12345678" };
	int k3 = 5;  
	od_a02_impl(input3, k3); //123
}
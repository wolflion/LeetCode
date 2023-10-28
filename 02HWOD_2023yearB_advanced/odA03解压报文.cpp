#include "test.h"

void od_a03_impl(string input) {
	stack<int> stk;
	string replace;
	string repeat;
	string val;

	for (char c : input) {
		if (c == ']') {
			while ((stk.size() > 0) && (stk.top() != '[')) {
				replace += stk.top();
				stk.pop();
			}

			reverse(replace.begin(), replace.end());

			if (stk.size() > 0 && stk.top() == '[') {   //lionel,这个if是在if(c==']')的里面
				stk.pop();//把`[`出掉
				while (stk.size() > 0 && isdigit(stk.top())) {
					repeat += stk.top();
					stk.pop();
				}
				

				reverse(repeat.begin(), repeat.end());

				cout << repeat << endl;//lionel，第2个case有问题，用例写错了
				int num = stoi(repeat);
				repeat.clear();
				while (num) {
					val += replace;
					num--;
				}
				replace.clear();
				//cout << val << endl;
				
				for (int i = 0; i < val.size(); i++) {
					stk.push(val[i]);  //lionel，这时候把替换过的字符再插入回去
				}
				val.clear();  //lionel，卡在了，每次都clear()掉才行
				continue;//lionel，这个continue是我没想到的
			}
		}
		
		stk.push(c);  //表示，只有不为`[`的时候，才push进来
	}

	string res;
	while (!stk.empty()) {
		res += stk.top();
		stk.pop();
	}
	reverse(res.begin(), res.end());
	cout << res << endl;
}

void od_a03() {
	string input1{ "3[m2[c]]" }; //mccmccmcc
	od_a03_impl(input1);
	//我如果写成"10[k]2[3ms[j2[op]]]"就不对，主要是用例错了，[]前面是s，转成stoi（）报错了
	string input2{ "10[k]2[3n3[j2[op]]]" };  //kkkkkkkkkk3njopopjopopjopop3njopopjopopjopop
	od_a03_impl(input2);
}
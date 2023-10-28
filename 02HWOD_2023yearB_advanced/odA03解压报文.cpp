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

			if (stk.size() > 0 && stk.top() == '[') {   //lionel,���if����if(c==']')������
				stk.pop();//��`[`����
				while (stk.size() > 0 && isdigit(stk.top())) {
					repeat += stk.top();
					stk.pop();
				}
				

				reverse(repeat.begin(), repeat.end());

				cout << repeat << endl;//lionel����2��case�����⣬����д����
				int num = stoi(repeat);
				repeat.clear();
				while (num) {
					val += replace;
					num--;
				}
				replace.clear();
				//cout << val << endl;
				
				for (int i = 0; i < val.size(); i++) {
					stk.push(val[i]);  //lionel����ʱ����滻�����ַ��ٲ����ȥ
				}
				val.clear();  //lionel�������ˣ�ÿ�ζ�clear()������
				continue;//lionel�����continue����û�뵽��
			}
		}
		
		stk.push(c);  //��ʾ��ֻ�в�Ϊ`[`��ʱ�򣬲�push����
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
	//�����д��"10[k]2[3ms[j2[op]]]"�Ͳ��ԣ���Ҫ���������ˣ�[]ǰ����s��ת��stoi����������
	string input2{ "10[k]2[3n3[j2[op]]]" };  //kkkkkkkkkk3njopopjopopjopop3njopopjopopjopop
	od_a03_impl(input2);
}
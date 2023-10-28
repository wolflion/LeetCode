#include "test.h"

//ԭ��Lc402���Ƶ�kλ����

void od_a02_impl(string input, int k) {
	//��׳��
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
		res.push(current);//lionel��ɶʱ�����أ�������Сֵ��Ҫ��ȡ���ֵ�أ�
	}

	while (k > 0) {
		res.pop();  //Ҳ������for���������Ҫ�ƶ���Ŀ
		k--;  //�������д�ˣ���ʵ����д��while(k--) res.pop();  ����ֱ�ӳ����밡��ȷʵû��������Ȼ���ʼ��д����forѭ����
	}

	//��ջת��string����ת��һ��
	string s;
	while (!res.empty()) {
		s += res.top();
		res.pop();
	}
	reverse(s.begin(), s.end());

	//��ת��ǰ���0��ȥ���������0�Ļ�
	int pos = 0;
	while (pos < s.size() && s[pos] == '0') {
		pos++;
	}
	if (pos == s.size()) {
		cout << "0" << endl;
	}

	cout << s.substr(pos) << endl;  //lionel��substr()�����÷�
}

void od_a02() {
	// k��ʾҪ�Ƴ���λ����Ŀ
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
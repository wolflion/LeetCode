#include "test.h"

//https://blog.csdn.net/goldarmour/article/details/132330506

//https://blog.csdn.net/weixin_54707168/article/details/113832621 ���룬�����case

void od88_impl(string input) {
	vector<char> res;
	for (int i = 0; i < input.size(); i++) {
		if (isdigit(input[i])) {
			if (input[i] - '0' <= 2) {
				//cout << input[i] - '0' << endl;
				cout << "!error" << endl;
				break;
			} else {
				int num = input[i] - '0';
				while (num-1 > 0) {
					res.push_back(input[i + 1]);
					num--;
				}
			}
		}else if (isalpha(input[i])) {
			res.push_back(input[i]);
		} else {
			cout << "!error" << endl;
			break;
		}
	}

	//cout << res << endl;
	string str(res.begin(), res.end()); //https://blog.csdn.net/liuzehn/article/details/107606163  ��vector<char>ת��string
	cout << str << endl;  //lionel��д�˻�������׳������˼����
}

void od88() {
	//��������2����ͬ����ĸѹ��������2dff������!error��
	string input1("4dff");
	od88_impl(input1);
	string input2("2dff");
	od88_impl(input2);
	string input3("4d@A");
	od88_impl(input3);
}
#include "test.h"

//https://blog.csdn.net/goldarmour/article/details/132330506

//https://blog.csdn.net/weixin_54707168/article/details/113832621 输入，输出的case

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
	string str(res.begin(), res.end()); //https://blog.csdn.net/liuzehn/article/details/107606163  把vector<char>转成string
	cout << str << endl;  //lionel，写了还不够健壮，但意思到了
}

void od88() {
	//连续超过2个相同的字母压缩，所以2dff，就是!error了
	string input1("4dff");
	od88_impl(input1);
	string input2("2dff");
	od88_impl(input2);
	string input3("4d@A");
	od88_impl(input3);
}
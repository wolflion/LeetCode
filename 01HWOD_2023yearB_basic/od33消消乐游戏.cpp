#include "test.h"

void od33_impl(string inputs) {
	stack<char> s;
	for (int i = 0; i < inputs.size(); i++) {
		s.push(inputs[i]);
		if (s.top() == inputs[i+1]) { //i++��++i��������������ģ�дһ�У��ͷ�����д��������˵����
			s.pop();
			i++;
			break; //lionel��break���ǵ��Գ����ģ�
		}
	}
	cout << s.size() << endl;
}

void od33() {
	string inputs1{ "gg" };  //0
	od33_impl(inputs1);
	string inputs2{ "mMbccbc" };//3��mMc
	od33_impl(inputs2);
}
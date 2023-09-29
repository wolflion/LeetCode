#include "test.h"

void od33_impl(string inputs) {
	stack<char> s;
	for (int i = 0; i < inputs.size(); i++) {
		s.push(inputs[i]);
		if (s.top() == inputs[i+1]) { //i++和++i还是有蛮大区别的，写一行，和分两行写，还是有说法的
			s.pop();
			i++;
			break; //lionel，break还是调试出来的；
		}
	}
	cout << s.size() << endl;
}

void od33() {
	string inputs1{ "gg" };  //0
	od33_impl(inputs1);
	string inputs2{ "mMbccbc" };//3，mMc
	od33_impl(inputs2);
}
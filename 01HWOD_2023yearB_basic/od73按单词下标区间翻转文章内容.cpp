#include "test.h"

void od73_impl(string input, int start, int end) {
	regex ws_re("\\s+");//lionel，不是太明白这个正则
	vector<string> res_helper(sregex_token_iterator(input.begin(), input.end(), ws_re, -1), sregex_token_iterator());

	while(start<end){
		swap(res_helper[start], res_helper[end]);
		start++;
		end--;
	}

	string res;
	for (auto val : res_helper) {
		res += val;
		res += " ";
	}
	cout << res << endl;
}

void od73() {
	string inputs1{ "I am a developer" };
	int start1 = 1;
	int end1 = 2;
	od73_impl(inputs1, start1, end1);
}
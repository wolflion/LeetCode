/*
* ��дһ������������ �ַ������� �е��������׺��������ڹ�����׺�����ع̶��ַ���:@Zero.

����˵��:

1���ַ������ȷ�Χ:[2,1000];



2���ַ������ַ����ȷ�ΧΪ[1��126]

��������

["abc" "bbc" c]

�������

"c"



ʾ��1��

����:

["abc","bbc","c"]

���:

"c"

˵��:

���ع�����׺: c
*/

#include "test.h"

void od59_impl(vector<string> input) {
	for (auto &s : input) {
		reverse(s.begin(), s.end());
	}
	string res;

	for (int i = 0; input[0][i]; ++i) {  //lionel��ȡ��1��ĵ�i��
		for (int j = 1; j < input.size(); j++) {//�ӵ�2�鿪ʼȡ�����Ƚ�i��
			if (input[0][i] != input[j][i]) {
				res = input[0].substr(0, i);
				if(!res.empty()){
					cout<<res<<endl;
				}else{
					cout << "@Zero" << endl;
				}
				return;
			} 
		}
	}
	cout << input[0] << endl;
}

void od59() {
	//lionel�����ģ��ȷ�ת���������������ǰ׺����Ҫ�Ǻ�׺�Ļ���û��ͳ���ĸ�Խ�磿
	vector<string> inputs1{ "abc","bbc","c" };
	od59_impl(inputs1);
	vector<string> inputs2{ "aa","bb","cc" };
	od59_impl(inputs2);
}


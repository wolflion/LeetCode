#include "test.h"

//������������ϣ���������
#if 0
void helper(vector<char> input, int index, string &cur, vector<string> &result) {
	//if (cur.size() == 3) {  //lionel����������ǲ���д���ˣ� ������д��index==3?��
	if(index == 3){
		result.push_back(cur);
	} else if (index < 3) {
		helper(input, index + 1, cur, result); //������

		cur.push_back(input[index]);
		helper(input, index + 1, cur, result);
		cur.pop_back();
	}
}

void od_a08_impl(int n, vector<char> input) {
	vector<string> result;
	if (input.size() == 0) {
		//for_each(input.begin(), input.end(), []() {cout<<})  //lionel��foreach��д������̫��
		for (auto s : result) {
			cout << s << endl;
		}
		return;
	}
	string cur;

	helper(input, 0, cur, result);  //lionel���´�����д���ͼ�ס��

	for (auto s : result) {
		cout << s << endl;
	}
}
#endif

void swap08(vector<char> &input, int index, int i) {  //lionel�������������ط�ûд�����ã����½�����û�б仯
	if (index != i) {
		char tmp = input[index];
		input[index] = input[i];
		input[i] = tmp;
	}
}

void helper(vector<char> input, int index, vector<string>& result) {
	if (index == 3) {  //lionel��index==input.size()����ʵ����3
		string cur;
		for (auto c : input) {
			cur.push_back(c);
		}
		result.emplace_back(cur);
	} else {
		for (int i = index; i < 3; ++i) {  //lionel�������ǽ���˳��
			//cout << index << "," << i << endl;
			swap08(input, index, i);
			helper(input, index + 1, result);
			swap08(input, index, i);
		}
	}
}

void od_a08_impl(int n, vector<char> input) {
	//n��ȫ���У�����Ҫn��������һ������ʱ������n��ѡ�����ɵ�2�����֣�����n-1��ѡ��.....
	vector<string> result;
	helper(input, 0, result);
	for (auto s : result) {
		cout << s << endl;
	}
}

void od_a08() {
	int n1 = 3;  //��ʯ����
	vector<char> input1{ 'a','b','c'};
	od_a08_impl(n1, input1);
}
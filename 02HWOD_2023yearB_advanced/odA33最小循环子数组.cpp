#include"test.h"

/*
* ����һ��������������ɵ�����nums�����������Ƿ�����ĳ���������ظ�ѭ��ƴ�Ӷ��ɣ�����������С�������顣

��������

��һ������������Ԫ�ظ���n��1 <= n <= 100000

�ڶ��������������������nums���Կո�ָ0 <= nums[i] <= 10

�������

�����С����������������У��Կո�ָ�;

��ע

���鱾���������������飬ѭ��1�ο����ɵ�����
*/

void getNext(int *next, string s) {
	next[0] = 0;
	int j = 0;
	for (int i = 1; i < s.size(); i++) {
		while (j > 0 && s[i] != s[j]) {
			j = next[j - 1];
		}
		if (s[i] == s[j]) {  //lionel��next�����������ˣ�����ط�д���ˣ���==д����=
			j++;
		}
		next[i] = j;
	}
}

void od_a33_impl(int n, vector<int> nums) {
	if (nums.size() == 0) {
		cout << "null" << endl;
		return;
	}

	int next[10]; //lionel�������ǳ���
	string tmp;
	for (auto c : nums) {
		tmp += to_string(c);
	}
	getNext(next, tmp);
	int len = tmp.size();
	int L = len - next[len - 1];//lionel���ص㻹���� ��� ʲô��**��Сѭ����**
	while (L--) {
		cout << tmp[L] << " ";
	}

#if 0
	//�����֪������˭��
	cout << tmp[next[1]] << "," << next[2] << "," << next[3] << endl;
	//if (next[len - 1] != 0 && len % (len - next[len - 1]) == 0)
		//cout << next << endl;
#endif
}

void od_a33() {
	int n = 9;
	vector<int> nums{ 1,2,1,1,2,1,1,2,1 };
	od_a33_impl(n, nums);
}

//https://blog.csdn.net/weixin_45830552/article/details/129736966   LC459  �ظ������ַ���

//https://blog.csdn.net/u013190417/article/details/123810465 

//https://blog.nowcoder.net/n/7459ca2934ae43f99d92a7a6b5486778?from=nowcoder_improve

//https://www.cnblogs.com/grandyang/p/6992403.html
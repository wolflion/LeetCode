#include "test.h"

/*
* ��νˮ�ɻ�������ָһ��nλ�������������λ���ֵ�n�η��͵��ڸ�����������153��ˮ�ɻ�����153��һ��3λ��������153=1^3+5^3+3^3

��������

��һ������һ������n����ʾһ��nλ����������n��3��7֮�䣬����3��7.

�ڶ�������һ��������m����ʾ��Ҫ���ص�m��ˮ�ɻ�����

�������

���س�����n�ĵ�m��ˮ�ɻ�����������0��ʼ�����m����ˮ�ɻ����ĸ������������һ��ˮ�ɻ�����m�ĳ˻��������벻�Ϸ�������-1��
*/


bool isCheck(int x, int n) {
	vector<int> a;
	int value = x;
	while (x) {
		int t = x % 10;
		x = x / 10;
		a.push_back(t);
	}

	int sum = 0;
	for (auto num : a) {
		sum += pow(num, n);
	}
	a.clear();  //lionel��vec����հ취��clear()��erarse()��swap()3�ַ���

	if (sum == value) {
		return true;
	}
	return false;
}

void od23() {
	int n = 3;
	//cin >> n;
	int m = 0;
	//cin >> m;

	int value = 1;
	int tmp = n;
	while (tmp--) {
		value *= 10;
	}

	vector<int> res;
	for (int i = 0; i < value; i++) {
		if (isCheck(i, n) && i>1) { //lionel������ط�����һ��i>1����Ȼ�Ļ���0Ҳ�Ƿ��ϵģ�1Ҳ�Ƿ��ϵ�
			res.push_back(i);
		}
	}
	cout << res[m] << endl;
}

//https://zhuanlan.zhihu.com/p/644158241
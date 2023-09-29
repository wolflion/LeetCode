#include "test.h"

void od53_impl(vector<int> cake, vector<int> gift, int value) {
	int res = 0;
	//���Ÿ���
	sort(cake.begin(), cake.end());
	sort(gift.begin(), gift.end());
	for (int i = cake.size() - 1; i >= 0; i--) { //lionel��i>=0�����ж�һλ
		if (cake[i] > value) {
			continue; //lionel���������û���壬break��contiue�����𣬻��ǵ��Գ�����
		}
		for (int j = gift.size() - 1; j >= 0; j--) {
			if (cake[i] + gift[j] <= value) {
				res++;
			}
		}
	}
	cout << res << endl;
}

void od53() {
	vector<int> cake1{ 10,20,5 };
	vector<int> gift1{ 5,5,2 };
	int value1 = 15;
	od53_impl(cake1, gift1, value1);
}
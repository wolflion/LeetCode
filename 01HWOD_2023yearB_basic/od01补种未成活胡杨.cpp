#include "test.h"


void od01_impl(int N, int M, vector<int>num, int k) {
	//lionel���о�д�ò�����׳��
	int left = 1, right = 0;
	int res = 0;
	for (int i = 0; i < num.size()-k; i++) {  //֮ǰ����ط���k��д����1������̫ƴ�գ��Ÿĵ�k�����Ӧ�ò�����ȫAC��
		if (num[i] > left) {
			right = num[i + k];
			res = right - left ? right - left : res;
			left = num[i];
		}
	}
	res = N - left ? N - left : res;
	cout << res << endl;
#if 0
	
	int res = 0;
	for (auto c : num) {
		if (c > left) {
			res = c - left ? c - left : res;
			left = c;
		}
	}
	int max = num[num.size()-1];
	if (left >= max && left < right) {
		res = right - left ? right - left : res;
	}
	cout << res << endl;

	while (right < N) {
		for (int i = 0; i < num.size();i++) {
			right = num[i];
			int diff = right - left;
			res = diff > res?diff: res;
			left = right;
		}
		right++;
	}
	res = N - left ? N - left : res;
	cout << res << endl;

	//�������ڣ���num1����k��
	int res = 0;

	for (int i = 0; i+k < M; i+=k) {
		cout << i << endl;
		cout << num[i] << "," << num[i + k] << endl;
		if ( (num[i+k] - 1)- (num[i] - 1) > res) {
			res = (num[i+k] - 1) - (num[i] - 1);
		}
	}

	cout << res << endl;
#endif
}

void od01() {
	int N1 = 10; //����
	int M1 = 3; //δ�ɻ�
	vector<int>num1{ 2,4,7 };
	int k1 = 1;//����һ��
	od01_impl(N1, M1, num1, k1);// Ӧ�����6

	int N2 = 5; //����
	int M2 = 2; //δ�ɻ�
	vector<int>num2{ 2,4};
	int k2 = 1;//����һ��
	od01_impl(N2, M2, num2, k2);// Ӧ�����6
}
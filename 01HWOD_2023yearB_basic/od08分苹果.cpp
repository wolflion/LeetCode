#include "test.h"

void od08_impl(int num, vector<int> input) {   //lionel�������ʼ��Ŀ��������
	//lionel�������ǣ�1�����Ķ�������ô�㣿 ��˭ȥ���

	// ���Ÿ���lionel����ʵ����ν
	sort(input.begin(), input.end());

	int res = 0;

	for (int i = 1; i < input.size()-1; i++) { //lionel������ط�Ϊ���Ǵ�1��ʼ������ֻ��input.size()-1 ��
		int binA = 0, binB = 0;
		int sumA = 0, sumB = 0;  //lionel����2������ֵ���ǲ���ֻ����for���渳ֵ��ɶ��˼��
		//left
		for (int left = 0; left < i; left++) {
			binA ^= input[left];
			sumA += input[left];
		}

		//right
		for (int right = i; right < input.size(); right++) {
			binB ^= input[right];
			sumB += input[right];
		}

		if (binA == binB) {
			res = max(sumA, sumB);
		}
	}
	cout << res << endl;
	
}

void od08() {
	int num1 = 3;
	vector<int> inputs1{ 3,5,6 };
	od08_impl(3, inputs1);
}
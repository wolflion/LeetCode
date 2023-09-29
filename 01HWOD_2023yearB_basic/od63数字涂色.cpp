#include "test.h"


void od63_impl(int n, vector<int> inputs) {
	vector<int> res;
	int min = inputs[0];
	res.push_back(min);
	for (int i = 1; i < inputs.size(); i++) {
		if (inputs[i] % min != 0) {
			res.push_back(inputs[i]);
		} else
		{
			break;
		}

	}
	cout << res.size() << endl;
}
#if 0
void od63_impl(int n, vector<int> inputs) {
	static int count = 0;
	if (n==0) {
		cout << count << endl;
		return;
	}
	count++;
	sort(inputs.begin(), inputs.end());
	int min = inputs[0];
	for (int i = 0; i < inputs.size(); i++) {
		//cout << inputs[i] << endl;
		if (inputs[i] % min == 0) {
			--n;
			inputs.erase(inputs.begin() + i);
		}
	}
	od63_impl(n, inputs);
}
#endif

void od63() {
	int n1 = 3;
	vector<int> inputs1{ 2,4,6 };  //����С��2�����ܱ��������������1
	od63_impl(n1, inputs1);

	int n2 = 5;
	vector<int> inputs2{ 2,3,4,6,9 };  //Ҫ����2��3���������2
	od63_impl(n2, inputs2);
}


//https://blog.csdn.net/goldarmour/article/details/131732972 ����Ϳɫ��ûˢ������������˼

//https://blog.csdn.net/zhizhengguan/article/details/127045383  �˼�˵����������������û�뵽���ҵ�˼·�� ���ϲ��ܱ���1������������
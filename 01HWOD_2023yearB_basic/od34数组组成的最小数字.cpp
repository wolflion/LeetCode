#include "test.h"

bool cmp(int i1, int i2) {//���lambda�Ļ����Ҳ�֪��sort����Ĳ�����ɶ  ,�������ǶԵģ��ų������ǣ�5��21��30��Ȼ����ϡ�
	//cout << i1 << "input," << i2<<endl;
	string s1 = to_string(i1);
	string s2 = to_string(i2);
	if (s1.size() < s2.size()) {
		return 1;
	} else if (s1.size() == s2.size()) {
		for (int i = 0; i < s1.size(); i++) {
			//cout << s1[i] << "," << s2[i] << endl;
			if (s1[i] < s2[i]) {
				return 1;
			} else
			{
				return 0;
			}
		}
	}
	return 0;
}

void od34_impl(vector<int> inputs) {
	while(inputs.size() < 3) {
		inputs.emplace_back(0);
	}
	sort(inputs.begin(), inputs.end(), cmp);  //lionel��sort���÷�
	//for (auto c : inputs) {
	//	cout << c << endl;
	//}
	string s1 = to_string(inputs[0]);
	string s2 = to_string(inputs[1]);
	string s3 = to_string(inputs[2]);

	//�ص�����������ϣ�3��string�����ȫ����
	vector<string> v1{ s1,s2,s3 };
	sort(v1.begin(), v1.end());
	vector<string>v2;
	do {
		//cout << v1 << endl;
		v2.push_back(v1[0] + v1[1] + v1[2]);
	} while (next_permutation(v1.begin(), v1.end()));


	cout << stoi(v2[0]) << endl;
}

void od34(){
	vector<int> inputs1{ 21,30,62,5,31 };
	od34_impl(inputs1);
	vector<int> inputs2{5,21};
	od34_impl(inputs2);
}
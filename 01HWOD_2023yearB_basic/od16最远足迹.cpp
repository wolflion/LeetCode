/*
* ĳ̽�նӸ���Ե��¶�Ѩ����̽�ա�̽�նӳ�Ա�ڽ���̽������ʱ������Я���ļ�¼���᲻���ڵؼ�¼��������꣬���ڼ�¼�ļ�϶��Ҳ���¼�������ݡ�̽������������̽�ն���Ҫ��ȡ��ĳ��Ա��̽�չ����������̽�ն��ܲ�����Զ���㼣λ��

1.�Ǽ�¼����ʱ����������ݸ�ʽΪ(x,y)����(1,2)��(100,200)������0<x<1000��0<y<1000��ͬʱ���ڷǷ����꣬��(01,1)��(1,01)��(0,100)���ڷǷ����ꡣ

2.�趨̽�ն��ܲ�������Ϊ(0,0)��ĳλ������ܲ��ľ���Ϊ:x*x+y*y��

3.���������������ܲ��ľ�����ͬ�����һ�ε��������Ϊ��Զ���㼣��

4.����¼���е����궼���Ϸ�������ܲ�����(0,0)��

��ע:

����Ҫ����˫������Ƕ�׵����������sfsdfsd((1,2))��

��������

�ַ�������ʾ��¼���е�����

��:ferga13fdsf3(100,200)f2r3rfasf(300,400)

�������

�ַ�������ʾ��Զ�㼣�����������:(300,400)
*/

#include "test.h"

bool cmp16(pair<int, int> m1, pair<int, int> m2) {
	int sum1 = (m1.first - 0) * (m1.second - 0);
	int sum2 = (m2.first - 0) * (m2.second - 0);

	if (sum1 > sum2) {
		return 1;
	}
	return 0;
}

void od16_impl(string input) {
	vector <pair<int, int>> res;
	//lionel����ɶȥ���ˣ�����(��Ȼ��̶����ȼ���
#if 0
	auto pos = input.find('(');
	auto posR = input.find(')');
	string tmp = input.substr(pos + 1, posR-pos-1);
	cout << tmp << endl;
#endif

	//�������еĻ�����while
	char flagL = '(';
	char flagR = ')';
	int pos = 0;
	int i=0;
	vector<int> left;
	while ((pos = input.find(flagL, pos)) != string::npos) {
		left.emplace_back(pos);
		pos++;
		i++;
	}

	vector<int> right;
	pos = 0;
	i = 0;
	while ((pos = input.find(flagR, pos)) != string::npos) {
		right.emplace_back(pos);
		pos++;
		i++;
	}
	
	vector<string> val;
	//lionel��������վ������������ƥ����ô�죿
	for (int i = 0; i < right.size(); i++) {
		string tmp = input.substr(left[i] + 1, right[i] - left[i] - 1);
		val.emplace_back(tmp);
	}

	for (auto s : val) {
		auto pos = s.find(',');
		int left = stoi(s.substr(0, pos-0)); //substr���÷���ɶ�����һ���ǳ���
		int right = stoi(s.substr(pos+1, s.size()-pos-1));
		//cout << left << "," << right << endl;
		res.emplace_back(make_pair(left, right));
	}

	sort(res.begin(), res.end(), cmp16);

	//lionel���Ҿ��ø��򵥵ķ�ʽ��ջ����
	cout << res[0].first << "," << res[0].second << endl;
}

void od16() {
	string inputs1{ "ferg(3,10)a13fdsf3(3,4)f2r3rfasf(5,10)" };
	od16_impl(inputs1);
}
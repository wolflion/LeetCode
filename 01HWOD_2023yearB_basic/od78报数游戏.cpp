#include "test.h"

void od78_impl(int n) {
	//list<int> input;
	vector<int> input;
	for (int i = 1; i <= 100; i++)
		input.emplace_back(i);

	int index = 0;
	while (input.size() >= n) {
		index = (index + (n - 1)) % (input.size());  //lionel�����Ļ��������ʽ����Ȼ����Ҫ��vector����Ȼ��vectorʱ����erase(v.begin()+pos)
		//input.remove(index);
		input.erase(input.begin()+index);
		//cout << input.size() << endl;
	}

	for (auto c : input) {
		cout << c << endl;
	}
}

void od78()
{
	int n1 = 3;
	od78_impl(n1);
}

//https://codeleading.com/article/56424211682/  Լɪ�򻷵�����
#include"test.h"

void od85() {
	string str = "bcdefa";//�ҵ�a,��b��һ�£����acdefb

	string s2 = str;
	sort(s2.begin(), s2.end());

	char min = s2[0];
	int place = 0, change = 0;

	for (int i = 0; i < str.size(); i++) {
		if (str[i] == min) {//�ҵ�ԭ������С��λ��
			place = i;
			break;
		}
	}

	for (int j = 0; j < str.size(); j++) {
		if (str[j] != min) {  //����ط�ȡԭ����δ�����
			change = j;//��������󣬲��ȵĵط�
			break;
		}
	}

	if (place > change) {
		swap(str[place], str[change]);
	}

	cout << str << endl;
}

//https://blog.csdn.net/G1useppE/article/details/125025845
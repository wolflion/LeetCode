#include "test.h"

/*
* ĳ����ӡ�����ݴ�ӡ����ִ�д�ӡ���񡣴�ӡ�����Ϊ�Ÿ����ȼ����ֱ�������1-9��ʾ������Խ�����ȼ�Խ�ߡ���ӡ��ÿ�δӶ���ͷ��ȡ����һ������A��

Ȼ�������������������û�б�A���ȼ����ߵ���������б�A���ȼ��ߵ�����������A�ŵ�����β���������ִ������A�Ĵ�ӡ��

���дһ�����򣬸�������Ĵ�ӡ���У����ʵ�ʵĴ�ӡ˳��

��������

����һ�У�Ϊÿ����������ȼ������ȼ�֮���ö��Ÿ��������ȼ�ȡֵ��Χ��1~9��

�������

���һ�У�Ϊÿ������Ĵ�ӡ˳�򣬴�ӡ˳���0��ʼ���ö��Ÿ���



ʾ�� 1 �������ʾ���������ԣ���̨��������һ�㲻����ʾ��

����

9,3,5

���

0,2,1

˵��

����ͷ����������ȼ�Ϊ9�����ȴ�ӡ�������Ϊ0��

���Ŷ���ͷ���������ȼ�Ϊ3�������л������ȼ�Ϊ5���������ȼ�3�����Ƶ�����β����

���Ŵ�ӡ���ȼ�Ϊ5�����񣬹������Ϊ1��

������ȼ�Ϊ3����������Ϊ2��
*/

struct Item {
	int prio;
	int idx;
};

void od_a10() {
	string str;  // ����9,3,5
	getline(cin, str);

	//�ָ�ţ����������ܻ��õ�
	vector<Item> inputvi;
	str += ",";
	int id = 0;
	while (str.find(",") != string::npos) {
		int idx = str.find(",");
		string t = str.substr(0, idx);
		str = str.substr(idx + 1);
		inputvi.push_back({ stoi(t), id++ });// ����ṹ��
	}

	vector<Item> outvi;
	while (inputvi.size()) {
		int prio = inputvi[0].prio;

		if (inputvi.size() == 1) {  //lionel�������û����ɶ��˼
			outvi.push_back(inputvi[0]);
			inputvi.clear();
			break;
		}

		bool find = false;

		for (auto it = inputvi.begin() + 1; it != inputvi.end(); it++) {
			if (it->prio > prio) {
				find = true;
				break;
			}
		}

		if (find) {
			inputvi.push_back(*inputvi.begin());
			inputvi.erase(inputvi.begin());  //lionel��Ҳû̫��
		}

		outvi.push_back(inputvi[0]);
		inputvi.erase(inputvi.begin());
	}

	for (int i = 0; i < outvi.size(); ++i) {
		cout << outvi[i].idx;   //���0��2��1
		if (i != outvi.size() - 1) {
			cout << ",";
		}
	}
}

//�ο���https://blog.csdn.net/tomren/article/details/128693675?spm=1001.2014.3001.5502
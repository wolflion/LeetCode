#include "test.h"
/*
* ���嵱һ���ַ���ֻ��Ԫ����ĸ(a,e,i,o,u,A,E,I,O,U)���,
��ΪԪ���ַ������ָ���һ���ַ��������ҳ��������Ԫ���ַ�����
�������䳤�ȣ�����Ҳ����뷵��0��
�ַ���������һ�������ַ���ɵ������г�Ϊ���ַ������Ӵ�
��������
һ���ַ����䳤�� 0 < length ,�ַ��������ַ�a-z��A-Z���
�������
һ����������ʾ���Ԫ���ַ��Ӵ��ĳ���
ʾ��һ
����
asdbuiodevauufgh
���
3
*/

bool checkFlag(char c) {
	string str = "aeiouAEIOU";
	if (str.find(c) == str.npos) {
		return true;
	}
	return false;
}

void od82() {
	string str("asdbuiodevauufgh"); //�������ֱ�� cin>>str;����
	int tmpLen = 0;
	int maxLen = 0;
	for (auto c : str) {
		if (checkFlag(c)) {
			tmpLen++;
		} else {
			maxLen = max(maxLen, tmpLen);
			tmpLen = 0;
		}
	}
	maxLen = max(maxLen, tmpLen);
	cout << maxLen << endl;
}

//https://www.bilibili.com/read/cv23257608/

//https://blog.csdn.net/weixin_54707168/article/details/115717669
/*
* ˼·
* 1�����ϣ���������Ԫ����ĸ
* 2��max_len��cur_len����¼��͵�ǰԪ��
* 3�������������Ԫ����cur_len++,max_len���£����Ǿ�cur_lenΪ0��
* 4����󷵻�max_len
*/
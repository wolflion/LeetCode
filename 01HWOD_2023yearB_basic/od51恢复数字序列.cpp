/*
* ����һ��������������ɵ����У����Խ���ƴ�ӳ�һ���ַ������ٽ��ַ�����Ĳ����ַ�����˳��������8 9 10 11 12��ƴ�ӳɵ��ַ���Ϊ89101112������һ�����ַ���õ�90811211��ԭ����������10�ͱ������0��1��

�ָ���һ�������Ϲ���õ��Ĵ����ַ����ַ������뽫�仹ԭ���������������У��������������С�����֡�

��������
����һ�У�Ϊ�����ַ����ַ��������������еĳ��ȣ����߼��ÿո�ָ����ַ������Ȳ�����200��������������1000����֤������Ի�ԭ��Ψһ���С�
*/
#include "test.h"
void od51() {
	string input("90811211");
	int k = 5;
	int start = 1;//������ʼλ��
	int end = 1000 - k + 1;

	//��һ������ʼ��input�浽map��
	unordered_map<char, int> value;
	for (char c : input) {
		value[c]++;
	}


	while (start <= end)
	{
		//lionel��ÿ5��һͳ��
		unordered_map<char, int> count;//��¼ÿ���ַ����ֵĴ���
		for (int j = start; j < start + k; j++)  //lionel������ط���start����������  ����ʾ��߿�ʼ�� k����С�����䡿
		{
			string num = to_string(j);
			for (char c : num)
				count[c]++;
		}

		//lionel��Ȼ��checkһ��
		bool isMatch = true;
		for (auto p : value) {
			char c = p.first;
			if (count[c] != value[c]) {
				isMatch = false;
				break;
			}
		}

		if (isMatch) {
			cout << start << endl;
			return;
		}

		start++;
	}


}

//https://blog.csdn.net/weixin_42450130/article/details/131991831   [java]

//https://www.nowcoder.com/discuss/533314399520489472?sourceSSR=post  [cpp]
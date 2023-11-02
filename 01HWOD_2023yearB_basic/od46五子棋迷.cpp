#include "test.h"

/*
* �ű����������������ԣ�����֮�ྭ���д����ա� ����һ������ֵ��ű��ˣ�������һ����˼�������ˣ��������ϵ����ӷֲ����£� �������ʾ�� -1 0 1 1 1 0 1 0 1 -1

���ӷֲ�˵��:

-1 ������ӣ�0 �����λ��1 ������ӣ�
���鳤�� L, ���� 1 < L < 40, �� L Ϊ������
�����дһ����������������ĳ���λ�á�

���������壺

�ҵ�һ����λ (0)�������� (1/-1) ����λ�ã�����ʹ�õ�ǰ�ӵ�����������ȱ��
������ڶ��λ�ã���������м�Ľ�С���Ǹ����ꣻ
��������ڿ���λ�ã�ֱ�ӷ��� -1��
�������Ȳ��ܳ��� 5 ��(������Լ��)��
��������
��һ��: ��ǰ������ɫ �ڶ���: ��ǰ�����״̬

�������
1 ����������ʾ����λ�õ������±�

ʾ��һ
����
1
-1 0 1 1 1 0 1 0 1 -1 1
���
5
*/

//-1���ӣ�0��λ��1����

void od46_impl(int currentColor, vector<int> input) {

	int len = input.size();
	int middle = (len - 1) / 2;
	int res = -1, max = 0;
	for (int i = 0; i < len; i++) {
		if (input[i] == currentColor) {
			int right = i + 1;

			//�ҳ������ĵ�ǰ��ɫ���������ӵ��������
			while (right < len && input[right] == currentColor) {
				right++;
			}

			int tmpLen = right - i;
			//������ӷ���rightָ���λ��
			if (right < len && input[right] == 0) {
				if (tmpLen == max && abs(right - middle) < abs(middle - res)) {
					//�滻����ַ����Ⱥ�֮ǰ���滻�����ȣ���right���ӽ�����λ��
					res = right;
				} else if (tmpLen > max) {
					//�滻����ַ����������
					max = tmpLen;
					res = right;
				}
			}

			//������ӷ��� i-1 ָ���λ��
			if (i-1 >= 0 && input[i-1] == 0) {
				if (tmpLen == max && abs(i-1 - middle) < abs(middle - res)) {
					//�滻����ַ����Ⱥ�֮ǰ���滻�����ȣ���right���ӽ�����λ��
					res = i-1;
				} else if (tmpLen > max) {
					//�滻����ַ����������
					max = tmpLen;
					res = i-1;
				}
			}

			//����i
			i = right;
		}
	}

	cout << res << endl;
#if 0
	int left = 0, right = left+1;
	while (left < right) {
		if (right > input.size())
			break;

		if (input[left] != currentColor && input[left] != 0) {
			left++;
			right++;
		} else if (input[left] == currentColor && input[right] == currentColor) {
			right++;
		}
	}
#endif
}

void od46() {
	int currentColor1 = 1;
	vector<int> inputs{ -1,0,1,1,1,0,1,0,1,-1,1 };
	od46_impl(currentColor1, inputs);
}

void input()
{
	int cur;
	cin >> cur;
	vector<int> inputs;
	int num;
	while (cin>>num)
	{
		inputs.push_back(num);
		if (cin.get() == '\n')
			break;
	}
}

//https://blog.csdn.net/wj_phm/article/details/132941144

//LC424���滻����ظ��ַ�

//csdn����������Ա��weixin_42450130

//ctrl+k,ctrl+c   [ctrl+k, ctrl+u]
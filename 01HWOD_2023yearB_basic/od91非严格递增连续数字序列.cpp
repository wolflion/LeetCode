#include "test.h"
/*
* ���ϸ����������������
��Ŀ����
����һ���ַ�����������Сд��ĸ������
���ַ����а�������ķ��ϸ���������������г���
���磺
12234���ڷ��ϸ������������

��������
����һ���ַ�����������Сд��ĸ������

�������
����ַ����а�������ķ��ϸ���������������г���

ʾ��һ
����
abc2234019A334bc
���
4
*/

//https://www.jianshu.com/p/936a64ce681b

void od91() {
	string str("abc2234019A334bc");
	int first = 0, last = 1;
	int num = 0, res = 0;//int num=1; lionel����֪���������û�й�ϵ
	while (first < last) {
		if (last > str.size())
			break;
		if (isdigit(str[last]) && isdigit(str[first])) {
			if (str[last] > str[first]) {
				num++;
				if (num > res) {
					res = num;
				} 
			}
		} else {
			first = last;
			last++;
			num = 0;//num=1;
		}
		first++;
		last++;
	}
	cout << res << endl;
}

//https://ac.nowcoder.com/discuss/1050006

//https://blog.nowcoder.net/n/cdfc391fce2f4b779a8729b96e22756c
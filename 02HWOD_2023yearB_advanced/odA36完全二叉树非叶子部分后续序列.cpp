#include "test.h"

/*
* ��Ŀ����

����һ����˳�򴢴�ṹ�洢����ֵ�� ��ȫ������ ����(��� 1000 ������)�����ҳ�����ȫ�����������з�Ҷ�ӽڵ㲿�֣�Ȼ����ú��������ʽ���˲����� (������Ҷ��) �����

1.ֻ��һ���ڵ�������˽ڵ��϶�Ϊ���ڵ�(��Ҷ��)

2.����ȫ���������� ����������

���ܴ��ڵ����ڶ������Ҷ�ӻ�������Ҷ�ӵ��������˵��: �������ĺ������ Q �ǻ��ڸ���˵�ģ�����˳��Ϊ: ��-��-��

��������

��ͨ���ո�ָ�����������ַ���

�������

��Ҷ�Ӳ������ṹ����ע: ��������Կո�ָ�
*/


void dfs(vector<int>& inputs, int root, vector<int>& res) {
	int left = 2 * root + 1;
	int right = 2 * root + 2;   //lionel���������ܣ�����û�뵽��
	if (inputs.size() > left) {
		dfs(inputs, left, res);
		if (inputs.size() > right){
			dfs(inputs, right, res);  //����dfs��ʽ����Ҳ���ᣬ�Լ���ô��֯��
		}
		
		res.push_back(inputs[root]);  //lionel������ط���д���ˣ�д����res.push_back(root)�ˣ�Ӧ����ֵ��inputs[root]
	}
}

void od_a36() {
	vector<int> inputs{ 1,2,3,4,5,6,7 };
	vector<int> res;

	dfs(inputs, 0, res);
	
	for (auto c : res) {
		cout << c<<" ";
	}
}


//https://zhuanlan.zhihu.com/p/641757199
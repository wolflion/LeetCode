/*
* ��Ŀ����

����һ��m*n�Ķ�ά���飬���Աȡֵ��ΧΪ0��1��2��

����ֵΪ1��Ԫ�ؾ߱�ͬ�����ԣ�ÿ����1S������������ֵΪ0��Ԫ��ͬ��Ϊ1��

��ֵΪ2��Ԫ�أ�����ͬ����

���������г�Ա�����ʼ��Ϊ0��2���ٽ������[0, 0]Ԫ���޸ĳ�1���ھ����㹻����ʱ�����������ж��ٸ�Ԫ����0��2����0��2����֮�ͣ���
��������

�����ǰ���������Ǿ����С�����������־������ݡ�
�������

���ؾ����з�1��Ԫ�ظ�����
*/

#include "test.h"

using vvi = vector < vector<int >>; //lionel���Լ�����̫�������֣���˳�����ˣ� ��������д�� ��typedef���÷�
using pii = pair<int, int>;
int dirs32[4][2] = { {1,0},{-1,0},{0,-1},{0,1} };
void od_a32_impl(int m, int n, vvi &input) {
	//���������г�Ա�����ʼ��Ϊ0��2,�ٽ������[0,0]Ԫ���޸ĳ�1  --lionel��Ҫ�����
	input[0][0] = 1;
	queue<pii> q;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if (input[i][j] == 1) {
				q.push(make_pair(i, j));//lionel�����make_pair�����Ǳ����
			}
		}
	}
	int count = 1;

	while (q.size()) {  //lionel������ط���while()
		int x = q.front().first;  //lionel������û��top��ֻ��front
		int y = q.front().second;
		q.pop();
		for (auto dir : dirs32) {
			int mx = x + dir[0];
			int my = y + dir[1];

			if (mx >= 0 && mx < m && my >= 0 && my < n && input[mx][my] == 0) {
				input[mx][my] = 1;
				count++;
				q.push(make_pair(mx, my));
			}
		}
	}
	cout << m * n - count << endl;
}

void od_a32() {
	int m1 = 4, n1 = 4;
	vvi inputs1{ {0,0,0,0},{0,2,2,2},{0,2,0,0},{0,2,0,0} };
	od_a32_impl(m1, n1, inputs1);  //Ԥ��9�����9
}

//https://zhuanlan.zhihu.com/p/644880876
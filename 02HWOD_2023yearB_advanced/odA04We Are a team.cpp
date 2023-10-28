#include "test.h"

/*
* ��We Are A Team��

�ܹ��� n �����ڻ�����ÿ������һ����ţ�1<=���<=n�������Ƿֳ��˶���Ŷӣ���Ҫ������յ��� m ����Ϣ�ж�ָ�����������Ƿ���һ���Ŷ��У�����ģ�

1����Ϣ����Ϊ a b c������ a��b �ֱ���������˵ı�ţ����� c ����ָ��

2��c == 0 ���� a �� b ��һ���Ŷ���

3��c == 1 ������Ҫ�ж� a �� b �Ĺ�ϵ����� a �� b ��һ���Ŷӣ����һ�С�we are a team��,������ǣ����һ�С�we are not a team��

4��c Ϊ����ֵ����ǰ�� a �� b ���� 1~n �ķ�Χ�������da pian zi��

��������

��һ�а����������� n��m(1<=n,m<100000),�ֱ��ʾ�� n ���˺� m ����Ϣ
���� m �У�ÿ��һ����Ϣ����Ϣ��ʽΪ��a b c(1<=a,b<=n,0<=c<=1)
�������: 1��c ==1,���� a �� b �Ƿ���һ���Ŷ������һ���ַ�������һ���Ŷ��������we are a team��,����һ���Ŷ��������we are not a team�� 2��c Ϊ����ֵ����ǰ�� a �� b �ı��С�� 1 ���ߴ��� n ʱ������ַ�����da pian zi��
�����һ�� n �� m ��ֵ����Լ���ķ�Χʱ��
*/

vector<int> fa;//û�뵽Ҫ�� typedef ���� using����ʡ��һ�£�lionel
void init(int len) {
	fa.resize(len+1);//lionel������ط�����size̫С�ˣ�����Խ�磬�������ǲ����������ȷ��
	for (int i = 0; i < len; i++) {
		fa[i] = i;
	}
}

int find(int x) {
	if (x != fa[x]) {
		fa[x] = find(fa[x]);
	}
	return fa[x];
}

void merge(int x, int y) {

	int mx = find(x);
	int my = find(y);
	//lionel������Ҫ�жϣ�
	fa[x] = y;
	//lionel���������Ҹ�������д�ģ�Ҳ�ǿ�������
#if 0
	x = find(x);
	y = find(y);
	if (x > y) {
		fa[x] = y;
	} else {
		fa[y] = x;
	}
#endif
}

void od_a04_impl(int n, int m, vector<vector<int>> input) {
	init(n);//�ܹ�������
	for (int i = 0; i < m; i++) {
		int x = input[i][0];
		int y = input[i][1];
		int p = input[i][2];

		//lionel������������ط�����û������ǣ�ɶʱ��Ҫmerge()��ɶʱ��Ҫfind()�����������룬�ֿ������⣬�߼���������ϣ�Ҫ�࿴��
		if (x<1 || x>n || y<1 || y>m) {
			cout << "da pian zi" << endl;
		} else {
			if (p == 0) {
				merge(x, y);
			} else if (p == 1) {
				if (find(x) == find(y)) {
					cout << "we are team" << endl;
				} else {
					cout << "we are not team" << endl;
				}
			} else {
				cout << "da pian zi" << endl;
			}
		}
			
	}
}

void od_a04() {
	int n1 = 5, m1 = 7;
	vector<vector<int>> inputs1{ {1,2,0},{4,5,0},{2,3,0},{1,2,1},{2,3,1},{4,5,1},{1,5,1} };
	od_a04_impl(n1,m1,inputs1);
}
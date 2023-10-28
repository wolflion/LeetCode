/*
* ��Ŀ����

��ĩС��׼��ȥ��ɽ������0����ƽ�أ�ɽ�ĸ߶�ʹ��1��9����ʾ��С��ÿ����ɽ����ɽ�߶�ֻ�����k��k���ڣ�ÿ��ֻ����������һ���������ƶ�һ��С�������Ͻ�(0,0)λ�ó���

��������

��һ������m n k(�ո�ָ�)

������m*n�Ķ�άɽ��ͼ��kΪС��ÿ����ɽ����ɽ�߶Ȳ�����ֵ��Ȼ�����������ɽ��ͼ��һ��m��n�У����Կո�ָ���ȡֵ��Χ��

��0<m��500

��O<n��500

��0<k<5

�������

����С������������߷��ߣ�������߷����̲���������Կո�ָ���ͬ�߶ȵ�ɽ������϶̲�����

���û�п�������ɽ�壬��߶ȺͲ���������0��
*/


#include "test.h"
int m1 = 5, n1 = 4, k1 = 1;
vector<vector<int>> input1{ {0,1,2,0},{1,0,0,0},{1,0,1,2},{1,3,1,0},{0,0,0,9} };  
vector<vector<bool>> visited(m1, vector<bool>(n1, false));
vector<vector<int>> direction{ {1,0},{-1,0},{0,1},{0,-1} };

map<int, int> minSteps;

extern void dfs(int i, int j, int steps);

//2 2����߷���(0,2)��λ�ã��߶�Ϊ2��  ���·����0,0)-(0,1)-(0,2)����̲���Ϊ2
void od_a41() {
	int max = input1[0][0];

	int steps = 0;
	minSteps[max] = 0;

	dfs(0, 0, 0);  //�ӿ�ʼ��(i,j)Ҳ����(0,0)�Ѿ�����steps������һ��steps��0

	for (auto c : minSteps) {
		if (c.first > max) {
			max = c.first;
			steps = c.second;
		}
	}

	cout << max << "," << steps << endl; //�����2,2  lionel����עһ��
}

void dfs(int i, int j, int steps) {
	//��ǰɽ��߶�
	int curHeight = input1[i][j];
	//4������
	for (auto d : direction) {
		int mx = i + d[0];
		int my = j + d[1];

		//cout << mx << "," << my << "," << visited[i][j] << endl;
		//lionel����עһ�£�Ӧ����mx>=input1.size()����д��mx>input1.size()������ʽ�ӣ���Сд��һ��=�ţ�����core����
		if (mx<0 || mx>=input1.size() || my<0 || my>=input1[0].size() || visited[i][j]) {
			continue;
		}

		//��һ��ɽ��
		int nextHeight = input1[mx][my];
		if (abs(curHeight - nextHeight) <= k1) {
			steps++;
			if (!minSteps[nextHeight] || minSteps[nextHeight] > steps) {
				minSteps[nextHeight] = steps;
			}

			//���Ϊ�ѷ���
			visited[i][j] = true;
			//��һ��
			dfs(mx, my, steps);
			//����
			visited[i][j] = false;  //lionel����ͺܻ��ݵ�˼����
			steps--;
		}
	}
}

//https://blog.csdn.net/wj_phm/article/details/132748092
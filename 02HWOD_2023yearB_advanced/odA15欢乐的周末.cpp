/*
* С����СΪ�Ǻ�Ҫ�õ����ѣ�����Լ����ĩһ��Է���

ͨ���ֻ������������ڵ�ͼ��ѡ���˶���۲͵ص㣨������Ȼ���ε�ԭ�򣬲��־۲͵ص㲻�ɴ����С����СΪ���ܵ���ľ۲͵ص��ж��ٸ���

��������

��һ������m��n��m�����ͼ�ĳ��ȣ�n�����ͼ�Ŀ�ȡ�

�ڶ��п�ʼ���������ͼ��Ϣ����ͼ��Ϣ������

0 Ϊͨ���ĵ�·

1 Ϊ�ϰ���ҽ�1Ϊ�ϰ��

2 ΪС������СΪ����ͼ�бض����ҽ���2�� �����ϰ��

3 Ϊ��ѡ�еľ۲͵ص㣨���ϰ��

�������

���Ա�����������ľ۲͵ص���������ĩ�޿ո�
*/

#include "test.h"

//���������dfs��ģ����ɶ��  ��dfs��Ҫ�ǵݹ飬������ݹ飬����ջ��

int m = 4, n = 4;  //������

void dfs(vector<vector<int>> input, int x, int y, vector<vector<int>>& point, vector<vector<int>> &person) {
	if (x < 0 || y < 0 || x >= m || y >= n || input[x][y] == 1 || person[x][y] == 1) {
		return;
	}

	if (input[x][y] == 3 && person[x][y] == 0) {
		point[x][y]++;//���ʴ���+1
	}

	person[x][y] = 1;  //�Ѿ����ʹ�

	//lionel����for��dirs[4][2]��һ����
	dfs(input, x + 1,y, point, person);
	dfs(input, x, y+1, point, person);
	dfs(input, x - 1, y, point, person);
	dfs(input, x, y-1, point, person);
}

void od_a15_impl(int m, int n, vector<vector<int>> input){
	//vector<vector<int>> v(m, vector<int>(n, 0)); //�о�����input��
	int sum = 0;
	vector<vector<int>> inn(m, vector<int>(n, 0));
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {  //lionel������ط�j<n��д����i<n������Խ�����
			if (input[i][j] == 2)
				inn.push_back({ i, j });  //lionel����û�������������������
		}
	}

	vector<vector<int>> point(m, vector<int>(n, 0));
	vector<vector<int>> hua(m, vector<int>(n, 0));
	vector<vector<int>> wei(m, vector<int>(n, 0));

	dfs(input, inn[0][0], inn[0][1], point, hua);
	dfs(input, inn[1][0], inn[1][1], point, wei);

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (point[i][j] >= 2)
				sum++;
		}
	}

	cout << sum << endl;
}

void od_a15() {
	int m1 = 4, n1 = 4;  //������
	vector<vector<int>> input1{ {2,1,0,3},{0,1,2,1},{0,3,0,0},{0,0,0,0} };  //3�����۲͵ĵط���2��ʾ��С����СΪ��λ�ã���0��ͨ�У�1����ͨ��
	od_a15_impl(m1, n1, input1);  //���2
}

// https://zhuanlan.zhihu.com/p/645083603�������python�Ĳ��鼯

// c++�Ĳ��鼯 http://www.sylblog.xin/52/

//https://www.nowcoder.com/discuss/525451151773270016������C++��dfs
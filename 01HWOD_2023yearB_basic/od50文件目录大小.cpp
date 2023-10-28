#include "test.h"

/*
* һ���ļ�Ŀ¼�����ݸ�ʽΪ��Ŀ¼id,��Ŀ¼���ļ���С��(��Ŀ¼id�б�)��

����Ŀ¼idȫ��Ψһ��ȡֵ��Χ[1,200],��Ŀ¼���ļ���С��Χ[1,1000],��Ŀ¼id�б����[0,10]���磺1 20 (2,3)��ʾĿ¼1���ļ��ܴ�С��20,��������Ŀ¼��id�ֱ���2��3

��������һ���ļ�ϵͳ������Ŀ¼��Ϣ���Լ�����ѯ��Ŀ¼id,�������Ŀ¼�ͼ���Ŀ¼������Ŀ¼�Ĵ�С֮�͡�

��������

��һ��Ϊ��������M,N,�ֱ��ʾĿ¼�ĸ����ʹ���ѯ��Ŀ¼id,

��1��M��100

��1��N��200

������M�У�ÿ��Ϊ1��Ŀ¼�����ݣ�

Ŀ¼id��Ŀ¼���ļ���С(��Ŀ¼id�б�)

��Ŀ¼�б��е���Ŀ¼id�Զ��ŷָ���

�������

����ѯĿ¼������Ŀ¼�Ĵ�С֮��

3 1  //��1
3 15()
1 20(2)
2 10(3)

// case 2
4 2
4 20()
5 30()
2 10(4,5)
1 40()
*/

//�ο�LC690
typedef struct f {
	int id;
	int size;
	vector<int> subordinates;
}file;

void dfs(int id, unordered_map<int, file>& um, int& sum) {
	for (auto id : um[id].subordinates) {
		sum += um[id].size;
		dfs(id, um, sum);
	}
}

void od_50_impl(int n, vector<file> input) {
	unordered_map<int, file> um;
	for (auto c : input) {
		um[c.id] = c;
	}

	int sum = um[n].size;
	dfs(n, um, sum);
	cout << sum << endl;
}

//lionel���൱�ڣ���Ҫ��ÿһ�зŵ� file �ṹ����

void od50() {
	int m = 4;
	int n = 2;
	vector<int> tmp{ 4,5 };
	vector<int> emp;
	vector<file> inputs{ {4,20,emp},{5,30,emp},{2,10,tmp},{1,40,emp} };  //�������60
	od_50_impl(n, inputs);  //lionel�������ָ�룿
}
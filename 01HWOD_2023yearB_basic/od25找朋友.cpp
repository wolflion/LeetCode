#include "test.h"

/*
* 
* ��Ŀ����

��ѧУ�У�N��С����վ��һ�ӣ���i��С���ѵ����Ϊheight[i]��i��С���ѿ��Կ����ĵ�һ�����Լ���߸��ߵ�С����j����ô�ǵĺ�����(Ҫ��j>i)������������һ���б���Ӧλ�õ������ÿ��С���ѵĺ�����λ�ã����û�п��������ѣ����ڸ�λ����0���档С����������Χ��[0,40000].

��������

��һ������N��N��ʾ��N��С����

�ڶ�������N��С���ѵ����height[i]����������

�������

���N��С���ѵĺ����ѵ�λ��
*/

void od25() {
	int N=8;
	//cin >> N;
	vector<int> input{ 123,124,125,121,119,122,126,123 };
#if 0
	//��֤������������
	vector<int> tmp;
	int N1 = N;
	int num;
	while (N1-- && cin>>num){
		tmp.push_back(num);
	}
#endif
	
	vector<int> res(N);
	stack<int> stk;
	for (int i = N - 1; i >= 0; i--) {
		//ջ��Ԫ�رȵ�ǰС���򵯳�
		while (!stk.empty() && input[stk.top()] < input[i]) {
			stk.pop();
		}

		//���ջΪ�գ���˵���ұ�û�бȵ�ǰ�����
		if (stk.empty()) {
			res[i] = 0;   //��û�� vector<int> res(N);���г�ʼ��ʱ���±�������϶���crash��
		} else {
			res[i] = stk.top();
			//stk.pop();   //lionel��Ϊɶ������Բ���pop();
		}

		stk.push(i);
	}

	//output
	for (int i = 0; i < N; i++) {
		cout << res[i] << " ";  //lionel��Ϊɶ�������ֱ�����  1 2 6 5 5 6 0 0
	}
}


//https://blog.csdn.net/wj_phm/article/details/132477921
// 
//https://zhuanlan.zhihu.com/p/645550229
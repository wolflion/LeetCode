#include<iostream>
using namespace std;
#include<utility>
#include<vector>
#include<algorithm>
#include<string>
#include<sstream>

/*
* ��������ģ��һ����Ϣ���� ����������һ�������ߺ����������ߣ������߻��ڸ�����ʱ������Ϣ���з�����Ϣ,

����ʱ��Ϣ�����������߶��ģ������Ϣ�ᱻ���͵����ĵ������������ȼ����(�����������߰����ȼ���������)��һ��;
����ʱû�ж��ĵ������ߣ�����Ϣ����Ϣ���ж�����
����������ڸ�����ʱ�̶�����Ϣ���л�ȡ�����ġ�

����Ϣ���ͺͶ��ķ�����ͬһʱ��ʱ���ȴ����Ĳ�������ͬһʱ�̶��ĵ������߳�Ϊ��Ϣ���͵ĺ�ѡ��
����Ϣ���ͺ�ȡ�����ķ�����ͬһʱ��ʱ���ȴ���ȡ�����Ĳ���������Ϣ���ᱻ���͵�ͬһʱ��ȡ�����ĵ�������.
��������
����Ϊ���С� ��һ��Ϊ2N�����������������߷��͵�N����Ϣ��ʱ�̺�����(Ϊ������ۣ���Ϣ����Ҳ�������̱�ʾ)����һ�������ǵ�һ����Ϣ�ķ���ʱ�̣��ڶ��������ǵ�һ����Ϣ�����ݣ��Դ����ơ�������֤����ʱ�̲����ظ�����ע����Ϣ��û�а��շ���ʱ�����С� �ڶ���Ϊ2M��������������M�������߶��ĺ�ȡ�����ĵ�ʱ�̡���һ�������ǵ�һ�������߶��ĵ�ʱ�̣��ڶ��������ǵ�һ��������ȡ�����ĵ�ʱ�̣��Դ���ѡ�������֤ÿ�������ߵ�ȡ������ʱ�̴��ڶ���ʱ�̣������߰����ȼ� ��ϯ���С�

���е����ֶ��ɿո�ָ���N������100��M������10��ÿ�еĳ��Ȳ�����1000�ַ���

�������
���ΪM�У�����ΪM���������յ�����Ϣ���ݣ���Ϣ���ݰ��յ���˳�����У����ɿո�ָ�; ��ĳ��������û���յ��κ���Ϣ�����Ӧ�������-1��

����
����

2 22 1 11 4 44 5 55 3 33
1 7 2 3
���

11 33 44 55
22
˵��

��Ϣ11��1ʱ�̵����ʱֻ�е�һ�������߶��ģ���Ϣ���͸���;

��Ϣ22��2ʱ�̵����ʱ���������߶������ˣ���Ϣ���͸����ȼ���ߵĵڶ���������;

��Ϣ33��ʱ��3�����ʱֻ�е�һ�������߶��ģ���Ϣ���͸�����

���µ���Ϣ������Ҳ�Ƿ��͸���һ�������ߡ�

����

5 64 11 64 9 97
9 11 4 9
���

97
64
˵��

��Ϣ64��5ʱ�̵����ʱֻ�еڶ��������߶��ģ���Ϣ���͸�����

��Ϣ97��9ʱ�̵����ʱֻ�е�һ�����߶���(��Ϊ�ڶ��������߸պ���9ʱ��ȡ������)����Ϣ���͸�����

11ʱ��Ҳ������һ������Ϊ64����Ϣ��������Ϊû�������߶��ģ���Ϣ��������
*/


/*
* �ҵ�˼·��
* 1�����⣨Ҫ��5min��������
* 2�����������ʱ��û����⵽2��**������ȼ�**  ����ʵ���Ǵ�������ȼ���ʼ��
*/

bool cmp75(pair<int, int> &p1, pair<int, int> &p2) {
	return p1.first < p2.first;
}

void impl75(vector<pair<int, int>>& produce, vector<pair<int, int>>& consumer) {
	//�����ߵ�ʱ��
	int consumerLen = consumer.size();
	vector<vector<int>> res(consumerLen); //����ط���ʾ2ά��

	for (int i = 0; i < produce.size(); i++) {
		//for (int j = 0; j < consumer.size()-1; j++) {
		//����ʱ��Ϣ�����������߶��ģ������Ϣ�ᱻ���͵����ĵ������������ȼ����(�����������߰����ȼ���������)��һ��;
		for (int j = consumerLen -1; j >= 0; j--) {  //lionel������ط���ʾ[1,7],[2,3]  ���ȸ���һ���ȣ����ֱ�Ӹ�ǰһ���ȣ��϶�������
			//cout << produce[i].first << "," << consumer[j].first << "," << consumer[j].second << endl;
			if (produce[i].first >= consumer[j].first && produce[i].first < consumer[j].second) {
				res[j].push_back(produce[i].second);
				break;  //lionel�����break�����Ǳ���ֻ�������������һ������������ȼ����Ǹ�
			}
		}
	}

	//���
	for (int i = 0; i < consumerLen; i++) {
		if (res[i].empty()) {
			cout << "-1"<<endl;
		} else {
			for (int j = 0; j < res[i].size(); j++) {
				if (j > 0) {
					cout << " ";
				}
				cout << res[i][j];
			}
			cout << endl;
		}
	}
}

int main() {

#if 0
	string linep;
	string linec;
	//cin >> linep;  //����������д���ģ�2 22 1 11 4 44 5 55 3 33  ������ֻ�ܵ�2��
	//cin >> linec; //1 7 2 3  ������ֻ�ܵ�1��
	getline(cin, linep);
	getline(cin, linec);

	vector<pair<int, int>> produce, consumer;
	istringstream issp(linep);
	int num, content;
	while (issp >> num>>content) {
		produce.push_back(make_pair(num, content));
	}
	istringstream issc(linec);
	int start, end;
	while (issc >> start >> end) {
		consumer.push_back(make_pair(start, end));
	}
#endif

	vector<pair<int, int>> produce{ {2, 22}, {1, 11}, {4 ,44},{5, 55}, {3 ,33} };
	vector<pair<int, int>> consumer{ {1,7}, {2,3} };

	sort(produce.begin(), produce.end(), cmp75);

	impl75(produce, consumer);
}
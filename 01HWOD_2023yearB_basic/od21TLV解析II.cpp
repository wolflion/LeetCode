#include "test.h"
/*
* ��Ŀ����

����ͨ��TLV��ʽ�ı�����ͨ�ţ������յ��Զ˵�һ��TLV��ʽ����Ϣ����Ҫ������ƥ����(tag, length, valueOffset)�б�����Ҫ�����£�

(1)��Ϣ���ж���tag��length��value�������У�����tag,length��ռ1�ֽ�(uint8_t),value��ռ�ֽ�������length��ֵ

(2)���������tagֵ��֪����Ҫ���ÿ��tag��Ӧ���ݵ�length��valueOffsetֵ(valueOffsetΪvalue��ԭ��Ϣ���е���ʼƫ����(��0��ʼ�����ֽ�Ϊ��λ)),

������Ϣ���е�tag���������е�tag����ƥ��(���ܴ���ƥ��ʧ�ܵ����������������е�tag����Ϣ�����Ҳ�������length��

valueOffset��Ϊ0)

(3)��Ϣ���ͽ�������е�tagֵ�����������У��Ҳ��ظ�

(4)����Ϣ��δ���۸ģ���β�����ܲ���������������һ��TLV�붪����

��������

��һ�У�һ���ַ����������յ�����Ϣ�����ַ���������10000���ڡ�

��˵��1�ַ���ʹ��ʮ�������ı���ʽ(��ĸΪ��д)��չʾ��Ϣ�������ݣ���0F04ABABABAB����һ��TLVǰ�����ַ�(0F)����

tagֵΪ15,�����������ַ�(04)����lengthֵΪ4�ֽڣ�������8���ַ���Ϊ4�ֽڵ�value��

��˵��2:�����ַ����У�ÿһ��TLV�������У��м��޿ո�ȷָ���

�ڶ��У���Ҫƥ���tag����n(O<n<1000)��

����n�У���Ҫƥ���n��tagֵ(ʮ���Ʊ�ʾ),�������С�

�������

����Ҫƥ���n��tag��Ӧ��n��ƥ������ÿһ���ɳ��Ⱥ�ƫ�������
*/

//lionel��������Ⱦ���0x4��ƫ��������0xF0x4����2��ƫ������8���ַ�������4�ֽڣ�

void od21() {
	string s = "0F04ABABABAB";
	//getline(cin, s);
	int n = 1;
	int tag = 15;
	//int n=2,tag����2��ֵ��15��17

	//lionel�����ᣬ��map����¼��Ҫƥ���tag����������[��ʼ�㣬������]
	map<int, vector<int>> tagOffset;
	for (int i = 0; i < n; i++) {
		vector<int> tmp = { 0,0 };
		tagOffset[tag] = tmp;
	}

	int bound = s.size();
	int left = 0;
	int right = 2;
	int offset = 2;
	while (left < bound) {  //lionel,����ط�������д����left<=bound���Ҹĳ���left<bound
		//һ��ʼƥ��ľ���tag
		//https://blog.csdn.net/ma_minmin/article/details/126908825  [stoi(tmp,0,16)]
		string tmp = s.substr(left, right);//https://blog.csdn.net/zjl2222/article/details/112135497  [C++��16���ƣ�ת��10����]
		int tag = stoi(tmp,0,16);  //lionel��get�������

		int length = stoi(s.substr(left + 2, right + 2));

		//�ж�tag�Ƿ�ƥ��
		if (tagOffset.find(tag) != tagOffset.end() && ((offset + length) * 2 <= bound)) {  //lionel������ط�������д����<bound���Ҹĳ�<=��
			tagOffset[tag] = { length,offset };
		}

		//���ݳ���������ƫ����
		offset = offset + length + 2;
		left += (length * 2) + 4;
		right += (length * 2) + 4;
	}

	for (auto c : tagOffset) {
		cout << c.second[0] << " " << c.second[1] << endl;
	}
}


//https://zhuanlan.zhihu.com/p/647335136

//https://blog.csdn.net/wj_phm/article/details/132422947
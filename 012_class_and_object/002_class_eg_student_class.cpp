#include<iostream>


using std::cout;
using std::endl;
using std::string;
using std::cin;

// ����һ��ѧ����, ��������ѧ������, ���Ը�������ѧ�Ÿ�ֵ, ������ʾѧ����ѧ��
class Student {
	public:
		string s_name;
		string s_id;

		void setStuName(string name) {
			s_name = name;
		};
		void setStuId(string id) {
			s_id = id;
		};

		void showStuInfo() {
			string type = "";
			cout << "��������Ҫ��ѯ����Ϣ, name:ѧ������;id:ѧ��ѧ��;all:������ѧ��" << endl;
			cin >> type;
			if (type == "name") {
				cout << s_name << endl;
			}
			else if (type == "id") {
				cout << s_id << endl;
			}
			else if (type == "all") {
				cout <<"����" << s_name << endl;
				cout <<"ѧ��" << s_id << endl;
			}
		};


};


int main2() {
	Student stu1;
	stu1.setStuName("����");
	stu1.setStuId("114514");

	stu1.showStuInfo();

	system("pause");
	return 0;
}
#include<iostream>


using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ostream;


// ���� class �е� ��Ա������Ϊ˽��
// 1.���Կ��Ƴ�Ա���ԵĶ�д
// 2.����дȨ��,���Լ�����ݵ���Ч��

class Person {
public:
	void setName(string name) {
		p_name = name;
	};
	void getName() {
		cout << p_name << endl;
	};
	void getAge() {
		cout << (p_age ? 0 : p_age) << endl;
	};
	void setSex(int sex) {
		p_sex = sex == 1 ? "��" : "Ů";
	}



private:
	string p_name;// �ɶ���д
	int p_age;// ֻ��
	string p_sex;// ֻд
};

int main5() {
	Person person;
	person.setName("����");
	person.setSex(1);
	person.getAge();
	person.getName();
	system("pause");
	return 0;
}
#include <iostream>

using std::cout;
using std::endl;
using std::string;

//������
class Person {
public:
	int m_Age;
	mutable int m_Height;// mutable ���γ�Ա����,��ָ������һ�����޸ĵĳ�Ա����, ���ܵ���������Ӱ��
	// this ָ��ı�����һ��ָ�볣��,ָ���ָ���ǲ����Ըı��,��Զָ�� ʵ������
	// ���� thisָ���ֵ�ǿ��Ա��
	void setAge(int age) {
		this->m_Age = age;
	}
	// ͨ��const���غ�����������������this,  ��thisָ����һ�� ����ָ�볣��, ʹ��thisָ��(ʵ��)�����ֵҲ���ɱ��޸�
	void setHeight(int h)const {
		//this->m_Age = 20;// errorҪ���޸� ��Ա����, �������mutable
		this->m_Height = h;//Error, Ҫ���޸� ��Ա����, �������mutable
	}
};
// ������, ���ʻ��Ǻ�thiָ��һ����, ��Ϊthisָ��ָ��ľ��ǳ�����
void test01() {
	const Person p;// 1. ʹ��const ������һ��������,  �������Ա���Բ��ܸ���, ���Ǹó�Ա����ǰ��mutable���η���
	p.setHeight(20);// ������ֻ�ܵ��ó�����
	//p.setAge(20);//�������ܵ�����ͨ����,��Ϊ��ͨ�������Ը������Գ�Ա, ��������ķ�mutable��Ա�����ǲ��������ĵ�,���Գ�����ֻ�ܵ��ó�����
}
int main() {
	test01();
	system("pause");
	return 0;
}

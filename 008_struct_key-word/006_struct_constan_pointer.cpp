#include<iostream>


using namespace std;



// 1.���� ������Ϣ�ṹ��
struct Song {
	string name;
	string author;
	int second;
	bool isVIP;
};

//3.��������  ��ַ����
void printSongInfoByAddress(Song* song);

int main6() {

	// 6. �����ṹ�����
	Song song = { "������","�ܽ���",321,true };
	cout << "�ṹ��ռ�ÿռ�" << sizeof(song) << endl;// 88

	printSongInfoByAddress(&song);// ��ַ����
	cout << "��ַ���ݺ�,ԭ���ṹ������ֱ�Ϊ��:" << song.name << endl;// ���ǵ�ַ���ݰ汾 ��ַ����, ʵ�θı���
	return 0;
}
// 5.�����ӡ������Ϣ����  ��ַ���ݰ汾
void printSongInfoByAddress(const Song* song) {// ָ�봫�� ���ֵ���ݿ��Խ�ʡ�ڴ�, ���ǲ���ȫ,���ݿ��ܻᱻ�޸�, ʹ�ó���ָ��,�����޸�
	//song->name = "���ǵ�ַ���ݰ汾";// ʹ�ó���ָ���, ��Աvalue���ܱ��޸�
	cout << "������: " << song->name << "\n����: " << song->author << "\nʱ��" << song->second << "\n�Ƿ���ҪVIP: " << (song->isVIP ? "��" : "��") << endl;
};

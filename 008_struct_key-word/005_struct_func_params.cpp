#include<iostream>


using namespace std;



// ��������Ϣ��װΪ�ṹ��, Ȼ��ȥ��ӡ������Ϣ
// 1.���� ������Ϣ�ṹ��

struct Song {
	string name;
	string author;
	int second;
	bool isVIP;
};

//2.��������   ֵ����
void printSongInfoByValue(struct Song song);

//3.��������  ��ַ����
void printSongInfoByAddress(struct Song *song);

int main5() {

	// 6. �����ṹ�����
	Song song = {"������","�ܽ���",321,true};
	cout << "�ṹ��ռ�ÿռ�" << sizeof(song) << endl;// 88

	printSongInfoByValue(song); // ֵ����
	cout << "ֵ���ݺ�,ԭ���ṹ������ֱ�Ϊ��:" << song.name << endl;//������ ����  ֵ���ݲ���ı�ԭ���ṹ���г�Ա��value

	printSongInfoByAddress(&song);// ��ַ����
	cout << "��ַ���ݺ�,ԭ���ṹ������ֱ�Ϊ��:" << song.name << endl;// ���ǵ�ַ���ݰ汾 ��ַ����, ʵ�θı���
	return 0;
}


// 4.�����ӡ������Ϣ����  ֵ���ݰ�
void printSongInfoByValue(struct Song song) {
	song.name = "����ֵ���ݺ����ı��˵�";
	cout << "������: " << song.name << "\n����: " << song.author << "\nʱ��" << song.second << "\n�Ƿ���ҪVIP: " << (song.isVIP ? "��" : "��") << endl;
};


// 5.�����ӡ������Ϣ����  ��ַ���ݰ汾
void printSongInfoByAddress(struct Song *song) {
	song->name = "���ǵ�ַ���ݰ汾";
	cout << "������: " << song->name << "\n����: " << song->author << "\nʱ��"<<song->second << "\n�Ƿ���ҪVIP: " << (song->isVIP ? "��" : "��") << endl;
};

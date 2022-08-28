#include<iostream>


using namespace std;



// 将歌曲信息包装为结构体, 然后去打印歌曲信息
// 1.定义 歌曲信息结构体

struct Song {
	string name;
	string author;
	int second;
	bool isVIP;
};

//2.声明函数   值传递
void printSongInfoByValue(struct Song song);

//3.声明函数  地址传递
void printSongInfoByAddress(struct Song *song);

int main5() {

	// 6. 创建结构体变量
	Song song = {"七里香","周杰伦",321,true};
	cout << "结构体占用空间" << sizeof(song) << endl;// 88

	printSongInfoByValue(song); // 值传递
	cout << "值传递后,原来结构体的名字变为了:" << song.name << endl;//七里香 不变  值传递不会改变原来结构体中成员的value

	printSongInfoByAddress(&song);// 地址传递
	cout << "地址传递后,原来结构体的名字变为了:" << song.name << endl;// 这是地址传递版本 地址传递, 实参改变了
	return 0;
}


// 4.定义打印歌曲信息函数  值传递版
void printSongInfoByValue(struct Song song) {
	song.name = "这是值传递函数改变了的";
	cout << "歌曲名: " << song.name << "\n作者: " << song.author << "\n时长" << song.second << "\n是否需要VIP: " << (song.isVIP ? "是" : "否") << endl;
};


// 5.定义打印歌曲信息函数  地址传递版本
void printSongInfoByAddress(struct Song *song) {
	song->name = "这是地址传递版本";
	cout << "歌曲名: " << song->name << "\n作者: " << song->author << "\n时长"<<song->second << "\n是否需要VIP: " << (song->isVIP ? "是" : "否") << endl;
};

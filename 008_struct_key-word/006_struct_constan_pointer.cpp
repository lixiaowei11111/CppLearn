#include<iostream>


using namespace std;



// 1.定义 歌曲信息结构体
struct Song {
	string name;
	string author;
	int second;
	bool isVIP;
};

//3.声明函数  地址传递
void printSongInfoByAddress(Song* song);

int main6() {

	// 6. 创建结构体变量
	Song song = { "七里香","周杰伦",321,true };
	cout << "结构体占用空间" << sizeof(song) << endl;// 88

	printSongInfoByAddress(&song);// 地址传递
	cout << "地址传递后,原来结构体的名字变为了:" << song.name << endl;// 这是地址传递版本 地址传递, 实参改变了
	return 0;
}
// 5.定义打印歌曲信息函数  地址传递版本
void printSongInfoByAddress(const Song* song) {// 指针传递 相比值传递可以节省内存, 但是不安全,数据可能会被修改, 使用常量指针,仿真修改
	//song->name = "这是地址传递版本";// 使用常量指针后, 成员value不能被修改
	cout << "歌曲名: " << song->name << "\n作者: " << song->author << "\n时长" << song->second << "\n是否需要VIP: " << (song->isVIP ? "是" : "否") << endl;
};

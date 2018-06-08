#include <iostream>
#include <windows.h>
#pragma comment(lib,"winmm.lib")
using namespace std;

/**
 * @@ 函数使用说明
 * 1. 更改引用文件地址
 * 2. 更改引用文件别名
 * 3. 调用函数，传递参数
 */

class Sounder {
	public:
		void sounder(int f);
	private:
		int f;
};

void Sounder::sounder(int f)
{
	mciSendString("open x.mp3 alias xxx", NULL, 0, NULL);	//更改 x.mp3 为实际路径文件名，更改 xxx 为后续调用别名
	if (f == 1) {
		mciSendString("play xxx", NULL, 0, NULL);	//若参数为 1，则播放 xxx
	}
	else if (f == 2) {
		mciSendString("stop xxx", NULL, 0, NULL);	//若参数为 2，则停止 xxx
	}
	else if (f == 0) {
		mciSendString("close xxx", NULL, 0, NULL);	//若参数为 0，则关闭 xxx 。关闭后若想再次打开文件，请再次调用函数
	}
}

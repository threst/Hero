#include <iostream>
#include <ctime>
using namespace std;

class Timer {
	public:
		void timer(int n);
	private:
		int n;
};

void Timer::timer(int n)
{
	double dur;				//经历时间
	clock_t str, end;			//开始时刻, 结束时刻

	cout << n << endl;			//预留参数接口测试
	str = clock();
	cout << str << endl;			//替换技能释放函数
	end = clock();
	dur = (double)(end - str);
	cout << dur/CLOCKS_PER_SEC << endl;	//时间单位_毫秒转秒
}

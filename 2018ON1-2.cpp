/*
 * Start Time:2020. 06. 26. (금) 17:02:51 KST
 */
#include <iostream>
#include <cstring>
#include <climits>
int startP;
int arrLen;
int comCnt;
int arr[100000];

void getInput()
{
	std::cin >> arrLen >> startP >> comCnt;
	for (int i = 0; i < arrLen; i++)
		std::cin >> arr[i];
}

bool getRange(int cmd, int* begin, int* end, int target)
{
	int a, b;

	if (cmd > 0) {
		a = 0;
		b = cmd -1;
	}
	else {
		a = arrLen +cmd;
		b = arrLen -1;
	}

	if (target >= a && target <= b) {
		*begin = a;
		*end = b;
		return true;
	}
	return false;
}

int getNewPosition(int begin, int end, int target)
{
	return end - (target - begin);
}

int solve()
{
	int ret = startP -1;

	for (int i = 0; i < comCnt; i++) {
		int cmd;
		int begin;
		int end;

		std::cin >> cmd;

		if (getRange(cmd, &begin, &end, ret)) {
			ret = getNewPosition(begin, end, ret);
		}
	}

	return ret +1;
}

int main()
{
	getInput();

	int ret = solve();
	std::cout << ret << std::endl;

	return 0;
}
/*
 * End Time: 2020-06-26 17:29:24 KST

 */

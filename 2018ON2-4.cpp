/*
 * Start Time:2020. 07. 21. (화) 09:37:05 KST
 */
#include <iostream>
#include <map>
#include <cstring>
#include <climits>

std::map<int, int> hMap;

/* for R, C, D, W */
int R, C, D, W;
/* for R x C */
int cnt;
/* for map */
int map[50][50];
int vMap[50][50];

void getInput()
{
	std::cin >> R >> C >> D >> W;
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++) {
			std::cin >> map[i][j];
			auto ret = hMap.insert(std::pair<int, int>(map[i][j], 1));
			if (!ret.second)
				ret.first->second++;
		}
	// to store area size */
	int tmp = 0;
	for (auto& i : hMap) {
		i.second += tmp;
		tmp = i.second;
	}

	cnt = R * C;
	if (!(cnt & 1))
		hMap.insert(std::pair<int, int>(0, 0));
}

bool isValid(int y, int r, int c)
{
	if (r >= R)
		return true;

	if (c >= C)
		return isValid(y, r+1, 0);

	if (vMap[r][c])
		goto GO_NEXT;
	vMap[r][c] = 1;
	if (map[r][c] <= y) {
		/* handle building */
		//std::cout << '[' << r << ',' << c << ']' << 'b' << std::endl;
		goto GO_NEXT;
	}
	else { /* handle park */
		//std::cout << '[' << r << ',' << c << ']' << 'p' << std::endl;
		if (c+1 < C && map[r][c+1] > y && !vMap[r][c+1]) {
			//std::cout << '[' << r << ',' << c+1 << ']' << 'p' << std::endl;
			vMap[r][c+1] = 1;
			if (isValid(y, r, c+2))
				return true;
			//std::cout << '[' << r << ',' << c+1 << ']' << 'x' << std::endl;
			vMap[r][c+1] = 0;
		}
		if (r+1 < R && map[r+1][c] > y && !vMap[r+1][c]) {
			//std::cout << '[' << r+1 << ',' << c << ']' << 'p' << std::endl;
			vMap[r+1][c] = 1;
			if (isValid(y, r, c+1))
				return true;
			vMap[r+1][c] = 0;
			//std::cout << '[' << r+1 << ',' << c << ']' << 'x' << std::endl;
		}
		return false;
	}

GO_NEXT:
	return isValid(y, r, c+1);
}

int solve()
{
	int ret = INT_MAX;

	for (auto& i : hMap) {
		memset(vMap, 0x00, sizeof(int) * 50 * 50);
		if ((cnt - i.second) & 1) {
			//std::cout << i.first << " is not good" << std::endl;
			continue;
		}
		int building = i.first * W;
		int park = ((cnt - i.second) >> 1) * D;
		int sum = building + park;
		if (ret <= sum) {
			//std::cout << i.first << " is big:" << sum << std::endl;
			continue;
		}
		if (!isValid(i.first, 0, 0)) {
			//std::cout << i.first << " is not valid:" << sum << std::endl;
			continue;
		}
		//std::cout << i.first << " is good:" << sum << std::endl;
		ret = sum;
	}

	return ret;
}

int main()
{
	getInput();

	for (auto& i : hMap)
		std::cout << i.first << ':' << i.second << std::endl;

	std::cout << solve();

	return 0;
}
/*
 * End Time: from LGE CodeJam site
 */

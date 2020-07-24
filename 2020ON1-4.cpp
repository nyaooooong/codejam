/*
 * Start Time:2020. 07. 23. (목) 12:21:52 KST
 */
#include <iostream>
#include <cstring>
#include <climits>

int solve(int R, int C)
{
	std::vector<std::pair<int, int>> e1;
	std::vector<std::pair<int, int>> e2;
	std::vector<std::pair<int, int>> e3;
	std::vector<std::pair<int, int>> e4;

	for (int r = R; r > 0; r--) {
		for (int c = C-1; c > 0; c--) {
			int tmp;
			std::cin >> tmp;
			switch (tmp) {
				case 1: std::pair<int, int>
					break;
				case 2:
					break;
				case 3:
					break;
				case 4:
					break;
			}
		}
	}

	return 0;
}

int main()
{
	std::cout.sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t;

	std::cin >> t;

	while (t--) {
		int r, c;
		std::cin >> r >> c;
		int ret = solve(r, c);
	}

	return 0;
}
/*
 * End Time: from LGE CodeJam site
 */

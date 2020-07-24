/*
 * Start Time:2020. 07. 21. (화) 18:55:48 KST
 */
#include <ios>
#include <iostream>
#include <cstring>
#include <climits>
#include <vector>
#include <array>
#include <algorithm>


struct _comp {
	bool operator() (std::array<int, 5>& a, std::array<int, 5>& b) {
		return a[4] < b[4];
	}
} compObj;

int solve(int n)
{
	std::vector<std::array<int, 5>> man(n+1, {0, 0, 0, 0, 0});
	std::vector<int> out[3];
	int a, b, c, i;
	std::cin >> a >> b >> c;

	std::cin >> i;
	while (i--) {
		int tmp;
		std::cin >> tmp;
		man[tmp][1] = 1;
		man[tmp][4]++;
		man[0][1]++;
	}
	std::cin >> i;
	while (i--) {
		int tmp;
		std::cin >> tmp;
		man[tmp][2] = 1;
		man[tmp][4]++;
		man[0][2]++;
	}
	std::cin >> i;
	while (i--) {
		int tmp;
		std::cin >> tmp;
		man[tmp][3] = 1;
		man[tmp][4]++;
		man[0][3]++;
	}
	
	for (int i = 1; i <= n; i++)
		man[i][0] = i;

	std::sort(man.begin()+1, man.end(), compObj);

	/*
	for (int i = 0; i <= n; i++)
		std::cout << man[i][0] << ',' << man[i][4] << ',' << man[i][1] << ',' << man[i][2] << ',' << man[i][3] << '\n';
	std::cout << '\n';
	*/

	for (int i = 1; i <= n; i++) {
		if (man[i][1] && a > 0) {
			a--;
			out[0].push_back(man[i][0]);
		}
		else if (man[i][2] && b > 0) {
			b--;
			out[1].push_back(man[i][0]);
		}
		else if (man[i][3] && c > 0) {
			c--;
			out[2].push_back(man[i][0]);
		}
	}

	int cnt = out[0].size() + out[1].size() + out[2].size();
	std::cout << cnt << '\n';
	for (int i = out[0].size() -1; i >= 0; i--)
		std::cout << out[0][i] << ' ' << 'A' << '\n';
	for (int i = out[1].size() -1; i >= 0; i--)
		std::cout << out[1][i] << ' ' << 'B' << '\n';
	for (int i = out[2].size() -1; i >= 0; i--)
		std::cout << out[2][i] << ' ' << 'C' << '\n';

	return 0;
}

int main()
{
	int T, n;
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::cin >> T;

	for (; T > 0; T--) {
		std::cin >> n;
		solve(n);
	}

	return 0;
}
/*
 * End Time: from LGE CodeJam site
 */

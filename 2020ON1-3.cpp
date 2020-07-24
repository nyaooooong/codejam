/*
 * Start Time:2020. 07. 22. (수) 19:42:41 KST
 */
#include <ios>
#include <iostream>
#include <cstring>
#include <climits>
#include <array>
#include <deque>
#include <algorithm>

struct _compObj {
	bool operator() (std::array<int, 2>& a,std::array<int, 2>& b) {
		return abs(a[0] - a[1]) < abs(b[0] - b[1]);
	}
} compObj;

int solve(int n, int k)
{
	int ret = 0;
	std::deque<std::array<int, 2>> man(n);
	std::deque<std::array<int, 2>> o;
	std::deque<std::array<int, 2>> d;

	for (int i = n-1; i >= 0; i--)
		std::cin >> man[i][0];
	for (int i = n-1; i >= 0; i--)
		std::cin >> man[i][1];

	for (int i = n-1; i >= 0; i--)
		if (man[i][0] > man[i][1])
			o.push_back(man[i]);
		else
			d.push_back(man[i]);

	std::sort(o.begin(), o.end(), compObj);
	std::sort(d.begin(), d.end(), compObj);

	while(abs(o.size() - d.size()) > k) {
		if (o.size() > d.size()) {
			d.push_front(o.front());
			o.pop_front();
		}
		else {
			o.push_front(d.front());
			d.pop_front();
		}
	}

	std::deque<std::array<int, 2>>::iterator it = o.begin();
	while (it != o.end())
		ret += (*it++)[0];
	it = d.begin();
	while (it != d.end())
		ret += (*it++)[1];

	std::cout << ret << '\n';
	/*
	for (int i = n-1; i >= 0; i--)
		std::cout << man[i][0] << ' ';
	std::cout << '\n';
	*/

	return 0;
}

int main()
{
	int t;
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::cin >> t;
	while (t--) {
		int n, k;
		std::cin >> n >> k;
		solve(n, k);
	}

	return 0;
}
/*
 * End Time: from LGE CodeJam site
 */

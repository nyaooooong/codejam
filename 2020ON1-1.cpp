/*
 * Start Time:2020. 07. 21. (화) 12:48:13 KST
 */
#include <iostream>
#include <cstring>
#include <climits>
#include <algorithm>
#include <string>
#include <vector>

int T;

void getInput()
{
	std::cin >> T;
}

int solve()
{
	int n;

	std::cin >> n;
	std::vector<std::string> d1(n), d2(n);
	for (int i = n-1; i >= 0; i--)
		std::cin >> d1[i];
	for (int i = n-1; i >= 0; i--)
		std::cin >> d2[i];
	std::sort(d1.begin(), d1.end());
	std::sort(d2.begin(), d2.end());

	for (int i = n-1; i >= 0; i--)
		if (d1[i] != d2[i])
			return 1;
	return 0;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	getInput();

	for (int i = T; i > 0; i--)
		std::cout << (solve()? "CHEATER\n" : "NOT CHEATER\n");

	return 0;
}
/*
 * End Time: 2020-07-21 18:55:13 KST
 */

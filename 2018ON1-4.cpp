/*
 * Start Time:2020. 06. 30. (화) 09:39:11 KST
 */
#include <iostream>
#include <cstring>
#include <climits>
#include <vector>
#include <algorithm>

int N;
int M;
int K;

class Road {
public :
	int v1;
	int v2;
	int c;
	int t;
	Road(int tmpa, int tmpb, int tmpc, int tmpt) : v1(tmpa), v2(tmpb), c(tmpc), t(tmpt) {}
	static bool compare(Road& a, Road& b) {
		if (a.v1 == b.v1) 
			return a.v2 < b.v2;
		return a.v1 < b.v1;
	}
};

std::vector<Road> rmap;

void getInput()
{
	std::cin >> N >> M >> K;
	for (int i = 0; i < M; i++) {
		int a, b, c, t;
		std::cin >> a >> b >> c >> t;
		Road r(a, b, c, t);
		rmap.push_back(r);
	}
	std::sort(rmap.begin(), rmap.end(), Road::compare);
}

void printOut()
{
	std::cout << N << std::endl;
	std::cout << M << std::endl;
	std::cout << K << std::endl;
	std::vector<Road>::iterator itor = rmap.begin();
	for (;itor != rmap.end(); itor++)
		std::cout << (*itor).v1 << ' ' << (*itor).v2 << std::endl;
}

int solve()
{
//	printOut();


	return 0;
}

int main()
{
	getInput();

	int ret = solve();
	std::cout << ret << std::endl;

	return 0;
}
/*
 * End Time: from LGE CodeJam site
 */

/*
 * Start Time:2020. 06. 29. (월) 08:13:44 KST
 */
#include <iostream>
#include <cstring>
#include <climits>
#include <set>
#include <vector>

int N;
std::vector<int> tower[1000];
int dices[1000];
std::multiset<int> diceSet;

void getInput()
{
	std::cin >> N;
	for (int i = 0; i < N; i++) {
		int tmp;
		std::cin >> tmp;
		diceSet.insert(tmp);
		dices[i] = tmp;
	}
}

void out()
{
	std::multiset<int>::iterator it = diceSet.begin();
	for (it = diceSet.begin(); it != diceSet.end(); it++) {
		std::cout << *it << std::endl;
	}
}

int solve()
{
	int towerCnt = 0;

	std::multiset<int>::iterator it = diceSet.begin();
	for (it = diceSet.begin(); it != diceSet.end(); it++) {
		int curDice = *it;
		bool find = false;
		for (int i = 0; i < towerCnt; i++) {
			if (tower[i].size() <= curDice) {
				find = true;
				tower[i].push_back(curDice);
				break;
			}
		}
		if (!find) {
			tower[towerCnt].push_back(curDice);
			towerCnt++;
		}

	}

	return towerCnt;
}

int main()
{
	getInput();

	int ret = solve();
	std::cout << ret << std::endl;

	return 0;
}
/*
 * End Time:2020-06-29 09:09:16 KST
 */

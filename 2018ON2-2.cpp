/*
 * Start Time:2020. 07. 06. (월) 17:16:08 KST
 */
#include <iostream>
#include <cstring>
#include <climits>

int N, Q, M;

void getInput()
{
	std::cin >> N >> Q >> M;
}

int solve(int n)
{
	int X[2][n];
	int cur = 0;
	int pcur;

	for (int i = n-1; i >= 0; i--) {
		X[cur][i] = 0;
	}

	for (int i = Q; i > 0; i--) {
		pcur = cur;
		cur ^= 1;
		char cmd;
		std::cin >> cmd;
		if (cmd == 'r') {
			int cmd1, cmd2;
			std::cin >> cmd1 >> cmd2;
			for (int j = n -1; j >= 0; j--) {
				if (j > cmd2 || j < cmd1)
					X[cur][j] = X[pcur][j];
				else
					X[cur][cmd1 + cmd2 - j] = X[pcur][j];
			}
		}
		else {
			for (int j = n -1; j >= 0; j--)
				X[cur][j] = X[pcur][j] + j;
		}
	}

	for (int i = M; i > 0; i--) {
		int Y;
		std::cin >> Y;
		std::cout << X[cur][Y] << std::endl;
	}

	return 0;
}

int solve2(int q)
{
	int cmd[q][3];
	int cmdCnt = -1;
	char prevCmd = 'a';

	for (int i = q; i > 0; i--) {
		char tmp;
		std::cin >> tmp;
		if (tmp == 'a') {
			if (cmdCnt == -1 || prevCmd != tmp) {
				cmd[++cmdCnt][0] = 0;
				cmd[cmdCnt][1] = 1;
			}
			else
				cmd[cmdCnt][1]++;
		}
		else {
			cmd[++cmdCnt][0] = 1;
			std::cin >> cmd[cmdCnt][1] >> cmd[cmdCnt][2];
		}
		prevCmd = tmp;
	}

	for (int i = M; i > 0; i--) {
		int Y;
		long long int xv = 0;
		std::cin >> Y;
		int xi = Y;
		for (int j = cmdCnt; j >= 0; j--) {
			if (cmd[j][0]) {
				if (xi >= cmd[j][1] && xi <= cmd[j][2])
					xi = cmd[j][1] + cmd[j][2] - xi;
			}
			else {
				xv += xi * cmd[j][1];
			}
		}
		std::cout << xv << std::endl;
	}

	return 0;
}

int main()
{
	getInput();

//	int ret = solve(N);
	int ret = solve2(Q);

	return ret;
}
/*
 * End Time: 2020-07-06 18:38:35 KST
 */

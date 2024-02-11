#include <bits/stdc++.h>
using namespace std;

/*
 Q2. Given a snake and ladder board, assume, a player has total control over the outcome of the dice
 throw and wants to determine the minimum number of throws required to reach the last cell
 from the first cell. The solution is not necessarily unique.
 [Rule: If the player reaches a cell which is the base of a ladder, the player has to climb up that
 ladder and if reaches a cell is the mouth of the snake, and has to go down to the tail of the snake
 without a dice throw.]
*/

struct QueueEntry {
	int vertex;
	int distance;
};

int getMinDiceThrows(int moves[], int N) {
	bool* visited = new bool[N]();
	queue<QueueEntry> q;
	visited[0] = true;
	QueueEntry start = { 0, 0 };
	q.push(start);

	QueueEntry current;
	while (!q.empty()) {
		current = q.front();
		int v = current.vertex;
		if (v == N - 1)
			break;
		q.pop();
		for (int j = v + 1; j <= (v + 6) && j < N; ++j) {
			if (!visited[j]) {
				QueueEntry next;
				next.distance = (current.distance + 1);
				visited[j] = true;
				next.vertex = (moves[j] != -1) ? moves[j] : j;
				q.push(next);
			}
		}
	}
	return current.distance;
}

int main() {
	int boardSize = 30;
	int moves[boardSize] = { -1 };

    // Ladders
	moves[2] = 21;
	moves[4] = 7;
	moves[10] = 25;
	moves[19] = 28;

    // Snakes
	moves[26] = 0;
	moves[20] = 8;
	moves[16] = 3;
	moves[18] = 6;
	cout << "Minimum number of dice throws required is " << getMinDiceThrows(moves, boardSize);
	return 0;
}
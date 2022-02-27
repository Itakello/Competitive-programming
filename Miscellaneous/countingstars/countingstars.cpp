// https://open.kattis.com/contests/pp9wfr/problems/countingstars
#include <iostream>
#include <stdio.h>

using namespace std;
int M, N;

void rec(int i, int j, bool** mat, bool** visited) {
	if (i >= 0 && i < M && j >= 0 && j < N) {
		if (!visited[i][j]) {
			visited[i][j] = true;
			if (mat[i][j]) {
				rec((i - 1), j, mat, visited);
				rec((i + 1), j, mat, visited);
				rec(i, (j - 1), mat, visited);
				rec(i, (j + 1), mat, visited);
				}
			}
		}
	}

int main(int argc, char const* argv[]) {
	int num = 1;
	while (cin >> M) {
		cin >> N;

		bool** mat;
		mat = new bool* [M];
		for (int i = 0; i < M; i++) {
			mat[i] = new bool[N];
			for (int j = 0; j < N; j++) {
				char pix;
				cin >> pix;
				mat[i][j] = pix == '#' ? false : true;
				}
			}

		bool** visited;
		visited = new bool* [M];
		for (int i = 0; i < M; i++) {
			visited[i] = new bool[N];
			for (int j = 0; j < N; j++) {
				visited[i][j] = false;
				}
			}

		int count = 0;
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				if (!visited[i][j]) {
					visited[i][j] = true;
					if (mat[i][j]) {
						//cout << "ok " << i << "-" << j;
						count++;
						rec((i - 1), j, mat, visited);
						rec((i + 1), j, mat, visited);
						rec(i, (j - 1), mat, visited);
						rec(i, (j + 1), mat, visited);
						}
					}
				}
			}
		cout << "Case " << num << ": " << count << endl;
		num++;
		}
	return 0;
	}

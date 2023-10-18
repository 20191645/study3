// ���� ����Ʈ ��� �׷����� Ȱ���Ͽ� BFS ����
#include "ALGraphBFS.h"
#include <iostream>

// ������ -- ALGraph ���� �� �ʱ�ȭ, �湮 ���� �迭 �ʱ�ȭ
ALGraphBFS::ALGraphBFS(int v)
	:ALGraph(v)
{
	visit = new int[v];
	// visitinfo �ʱ�ȭ -- 0: �湮X, 1: �湮O
	for (int i = 0; i < v; i++)
		visit[i] = 0;
}

// �ı���
ALGraphBFS::~ALGraphBFS() {
	delete[] visit;
}

// DFS ������� �׷����� Ž���Ͽ� ���� ���� ���
void ALGraphBFS::ShowVertexInfo(int start) const {
	ArrayQueue path;	// ��� ������ ���� ���� ���� ����
	int cur = start;	// ���� Ž�� ����
	int next;			// ���� Ž�� ����
	int p;				// 1�̸� �湮 ���� ���� ã�Ҵٴ� ��

	// visitinfo �ʱ�ȭ -- 0: �湮X, 1: �湮O
	for (int i = 0; i < Vnum; i++)
		visit[i] = 0;
	
	path.Enqueue(start);
	std::cout << char(cur + 65) << ' ';
	while (!path.isEmpty()) {
		cur = path.Dequeue();
		visit[cur] = 1;

		// ����� ���� �� �湮 ���� ���� ��� �湮
		if (adjList[cur].LFirst(&next)) {
			if (visit[next] == 0) {
				std::cout << char(next + 65) << ' ';
				visit[next] = 1;
				path.Enqueue(next);
			}
			while(adjList[cur].LNext(&next))
				if (visit[next] == 0) {
					std::cout << char(next + 65) << ' ';
					visit[next] = 1;
					path.Enqueue(next);
				}
		}
	}
}


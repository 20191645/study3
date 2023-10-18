// ���� ����Ʈ ��� �׷����� Ȱ���Ͽ� DFS ����
#include "ALGraphDFS.h"
#include <iostream>

// ������ -- ALGraph ���� �� �ʱ�ȭ, �湮 ���� �迭 �ʱ�ȭ
ALGraphDFS::ALGraphDFS(int v)
	:ALGraph(v)
{
	visit = new int[v];
	// visitinfo �ʱ�ȭ -- 0: �湮X, 1: �湮O
	for (int i = 0; i < v; i++)
		visit[i] = 0;
}

// �ı���
ALGraphDFS::~ALGraphDFS() {
	delete[] visit;
}

// DFS ������� �׷����� Ž���Ͽ� ���� ���� ���
void ALGraphDFS::ShowVertexInfo(int start) const {
	ArrayStack path;	// ��� ������ ���� ���� ���� ����
	int cur = start;	// ���� Ž�� ����
	int next;			// ���� Ž�� ����
	int p;				// 1�̸� �湮 ���� ���� ã�Ҵٴ� ��

	// visitinfo �ʱ�ȭ -- 0: �湮X, 1: �湮O
	for (int i = 0; i < Vnum; i++)
		visit[i] = 0;

	path.Push(start);
	std::cout << char(cur + 65) << ' ';
	while (!path.isEmpty()) {
		visit[cur] = 1;
		p = 0;

		// ����� ���� �� �湮 ���� ���� ã��
		if (adjList[cur].LFirst(&next)) {
			if (visit[next] == 0)
				p = 1;
			while (p == 0 && adjList[cur].LNext(&next))
				if (visit[next] == 0)
					p = 1;
		}

		// ����� ������ ��� �湮�� ������ ��� -- �� Ʈ��ŷ
		if (p == 0) {
			next = path.Pop();
		}
		// �湮 ���� ������ ã�� ���
		else {
			path.Push(cur);
			// ���� �湮�� ���� ���
			std::cout << char(next + 65) << ' ';
		}

		cur = next;
	}

}


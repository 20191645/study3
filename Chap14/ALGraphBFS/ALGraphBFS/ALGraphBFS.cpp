// 인접 리스트 기반 그래프를 활용하여 BFS 구현
#include "ALGraphBFS.h"
#include <iostream>

// 생성자 -- ALGraph 생성 및 초기화, 방문 정보 배열 초기화
ALGraphBFS::ALGraphBFS(int v)
	:ALGraph(v)
{
	visit = new int[v];
	// visitinfo 초기화 -- 0: 방문X, 1: 방문O
	for (int i = 0; i < v; i++)
		visit[i] = 0;
}

// 파괴자
ALGraphBFS::~ALGraphBFS() {
	delete[] visit;
}

// DFS 기반으로 그래프를 탐색하여 정점 정보 출력
void ALGraphBFS::ShowVertexInfo(int start) const {
	ArrayQueue path;	// 경로 추적을 위한 정점 정보 스택
	int cur = start;	// 현재 탐색 정점
	int next;			// 다음 탐색 정점
	int p;				// 1이면 방문 안한 정점 찾았다는 뜻

	// visitinfo 초기화 -- 0: 방문X, 1: 방문O
	for (int i = 0; i < Vnum; i++)
		visit[i] = 0;
	
	path.Enqueue(start);
	std::cout << char(cur + 65) << ' ';
	while (!path.isEmpty()) {
		cur = path.Dequeue();
		visit[cur] = 1;

		// 연결된 정점 중 방문 안한 정점 모두 방문
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


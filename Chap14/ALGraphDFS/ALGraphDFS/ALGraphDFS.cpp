// 인접 리스트 기반 그래프를 활용하여 DFS 구현
#include "ALGraphDFS.h"
#include <iostream>

// 생성자 -- ALGraph 생성 및 초기화, 방문 정보 배열 초기화
ALGraphDFS::ALGraphDFS(int v)
	:ALGraph(v)
{
	visit = new int[v];
	// visitinfo 초기화 -- 0: 방문X, 1: 방문O
	for (int i = 0; i < v; i++)
		visit[i] = 0;
}

// 파괴자
ALGraphDFS::~ALGraphDFS() {
	delete[] visit;
}

// DFS 기반으로 그래프를 탐색하여 정점 정보 출력
void ALGraphDFS::ShowVertexInfo(int start) const {
	ArrayStack path;	// 경로 추적을 위한 정점 정보 스택
	int cur = start;	// 현재 탐색 정점
	int next;			// 다음 탐색 정점
	int p;				// 1이면 방문 안한 정점 찾았다는 뜻

	// visitinfo 초기화 -- 0: 방문X, 1: 방문O
	for (int i = 0; i < Vnum; i++)
		visit[i] = 0;

	path.Push(start);
	std::cout << char(cur + 65) << ' ';
	while (!path.isEmpty()) {
		visit[cur] = 1;
		p = 0;

		// 연결된 정점 중 방문 안한 정점 찾기
		if (adjList[cur].LFirst(&next)) {
			if (visit[next] == 0)
				p = 1;
			while (p == 0 && adjList[cur].LNext(&next))
				if (visit[next] == 0)
					p = 1;
		}

		// 연결된 정점이 모두 방문한 정점인 경우 -- 백 트래킹
		if (p == 0) {
			next = path.Pop();
		}
		// 방문 안한 정점을 찾은 경우
		else {
			path.Push(cur);
			// 새로 방문할 정점 출력
			std::cout << char(next + 65) << ' ';
		}

		cur = next;
	}

}


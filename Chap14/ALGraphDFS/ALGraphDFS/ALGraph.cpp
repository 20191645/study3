// 인접 리스트(AdjacentList) 기반 그래프 구현
#include "ALGraph.h"
#include <iostream>

// 리스트 정렬 기준 함수
int SortFunction(int v1, int v2) {
	if (v1 < v2)	// v1의 정렬 순서가 앞이다
		return 0;
	else			// v2의 정렬 순서가 앞이다
		return 1;
}

// 생성자 -- 그래프 초기화, 매개변수: 정점 개수
ALGraph::ALGraph(int v)
	:Vnum(v), Enum(0)
{
	adjList = new LinkedList[v];
	// 정렬 기준 설정
	for (int i = 0; i < v; i++) {
		adjList[i].SetSortRule(SortFunction);
	}
}

// 파괴자
ALGraph::~ALGraph() {
	delete[]adjList;
}

// fromV - toV 연결하는 간선 추가
// 인접 리스트의 인덱스: fromV, 리스트의 데이터: toV
void ALGraph::AddEdge(int fromV, int toV) {
	// 이미 간선이 존재하는지 확인
	LData data;
	if (adjList[fromV].LFirst(&data)) {
		if (data == toV) {
			std::cout << "이미 존재하는 간선입니다.\n";
			return;
		}
		while(adjList[fromV].LNext(&data))
			if (data == toV) {
				std::cout << "이미 존재하는 간선입니다.\n";
				return;
			}
	}

	adjList[fromV].LInsert(toV);
	adjList[toV].LInsert(fromV);

	// 노드는 2개 추가하지만 간선은 1개로 취급
	Enum++;
}

// 그래프의 간선 정보 출력
void ALGraph::ShowEdgeInfo() const {
	using std::cout;
	using std::endl;

	LData data;
	for (int i = 0; i < Vnum; i++) {
		if (adjList[i].LFirst(&data)) {
			cout << char(i + 65) << "과 연결된 정점: ";
			cout << char(data + 65) << ' ';
			while (adjList[i].LNext(&data))
				cout << char(data + 65) << ' ';
		}
		std::cout << std::endl;
	}
}

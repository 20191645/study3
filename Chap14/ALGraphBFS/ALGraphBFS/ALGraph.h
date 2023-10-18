// 인접 리스트(AdjacentList) 기반 그래프 구현
// 연결 리스트를 활용하기 때문에 "LinkedList2.h, cpp"와 함께 컴파일
// LinkedList의 LData 타입과 정점 타입이 동일해야 한다 -- int형
#ifndef ALGRAPH_H_
#define ALGRAPH_H_

#include "LinkedList2.h"

enum { A, B, C, D, E, F, G, H, I, J };	// 정점 이름 상수화 -- adjList의 인덱스

class ALGraph {
// protected로 변수를 선언하여 상속받는 DFS, BFS 클래스에서 사용할 수 있게
protected:
	LinkedList* adjList;	// 간선의 정보를 담은 리스트
	int Vnum;				// 정점 개수
	int Enum;				// 간선 개수

public:
	ALGraph(int v);
	~ALGraph();

	void AddEdge(int fromV, int toV);
	void ShowEdgeInfo() const;
};

#endif
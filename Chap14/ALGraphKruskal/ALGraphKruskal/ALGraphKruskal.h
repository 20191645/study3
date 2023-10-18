// 인접 리스트 기반 그래프를 활용하여, 크루스칼 알고리즘 기반 최소 신장 트리(MST) 구현
// "LinkedList2.h, cpp" -- 연결 리스트 활용하여 간선 정보 저장
// "PriorityQueue.h, cpp" -- 가중치 기준으로 간선 정렬을 위한 우선순위 큐
// "PQueueHeap.h, cpp" -- "PriorityQueue.h, cpp"에 포함되어 함께 컴파일
// "ArrayStack.h, cpp" -- DFS 탐색을 위한 스택
#ifndef ALGRAPHKRUSKAL_H_
#define ALGRAPHKRUSKAL_H_

#include "ArrayStack.h"
#include "LinkedList2.h"
#include "PriorityQueue.h"
#include "ALEdge.h"

enum { A, B, C, D, E, F, G, H, I, J };	// 정점 이름 상수화

// 크루스칼 알고리즘을 위한 ALGraph
class ALGraph {
private:
	int Vnum;				// 정점 개수
	int Enum;				// 간선 개수
	int* visit;				// 방문 정보
	LinkedList* adjList;	// 간선 정보 -- 데이터 타입: int
	PQueue pqueue;			// 간선의 가중치 정보 -- 데이터 타입: Edge

public:
	ALGraph(int v);
	~ALGraph();

	void AddEdge(int fromV, int toV, int weight);
	void ShowEdgeInfo() const;
	void ShowVertexInfo(int start) const;

	void KruskalMST();
	void ShowEdgeWeightInfo();

	// KruskalMST() 함수에서 이용
	friend bool IsConnect(ALGraph* graph, int fromV, int toV);
};

#endif
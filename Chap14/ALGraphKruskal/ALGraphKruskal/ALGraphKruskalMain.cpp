// 인접 리스트 기반 그래프를 활용하여, 크루스칼 알고리즘 기반 최소 신장 트리(MST) 확인
#include "ALGraphKruskal.h"

int main() {
	ALGraph graph(6);
	
	// 간선 추가
	graph.AddEdge(A, B, 9);
	graph.AddEdge(B, C, 2);
	graph.AddEdge(A, C, 12);
	graph.AddEdge(A, D, 8);
	graph.AddEdge(D, C, 6);
	graph.AddEdge(A, F, 11);
	graph.AddEdge(F, D, 4);
	graph.AddEdge(D, E, 3);
	graph.AddEdge(E, C, 7);
	graph.AddEdge(F, E, 13);

	// MST 변환
	graph.KruskalMST();

	// 그래프 정보 출력
	graph.ShowEdgeInfo();
	graph.ShowEdgeWeightInfo();

	return 0;
}
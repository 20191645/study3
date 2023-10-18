// 인접 리스트(AdjacentList) 기반 그래프의 DFS 확인
// -- 다른 메인 함수(~Main.cpp)와 함께 컴파일하지 않기
#include "ALGraphDFS.h"
#include <iostream>

int main() {
	// 그래프 생성 및 초기화
	ALGraphDFS graph(7);

	// 간선 추가
	graph.AddEdge(A, B);
	graph.AddEdge(A, D);
	graph.AddEdge(B, C);
	graph.AddEdge(D, C);
	graph.AddEdge(D, E);
	graph.AddEdge(E, F);
	graph.AddEdge(E, G);

	// 간선 정보 출력
	graph.ShowEdgeInfo();

	// DFS를 이용한 정점 정보 출력
	graph.ShowVertexInfo(A);
	std::cout << std::endl;
	graph.ShowVertexInfo(C);
	std::cout << std::endl;
	graph.ShowVertexInfo(E);
	std::cout << std::endl;
	graph.ShowVertexInfo(G);

	return 0;
}
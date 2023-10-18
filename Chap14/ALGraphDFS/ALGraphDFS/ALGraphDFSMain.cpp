// ���� ����Ʈ(AdjacentList) ��� �׷����� DFS Ȯ��
// -- �ٸ� ���� �Լ�(~Main.cpp)�� �Բ� ���������� �ʱ�
#include "ALGraphDFS.h"
#include <iostream>

int main() {
	// �׷��� ���� �� �ʱ�ȭ
	ALGraphDFS graph(7);

	// ���� �߰�
	graph.AddEdge(A, B);
	graph.AddEdge(A, D);
	graph.AddEdge(B, C);
	graph.AddEdge(D, C);
	graph.AddEdge(D, E);
	graph.AddEdge(E, F);
	graph.AddEdge(E, G);

	// ���� ���� ���
	graph.ShowEdgeInfo();

	// DFS�� �̿��� ���� ���� ���
	graph.ShowVertexInfo(A);
	std::cout << std::endl;
	graph.ShowVertexInfo(C);
	std::cout << std::endl;
	graph.ShowVertexInfo(E);
	std::cout << std::endl;
	graph.ShowVertexInfo(G);

	return 0;
}
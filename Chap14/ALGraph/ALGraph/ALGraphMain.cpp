// ���� ����Ʈ(AdjacentList) ��� �׷��� Ȯ��
// -- �ٸ� ���� �Լ�(~Main.cpp)�� �Բ� ���������� �ʱ�
#include "ALGraph.h"
#include <iostream>

int main() {
	// �׷��� ���� �� �ʱ�ȭ
	ALGraph graph(5);

	// �׷��� ���� �߰�
	graph.AddEdge(A, B);
	graph.AddEdge(A, D);
	graph.AddEdge(B, C);
	graph.AddEdge(C, D);
	graph.AddEdge(D, E);
	graph.AddEdge(E, A);

	// �׷��� ���� ���� ���
	graph.ShowEdgeInfo();

	return 0;
}

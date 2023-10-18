// ���� ����Ʈ(AdjacentList) ��� �׷��� ����
#include "ALGraph.h"
#include <iostream>

// ����Ʈ ���� ���� �Լ�
int SortFunction(int v1, int v2) {
	if (v1 < v2)	// v1�� ���� ������ ���̴�
		return 0;
	else			// v2�� ���� ������ ���̴�
		return 1;
}

// ������ -- �׷��� �ʱ�ȭ, �Ű�����: ���� ����
ALGraph::ALGraph(int v)
	:Vnum(v), Enum(0)
{
	adjList = new LinkedList[v];
	// ���� ���� ����
	for (int i = 0; i < v; i++) {
		adjList[i].SetSortRule(SortFunction);
	}
}

// �ı���
ALGraph::~ALGraph() {
	delete[]adjList;
}

// fromV - toV �����ϴ� ���� �߰�
// ���� ����Ʈ�� �ε���: fromV, ����Ʈ�� ������: toV
void ALGraph::AddEdge(int fromV, int toV) {
	// �̹� ������ �����ϴ��� Ȯ��
	LData data;
	if (adjList[fromV].LFirst(&data)) {
		if (data == toV) {
			std::cout << "�̹� �����ϴ� �����Դϴ�.\n";
			return;
		}
		while(adjList[fromV].LNext(&data))
			if (data == toV) {
				std::cout << "�̹� �����ϴ� �����Դϴ�.\n";
				return;
			}
	}

	adjList[fromV].LInsert(toV);
	adjList[toV].LInsert(fromV);

	// ���� 2�� �߰������� ������ 1���� ���
	Enum++;
}

// �׷����� ���� ���� ���
void ALGraph::ShowEdgeInfo() const {
	using std::cout;
	using std::endl;

	LData data;
	for (int i = 0; i < Vnum; i++) {
		if (adjList[i].LFirst(&data)) {
			cout << char(i + 65) << "�� ����� ����: ";
			cout << char(data + 65) << ' ';
			while (adjList[i].LNext(&data))
				cout << char(data + 65) << ' ';
		}
		std::cout << std::endl;
	}
}

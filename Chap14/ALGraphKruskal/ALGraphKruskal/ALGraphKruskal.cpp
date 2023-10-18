// ���� ����Ʈ ��� �׷����� Ȱ���Ͽ�, ũ�罺Į �˰��� ��� �ּ� ���� Ʈ��(MST) ����
#include "ALGraphKruskal.h"
#include <iostream>

// �켱���� ť �� ���� �Լ� -- ����ġ �������� ����
int PQWeight(Edge d1, Edge d2) {
	return d1.weight - d2.weight;
}

// ����Ʈ ���� ���� �Լ� -- ���� �������� ����
int SortFunction(int v1, int v2) {
	if (v1 < v2)	// v1�� ���� ������ ���̴�
		return 0;
	else			// v2�� ���� ������ ���̴�
		return 1;
}

// ������ -- �׷��� �ʱ�ȭ
ALGraph::ALGraph(int v) 
	:Vnum(v), Enum(0), pqueue(PQWeight)
{
	adjList = new LinkedList[v];
	for (int i = 0; i < v; i++)
		adjList[i].SetSortRule(SortFunction);

	visit = new int[v];
	for (int i = 0; i < v; i++)
		visit[i] = 0;
}

// �ı���
ALGraph::~ALGraph() {
	delete[] adjList;
	delete[] visit;
}

// fromV - toV �����ϴ� ���� �߰�
// ���� ����Ʈ�� �ε���: fromV, ����Ʈ�� ������: toV
void ALGraph::AddEdge(int fromV, int toV, int weight) {
	// ���� ������ ���� ����Ʈ�� ����
	adjList[fromV].LInsert(toV);
	adjList[toV].LInsert(fromV);
	Enum++;

	// ������ ����ġ ������ �켱���� ť�� ����
	Edge edge = { fromV,toV,weight };
	pqueue.Enqueue(edge);
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

// DFS ������� �׷����� Ž���Ͽ� ���� ���� ���
void ALGraph::ShowVertexInfo(int start) const {
	ArrayStack path;	// ��� ������ ���� ���� ���� ����
	int cur = start;	// ���� Ž�� ����
	int next;			// ���� Ž�� ����
	int p;				// 1�̸� �湮 ���� ���� ã�Ҵٴ� ��

	// visitinfo �ʱ�ȭ -- 0: �湮X, 1: �湮O
	for (int i = 0; i < Vnum; i++)
		visit[i] = 0;

	path.Push(start);
	std::cout << char(cur + 65) << ' ';
	while (!path.isEmpty()) {
		visit[cur] = 1;
		p = 0;

		// ����� ���� �� �湮 ���� ���� ã��
		if (adjList[cur].LFirst(&next)) {
			if (visit[next] == 0)
				p = 1;
			while (p == 0 && adjList[cur].LNext(&next))
				if (visit[next] == 0)
					p = 1;
		}

		// ����� ������ ��� �湮�� ������ ��� -- �� Ʈ��ŷ
		if (p == 0) {
			next = path.Pop();
		}
		// �湮 ���� ������ ã�� ���
		else {
			path.Push(cur);
			// ���� �湮�� ���� ���
			std::cout << char(next + 65) << ' ';
		}

		cur = next;
	}

}

// �׷��� ����ġ ���� ���
void ALGraph::ShowEdgeWeightInfo() {
	using std::cout;
	using std::endl;

	// ��¿� �켱���� ť ����
	PQueue temp = pqueue;
	Edge edge;

	while (!temp.isEmpty()) {
		edge = temp.Dequeue();
		cout << "(" << char(edge.v1 + 65) << "-" << char(edge.v2 + 65)
			<< "), w: " << edge.weight << endl;
	}
}



// ���� ���� ���� �Լ� -- KruskalMST() �Լ����� �̿�
void RemoveEdge(LinkedList* adjList, Edge max) {
	int temp;

	if (adjList[max.v1].LFirst(&temp)) {
		if (temp == max.v2)
			adjList[max.v1].LRemove();
		while (adjList[max.v1].LNext(&temp)) {
			if (temp == max.v2) {
				adjList[max.v1].LRemove();
				break;
			}
		}
	}

	if (adjList[max.v2].LFirst(&temp)) {
		if (temp == max.v1)
			adjList[max.v2].LRemove();
		while (adjList[max.v2].LNext(&temp)) {
			if (temp == max.v1) {
				adjList[max.v2].LRemove();
				break;
			}
		}
	}
}

// ���� ���� ���� �Լ� -- KruskalMST() �Լ����� �̿�
void RecoverEdge(LinkedList* adjList, Edge max) {
	adjList[max.v1].LInsert(max.v2);
	adjList[max.v2].LInsert(max.v1);
}


// DFS�� �̿��� ���� 2�� ���� Ȯ�� �Լ� -- KruskalMST() �Լ����� �̿�
bool IsConnect(ALGraph* graph, int fromV, int toV) {
	ArrayStack path;	// ��� ������ ���� ���� ���� ����
	int cur = fromV;	// ���� Ž�� ����
	int next;			// ���� Ž�� ����
	int p;				// 1�̸� �湮 ���� ���� ã�Ҵٴ� ��

	// visitinfo �ʱ�ȭ -- 0: �湮X, 1: �湮O
	for (int i = 0; i < graph->Vnum; i++)
		graph->visit[i] = 0;

	path.Push(cur);
	while (!path.isEmpty() && graph->visit[toV] == 0) {
		graph->visit[cur] = 1;
		p = 0;

		// ����� ���� �� �湮 ���� ���� ã��
		if (graph->adjList[cur].LFirst(&next)) {
			if (graph->visit[next] == 0)
				p = 1;
			while (p == 0 && graph->adjList[cur].LNext(&next))
				if (graph->visit[next] == 0)
					p = 1;
		}

		// ����� ������ ��� �湮�� ������ ��� -- �� Ʈ��ŷ
		if (p == 0) {
			next = path.Pop();
		}
		// �湮 ���� ������ ã�� ���
		else {
			path.Push(cur);
		}

		cur = next;
	}

	return graph->visit[toV] == 1;
}


// ũ�罺Į �˰����� ���� MST ����
void ALGraph::KruskalMST() {
	Edge max;			// ���� ����ġ�� ����
	Edge temp[30];		// ���� �� ������ ������ ����
	int index = 0;			// temp�� �ε���

	// ���� ������ ���� �������� 1�� ������ MST �ϼ�
	while (Enum != Vnum - 1) {
		max = pqueue.Dequeue();

		// ���� ����
		RemoveEdge(adjList, max);

		// ���� ���� ���� -- ���� �����ϴ� ��� ����
		if (IsConnect(this, max.v1, max.v2)) {
			Enum--;
		}
		// ���� ���� �Ұ���
		else {
			RecoverEdge(adjList, max);
			temp[index++] = max;
		}
	}

	// �켱���� ť�� ���� ���� ����
	for (int j = 0; j < index; j++)
		pqueue.Enqueue(temp[j]);
}
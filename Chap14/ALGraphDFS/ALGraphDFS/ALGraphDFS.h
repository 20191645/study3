// ���� ����Ʈ ��� �׷����� Ȱ���Ͽ� DFS ����
// "ALGraph.h, cpp" -- ���� ����Ʈ ��� �׷��� Ȱ���ϱ� ���� �Բ� ������
// "LinkedList2.h, cpp" -- "ALGraph.h, cpp"���� ���ԵǾ� �Բ� ������
// "ArrayStack.h, cpp" -- ��� ������ ���� ������ �̿��ϱ� ���� �Բ� ������
// LinkedList�� LData Ÿ�԰� ArrayStack�� Data Ÿ�԰� ���� Ÿ���� �����ؾ� �Ѵ� -- int��
#ifndef ALGRAPHDFS_H_
#define ALGRAPHDFS_H_

#include "ALGraph.h"
#include "LinkedList2.h"
#include "ArrayStack.h"

// ALGraph�� ����Ͽ� DFS ������ ���� ��������� �Լ��� �߰�
class ALGraphDFS: public ALGraph{
private:
	int* visit;	// �湮 ���� �迭 -- �ε���: ����

public:
	ALGraphDFS(int v);
	~ALGraphDFS();

	void ShowVertexInfo(int start) const;
};

#endif ALGRAPHDFS_H_
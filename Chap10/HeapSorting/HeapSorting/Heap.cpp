// 배열 기반 힙(Heap) 구현 -- 우선순위가 높을수록 앞 부분에 위치
// 힙: 완전 이진 트리
#include "Heap.h"
#include <iostream>
#include <cstdlib>

// 힙 원소 삽입
void Heap::Insert(HData data) {
	// 힙이 꽉찬 경우
	if (num >= arrLen - 1) {
		std::cout << "힙이 꽉 찼습니다!\n";
		exit(EXIT_FAILURE);
	}
	
	int index = ++num;	// 새로운 원소가 이동할 인덱스

	// 부모 노드와 계속 바꾸면서 자리 찾기 -- 부모 노드가 존재할 때까지
	while (index > 1) {
		// 삽입하려는 원소의 우선순위가 부모의 우선순위보다 높은 경우
		if (comp(data, arr[index / 2]) >= 0) {
			arr[index] = arr[index / 2];
			index /= 2;
		}
		else
			break;
	}

	arr[index] = data;
}


// Delete 연산 시 Child 인덱스 계산 함수
int Heap::GetChildIndex(int index) const {
	// 리턴값 0: child 존재X -- 단말 노드
	if (index * 2 > num)
		return 0;
	// child가 왼쪽 노드 하나 존재
	else if (index * 2 == num)
		return index * 2;
	else {
		// 왼쪽 노드의 우선 순위가 높은 경우
		if (comp(arr[index * 2], arr[index * 2 + 1]) >= 0)
			return index * 2;
		else
			return index * 2 + 1;
	}
}

// 힙에서 가장 우선순위가 높은 원소 삭제
HData Heap::Delete() {
	// 힙이 비어있는 경우
	if (num < 1) {
		std::cout << "힙이 비어있습니다!\n";
		exit(EXIT_FAILURE);
	}

	HData data = arr[1];	// 삭제하려는 원소 -- 루트 노드
	int index = 1;	// 마지막 원소가 이동할 인덱스
	int child;	// 자식 노드 인덱스

	// 자식 노드와 계속 바꾸면서 자리 찾기 -- 자식 노드가 존재할 때까지
	while (child = GetChildIndex(index)) {
		// 마지막 원소의 우선순위가 자식의 우선순위보다 낮은 경우
		if (comp(arr[num], arr[child]) < 0) {
			arr[index] = arr[child];
			index = child;
		}
		else
			break;
	}

	arr[index] = arr[num--];
	return data;
}
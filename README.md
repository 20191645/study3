# study3
'열혈 자료구조' 교재를 학습하면서 진행했던 코드들입니다
- 각 챕터별로 C 스타일로 구현하는 자료구조를 직접 C++ 스타일로 변경하여 구현하였습니다
- 각 챕터 내 주제에 따라 프로젝트를 분리하였습니다

Chap1: 순차 탐색, 이진 탐색
Chap2: 재귀, 하노이 타워 문제
Chap3: 배열 리스트
  - ArrayList: int형 배열 리스트
  - NameArrayList: NameCard형 배열 리스트
Chap4: 단순 연결 리스트
  - LinkedList: (int형) 연결 리스트(head/tail 방식)
  - PointLinkedList: (Point형) 연결 리스트(tail 방식)
Chap5: 원형 연결 리스트, 양방향 연결 리스트
  - CircularLinkedList: (int형) 원형 연결 리스트(head/tail 선택 방식)
  - DoublyLinkedList: 양방향 연결 리스트(tail 방식)
  - EmployeeCircularList: (Employee형) 원형 연결 리스트(tail 방식)
Chap6: 배열 기반 스택, 연결 리스트 기반 스택, 원형 연결 리스트 기반 스택, 전위·중위·후위 표기법
  - ArrayStack: 배열 기반 스택
  - ListStack: 연결 리스트 기반 스택
  - CircularStack: 원형 연결 리스트 기반 스택 -- CircularLinkedList 헤더파일 포함
  - InfixCalculator: 후위 표기법 연산 프로그램 -- ListStack 헤더파일 포함
Chap7: 배열 기반 원형 큐, 연결 리스트 기반 큐, 시뮬레이션, 덱
  - ArrayQueue: 배열 기반 원형 큐
  - ListQueue: 연결 리스트 기반 큐
  - Deque: 양방향 연결 리스트 기반 덱
  - Hamburger_Simulation: 배열 기반 원형 큐를 이용한 시뮬레이션 -- ArrayQueue 헤더파일 포함
Chap8: 연결 리스트 기반 이진 트리, 전위·중위·후위 탐색, 수식 트리
  - BinaryTree: 연결 리스트 기반 이진 트리
  - ExpressionTree: 이진 트리와 연결 리스트 기반 수식 트리 -- BinaryTree, ListStack 헤더파일 포함
Chap9: 배열 기반 힙, 힙 기반 우선순위 큐
  - Heap: 배열 기반 힙
  - PriorityQueue: 힙 기반 우선순위 큐 -- Heap 헤더파일 포함
Chap10: 버블 정렬, 선택 정렬, 삽입 정렬, 힙 정렬, 병합 정렬, 퀵 정렬, 기수 정렬
  - SimpleSorting: 버블·선택·삽입·병합·퀵 정렬 -- 헤더파일 없는 정렬
  - HeapSorting: 힙 정렬 -- Heap 헤더파일 포함
  - RadixSorting: 기수 정렬 -- ListQueue 헤더파일 포함
Chap11: 보간 탐색, 이진 탐색 트리
  - InterpolSearch: 보간 탐색
  - BinarySearchTree: 이진 탐색 트리 -- BinaryTree 헤더파일 포함
Chap12: AVL 트리 -- BinarySearchTree, BinaryTree 헤더파일 포함
Chap13: 연결 리스트 기반 해쉬 테이블, 체이닝 -- LinkedList1 헤더파일 포함
Chap14: 인접 리스트 기반 그래프, DFS, BFS, 크루스칼 알고리즘 기반 최소 신장 트리  
  - ALGraph: 인접 리스트 기반 그래프 -- LinkedList2 헤더파일 포함
  - ALGraphDFS: 인접 리스트 기반 그래프 DFS -- ALGraph, LinkedList2, ArrayStack 헤더파일 포함
  - ALGraphBFS: 인접 리스트 기반 그래프 BFS -- ALGraph, LinkedList2, ArrayQueue 헤더파일 포함
- ALGraphKruskal: 크루스칼 알고리즘 기반 최소 신장 트리 -- LinkedList2, ArrayStack, PriorityQueue, Heap 헤더파일 포함

// 이진 트리와 연결 리스트 기반 스택을 기반으로 수식 트리 구현
// ListStack의 데이터형: TreeNode*, TreeNode의 데이터형: int
#include "ExpressionTree.h"
#include "ListStack.h"
#include <cctype>
#include <iostream>

// Traverse 매개변수용 함수
void ShowData(int data) {
	// ASCII 코드에 맞춰 int형을 char형으로 변환하여 출력
	std::cout << (char)data;
}

// 후위 표현식으로 수식 트리 구성
TreeNode* ExpTree::MakeExpTree(char exp[]) {
	// 후위 표현식 변환 과정을 담당할 TreeNode*형 스택
	ListStack stack;

	// 이진 트리 함수를 활용하기 위한 클래스 객체
	BinaryTree tree;

	/*
		구현 과정:
		1. 일단 exp[]를 data로 담는 TreeNode* 변수로 만들기
		2. 피연산자이면 스택으로 이동, 연산자이면 스택에서 2개 꺼내기
		3. root는 연산자, 첫번째 pop() 결과는 right, 두번째 pop() 결과는 left로 하는 Node 생성
		4. 해당 TreeNode*는 다시 스택에 넣기
		5. 마지막으로 스택에 남은 하나의 TreeNode* 변수가 결과
	*/

	// 스택에 담기 위한 TreeNode* 변수
	TreeNode* temp;
	int i = 0;
	while (exp[i]) {
		temp = tree.MakeNode();
		tree.SetData(temp, exp[i]);
		
		// 피연산자
		if (isalnum(exp[i])) {
			stack.Push(temp);
		}
		// 연산자
		else {
			tree.MakeRight(temp, stack.Pop());	// 두번째 피연산자
			tree.MakeLeft(temp, stack.Pop());	// 첫번째 피연산자
			stack.Push(temp);
		}

		i++;
	}

	temp = stack.Pop();
	return temp;
}

// 재귀를 이용하여 수식 트리 계산
int ExpTree::ExpTreeCalculator(TreeNode* bt) {
	int result = 0;	// 수식 결과

	// 연산자
	if (!isalnum(bt->data)) {
		int op1 = ExpTreeCalculator(bt->left);	// 왼쪽 노드
		int op2 = ExpTreeCalculator(bt->right);	// 오른쪽 노드
		
		switch (bt->data) {
		case '*':
			result = op1 * op2;
			break;

		case '/':
			result = op1 / op2;
			break;

		case '+':
			result = op1 + op2;
			break;

		case '-':
			result = op1 - op2;
			break;
		}
	}
	// 피연산자 -- 단말 노드
	else {
		return (bt->data) - '0';
	}

	return result;
}

// 전위 표기법 기반으로 출력
void ExpTree::ShowPrefixTypeExp(TreeNode* bt) {
	BinaryTree tree;
	tree.PreOrderTraverse(bt, ShowData);
}

// 중위 표기법 기반으로 출력 -- 소괄호까지 포함해서 출력하도록 수정
void ExpTree::ShowInfixTypeExp(TreeNode* bt) {
	// 재귀 탈출 조건
	if (bt == NULL)
		return;

	// 왼쪽 소괄호 출력 -- 말단 노드X, 하나의 연산식을 시작할때
	if (bt->left != NULL || bt->right != NULL)
		std::cout << "(";

	ShowInfixTypeExp(bt->left);
	ShowData(bt->data);
	ShowInfixTypeExp(bt->right);

	// 오른쪽 소괄호 출력 -- 말단 노드X, 하나의 연산식을 끝냈을때
	if (bt->left != NULL || bt->right != NULL)
		std::cout << ")";
}

// 후위 표기법 기반으로 출력
void ExpTree::ShowPostfixTypeExp(TreeNode* bt) {
	BinaryTree tree;
	tree.PostOrderTraverse(bt, ShowData);
}
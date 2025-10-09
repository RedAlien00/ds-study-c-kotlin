#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "stack.h"

typedef enum {
	PLUS = '+',      
	MINUS = '-',     
	MULTIPLY = '*',  
	DIVIDE = '/',
	LEFT_PAREN = '(',
	RIGHT_PAREN = ')'  
} OPERATOR;

int isOperator(char* str) {
	return 
		*str == PLUS || *str == MINUS || *str == MULTIPLY || *str == DIVIDE ||
		*str == LEFT_PAREN || *str == RIGHT_PAREN;
}

int isRightParen(char str) {
	return str == RIGHT_PAREN;
}

int getPriority(char* op) {
	switch (*op) {
		case LEFT_PAREN:
			return 0;
		case PLUS:
			return 1;
		case MINUS:
			return 1;
		case MULTIPLY:
			return 2;
		case DIVIDE:
			return 2;
		default :
			return -1;
	}
}

// top 연산자가 현재 연산자보다 우선 순위가 높거나 같다면 true
int isHigherPrecedence(char* pTopOp, char* pCurOp) {
	if (*pTopOp == LEFT_PAREN || *pCurOp == LEFT_PAREN ) return 0;	// ) 일 경우는 false
	
	int _topOp = getPriority(pTopOp);
	int _curOp = getPriority(pCurOp);
	return _topOp >= _curOp;
}

// 토큰 가져오기 : 띄어쓰기로 구분, 마지막 \0 문자 추가해서 리턴
char* getNextTokenFromInfix(char** ppCursor) {
	char* pCursor = *ppCursor;  // 문자열의 주소가 담김

	if (*pCursor == '\0') {
		*ppCursor = '\0';
		return NULL;
	}
	while (isspace(*pCursor)) pCursor++;	// 공백이 들어올 경우 건너뛰기
	char* pTokenStart = pCursor;
	
	while (!isspace(*pCursor) ) {			// 공백전까지 읽기
		if (*pCursor == '\0') {
			break;
		}
		pCursor++;
		if (*pCursor == '(' || *pCursor == ')') {
			break;
		}
	}
	int length = pCursor - pTokenStart;
	char* token = (char*) calloc(length + 1, sizeof(char)); // +1 : \0 공간
	strncpy_s(token, length + 1, pTokenStart, length);
	token[length] = '\0';
	*ppCursor = pCursor;		// 매우 중요 : pCursor의 값 업데이트
	return token;
}

// 결과에 토큰 문자열 추가 ( memcpy )
void addResult(char** ppWrite, char* pToken ) {
	char* pWrite = *ppWrite;

	int length = strlen(pToken);	// 주의 : strlen은 \0을 세지 않음
	pToken[length] = ' ';			// \0을 ' '으로 대체

	memcpy_s(pWrite, length+1, pToken, length+1);	// +1 : 공백까지 포함시키기 위해
	for (size_t i = 0; i < length + 1; i++) {		// +1 : 공백까지 고려하여 읽기 위치 이동
		pWrite++;	
	}
	*ppWrite = pWrite;
}

// 중위 표현식 -> 후위 표현식 변환
// 각 토큰을 하나의 문자열로 합쳐 반횐 
char* convertPostfix(const char* pInfix) {
	
	char* pResult = (char*) calloc(1, strlen(pInfix) + 1);  // 결과를 담을 변수
	pResult[strlen(pInfix)] = '\0';
	char* pResultCursor = pResult;							// 쓰기 전용 포인터
	STACK* pStack = Stack();
	
	char* pInfixCursor = pInfix;  // 읽기 전용 포인터
	char* pToken = NULL;
	
	while (pToken = getNextTokenFromInfix(&pInfixCursor)) {
		if (!isOperator(pToken)) {		// 연산자가 아닌 경우, 결과에 추가
			addResult(&pResultCursor, pToken);
		}
		else {	// 연산자인 경우
			if (isEmpty(pStack)) {
				push(pStack, pToken);
			}
			else if (isRightParen(*pToken)) {	// `)`인 경우 `(`가 나올 때까지 결과에 추가
				NODE* pTemp = pop(pStack);

				while ( *(char*)(pTemp->data)!= '(' && pTemp != NULL) {
					addResult(&pResultCursor, pTemp->data);
					pTemp = pop(pStack);
				}
			}
			else {	// 그 외 연산자인 경우
				// top 연산자가 우선순위가 높거나 같을 경우
				if ( isHigherPrecedence(pStack->top->data, pToken)) {
					while (isHigherPrecedence(pStack->top->data, pToken)) {
						NODE* pTemp = pop(pStack);

						addResult(&pResultCursor, pTemp->data);
						if (isEmpty(pStack)) break;
					}
					push(pStack, pToken);
				}
				else {  // top 연산자가 우선순위가 낮을 경우
					push(pStack, pToken);
				}
			}
		}
	}
	// 스텍에 남은 것들 결과에 추가
	NODE* pTemp = pop(pStack);
	while (pTemp != NULL) {
		addResult(&pResultCursor, pTemp->data);

		pTemp = pop(pStack);
	}
	return pResult;
}

// 후위 표현식에서 토큰 가져오기
char* getNextTokenFromPostfix(const char** ppCursor) {
	char* pCursor = *ppCursor;

	while (isspace(*pCursor)) pCursor++;	// 앞단 공백 삭제
	char* pStart = pCursor;

	while (!isspace(*pCursor)) {
		if (*pCursor == '\0') return NULL;
		pCursor++;
	}
	int length = pCursor - pStart;
	char* pResult = (char*)calloc(length + 1, sizeof(char));
	strncpy_s(pResult, length + 1, pStart, length);
	*ppCursor = pCursor;

	return pResult;
}

 //12 34 5 - 6 78 + * 9 10 - / +
char* postfixCaculator(const char* const pPostfix) {
	const char* pCursor = pPostfix;
	char* pToken = NULL;
	STACK* pStack = Stack();

	while (pToken = getNextTokenFromPostfix(&pCursor)) {
			
		if (!isOperator(pToken)) { // 숫자일 경우
			push(pStack, pToken);
		} else {					// 연산자일 경우
			NODE* temp1 = pop(pStack);
			NODE* temp2 = pop(pStack);
			int temp1Int = atoi( (char*) temp1->data);	// 문자 -> 숫자 
			int temp2Int = atoi( (char*) temp2->data);
			int resultInt = 0;
			char* pResultStr = (char*)calloc(10, sizeof(char));

			switch (*pToken) {
				case PLUS: resultInt = temp2Int + temp1Int;		break;
				case MINUS: resultInt = temp2Int - temp1Int;		break;
				case MULTIPLY: resultInt = temp2Int * temp1Int;	break;
				case DIVIDE: resultInt = temp2Int / temp1Int;		break;
			}
			snprintf(pResultStr, sizeof(char) * 10, "%d", resultInt);	// 숫자 -> 문자
			push(pStack, pResultStr);
		}
	}
	NODE* resultNode = pop(pStack);
	return resultNode->data;
}

int main() {
	
	char* pInfix = "12 + (( 34 - 5 ) * ( 6 + 78 )) / ( 9 - 10 )";
	char* result = convertPostfix( pInfix);

	printf("%s\n", result);
	char* a = postfixCaculator(result);

	printf("%s\n", a);

}
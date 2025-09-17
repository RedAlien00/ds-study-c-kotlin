
typedef struct NODE {
	void* data;
	struct NODE* pLeftChild;
	struct NODE* pRightSibiling;
} NODE;

// 노드 생성
NODE* Node(void*);

// 노드 소멸
void destroyNode(NODE*);

// 트리 소멸
void destroyTree(NODE*);

// 자식 노드 추가( 부모, 자식 )
void addChildNode(NODE*, NODE*);

// 트리 출력
void printTree(NODE*, int);
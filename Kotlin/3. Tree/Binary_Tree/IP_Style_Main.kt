enum class ORDER {
    PREORDER, INORDER, POSTORDER
}

interface Tree<T> {
    fun insert(data: T);
    fun printByOrder(order: ORDER): Unit;
}

class Node<T>(public val data: T ) {
    var left: Node<T>? = null
    var right: Node<T>? = null
}

class BinaryTree( private val rootInt: Int) : Tree<Int> {
    private val rootNode: Node<Int> = Node(rootInt);
    private val traversal: Traversal<Int> = Traversal<Int>();

    private var _totalCount: Int = 1;
    val totalCount: Int
        get() = _totalCount

    override fun insert(int: Int ) {
        val newNode = Node(int);

        if (_totalCount == 1) {
            when {
                rootNode.data > newNode.data -> rootNode.left = newNode
                rootNode.data < newNode.data -> rootNode.right = newNode
            }
            _totalCount++
            return
        }
        var temp: Node<Int> = rootNode;
        while (true) {
            when {
                // 작은 경우, 왼쪽
                temp.data > newNode.data -> {
                    if (temp.left != null) {
                        temp = temp.left!!
                        continue
                    }
                    temp.left = newNode
                    break
                }
                // 작은 경우, 오른쪽
                temp.data < newNode.data -> {
                    if (temp.right != null) {
                        temp = temp.right!!
                        continue
                    }
                    temp.right = newNode
                    break
                }
            }
        }
        _totalCount++
    }

    override fun printByOrder(order: ORDER) {
        when(order) {
            ORDER.PREORDER -> traversal.preorder(rootNode)
            ORDER.INORDER -> traversal.inorder(rootNode)
            ORDER.POSTORDER -> traversal.postorder(rootNode)
        }
        val result = traversal.getResult()
        println(result)
    }
}


fun main() {
    val bTree = BinaryTree(10);

    val ints = arrayOf(10, 5, 3, 2, 7, 6, 8, 15, 20, 18)
    for (int in ints) {
        bTree.insert(int)
    }
    bTree.printByOrder(ORDER.POSTORDER)
}
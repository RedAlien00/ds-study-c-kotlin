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
    private var rootNode: Node<Int> = Node(rootInt);
    private val traversal = Traversal<Int>()

    override fun insert(data: Int) {
        fun insertRecursive(node: Node<Int>?, value: Int): Node<Int> {
            if (node == null) return Node(value);
            when {
                node.data > value -> node.left = insertRecursive(node.left, value);
                node.data < value -> node.right = insertRecursive(node.right, value);
            }
            return node;
        }
        rootNode = insertRecursive(rootNode, data) //
    }
    override fun printByOrder(order: ORDER) {
        val result = when(order) {
            ORDER.PREORDER -> traversal.preorder(rootNode)
            ORDER.INORDER -> traversal.inorder(rootNode)
            ORDER.POSTORDER -> traversal.postorder(rootNode)
        }
        println(result)
    }
}

fun main() {
    val bTree = BinaryTree(10);

    val ints = arrayOf(5, 3, 2, 7, 6, 8, 15, 20, 18)
    for (int in ints) {
        bTree.insert(int)
    }
    bTree.printByOrder(ORDER.POSTORDER)
}
interface Tree<T> {
    fun addChildNode(parentNode: Node<Char>, childNode: Node<Char>);
    fun print(): Unit;
}

class Node<T>(public val data: T ) {
    var child: Node<T>? = null
    var sibling: Node<T>? = null
}

class GeneralTree( private val rootNode: Node<Char> ): Tree<Char> {

    override fun addChildNode(parentNode: Node<Char>, childNode: Node<Char>) {
        fun getLastSibling(node: Node<Char>?): Node<Char>? {
            if (node?.sibling == null) return node
            return getLastSibling(node.sibling)
        }
        when(parentNode.child) {
            null -> parentNode.child = childNode
            else -> getLastSibling(parentNode.child)?.sibling = childNode
        }
    }
    override fun print() {
        fun printRecursive(node: Node<Char>?) {
            if (node == null) return;

            print("${node.data} ");
            printRecursive(node.child)
            printRecursive(node.sibling)
        }
        printRecursive(rootNode)
        println()
    }
}

fun main() {
    val node1 = Node('A'); val node2 = Node('B'); val node3 = Node('C')
    val node4 = Node('D'); val node5 = Node('E') ; val node6 = Node('F')
    val node7 = Node('G'); val node8 = Node('H'); val node9 = Node('I')
    val node10 = Node('J'); val node11 = Node('K')

    val gTree = GeneralTree(node1);
    gTree.addChildNode(node2, node3)
    gTree.addChildNode(node2, node4)

    gTree.addChildNode(node4, node5)
    gTree.addChildNode(node4, node6)

    gTree.addChildNode(node7, node8)

    gTree.addChildNode(node9, node10)
    gTree.addChildNode(node9, node11)

    gTree.addChildNode(node1, node2)
    gTree.addChildNode(node1, node7)
    gTree.addChildNode(node1, node9)

    gTree.print()
}
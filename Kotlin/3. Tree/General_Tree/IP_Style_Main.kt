package org.example

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
        when(parentNode.child) {
            null -> parentNode.child = childNode
            else -> {
                var temp: Node<Char>? = parentNode.child
                while (temp?.sibling != null) {
                    temp = temp.sibling
                }
                temp?.sibling = childNode
            }
        }
    }
    override fun print() {
        fun printRecursive(node: Node<Char>?) {
            print("${node?.data} ");

            if (node?.child != null) printRecursive(node.child)

            var temp = node?.sibling
            while (temp != null) {
                print("${temp.data} ");
                if (temp.child != null) printRecursive(temp.child)
                temp = temp.sibling
            }
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

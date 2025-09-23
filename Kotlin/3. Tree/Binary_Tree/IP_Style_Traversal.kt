package org.example

class Traversal<T> {
    private val _list = mutableListOf<T>();
    val list: List<T>
        get() = _list

    fun preorder(rootNode: Node<T>)  {
        _list.add(rootNode.data)
        if (rootNode.left != null) preorder(rootNode.left!!)
        if (rootNode.right != null) preorder(rootNode.right!!)
    }

    fun inorder(rootNode: Node<T>) {
        if (rootNode.left != null) inorder(rootNode.left!!)
        _list.add(rootNode.data)
        if (rootNode.right != null) inorder(rootNode.right!!)
    }
    fun postorder(rootNode: Node<T>) {
        if (rootNode.left != null) postorder(rootNode.left!!)
        if (rootNode.right != null) postorder(rootNode.right!!)
        _list.add(rootNode.data)
    }
    fun getResult() = list;
}
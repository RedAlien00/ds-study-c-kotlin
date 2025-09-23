class Traversal<T> {
    fun preorder(node: Node<T>?): List<T> {
        if (node == null) return emptyList<T>()
        return listOf(node.data) + preorder(node.left) + preorder(node.right)
    }
    fun inorder(node: Node<T>?): List<T> {
        if (node == null) return emptyList<T>()
        return inorder(node.left) + listOf(node.data) + inorder(node.right)
    }
    fun postorder(node: Node<T>?): List<T> {
        if (node == null) return emptyList<T>()
        return postorder(node.left) + postorder(node.right) + listOf(node.data)
    }
}
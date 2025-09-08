package org.example

interface MyList {
    val head: Node
    val tail: Node

    fun isEmpty(): Boolean;
    fun insertAtHead (node: Node): Unit;
    fun insertAtTail(node: Node): Unit;
    fun remove (targetNode: Node?): Unit;
    fun getNodeAtPosition(position: Int): Node?;
    fun getTotalNodeCount(): Int
    fun printAll(): Unit;
}






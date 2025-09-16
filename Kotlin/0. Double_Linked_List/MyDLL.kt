package org.example

class MyDLL(
    override val head: Node,
    override val tail: Node,
): MyList {
    private var totalCount: Int = 0;

    init {
        head.next = tail
        tail.prev = head;
        totalCount = 0;
    }

    override fun isEmpty(): Boolean {
        return head.next === tail && tail.prev === head;
    }

    override fun insertAtHead(newNode: Node): Unit {
        var temp: Node? = null;
        temp = head.next;
        head.next = newNode;
        newNode.prev = head

        newNode.next = temp
        temp?.prev = newNode
        totalCount++
    }
    override fun insertAtTail(newNode: Node): Unit {
        if (isEmpty()) {
            insertAtHead(newNode)
            return;
        }
        var temp: Node? = null;
        temp = tail.prev;
        tail.prev = newNode;
        newNode.next = tail

        newNode.prev = temp
        temp?.next = newNode
        totalCount++
    }
    override fun remove(targetNode: Node?): Unit {
        when {
            isEmpty() -> println("빈 배열입니다")
            targetNode == null -> return
        }

        var temp: Node? = head.next;

        while (temp != null && temp !== targetNode && temp !== tail) {
            temp = temp.next
        }
        val prevNode = temp?.prev
        val nextNode = temp?.next
        prevNode?.next = nextNode
        nextNode?.prev = prevNode

        totalCount--
    }
    override fun getNodeAtPosition(position: Int): Node? {
        if (position > totalCount ) {
            return null
        }
        var position = position;
        var temp: Node? = head;

        while (--position >= 0) {
            temp = temp?.next
        }
        return temp;
    }
    override fun getTotalNodeCount(): Int = totalCount;

    override fun printAll() {
        if (isEmpty()) {
            println("빈 배열입니다")
        }
        var temp: Node? = head.next;

        while (temp!= null && temp !== tail) {
            println( temp.getKey() )
            temp = temp.next!!
        }
    }
}
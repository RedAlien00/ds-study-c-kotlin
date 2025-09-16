package org.example


fun getKeyFromStudent(student: Student): String {
    return student.name
}

fun main() {
    val head = Student();
    val tail = Student();
    val dll: MyList = MyDLL(head, tail )

    val node1 = Student(13, 156.5, "김창섭");
    val node2 = Student(15, 178.5, "한수연");
    val node3 = Student(20, 190.5, "김곰돌");
    val node4 = Student(20, 190.5, "김곰돌");


    dll.insertAtHead(node1)
    dll.insertAtTail(node2)
    dll.insertAtTail(node3)
    dll.insertAtTail(node4)

    val result: Node? = dll.getNodeAtPosition(1)
    println("getNode 결과 : ${result?.getKey()}" )

    dll.remove(result)
    println(dll.getTotalNodeCount())
    dll.printAll()
}










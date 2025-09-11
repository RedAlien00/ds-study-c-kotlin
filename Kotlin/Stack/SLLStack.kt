// 추상화 정의, arrayStack으로 구현하든 linkedListStack으로 구현하든
// 동일하게 사용할 수 있게 인터페이스  정의
interface Stack {
    fun push(node: Node ): Unit;
    fun pop(): Node;
    fun popOrNull(): Node?;
}

// Node의 기능 부여
interface Node {
    var prev: Any?;
}

// ArrayStack의 Node로 들어갈 클래스
class Student(private val age: Int, private val name: String): Node {
    override var prev: Any? = null

    fun print() = "age : $age, name : $name";
}

class SLLStack() : Stack {
    private var top: Node? = null;
    private var totalNode = 0;

    fun getTotalNode(): Int = totalNode;

    override fun push(newTop: Node) {
        val temp = top
        top = newTop
        newTop.prev = temp
        totalNode++
    }
    override fun pop(): Node {
        if (top == null) throw Exception("Cannot pop: stack is empty")
        val out: Node? = top
        top = out?.prev as Node?
        totalNode--
        return out!!
    }
    override fun popOrNull(): Node? {
        if (top == null) return null;
        val out: Node? = top
        top = out?.prev as Node?
        totalNode--
        return out!!
    }
}

fun main() {
    val students = arrayOf(
        Student(3, "김갑갑"),
        Student(5, "홍길동"),
        Student(15, "박대감"),
        Student(134, "송이버섯"),
    )

    val myStack = SLLStack();

    students
        .forEach {  myStack.push(it)  }

    repeat(5) {
        val result: Student? = myStack.popOrNull() as Student?;
        println("pop 결과 : ${result?.print()}")
        println("totalNOde : ${myStack.getTotalNode()}")
    }
}
// 추상화 정의, arrayStack으로 구현하든 linkedListStack으로 구현하든
// 동일하게 사용할 수 있게 인터페이스  정의
interface Stack<T> {
    fun push(node: T ): Unit;
    fun pop(): T;
    fun popOrNull(): T?;
}

// ArrayStack의 Node로 들어갈 클래스 
class Student(private val age: Int, private val name: String) {
    fun print() = "age : $age, name : $name";
}

class ArrayStack<T>(private val capacity: Int) : Stack<T> {
    private val myArray: Array<Any?> = arrayOfNulls(capacity)
    private var top: Int = -1;

    fun getTotalNode(): Int  = top + 1;

    override fun push(node: T): Unit {
        if (capacity == getTotalNode()) return;
        top++;
        myArray[top] = node;
    }
    override fun pop(): T {
        if (top == -1)  throw ArrayIndexOutOfBoundsException(-1);
        val node = myArray[top]; //
        myArray[top--] = null;  // 메모리 누수 방지
        return node as T;
    }
    override fun popOrNull(): T? {
        if (top == -1)  return null;
        val node = myArray.get(top); //
        myArray[top--] = null;  // 메모리 누수 방지
        return node as T?;
    }
}

fun main() {
    val myStack = ArrayStack<Any>(5);
    val students = arrayOf(
        Student(3, "김갑갑"),
        Student(5, "홍길동"),
        Student(15, "박대감"),
        Student(134, "송이버섯"),
    )
    students
        .forEach {  myStack.push(it)  }

    repeat(5) {
        val result: Student? = myStack.popOrNull() as Student?;
        println("pop 결과 : ${result?.print()}")
        println("totalNOde : ${myStack.getTotalNode()}")
    }
}
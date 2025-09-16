interface MyQueue {
    fun enque(data: Any): Unit;
    fun deque(): Any;
    fun deQueOrNull(): Any?;
}

class ArrayQueue(private val capacity: Int) : MyQueue {
    private val array: Array<Any?> = arrayOfNulls<Any?>(capacity);

    private var _totalCount: Int = 0;
    val totalCount: Int
        get() = _totalCount

    private var front: Int = 0;
    private var rear: Int = 0;

    override fun enque(data: Any) {
        if (totalCount == capacity) throw Exception("Queue is Full !")
        if (rear == capacity) rear = 0;

        println("enque() : array[$rear]")   // 로깅
        array[rear++] = data;
        _totalCount++;
    }

    override fun deque(): Any {
        if (_totalCount == 0) throw Exception("Queue is Empty !")
        if (front == capacity) front = 0;

        println("deque() : array[$front]")  // 로깅
        val out: Any = array[front++]!!;
        _totalCount--;
        return out;
    }

    override fun deQueOrNull(): Any? {
        if (_totalCount == 0) return null;
        if (front == capacity) front = 0;

        val out: Any = array[front++]!!;
        _totalCount--;
        return out;
    }
}

class Order(
    private val id: Int,
    private val name: String,
) {}

fun main() {
    val orders = listOf(
        Order(1, "새우버거"),
        Order(1, "불고기버거"),
        Order(1, "치즈버거"),
    )
    val q = ArrayQueue(5);
    q.enque(orders[0]);
    q.enque(orders[1]);
    q.deque()
    q.deque()

    println(q.totalCount);
}
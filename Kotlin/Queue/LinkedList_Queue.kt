
interface MyQueue {
    fun enque(newNode: Node): Unit;
    fun deque(): Node;
    fun deQueOrNull(): Node?;
}

interface Node {
    var prev: Node?;
}

class Order(
    private val id: Int,
    private val name: String,
): Node {
    override var prev: Node? = null;
}

class LinkedListQueue() : MyQueue {
    private var front: Node? = null;
    private var rear: Node? = null;

    private var _totalCount: Int = 0;
    val totalCount: Int
        get() = _totalCount;

    override fun enque(newNode: Node) {
        if (_totalCount == 0) {
            front = newNode;
            rear = newNode;
            _totalCount++;
            return
        }
        rear!!.prev = newNode;
        rear = newNode
        _totalCount++;
    }
    override fun deque(): Node {
        if (_totalCount == 0) throw Exception("Queue is Empty !");
        val temp = front!!;
        front = temp.prev;
        _totalCount--;
        return temp;
    }
    override fun deQueOrNull(): Node? {
        if (_totalCount == 0) return null;
        val temp = front!!;
        front = temp.prev;
        _totalCount--;
        return temp;
    }
}

fun main() {
    val orders = listOf(
        Order(1, "새우버거"),
        Order(2, "불고기버거"),
        Order(3, "치즈버거"),
    )
    val q = LinkedListQueue();
    q.enque(orders[0]);
    q.enque(orders[2]);
    q.deque()
    q.deque()
    println(q.totalCount);
}
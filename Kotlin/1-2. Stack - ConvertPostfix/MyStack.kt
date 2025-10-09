interface Stack {
    fun push(data: String);
    fun popOrNull(): String?;
    fun isEmpty(): Boolean;
}

class MyStack: Stack {
    private val list = mutableListOf<String>();

    private var _totalCount: Int = 0;
    val totalCount: Int
        get() = _totalCount

    val topElement: String?
        get() = if (_totalCount == 0) null else list[_totalCount - 1]

    override fun push(data: String) {
        list.add(_totalCount, data);
        _totalCount++;
    }

    override fun popOrNull(): String? {
        if (isEmpty()) return null;

        val result = list[_totalCount - 1];
        list.removeLast()
        _totalCount--;
        return result;
    }

    override fun isEmpty(): Boolean = _totalCount == 0;
}
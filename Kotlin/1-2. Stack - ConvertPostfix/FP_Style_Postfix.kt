fun String.separateToken(): List<String> =
    with( Regex("\\d+|[+-/*()]") ) {
      this.findAll(this@separateToken)
          .map { it.value }
          .toList()
    }

class Postfix {
    private fun getPriority(operator: String): Int =
        when(operator) {
            "+", "-" -> 1
            "*", "/" -> 2
            else -> 0
        }

    private fun isHighPriority(top: String?, operator: String): Boolean {
        if (top == null) return  false
        if (top.equals("(") || operator.equals("(") ) return false

        val topResult = getPriority(top)
        val opeResult = getPriority(operator)

        return topResult >= opeResult
    }

    fun convertToPostfix(infix: String): List<String> {
        return buildList {
            val stack = MyStack();
            infix
                .separateToken()    // infix -> 토큰 별로 분리
                .forEach { token ->
                    when {
                        token.toIntOrNull() != null -> {
                            this.add(token)
                        }
                        token == ")" -> {
                            // ( 를 만날 때까지 pop
                            generateSequence { stack.popOrNull() }
                                .takeWhile { it != "(" && it != null  }
                                .forEach { this.add(it) }
                        }
                        else -> {
                            // 연산자 우선 순위 판별
                            while (isHighPriority(stack.topElement, token)) {
                                stack.popOrNull()?.let { this.add(it) }
                            }
                            stack.push(token)
                        }
                    }
                }
            // 스택에 남은 요소들 결과에 추가
            generateSequence { stack.popOrNull() }.forEach { this.add(it) }
        }
    }

    fun calculate(postfix: List<String>): Int? {
        val stack = MyStack();

        postfix.forEach { token ->
            when {
                token.toIntOrNull() != null -> stack.push(token)
                else -> {
                    val a: Int? = stack.popOrNull()?.toIntOrNull()
                    val b: Int? = stack.popOrNull()?.toIntOrNull()

                    if (a != null && b != null) {
                        var result = when (token) {
                            "+" -> b + a
                            "-" -> b - a
                            "*" -> b * a
                            "/" -> b / a
                            else -> 0
                        }
                        stack.push(result.toString())
                    }
                }
            }
        }
        return stack.popOrNull()?.toIntOrNull()
    }
}
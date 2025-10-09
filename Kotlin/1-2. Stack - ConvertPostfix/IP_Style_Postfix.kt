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

    private fun separateToken(str: String): List<String> {
        val expr = "\\d+|[+-/*()]"
        val regex = expr.toRegex()

        return regex.findAll(str)
            .map { it.value }
            .toList()
    }

    fun convertToPostfix(infix: String): List<String> {
        val separatedInfix = separateToken(infix)   // 정규 표현식으로 토큰 추출
        val stack = MyStack();
        val result = mutableListOf<String>()        // 결과 저장용 List<String>

        for (token in separatedInfix ) {
            if(token.toIntOrNull() != null) result.add(token)   // Int로 변환 가능 시, 결과에 추가
            else {
                if (token.equals(")")) {     // `)` 를 만날 경우
                    var a = stack.popOrNull();

                    while (!a.equals("(") && a != null ) {
                        result.add(a)
                        a = stack.popOrNull()
                    }
                } else {    // 그 외, 연산자 우선 순위 판별
                    // 우선 순위가 top >= 현재 Operator 일 경우
                    while( isHighPriority(stack.topElement, token) ) {
                        val a = stack.popOrNull()
                        if( a != null) result.add(a)
                    }
                    // 그 외, push
                    stack.push(token);
                }
            }
        }
        while (!stack.isEmpty()) {
            val a = stack.popOrNull()
            if(a != null) result.add(a)
        }
        return result
    }

    fun calculate(postfix: List<String>): Int {
        val stack = MyStack();
        var result = 0

        for (token in postfix) {
            if (token.toIntOrNull() != null) stack.push(token)  // 숫자일 경우, push
            else {
                val a: Int? = stack.popOrNull()?.toIntOrNull()
                val b: Int? = stack.popOrNull()?.toIntOrNull()

                if (a != null && b != null) {
                    result = when(token) {
                        "+" -> b + a
                        "-" -> b - a
                        "*" -> b * a
                        "/" -> b / a
                        else -> 0
                    }
                }
                stack.push(result.toString())
            }
        }
        return result
    }
}
fun main() {
    val infix = "120/(4*5-8)+10"
    val postfix = Postfix();

    val convertedPostfix = postfix.convertToPostfix(infix)
    println(convertedPostfix)

    val calculated = postfix.calculate(convertedPostfix);
    println(calculated)
}
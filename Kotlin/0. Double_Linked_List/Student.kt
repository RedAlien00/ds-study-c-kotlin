package org.example

class Student(
    val age: Int = 0,
    val height: Double = 0.0,
    val name: String = ""
): Node {
    override var next: Node? = null
    override var prev: Node? = null

    override fun getKey() = name
}
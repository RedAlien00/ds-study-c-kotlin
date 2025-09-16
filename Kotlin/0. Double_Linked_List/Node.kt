package org.example

interface Node {
    var next: Node?
    var prev: Node?
    fun getKey(): Any;
}
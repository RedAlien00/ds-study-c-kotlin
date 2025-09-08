package org.example


interface TestIterator<T> {
    fun hasNext() : Boolean;
    fun next() : T
}

interface TestIterable<T> {
    fun iterator() : TestIterator<T>
}

class StudentCollection : TestIterable<String> {
    private var students = mutableListOf<String>()

    fun addStudent(student : String ) {
        students.add(student)
    }
    fun removeStudent(student : String ) {
        students.remove(student)
    }
    fun reverse() = students.reverse()

    fun print() = println(students)

    fun size() : Int = students.size

    override fun iterator(): TestIterator<String> {
        return studentIterator(students);
    }
    fun reverseIterator(): TestIterator<String> {
        return studentReverseIterator(students)
    }
    fun filterIterator(keyword: String): TestIterator<String> {
        return studentFilterIterator(students, keyword)
    }


    private class studentIterator( private val student: List<String>) : TestIterator<String> {
        var currentIndex = 0;

        override fun hasNext(): Boolean {
            return currentIndex < student.size
        }

        override fun next() : String  {
            if (!hasNext()) {
                throw Exception("학생이 없다요")
            } else {
                return student[currentIndex++]
            }
        }
    }




    private class studentReverseIterator( private val student: List<String> ) : TestIterator<String> {
        var currentIndex = student.size - 1; // 길이가 4일 경우, 3부터 시작

        override fun hasNext(): Boolean {
            return currentIndex >= 0;
        }

        override fun next() : String  {
            if (!hasNext()) {
                throw Exception("학생이 없다요")
            } else {
                return student[currentIndex--]
            }
        }
    }



    private class studentFilterIterator(
        private val student: List<String>,
        private val keyword: String
    ) : TestIterator<String> {

        var currentIndex = 0;
        val result = student.filter { it.contains(keyword, ignoreCase = true) }

        override fun hasNext(): Boolean {
            return currentIndex < result.size
        }

        override fun next() : String  {
            if (!hasNext()) {
                throw Exception("학생이 없다요")
            } else {
                return result[currentIndex++]
            }
        }
    }

}



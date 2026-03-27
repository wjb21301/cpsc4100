class StudentGrades {
// Subprogram to find the highest and lowest grades
def findGradeExtremes(grades: List[(String, Int)]): (String, Int, String, Int) = {
//you can use maxBy, minBy
//think about using _
val max = grades.maxBy(_._2)
val min = grades.minBy(_._2)
(max._1, max._2, min._1, min._2)
}
// Subprogram to calculate the average grade
def calculateAverage(grades: List[(String, Int)]): Double = {
if (grades.isEmpty) 0.0 else{
grades.map(_._2).sum.toDouble / grades.length
}
}
// Subprogram to display results
def displayResults(grades: List[(String, Int)]): Unit = {
// To complete
val returnedList = findGradeExtremes(grades)
val maxNum = returnedList._2
val maxName = returnedList._1
val minNum = returnedList._4
val minName = returnedList._3
val average = calculateAverage(grades)
println(s"$maxNum $maxName $minNum $minName $average")

}
}
object StudentGradesApp {
def main(args: Array[String]): Unit = {
// create your list and call for calculations
val grades = List(("Alice", 85), ("Bob", 92), ("Charlie", 78), ("David", 90));
val studentGrades = new StudentGrades()
studentGrades.displayResults(grades)
}
}
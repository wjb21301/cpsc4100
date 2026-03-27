// Define a class to handle set operations
class SetOperations {
// Subprogram to perform set operations
def computeOperations(set1: Set[Int], set2: Set[Int]): (Set[Int], Set[Int], Set[Int]) = {
val union = set1.union(set2)
val intersection = set1.intersect(set2)
val difference = set1.diff(set2)
(union, intersection, difference)
}
// Subprogram to display results
def displayResults(result: (Set[Int], Set[Int], Set[Int])): Unit = {
val (union, intersection, difference) = result
println(s"Union: $union")
println(s"Intersection: $intersection")
println(s"Difference: $difference")
}
}
// Companion object to handle execution
object SetOperationsApp {
def main(args: Array[String]): Unit = {
//create an object of setOperations
val setOps = new SetOperations
//create a few sets to be tested and display the operations results (union, intersection,etc.
val set1 = Set(1, 2, 3, 4, 5)
val set2 = Set(4, 5, 6, 7, 8)
val set3 = Set(9, 10, 11, 12, 13)
val set4 = Set(12, 13, 14, 15, 16)
val result = setOps.computeOperations(set1, set2)
val result2 = setOps.computeOperations(set3, set4)
setOps.displayResults(result)
setOps.displayResults(result2)
}
}
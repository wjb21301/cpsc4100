class ListProcessor {
// Subprogram to filter even numbers – nothing to add here :)
def filterEvenNumbers(numbers: List[Int]): List[Int] = numbers.filter(_ % 2 == 0)
// Subprogram to filter odd numbers
def filterOddNumbers(numbers: List[Int]): List[Int] = numbers.filter(_ % 2 != 0)
// Subprogram to square each number
def squareNumbers(numbers: List[Int]): List[Int] = numbers.map(x => x * x)
// Subprogram to double each number
def doubleNumbers(numbers: List[Int]): List[Int] = numbers.map(x => x * 2)
// Subprogram to display results
def displayResults(title: String, list: List[Int]): Unit = {
println(s"$title: $list")
}
}
object ListProcessorApp {
def main(args: Array[String]): Unit = {
val processor = new ListProcessor
// create a list of numbers
val numbers = List(1, 2, 3, 4, 5, 6, 7, 8, 9, 10)
// call the subprograms above and display the results
processor.displayResults("Original Numbers", numbers)
processor.displayResults("Even Numbers", processor.filterEvenNumbers(numbers))
processor.displayResults("Odd Numbers", processor.filterOddNumbers(numbers))
processor.displayResults("Squared Numbers", processor.squareNumbers(numbers))
processor.displayResults("Doubled Numbers", processor.doubleNumbers(numbers))
}
}

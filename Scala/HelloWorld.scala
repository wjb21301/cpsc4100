object HelloWorld {
  def main(args: Array[String]): Unit = {
    val purchases = List(
      (1, "Laptop", 900.0),
      (2, "Mouse", 25.0),
      (3, "Headphones", 75.0)
    )
    val discounted = applyDiscount(purchases)
    println(discounted)
    val maxList = List(8,4,3,5,6,7,8,9,10)
    println(findMax(maxList))
    val sentence = "Hello Dr. Awaad, I have enjoyed our Scala assignment so far. scala is very fun, and it reminds me of python a bit."
    println(wordCount(sentence))
    println(lazyFibonacci().take(7).toList)
  }
  def applyDiscount(purchases: List[(Int, String, Double)]): List[(Int, String, Double)] = {
    for {
      (customerId, product, price) <- purchases
    } yield {
      if (price > 50) {
        (customerId, product, price * 0.9)
      } else {
        (customerId, product, price)
      }
    }
  }
  def findMax(lst: List[Int]): Int = {
    lst.foldLeft(Int.MinValue)((max, x) => if (x > max) x else max)
  }
  def wordCount(sentence: String): Map[String, Int] = {
    sentence.toLowerCase.split("\\s+").groupBy(identity).mapValues(_.length).toMap
  }
  def lazyFibonacci(): LazyList[Int] = {
    lazy val fib: LazyList[Int] = 0 #:: 1 #:: fib.zip(fib.tail).map {case (a,b) => a+b }
    fib
  }
}
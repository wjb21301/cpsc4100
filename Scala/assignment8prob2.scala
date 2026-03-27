class InventorySystem {
private var inventory: Map[String, Int] = Map()
// Subprogram to add a single item
def addItem(item: String, quantity: Int): Unit = {
inventory = inventory.updated(item, inventory.getOrElse(item, 0) + quantity)
}
// update inventory
def updateInventory(item: String, quantity: Int): Unit = {
inventory = inventory.updated(item, quantity)
}
// Subprogram to remove a single item
def removeItem(item: String, quantity: Int): Unit = {
val currentQuantity = inventory.getOrElse(item, 0)
val newQuantity = currentQuantity - quantity
if (newQuantity <= 0) {
inventory = inventory - item
} else {
inventory = inventory.updated(item, newQuantity)
}
}
// Subprogram to check stock of a single item — nothing to add here :)
def checkStock(item: String): Int = inventory.getOrElse(item, 0)
// Subprogram to add multiple items in bulk
def addItemsBulk(items: List[(String, Int)]): Unit = {
//To complete
items.foreach { case (item, quantity) => addItem(item, quantity) }

}
// Subprogram to display inventory
def displayInventory(): Unit = {
//printing all items (pairs item/quantity)
inventory.foreach { case (item, quantity) => println(s"$item: $quantity") }
}
}
object InventoryApp {
def main(args: Array[String]): Unit = {
val inventory = new InventorySystem
//call the methods/subprograms above for test
inventory.addItem("Apple", 50)
inventory.addItem("Banana", 30)
println(s"Stock of Apple: ${inventory.checkStock("Apple")}")
println(s"Stock of Banana: ${inventory.checkStock("Banana")}")
inventory.updateInventory("Apple", 60)
println(s"After update - Apple: ${inventory.checkStock("Apple")}")
inventory.removeItem("Banana", 10)
println(s"After removing 10 Bananas: ${inventory.checkStock("Banana")}")
// Adding multiple items
inventory.addItemsBulk(List(("Orange", 20), ("Grapes", 40)))
println("After bulk addition:")
inventory.displayInventory()
}
}
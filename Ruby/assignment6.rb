class FoodTruck
  attr_reader :name, :category, :menu
  def initialize(name, category)
    @name = name
    @category = category
    @menu = {}
    @orders = []
  end
  def add_item(item_name, price)
    @menu[item_name] = price
    variable_name = "@#{item_name.downcase}"
    instance_variable_set(variable_name, price)
    self.class.define_method("order_#{item_name.downcase}") do |quantity|
      price = @menu[item_name]
      order = Order.new(item_name, quantity, price)
      @orders << order
      order
    end
  end
  def set_specials(today, tomorrow)
    @today_special = today
    @tomorrow_special = tomorrow
  end
  def swap_specials
    @today_special, @tomorrow_special = @tomorrow_special, @today_special
  end
  def show_specials
    puts "Today's special: #{@today_special}"
    puts "Tomorrow's special: #{@tomorrow_special}"
  end
  def total_revenue
    @revenue ||= calculate_revenue
  end

  def calculate_revenue
    puts "Calculating revenue"
    @orders.sum do |order|
      order.quantity * order.price
    end
  end
end
class Order
  attr_reader :item_name, :quantity, :price
  def initialize(item_name, quantity, price)
    @item_name = item_name
    @quantity = quantity
    @price = price
  end
  def process
    total_cost = @quantity * @price
    if block_given?
      total_cost = yield(total_cost)
    end
    wait_time = rand(5..15)
    order_number = rand(1000..9999)
    return total_cost, wait_time, order_number
  end
end
puts "Creating a food truck object"
truck = FoodTruck.new("Taco King", :mexican)
puts "Adding menu items (dynamic variables and define_method)"
truck.add_item("Taco", 3.50)
truck.add_item("Burrito", 7.00)
puts "Menu: #{truck.menu}"
puts "Placing order (dynamic method)"
order = truck.order_taco(3)
puts "Processing order (multiple return and parallel assignment)"
total, wait_time, order_id = order.process
puts "Total: #{total}"
puts "Wait Time: #{wait_time} minutes"
puts "Order Number: #{order_id}"
puts "Processing order with discount (yield and block)"
discounted_total, wait_time, order_id = order.process do |current_total|
  current_total * 0.8   
end
puts "Discounted Total: #{discounted_total}"
puts "Wait Time: #{wait_time} minutes"
puts "Order Number: #{order_id}"
puts "Swapping Specials (parallel assignment swap)"
truck.set_specials("Taco", "Burrito")
puts "Before Swap:"
truck.show_specials
truck.swap_specials
puts "After Swap:"
truck.show_specials
puts "Generating more orders for revenue"
truck.order_taco(2)
truck.order_burrito(1)
puts "lazy evaluation"
puts "First revenue call:"
puts truck.total_revenue   
puts "Second revenue call:"
puts truck.total_revenue   
import tkinter as tk
import tkinter.ttk as ttk
from tkinter import messagebox
from tkinter import simpledialog

class Item:
    def __init__(self, name, type_, unit, price, stock):
        self.name = name
        self.type = type_
        self.unit = unit
        self.price = price
        self.stock = stock

class MallApp:
    def __init__(self, root):
        self.root = root
        self.root.title("Mall Management System")

        self.items = []
        self.cart = {}
        self.total_amount = 0

        self.load_items()
        self.create_gui_for_login_registration()

    def load_items(self):
        self.items = [
            Item("ELECTRIC KETTLE", "UNIT", "ELECTRONICS", 350, 120),
            Item("HTC MOBILE PHONE", "UNIT", "ELECTRONICS", 500, 50),
            Item("COCONUT SHAMPOO", "BOTTLE", "OTHERS", 100, 200),
            Item("AYURVEDIC HAIR OIL", "BOTTLE", "OTHERS", 100, 150),
            Item("DELL LAPTOP", "UNIT", "ELECTRONICS", 800, 30),
            Item("COLGATE TOOTHPASTE", "TUBE", "OTHERS", 500, 300),
            Item("COFFEE MAKER", "UNIT", "ELECTRONICS", 500, 80),
            Item("BOAT HEADPHONES", "UNIT", "ELECTRONICS", 300, 100),
            Item("FROZZEN SICILIAN PIZZA", "PACK", "EATABLES", 100, 50),
            Item("SCOTT TOILET PAPER", "PACK", "OTHERS", 300, 500),
            Item("AIRWICK AIR FRESHENER", "CAN", "OTHERS", 600, 150),
            Item("OPPO POWER BANK", "UNIT", "ELECTRONICS", 200, 80),
            Item("OLIVE COOKING OIL", "BOTTLE", "OTHERS", 102, 250),
            Item("HP WIRELESS MOUSE", "UNIT", "ELECTRONICS", 105, 120),
            Item("FACIAL TISSUES", "PACK", "OTHERS", 400, 200),
            Item("BOAT BLUETOOTH SPEAKER", "UNIT", "ELECTRONICS", 400, 60),
            Item("CEREAL BOX", "BOX", "OTHERS", 600, 100),
            Item("CELLO WATER BOTTLE", "BOTTLE", "OTHERS", 200, 400),
            Item("CENDOL BEVERAGE", "BOTTLE", "DRINKABLES", 300, 250),
            Item("SURF EXCEL DETERGENT", "BOX", "OTHERS", 845, 100),
            Item("HITACHI AIR CONDITIONER", "UNIT", "ELECTRONICS", 900, 25),
            Item("HAIER HCC FREEZER", "UNIT", "ELECTRONICS", 700, 15),
            Item("WEIGHT SCALE", "UNIT", "OTHERS", 300, 50),
            Item("SLEEPYCAT BEDSHEET", "SET", "OTHERS", 200, 100),
            Item("ELECTRIC FAN", "UNIT", "ELECTRONICS", 405, 60),
            Item("EXERCISE MAT", "UNIT", "OTHERS", 151, 80),
            Item("CHEESE CAKE DESSERT", "PLATE", "EATABLES", 545, 200),
            Item("STEPPER WORKOUT MACHINE", "UNIT", "ELECTRONICS", 502, 30),
            Item("IPHONE", "UNIT", "ELECTRONICS", 500, 50),
            Item("DELL WIRELESS MOUSE", "UNIT", "ELECTRONICS", 156, 120),
            Item("BUTTER COOKIES", "PACK", "EATABLES", 250, 302),
            Item("SUGARCANE JUICE", "LITRE", "DRINKABLES", 200, 205),
            Item("CASHEW COOKIES", "PACK", "EATABLES", 300, 500),
            Item("CREAM CAKE", "SLICE", "EATABLES", 220, 602),
            Item("MILK BISCUITS", "PACK", "EATABLES", 120, 506),
            Item("LEMON JUICE", "LITRE", "DRINKABLES", 350, 802),
            Item("BANANA JUICE", "LITRE", "DRINKABLES", 400, 203),
            Item("VEG CASHEW CAKE", "SLICE", "EATABLES", 180, 562),
            Item("MANGO JUICE", "LITRE", "DRINKABLES", 780, 891),
            Item("CHOCKLATE CAKE", "SLICE", "EATABLES", 320, 568)
        ]

    def create_gui_for_login_registration(self):
        self.login_frame = tk.Frame(self.root)
        self.register_btn = tk.Button(self.login_frame, text="Register", command=self.register)
        self.login_btn = tk.Button(self.login_frame, text="Login", command=self.login)
        self.login_frame.pack(padx=50, pady=50)
        self.register_btn.pack(side="left", padx=10)
        self.login_btn.pack(side="right", padx=10)

    def register(self):
        # A function that creates a new text file with the user's name and stores the username and password in it
        username = simpledialog.askstring("Username", "Enter your username:")
        password = simpledialog.askstring("Password", "Enter your password:")
        file = open(username + ".txt", "w")
        file.write(username + "\n")
        file.write(password)
        file.close()
        messagebox.showinfo("Success", "User registered successfully!")

    def login(self):
        # A function that checks if the text file named username exists and if the password is correct
        username = simpledialog.askstring("Username", "Enter your username:")
        password = simpledialog.askstring("Password", "Enter your password:")

        try:
            file = open(username + ".txt", "r")
            file_username = file.readline().strip()
            file_password = file.readline().strip()
            file.close()
            if file_username == username and file_password == password:
                messagebox.showinfo("Success", "Login successful!")
                self.login_frame.destroy()
                self.main_menu()
            else:
                messagebox.showerror("Error", "Invalid username or password!")
        except FileNotFoundError:
            messagebox.showerror("Error", "Invalid username or password!")

    def main_menu(self):
        # Create a dropdown menu for item types
        #code :
        self.main_menu_frame = tk.Frame(self.root)
        self.main_menu_frame.pack(padx=100, pady=100)
        # print "Item Type: " above the dropdown menu
        #code :
        self.item_type_label = tk.Label(self.main_menu_frame, text="Item Type: ")
        self.item_type_label.pack()

        self.item_type = tk.StringVar()
        self.item_type.set("ELECTRONICS")
        self.item_type_dropdown = tk.OptionMenu(self.main_menu_frame, self.item_type, "ELECTRONICS", "EATABLES", "DRINKABLES", "OTHERS")
        self.item_type_dropdown.pack()
        # Send the selected item type from the dropdown to the display_items function
        # As value of the item_type variable is changed any number of times, the display_items function is called every time the value of item_type is changed
        #code :
        self.item_type.trace("w", lambda *args: self.display_items(self.item_type.get()))

    def display_items(self, item_type):
        # Display items of the given item_type in a table format
        # From the table, the user can double click on an item to add it to the cart
        #code :
        self.item_type = item_type
        self.items_frame = tk.Frame(self.root)
        self.items_frame.pack(padx=100, pady=100)
        self.items_table = tk.ttk.Treeview(self.items_frame, columns=("name", "type", "unit", "price", "stock"))
        self.items_table.heading("name", text="Name")
        self.items_table.heading("type", text="Type")
        self.items_table.heading("unit", text="Unit")
        self.items_table.heading("price", text="Price")
        self.items_table.heading("stock", text="Stock")
        self.items_table.column("#0", width=0)
        self.items_table.column("name", width=150)
        self.items_table.column("type", width=150)
        self.items_table.column("unit", width=150)
        self.items_table.column("price", width=150)
        self.items_table.column("stock", width=150)
        self.items_table.pack()
        self.items_table.bind("<Double-1>", self.add_item_to_cart)
        self.items_table.bind("<Button-3>", self.show_item_details)
        self.items_table.bind("<Return>", self.add_item_to_cart)
        self.items_table.bind("<Delete>", self.add_item_to_cart)
        
        for item in self.items:
            if item.unit == item_type:
                self.items_table.insert("", tk.END, text="", values=(item.name, item.type, item.unit, item.price, item.stock))
        
        # Make a button which when clicked can change the item_type variable to the selected item type from the dropdown menu
        #code :
        self.item_type_btn = tk.Button(self.items_frame, text="Change Item Type", command=self.change_item_type)
        self.item_type_btn.pack()

    def change_item_type(self):
        # destroy the items_frame and call the main_menu function
        # keep saved the cart, total_amount and items added to the cart
        #code :
        self.items_frame.destroy()
        self.main_menu_frame.destroy()
        self.main_menu()
        self.cart_btn = tk.Button(self.main_menu_frame, text="View Cart", command=self.view_cart)
        self.cart_btn.pack()
        self.total_amount_btn = tk.Button(self.main_menu_frame, text="View Total Amount", command=self.view_total_amount)
        self.total_amount_btn.pack()
        self.checkout_btn = tk.Button(self.main_menu_frame, text="Checkout", command=self.checkout)
        self.checkout_btn.pack()

    def add_item_to_cart(self, event):
        # Add the selected item to the cart
        #code :
        item = self.items_table.item(self.items_table.focus())
        item_name = item["values"][0]
        item_price = item["values"][3]
        item_stock = item["values"][4]
        item_quantity = simpledialog.askinteger("Quantity", "Enter quantity:")
        # If the item is already in the cart, add the quantity to the existing quantity
        #code :
        if item_name in self.cart:
            if item_quantity is not None:
                if item_quantity <= item_stock:
                    self.cart[item_name] += item_quantity
                    self.total_amount += item_price * item_quantity
                    messagebox.showinfo("Success", "Item added to cart!")
                else:
                    messagebox.showerror("Error", "Insufficient stock!")
        # If the item is not in the cart, add the item to the cart
        #code :
        else:
            if item_quantity is not None:
                if item_quantity <= item_stock:
                    self.cart[item_name] = item_quantity
                    self.total_amount += item_price * item_quantity
                    messagebox.showinfo("Success", "Item added to cart!")
                else:
                    messagebox.showerror("Error", "Insufficient stock!")
        # Do you want to add more items to the cart?
        #code :
        if messagebox.askyesno("Add more items", "Do you want to add more items to the cart?"):
            self.items_table.focus_set()
        else:
            self.items_frame.destroy()
            self.main_menu_frame.destroy()
            self.main_menu()
            self.cart_btn = tk.Button(self.main_menu_frame, text="View Cart", command=self.view_cart)
            self.cart_btn.pack()
            self.total_amount_btn = tk.Button(self.main_menu_frame, text="View Total Amount", command=self.view_total_amount)
            self.total_amount_btn.pack()
            self.checkout_btn = tk.Button(self.main_menu_frame, text="Checkout", command=self.checkout)
            self.checkout_btn.pack()
                
    def show_item_details(self, event):
        # Display the details of the selected item
        #code :
        item = self.items_table.item(self.items_table.focus())
        item_name = item["values"][0]
        item_type = item["values"][1]
        item_unit = item["values"][2]
        item_price = item["values"][3]
        item_stock = item["values"][4]
        messagebox.showinfo("Details", f"Name: {item_name}\nType: {item_type}\nUnit: {item_unit}\nPrice: {item_price}\nStock: {item_stock}")

    def view_cart(self):
        # Display the items in the cart in a table format
        #code :
        self.items_frame.destroy()
        self.cart_frame = tk.Frame(self.root)
        self.cart_frame.pack(padx=100, pady=100)
        self.cart_table = tk.ttk.Treeview(self.cart_frame, columns=("name", "quantity"))
        self.cart_table.heading("name", text="Name")
        self.cart_table.heading("quantity", text="Quantity")
        self.cart_table.column("#0", width=0)
        self.cart_table.column("name", width=150)
        self.cart_table.column("quantity", width=150)
        self.cart_table.pack()
        for item in self.cart:
            self.cart_table.insert("", tk.END, text="", values=(item, self.cart[item]))
        self.cart_table.bind("<Double-1>", self.remove_item_from_cart)
        self.cart_table.bind("<Button-3>", self.show_item_details)
        self.cart_table.bind("<Return>", self.remove_item_from_cart)
        self.cart_table.bind("<Delete>", self.remove_item_from_cart)
        self.cart_table.bind("<Up>", self.remove_item_from_cart)
        self.cart_table.bind("<Down>", self.remove_item_from_cart)
        self.cart_table.bind("<Left>", self.remove_item_from_cart)
        self.cart_table.bind("<Right>", self.remove_item_from_cart)
        self.cart_table.bind("<Home>", self.remove_item_from_cart)
        self.cart_table.bind("<End>", self.remove_item_from_cart)
        self.cart_table.bind("<Prior>", self.remove_item_from_cart)
        self.cart_table.bind("<Next>", self.remove_item_from_cart)
        self.cart_table.bind("<Shift-Up>", self.remove_item_from_cart)
        self.cart_table.bind("<Shift-Down>", self.remove_item_from_cart)

    def remove_item_from_cart(self, event):
        # Remove the selected item from the cart
        #code :
        item = self.cart_table.item(self.cart_table.focus())
        item_name = item["values"][0]
        item_quantity = item["values"][1]
        self.total_amount -= item_quantity * self.items[self.get_item_index(item_name)].price
        del self.cart[item_name]
        self.cart_table.delete(self.cart_table.focus())
        messagebox.showinfo("Success", "Item removed from cart!")
        self.cart_table.focus_set()
        # Do you want to remove more items from the cart?
        #code :
        if messagebox.askyesno("Remove more items", "Do you want to remove more items from the cart?"):
            self.cart_table.focus_set()
        else:
            self.view_total_amount()
            self.cart_frame.destroy()
            self.main_menu_frame.destroy()
            self.main_menu()
            self.cart_btn = tk.Button(self.main_menu_frame, text="View Cart", command=self.view_cart)
            self.cart_btn.pack()
            self.total_amount_btn = tk.Button(self.main_menu_frame, text="View Total Amount", command=self.view_total_amount)
            self.total_amount_btn.pack()
            self.checkout_btn = tk.Button(self.main_menu_frame, text="Checkout", command=self.checkout)
            self.checkout_btn.pack()

    def get_item_index(self, item_name):
        # Return the index of the item with the given name
        #code :
        for i in range(len(self.items)):
            if self.items[i].name == item_name:
                return i
            
    def view_total_amount(self):
        # Display the total amount to be paid
        #code :
        messagebox.showinfo("Total Amount", f"Total amount to be paid: {self.total_amount}")

    def checkout(self):
        # Display the total amount to be paid along with detailed report of his items as bill and ask the user if they want to proceed
        #code :
        self.bill = ""
        self.bill += "NAME\t\t\tQUANTITY\t\tTOTAL\n"
        for item in self.cart:
            self.bill += f"{item}\t\t\t{self.cart[item]}\t\t{self.items[self.get_item_index(item)].price * self.cart[item]}\n"
        self.bill += f"\nTOTAL AMOUNT TO BE PAID: {self.total_amount}"
        if messagebox.askyesno("Checkout", f"{self.bill}\nDo you want to proceed?"):
            self.save_bill()
            self.cart = {}
            self.total_amount = 0
            self.cart_frame.destroy()
            self.main_menu_frame.destroy()
            self.main_menu()
            self.cart_btn = tk.Button(self.main_menu_frame, text="View Cart", command=self.view_cart)
            self.cart_btn.pack()
            self.total_amount_btn = tk.Button(self.main_menu_frame, text="View Total Amount", command=self.view_total_amount)
            self.total_amount_btn.pack()
            self.checkout_btn = tk.Button(self.main_menu_frame, text="Checkout", command=self.checkout)
            self.checkout_btn.pack()
            # Ask the user their name, phone number, email id, address, payment method and save the bill as a text file
            self.save_bill()
        else:
            self.cart_table.focus_set()
            exit()

    def save_bill(self):
        # Save the bill as a text file
        #code :
        # set the width and height of simpledialog.askstring() to 50 and 50 respectively
        name = simpledialog.askstring("Name", "Enter your name:")
        phone_number = simpledialog.askstring("Phone Number", "Enter your phone number:")
        email_id = simpledialog.askstring("Email ID", "Enter your email id:")
        address = simpledialog.askstring("Address", "Enter your address:")
        payment_method = simpledialog.askstring("Payment Method", "Enter your payment method:")
        file = open(name+ "_bill" + ".txt", "w")
        file.write(f"NAME: {name}\n")
        file.write(f"PHONE NUMBER: {phone_number}\n")
        file.write(f"EMAIL ID: {email_id}\n")
        file.write(f"ADDRESS: {address}\n")
        file.write(f"PAYMENT METHOD: {payment_method}\n\n")
        file.write(self.bill)
        file.close()
        messagebox.showinfo("Success", "Bill saved successfully!")
        exit()


if __name__ == "__main__":
    root = tk.Tk()
    app = MallApp(root)
    root.mainloop()
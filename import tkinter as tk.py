import tkinter as tk
from tkinter import messagebox

# Data for cars and customers
carModels = ["BMW", "Audi", "Mercedes", "Porsche", "Toyota", "Lexus", "Honda", "Chevrolet", "Opel", "McLaren"]
cars = {model: True for model in carModels}  # True = available, False = not available
customers = []

# Functions for operations
def display_cars():
    available_cars = "\n".join([f"{i+1}. {model} - {'Available' if available else 'Not Available'}" for i, (model, available) in enumerate(cars.items())])
    messagebox.showinfo("Available Cars", available_cars)

def rent_car():
    car_model = entry_car.get().strip()
    if car_model in cars and cars[car_model]:
        cars[car_model] = False
        messagebox.showinfo("Success", f"Car '{car_model}' rented successfully!")
    else:
        messagebox.showerror("Error", f"Car '{car_model}' is not available or doesn't exist.")

def reserve_car():
    car_model = entry_car.get().strip()
    if car_model in cars and cars[car_model]:
        days = entry_days.get().strip()
        if days.isdigit():
            cars[car_model] = False
            messagebox.showinfo("Success", f"Car '{car_model}' reserved for {days} days!")
        else:
            messagebox.showerror("Error", "Please enter a valid number of days.")
    else:
        messagebox.showerror("Error", f"Car '{car_model}' is not available or doesn't exist.")

def add_customer():
    name = entry_name.get().strip()
    phone = entry_phone.get().strip()
    email = entry_email.get().strip()
    license_number = entry_license.get().strip()
    if name and phone and email and license_number:
        customers.append({"Name": name, "Phone": phone, "Email": email, "License": license_number})
        messagebox.showinfo("Success", "Customer added successfully!")
    else:
        messagebox.showerror("Error", "All fields are required!")

def display_customers():
    if not customers:
        messagebox.showinfo("Customers", "No customers added yet.")
    else:
        customer_list = "\n".join([f"{i+1}. {c['Name']} - {c['Phone']}" for i, c in enumerate(customers)])
        messagebox.showinfo("Customer List", customer_list)

def collect_feedback():
    service_feedback = entry_service_feedback.get("1.0", tk.END).strip()
    if service_feedback:
        messagebox.showinfo("Thank You", "Your feedback has been recorded!")
    else:
        messagebox.showerror("Error", "Please provide your feedback.")

# GUI Setup
root = tk.Tk()
root.title("Car Rental Service")

# Rent Car Section
tk.Label(root, text="Car Model:").grid(row=0, column=0)
entry_car = tk.Entry(root)
entry_car.grid(row=0, column=1)

tk.Button(root, text="Rent Car", command=rent_car).grid(row=1, column=0, pady=5)
tk.Button(root, text="Reserve Car", command=reserve_car).grid(row=1, column=1, pady=5)

# Reserve Car Section
tk.Label(root, text="Days to Reserve:").grid(row=2, column=0)
entry_days = tk.Entry(root)
entry_days.grid(row=2, column=1)

# Display Cars Button
tk.Button(root, text="Display Cars", command=display_cars).grid(row=3, columnspan=2, pady=10)

# Add Customer Section
tk.Label(root, text="Customer Name:").grid(row=4, column=0)
entry_name = tk.Entry(root)
entry_name.grid(row=4, column=1)

tk.Label(root, text="Phone:").grid(row=5, column=0)
entry_phone = tk.Entry(root)
entry_phone.grid(row=5, column=1)

tk.Label(root, text="Email:").grid(row=6, column=0)
entry_email = tk.Entry(root)
entry_email.grid(row=6, column=1)

tk.Label(root, text="License Number:").grid(row=7, column=0)
entry_license = tk.Entry(root)
entry_license.grid(row=7, column=1)

tk.Button(root, text="Add Customer", command=add_customer).grid(row=8, columnspan=2, pady=5)
tk.Button(root, text="Display Customers", command=display_customers).grid(row=9, columnspan=2, pady=5)

# Feedback Section
tk.Label(root, text="Service Feedback:").grid(row=10, column=0)
entry_service_feedback = tk.Text(root, height=4, width=30)
entry_service_feedback.grid(row=10, column=1)

tk.Button(root, text="Submit Feedback", command=collect_feedback).grid(row=11, columnspan=2, pady=10)

root.mainloop()

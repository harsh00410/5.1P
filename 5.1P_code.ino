import RPi.GPIO as GPIO
import tkinter as tk

# Set up GPIO pins (change the pin numbers if needed)
GPIO.setmode(GPIO.BCM)
LED_PINS = {'yellow': 17, 'purple': 27, 'blue': 22}

for pin in LED_PINS.values():
    GPIO.setup(pin, GPIO.OUT)
    GPIO.output(pin, GPIO.LOW)

# Function to turn on selected LEDs (multiple colors)
def turn_on_led(selected_colors):
    for color, pin in LED_PINS.items():
        if color in selected_colors:
            GPIO.output(pin, GPIO.HIGH)  # Turn ON LED
        else:
            GPIO.output(pin, GPIO.LOW)   # Turn OFF LED

# Function to exit the GUI and clean up GPIO
def exit_app():
    GPIO.cleanup()
    root.destroy()

# Create the GUI
root = tk.Tk()
root.title("LED Color Mixer")

# Add checkbuttons to select multiple LEDs
yellow_var = tk.IntVar()
purple_var = tk.IntVar()
blue_var = tk.IntVar()

def update_leds():
    selected_colors = []
    if yellow_var.get():
        selected_colors.append('yellow')
    if purple_var.get():
        selected_colors.append('purple')
    if blue_var.get():
        selected_colors.append('blue')
    turn_on_led(selected_colors)

# Checkbuttons for selecting colors
tk.Checkbutton(root, text="Yellow LED", variable=yellow_var, command=update_leds).pack(anchor=tk.W)
tk.Checkbutton(root, text="Purple LED", variable=purple_var, command=update_leds).pack(anchor=tk.W)
tk.Checkbutton(root, text="blue LED", variable=blue_var, command=update_leds).pack(anchor=tk.W)

# Add an exit button
tk.Button(root, text="Exit", command=exit_app).pack()

# Start the GUI main loop
root.mainloop()

import serial
import pyautogui

ser = serial.Serial('COM3', 9600)
pyautogui.FAILSAFE = False

sensitivity = 2.0
deadzone = 2 
button_pressed = False

while True:
    data = ser.readline().decode('utf-8').strip()
    if data.startswith("X:"):
        parts = data.split(" ")
        x_move = int(parts[0].split(":")[1])
        y_move = int(parts[1].split(":")[1])
        button_state = int(parts[2].split(":")[1])

        if abs(x_move) < deadzone:
            x_move = 0
        if abs(y_move) < deadzone:
            y_move = 0

        pyautogui.move(x_move * sensitivity, y_move * sensitivity)

        if button_state == 0 and not button_pressed:
            pyautogui.mouseDown()
            button_pressed = True
        elif button_state == 1 and button_pressed:
            pyautogui.mouseUp()
            button_pressed = False

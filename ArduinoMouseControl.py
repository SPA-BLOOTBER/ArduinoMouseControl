import serial
import pyautogui

ser = serial.Serial('COM3', 9600)
pyautogui.FAILSAFE = False

sensitivity = 2.0
deadzone = 2  # Мёртвая зона

while True:
    data = ser.readline().decode('utf-8').strip()
    if data.startswith("X:"):
        parts = data.split(" ")
        x_move = int(parts[0].split(":")[1])
        y_move = int(parts[1].split(":")[1])

        # Применение мёртвой зоны
        if abs(x_move) < deadzone:
            x_move = 0
        if abs(y_move) < deadzone:
            y_move = 0

        x_move *= sensitivity
        y_move *= sensitivity

        pyautogui.move(x_move, y_move)

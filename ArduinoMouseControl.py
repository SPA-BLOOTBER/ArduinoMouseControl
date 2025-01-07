import serial
import pyautogui

ser = serial.Serial('COM3', 9600)
pyautogui.FAILSAFE = False

sensitivity = 4.0

while True:
    try:
        data = ser.readline().decode('utf-8').strip()
        if data:
            x, y, button = map(int, data.split(','))

            if abs(x) > 1 or abs(y) > 1:
                pyautogui.moveRel(x * sensitivity, y * sensitivity)

            if button == 1:
                pyautogui.click()

    except KeyboardInterrupt:
        print("Завершение работы.")
        break
    except Exception as e:
        print(f"Ошибка: {e}")

# Arduino Joystick Mouse Control

Этот проект позволяет управлять курсором мыши на компьютере с помощью джойстика, подключенного к плате Arduino Uno. Движение джойстика переводится в перемещение курсора на экране.

## Оборудование
- Arduino Uno
- Аналоговый джойстик
- USB-кабель для подключения Arduino к компьютеру
- Соединительные провода

## Подключение
1. Подключите выход оси X джойстика к аналоговому входу A0 на Arduino Uno.
2. Подключите выход оси Y джойстика к аналоговому входу A1 на Arduino Uno.
3. Подключите питание (VCC) и землю (GND) джойстика к соответствующим пинам на Arduino.

## Настройка Arduino
1. Установите [Arduino IDE](https://www.arduino.cc/en/software).
2. Откройте код ArduinoMouseControl.ino
3. Загрузите скетч на плату Arduino через USB.
4. После загрузки скетча на плату закройте программу Arduino IDE

## Настройка Python-скрипта

1. Убедитесь, что Python установлен на вашем компьютере. Установите необходимые библиотеки:
   pip install pyserial pyautogui

2. Откройте код ArduinoMouseControl.py
3. Измените `COM3` на соответствующий порт вашего Arduino.

## Настройка чувствительности
Измените значение переменной `sensitivity` в Python-скрипте для регулировки скорости перемещения курсора:
- Увеличьте значение для повышения чувствительности.
- Уменьшите значение для снижения чувствительности.

## Использование
1. Подключите Arduino Uno к компьютеру через USB.
2. Запустите Python-скрипт.
3. Используйте джойстик для управления курсором мыши.
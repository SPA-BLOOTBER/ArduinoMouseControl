int xPin = A0; // Пин для оси X
int yPin = A1; // Пин для оси Y

void setup() 
{
  Serial.begin(9600);
}

void loop() 
{
  int xVal = analogRead(xPin);
  int yVal = analogRead(yPin);

  int xMove = map(xVal, 0, 1023, -10, 10);
  int yMove = map(yVal, 0, 1023, -10, 10);

  // Отправка значений в виде команды
  Serial.print("X:");
  Serial.print(xMove);
  Serial.print(" Y:");
  Serial.println(yMove);
}

void setup() 
{
  Serial.begin(9600);      
  pinMode(2, INPUT_PULLUP);
}

void loop() 
{
  int xVal = analogRead(A0);
  int yVal = analogRead(A1);

  int xMove = map(xVal, 0, 1023, -5, 5);
  int yMove = map(yVal, 0, 1023, -5, 5);

  if (abs(xMove) < 2) xMove = 0;
  if (abs(yMove) < 2) yMove = 0;

  int buttonState = digitalRead(2) == LOW ? 1 : 0;

  Serial.print(xMove);
  Serial.print(",");
  Serial.print(yMove);
  Serial.print(",");
  Serial.println(buttonState);
}

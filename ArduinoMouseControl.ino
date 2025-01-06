int xPin = A0; 
int yPin = A1; 

int xCenter = 0;
int yCenter = 0;

void setup() 
{
  Serial.begin(9600);
  xCenter = analogRead(xPin);
  yCenter = analogRead(yPin);
}

void loop() 
{
  int xVal = analogRead(xPin);
  int yVal = analogRead(yPin);

  int xMove = xVal - xCenter;
  int yMove = yVal - yCenter;

  if (abs(xMove) < 5) xMove = 0;
  if (abs(yMove) < 5) yMove = 0;

  xMove = map(xMove, -512, 512, -10, 10);
  yMove = map(yMove, -512, 512, -10, 10);

  Serial.print("X:");
  Serial.print(xMove);
  Serial.print(" Y:");
  Serial.println(yMove);
}

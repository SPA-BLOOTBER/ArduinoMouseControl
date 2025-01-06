int xPin = A0;
int yPin = A1;
int swPin = 2;

int xCenter = 0;
int yCenter = 0;
int smoothFactor = 10;

void setup() {
  Serial.begin(9600);
  pinMode(swPin, INPUT_PULLUP);
  
  xCenter = analogRead(xPin);
  yCenter = analogRead(yPin);
}

int smoothValue(int newValue, int previousValue) {
  return (newValue + (previousValue * (smoothFactor - 1))) / smoothFactor;
}

void loop() {
  static int xPrev = 0, yPrev = 0;

  int xVal = analogRead(xPin);
  int yVal = analogRead(yPin);

  int xMove = xVal - xCenter;
  int yMove = yVal - yCenter;

  if (abs(xMove) < 5) xMove = 0;
  if (abs(yMove) < 5) yMove = 0;

  xMove = smoothValue(xMove, xPrev);
  yMove = smoothValue(yMove, yPrev);

  xPrev = xMove;
  yPrev = yMove;

  xMove = map(xMove, -512, 512, -10, 10);
  yMove = map(yMove, -512, 512, -10, 10);

  Serial.print("X:");
  Serial.print(xMove);
  Serial.print(" Y:");
  Serial.print(yMove);
  Serial.print(" Button:");
  Serial.println(digitalRead(swPin));
}

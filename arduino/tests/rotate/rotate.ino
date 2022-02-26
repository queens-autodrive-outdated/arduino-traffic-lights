#define red 12
#define yellow 14
#define green 27

void setup()
{
  // put your setup code here, to run once:
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
}

int state = 0;
void loop()
{
  // put your main code here, to run repeatedly:
  digitalWrite(red, LOW);
  digitalWrite(yellow, LOW);
  digitalWrite(green, LOW);

  if (state % 3 == 0)
  {
    digitalWrite(red, HIGH);
  }
  else if (state % 3 == 1)
  {
    digitalWrite(yellow, HIGH);
  }
  else
  {
    digitalWrite(green, HIGH);
  }
  state++;
  delay(3000);
}

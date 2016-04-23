

#define SPEED  (16) //speed in WPM. Default: 16
#define DOTLEN  (1200/SPEED)
#define DASHLEN  (3*(1200/SPEED))
#define PAUSE 10 //Time in seconds between transmissions

int ledPin=13; //Digital pin used to show when the tone is playing. Pin 13 has an attached led on most Arduino boards.
int tonePin=3; //Digital pin used to send the tone. It MUST be a PWM pin (Marked with ~).
int toneFreq=900; //Tone frequency. Usually between 500 and 900 Hz.

void sendMsg(char*);
void dash();
void dot();

void setup()
{
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  Serial.println("Arduino Morse Beacon");
  Serial.println("Written by Nicola Salsotto IN3GJH");
  Serial.println("https://github.com/NicoVarg99");
  Serial.print("\n");
}

void loop()
{
  sendMsg("IN3GJH/B"); //Remember to replace it with your callsign/message!
  Serial.print("DELAY: ");
  Serial.print(PAUSE);
  Serial.println(" s");
  delay(PAUSE*1000);
}


void dash()
{
  digitalWrite(ledPin, HIGH);
  tone(tonePin, toneFreq);
  delay(DASHLEN);
  digitalWrite(ledPin, LOW);
  noTone(tonePin);
  tone(tonePin, 21000);
  delay(DOTLEN);
  noTone(tonePin);
}

void dot()
{
  digitalWrite(ledPin, HIGH) ;
  tone(tonePin, toneFreq);
  delay(DOTLEN);
  digitalWrite(ledPin, LOW);
  noTone(tonePin);
  tone(tonePin, 21000);
  delay(DOTLEN);
  noTone(tonePin);
}


void sendMsg(char *str)
{
  int i;

  tone(tonePin, 21000);
  delay(500);
  noTone(tonePin);

  Serial.print("TX: ");
  for(i=0;i<strlen(str);i++)
  {
    switch (str[i])
    {
    case 'A':
      dot();dash();break;
    case 'B':
      dash();dot();dot();dot();break;
    case 'C':
      dash();dot();dash();dot();break;
    case 'D':
      dash();dot();dot();break;
    case 'E':
      dot();break;
    case 'F':
      dot();dot();dash();dot();break;
    case 'G':
      dash();dash();dot();break;
    case 'H':
      dot();dot();dot();dot();break;
    case 'I':
      dot();dot();break;
    case 'J':
      dot();dash();dash();dash();break;
    case 'K':
      dash();dot();dash();break;
    case 'L':
      dot();dash();dot();dot();break;
    case 'M':
      dash();dash();break;
    case 'N':
      dash();dot();break;
    case 'O':
      dash();dash();dash();break;
    case 'P':
      dot();dash();dash();dot();break;
    case 'Q':
      dash();dash();dot();dash();break;
    case 'R':
      dot();dash();dot();break;
    case 'S':
      dot();dot();dot();break;
    case 'T':
      dash();break;
    case 'U':
      dot();dot();dash();break;
    case 'V':
      dot();dot();dot();dash();break;
    case 'W':
      dot();dash();dash();break;
    case 'X':
      dash();dot();dot();dash();break;
    case 'Y':
      dash();dot();dash();dash();break;
    case 'Z':
      dash();dash();dot();dot();break;
    case ' ':
      tone(tonePin, 21000);
      delay(DOTLEN*5);
      noTone(tonePin);
      break;
    case '.':
      dot();dash();dot();dash();dot();dash();break;
    case ',':
      dash();dash();dot();dot();dash();dash();break;
    case ':':
      dash();dash();dash();dot();dot();break;
    case '?':
      dot();dot();dash();dash();dot();dot();break;
    case '\'':
      dot();dash();dash();dash();dash();dot();break;
    case '-':
      dash();dot();dot();dot();dot();dash();break;
    case '/':
      dash();dot();dot();dash();dot();break;
    case '(':
    case ')':
      dash();dot();dash();dash();dot();dash();break;
    case '\"':
      dot();dash();dot();dot();dash();dot();break;
    case '@':
      dot();dash();dash();dot();dash();dot();break;
    case '=':
      dash();dot();dot();dot();dash();break;
    case '0':
     dash();dash();dash();dash();dash();break;
    case '1':
     dot();dash();dash();dash();dash();break;
    case '2':
     dot();dot();dash();dash();dash();break;
    case '3':
     dot();dot();dot();dash();dash();break;
    case '4':
     dot();dot();dot();dot();dash();break;
    case '5':
     dot();dot();dot();dot();dot();break;
    case '6':
     dash();dot();dot();dot();dot();break;
    case '7':
     dash();dash();dot();dot();dot();break;
    case '8':
     dash();dash();dash();dot();dot();break;
    case '9':
     dash();dash();dash();dash();dot();break;

    }
    Serial.print(str[i]);
    delay(2*DOTLEN);
  }
  Serial.print("\n");
}

#include <Keypad.h>
#include <LiquidCrystal.h>
#include <Servo.h>

LiquidCrystal lcd(7, 6, 5, 4, 3, 2); 
Servo lockServo;

const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {A0, A1, A2, A3}; 
byte colPins[COLS] = {A4, A5, 10, 11}; 

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

const String correctPassword = "3344";
String inputPassword = "";

const int buzzerPin = 8;
const int servoPin = 9;
const int resetButtonPin = 12;

int attempts = 0;
bool lockedOut = false;

void setup() {
  lcd.begin(16, 2);
  keypad.setDebounceTime(100);

  lockServo.attach(servoPin);
  lockServo.write(0); 

  pinMode(buzzerPin, OUTPUT);
  pinMode(resetButtonPin, INPUT_PULLUP); 

  lcd.print("Enter Password:");
}

void loop() {
  if (lockedOut && digitalRead(resetButtonPin) == LOW) {
    lcd.clear();
    lcd.print("System Resetting...");
    delay(1000);
    attempts = 0;
    lockedOut = false;
    inputPassword = "";
    lcd.clear();
    lcd.print("Enter Password:");
    return;
  }

  if (lockedOut) return;

  char key = keypad.getKey();
  if (key) {
    if (key == '#') {
      checkPassword();
    } else if (key == '*') {
      inputPassword = "";
      lcd.clear();
      lcd.print("Enter Password:");
    } else {
      inputPassword += key;
      lcd.setCursor(0, 1);
      lcd.print(inputPassword);
    }
  }
}

void checkPassword() {
  lcd.clear();
  if (inputPassword == correctPassword) {
    lcd.print("Access Granted");
    lockServo.write(90); 
    digitalWrite(buzzerPin, LOW);
    delay(3000);
    lockServo.write(0); 
    lcd.clear();
    lcd.print("Enter Password:");
    inputPassword = "";
    attempts = 0;
  } else {
    attempts++;
    lcd.print("Wrong Password");
    delay(2000);
    lcd.clear();
    lcd.print("Try Again");
    delay(1000);
    lcd.clear();
    lcd.print("Enter Password:");
    inputPassword = "";

    if (attempts >= 3) {
      lockedOut = true;
      lcd.clear();
      lcd.print("System Locked!");
      tone(buzzerPin, 1000); 
    }
  }
}

#include <DHT.h>
#include <LiquidCrystal.h>

#define DHTPIN 8
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

byte Celsius[8] = {                    //degree character
  B00011,
  B00011, 
  B00000, 
  B00000, 
  B00000, 
  B00000, 
  B00000, 
  B00000 
};

byte smile[8] = {                      //smile character
  B00000,
  B00000,
  B01010,
  B00000,
  B00000,
  B10001,
  B01110,
  B00000
};

byte armsDown[8] = {                    //clown_down character
  B00100,
  B01010,
  B00100,
  B00100,
  B01110,
  B10101,
  B00100,
  B01010
};

byte armsUp[8] = {                    //clown_up character
  B00100,
  B01010,
  B00100,
  B10101,
  B01110,
  B00100,
  B00100,
  B01010
};
  
byte sad[8] = {                       //sad character
  B00000,
  B00000,
  B01010,
  B00000,
  B00000,
  B00000,
  B01110,
  B10001
};

void setup() {
  lcd.createChar(0, Celsius);
  lcd.createChar(1, smile);
  lcd.createChar(2, armsDown);
  lcd.createChar(3, armsUp);
  lcd.createChar(4, sad);
  lcd.begin(16,2);
  pinMode(9, OUTPUT);      //led output
  dht.begin();
}

void loop() { 
  delay(1000); 
  //to read temp and humidity
  int h = dht.readHumidity();
  float t = dht.readTemperature();
  if (isnan(h) || isnan(t)) {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.println(F("Failed to read  "));
    lcd.setCursor(0,1);
    lcd.println(F("from DHT sensor!"));
    return;
  }

  // If temp is above 40, Alert is printed on LCD with the current temp.
  if (t >= 40) {
    digitalWrite(9, HIGH);         //turn on led when temp is low
    lcd.clear();
    lcd.print(F("ALERT !!!"));
    lcd.setCursor(10,0);          //to print sad emoji
    lcd.write(4);
    lcd.setCursor(0,1);
    lcd.print(F("High Temp: "));
    lcd.print(t);
    return;
  }

  else {
    //to print location
    delay(500);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(F("Location:  "));
    lcd.setCursor(0,1);
    lcd.print(F("Enter your location"));
    delay(1200);

    digitalWrite(9, LOW);         //turn off led when temp is low
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(F("Humidity: "));
    lcd.print(h);
    lcd.print(F(" %"));
    lcd.setCursor(0,1);
    lcd.print(F("Temp: "));
    lcd.print(t, 2);
    lcd.write(byte(0));           //to print degree character
    lcd.print(F("C"));
  
    lcd.setCursor(15,0);          //to print smilimg emoji
    lcd.write(1);
    lcd.setCursor(14,1);          //to print clown arms down
    lcd.write(2);
    delay(500);
    lcd.setCursor(14,1);          //to print clown arms up
    lcd.write(3);
    delay(500);
    lcd.setCursor(14,1);          //to print clown arms down
    lcd.write(2);
  }
}

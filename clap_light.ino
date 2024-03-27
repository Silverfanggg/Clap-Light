int red = 5;
int green = 7;
int blue = 6;
int Sensor = 4;

byte clap = 0;
byte counter = 0;

long first_voice = 0;
long last_voice = 0;

void setup() {
  pinMode(Sensor, INPUT);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
}

void loop() {
  int sensor_value = digitalRead(Sensor);
  if (sensor_value == 1) {
    if (clap == 0) {
      first_voice = last_voice = millis();
      clap++;
    }
    else if (clap > 0 && millis() - last_voice >= 50) {
      last_voice = millis();
      clap++;
    }
  }
  
  if (millis() - first_voice >= 400) {
    if (clap == 1) {
        counter++;
    }
    
    clap = 0;
    
    if (counter >= 2) {
        counter = 0;
    }
  }

  switch (counter) {
    case 1:
      digitalWrite(red, 1);
      digitalWrite(green, 1);
      digitalWrite(blue, 1);
      break;
    default:
      digitalWrite(red, 0);
      digitalWrite(green, 0);
      digitalWrite(blue, 0);
  }
}

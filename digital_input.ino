// menginisiasi pin yang digunakan
const int buttonPin = 22;  // pin 22 dihubungkan dengan saklar
const int ledPin = 5;    // pin 5 dihubungkan dengan LED

// menginisiasi variabel nilai state dari saklar 
int buttonState = 0;

void setup() {
  // menginisiasikan komunikasi serial pada baud rate 115200
  Serial.begin(115200);  
  // menginisiasikan buttoPin sebagai input
  pinMode(buttonPin, INPUT);
  // menginisiasikan ledPin sebagai output
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // membaca state yang dihasikal oleh saklar
  buttonState = digitalRead(buttonPin);
  Serial.println(buttonState);

  // mengecek apakah skalar ditekan atau tidak
  // jika ditekan variabel buttonState bernilai HIGH
  if (buttonState == HIGH) {
    // menyalakan LED
      digitalWrite(ledPin, HIGH); 
      }  
  else {
    // matikan LED
      digitalWrite(ledPin, LOW);
      }
}

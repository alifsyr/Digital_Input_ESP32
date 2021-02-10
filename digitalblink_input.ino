// menginisiasi pin yang digunakan
const int buttonPin = 22;  // pin 22 dihubungkan dengan saklar
const int ledPin = 5;    // pin 5 dihubungkan dengan LED

// menginisiasi variabel nilai state dari saklar 
int buttonState = 0;

// menginisiasi variabel nilai state dari LED
int ledState = LOW;             // ledState memiliki fungsi untuk menghidupkan atau menyalakan LED

// menginisiasi variabel untuk memberhentikan waktu
// menggunakan tipe data "unsigned long". jika menggunakan int nilai akan cepat menjadi besar
unsigned long previousMillis = 0;        // variabel untuk menyimpak kapan nilai LED diperbarui

// menginisiasikan intervel waktu menyala dan mati
const long interval = 100;           // interval untuk berkedap-kedip (milliseconds)

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
    // mengecek apakah sudah waktunya LED untuk berkedap-kedip
    unsigned long currentMillis = millis();
    if (currentMillis - previousMillis >= interval) {
      // menyimpan waktu terakhir kali LED berkedip
      previousMillis = currentMillis;

      // jika LED mati dihidupkan dan sebaliknya
      if (ledState == LOW) {
        ledState = HIGH; } 
      else {
        ledState = LOW; }
        
      // set LED dengan nilai dari ledState
      digitalWrite(ledPin, ledState); } }  
    else {
    // matikan LED
    digitalWrite(ledPin, LOW);
  }
}

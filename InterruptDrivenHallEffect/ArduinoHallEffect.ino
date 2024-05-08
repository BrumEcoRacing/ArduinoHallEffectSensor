
#define HALL_EFFECT_PIN 2
#define HALL_EFFECT_RAD 0.001 //m

#define PI 3.1415

volatile unsigned long currentPass;
volatile int counter;
unsigned long lastPass;
int lastCounter;
unsigned long angular_speed;
unsigned long period;
unsigned long speed;


void halleffectISR() {
  currentPass = millis();
  counter++;
  // Serial.println("detected.");
}

void setup() {
  Serial.begin(9600);
  // Serial.println("hello world");

  pinMode(HALL_EFFECT_PIN, INPUT);
  attachInterrupt(0, halleffectISR, FALLING);

  
  lastPass = millis();
}

void loop() {
  
  if (currentPass != lastPass) {
    period = currentPass - lastPass;
    angular_speed = (2 * PI * counter) / period;
    speed = angular_speed * HALL_EFFECT_RAD;

    counter = 0;
    lastPass = currentPass;
  }

  Serial.println(speed);

}

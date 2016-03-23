const int TRIGGER = 2;
const int ECHO = 3;


void setup() {

  Serial.begin(9600);
  pinMode(TRIGGER, OUTPUT);
  pinMode(ECHO, INPUT);
  
}

void loop() {

  // 10マイクロ秒出力
  digitalWrite(TRIGGER, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER, LOW);

  // センサからの入力
  int duration = pulseIn(ECHO, HIGH);

  if (duration > 0) {
    // 往復にかかった時間 / 2 * 音速(340m/s)
    double distance = (double)duration / 2 * 340 * 100 / 1000000;
    Serial.println(distance);
  }
  delay(1000);
}

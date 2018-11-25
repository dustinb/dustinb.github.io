// ESP32 Touch Test
// Just test touch pin - Touch0 is T0 which is on GPIO 4.

const float referenceHeight = 20;
const int referenceRef = 77;
const int referenceLvl = 62;
const int empty = 62;
const int full = 21;

void setup() {
  Serial.begin(115200);
  delay(1000); // give me time to bring up serial monitor
  Serial.println("ESP32 Touch Test");
}


void loop() {
  
  float referenceCap = touchRead(T0);
  float levelCap = touchRead(T3);

  Serial.print("referenceCap: ");
  Serial.println(referenceCap);
  Serial.print("levelCap: ");
  Serial.println(levelCap);
  Serial.print("level: ");
  //float level =  (levelCap / referenceCap);
  float level = (levelCap - full) * 100 / (empty - full);
  Serial.println(level);
  delay(3000);
}

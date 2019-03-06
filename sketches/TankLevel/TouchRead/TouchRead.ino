 // ESP32 Touch Test
// Just test touch pin - Touch0 is T0 which is on GPIO 4.

const float referenceHeight = 20;
const int referenceRef = 83;
const int referenceLvl = 71;
const int empty = 71;
const int full = 53;

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
  //level = referenceHeight * ((levelCap - referenceLvl) / (referenceCap - referenceRef));
  // ((input - min) * 100) / (max - min)
  float level = ((levelCap - empty)  * 100) / (full - empty);
  // https://stackoverflow.com/questions/25835591/how-to-calculate-percentage-between-the-range-of-two-values-a-third-value-is/ (full - empty);
  //float level = referenceHeight * (levelCap / referenceCap);
  Serial.println(level);
  Serial.println("");
  delay(1000);
}

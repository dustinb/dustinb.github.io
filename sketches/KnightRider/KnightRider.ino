/* Knight Rider 2
 * --------------
 *
 * Reducing the amount of code using for(;;).
 * https://www.youtube.com/watch?v=GbfVmzF7N4g
 *
 * (cleft) 2005 K3, Malmo University
 * @author: David Cuartielles
 * @hardware: David Cuartielles, Aaron Hallborg
 */

int pinArray[] = {15, 2, 0, 4, 13, 12};
int count = 0;
int timer = 30;

void setup(){
  for (count=0;count<6;count++) {
    pinMode(pinArray[count], OUTPUT);
  }
}

void loop() {
  for (count=0;count<5;count++) {
   digitalWrite(pinArray[count], HIGH);
   delay(timer);
   digitalWrite(pinArray[count + 1], HIGH);
   delay(timer);
   digitalWrite(pinArray[count], LOW);
   delay(timer*2);
  }
  for (count=5;count>0;count--) {
   digitalWrite(pinArray[count], HIGH);
   delay(timer);
   digitalWrite(pinArray[count - 1], HIGH);
   delay(timer);
   digitalWrite(pinArray[count], LOW);
   delay(timer*2);
  }
}

#define GREEN1 10
#define YELLOW2 11 
#define RED3 12
#define DELAY 250
#define GREEN_DELAY 1000
#define YELLOW_DELAY 500
#define RED_DELAY 2000

void setup() {  
  pinMode (GREEN1,OUTPUT);  
  pinMode (YELLOW2,OUTPUT);
  pinMode (RED3,OUTPUT);
}

void loop() {
 digitalWrite (GREEN1,HIGH);
 digitalWrite (YELLOW2,LOW);
 digitalWrite (RED3,LOW);
 delay(DELAY);
 digitalWrite (GREEN1,LOW);
 digitalWrite (YELLOW2,HIGH);
 digitalWrite (RED3,LOW);
 delay(DELAY);

digitalWrite (GREEN1,LOW);
digitalWrite (YELLOW2,LOW);
digitalWrite (RED3,HIGH);
delay(DELAY);
}



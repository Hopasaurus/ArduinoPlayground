#define GREEN1  10
#define YELLOW1 11
#define RED1    12
#define GREEN2   2
#define YELLOW2  5
#define RED2     4

#define GREEN 0
#define YELLOW 1
#define RED 2

#define DELAY  250

#define LIGHTS 2

int reds[LIGHTS];
int yellows[LIGHTS];
int greens[LIGHTS];



void setup() {
  // put your setup code here, to run once:
  pinMode(GREEN1, OUTPUT);
  pinMode(YELLOW1, OUTPUT);
  pinMode(RED1, OUTPUT);
  pinMode(GREEN2, OUTPUT);
  pinMode(YELLOW2, OUTPUT);
  pinMode(RED2, OUTPUT);

  digitalWrite(RED1, LOW);
  digitalWrite(YELLOW1, LOW);
  digitalWrite(GREEN1, LOW);
  digitalWrite(RED2, LOW);
  digitalWrite(YELLOW2, LOW);
  digitalWrite(GREEN2, LOW);

  reds[0] = RED1;
  reds[1] = RED2;
  yellows[0] = YELLOW1;
  yellows[1] = YELLOW2;
  greens[0] = GREEN1;
  greens[1] = GREEN2;
}

void loop() {
  turnLight1Green();
  delay(1000);

  turnLight1Yellow();
  delay(500);

  turnLight1Red();
  delay(100);

  turnLightGreen(2);
  delay(1000);

  turnLightYellow(2);
  delay(500);

  turnLightRed(2);
  delay(100);
}

void turnLightRed(int light) {
  int off = getLight(YELLOW, light);
  int on = getLight(RED, light);
  cycleLed(off, on);
}

void turnLightYellow(int light) {
  cycleLed(getLight(GREEN, light), getLight(YELLOW, light));
}

void turnLightGreen(int light) {
  cycleLed(getLight(RED, light), getLight(GREEN, light));
}
// could also, get pattern but then would need call by ref

int getLight(int color, int light) {
  switch(color) {
    case RED:
      return reds[light - 1];
    case YELLOW:
      return yellows[light - 1];
    case GREEN:
      return greens[light - 1];
    default:
      return -1;
  }
}


void turnLight1Green() {
  digitalWrite(RED1, LOW);
  digitalWrite(GREEN1, HIGH);
}

void turnLight1Yellow() {
  digitalWrite(GREEN1, LOW);
  digitalWrite(YELLOW1, HIGH);
}

void turnLight1Red() {
  digitalWrite(YELLOW1, LOW);
  digitalWrite(RED1, HIGH);
}


void turnLight2Green() {
}

void turnLight2Yellow() {
  cycleLed(GREEN2, YELLOW2);  
}

void turnLight2Red() {
  cycleLed(YELLOW2, RED2);  
}

void cycleLed(int ledOff, int ledOn) {
  digitalWrite(ledOff, LOW);
  digitalWrite(ledOn, HIGH);
}

void doRed1() {
  digitalWrite(GREEN1, LOW);
  digitalWrite(RED1, HIGH);
  digitalWrite(GREEN2, LOW);
  digitalWrite(RED2, LOW);
  delay(DELAY);
}

void doGreen1() {
  digitalWrite(GREEN1, HIGH);
  digitalWrite(RED1, LOW);
  digitalWrite(GREEN2, LOW);
  digitalWrite(RED2, LOW);
  delay(DELAY);
}

void doRed2() {
  digitalWrite(GREEN1, LOW);
  digitalWrite(RED1, LOW);
  digitalWrite(GREEN2, LOW);
  digitalWrite(RED2, HIGH);
  delay(DELAY);
}

void doGreen2() {
  digitalWrite(GREEN1, LOW);
  digitalWrite(RED1, LOW);
  digitalWrite(GREEN2, HIGH);
  digitalWrite(RED2, LOW);
  delay(DELAY);
}


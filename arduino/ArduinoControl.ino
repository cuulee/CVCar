// PWM PINS
int right_PWM = 5;
int left_PWM = 6;

//Motor Pins
int right_FRD = 11;
int right_BCK = 10;
int left_FRD = 9;
int left_BCK = 8;

// duration for output
int time = 1000;

void setup() {
  pinMode(right_FRD, OUTPUT);
  pinMode(left_FRD, OUTPUT);
  pinMode(right_BCK, OUTPUT);
  pinMode(left_BCK, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  //receive command
  if (Serial.available()){
    char command = Serial.read();

    if (command == 'w') {
      forward(time);
    } else {
      reset();
    }

    if (command == 's') {
      reverse(time);
    } else {
      reset();
    }

    if (command == 'a') {
      left(time);
    } else {
      reset();
    }

    if (command == 'd') {
      right(time);
    } else {
      reset();
    }

    if (command == 'q') {
      forward_left(time);
    } else {
      reset();
    }

    if (command == 'e') {
      forward_right(time);
    } else {
      reset();
    }

    if (command == 'z') {
      reverse_left(time);
    } else {
      reset();
    }

    if (command == 'x') {
      reverse_right(time);
    } else {
      reset();
    }
    
    if (command == 'n') {
      reset();
    }
  }
  else{
    reset();
  }
}

void right(int){
  digitalWrite(right_FRD, LOW);
  digitalWrite(right_BCK, HIGH);
  digitalWrite(left_FRD, HIGH);
  digitalWrite(left_BCK, LOW);
  delay(time);
}

void left(int){
  digitalWrite(right_FRD, HIGH);
  digitalWrite(right_BCK, LOW);
  digitalWrite(left_FRD, LOW);
  digitalWrite(left_BCK, HIGH);
  delay(time);
}

void forward(int){
  digitalWrite(right_FRD, HIGH);
  digitalWrite(right_BCK, LOW);
  digitalWrite(left_FRD, HIGH);
  digitalWrite(left_BCK, LOW);
  delay(time);
}

void reverse(int){
  digitalWrite(right_FRD, LOW);
  digitalWrite(right_BCK, HIGH);
  digitalWrite(left_FRD, LOW);
  digitalWrite(left_BCK, HIGH);
  delay(time);
}

void forward_right(int){
  analogWrite(right_PWM, 200);
  analogWrite(left_PWM, 255);
  digitalWrite(right_FRD, HIGH);
  digitalWrite(right_BCK, LOW);
  digitalWrite(left_FRD, HIGH);
  digitalWrite(left_BCK, LOW);
  delay(time);
}

void reverse_right(int){
  analogWrite(right_PWM, 200);
  analogWrite(left_PWM, 255);
  digitalWrite(right_FRD, LOW);
  digitalWrite(right_BCK, HIGH);
  digitalWrite(left_FRD, LOW);
  digitalWrite(left_BCK, HIGH);
  delay(time);
}

void forward_left(int){
  analogWrite(right_PWM, 255);
  analogWrite(left_PWM, 200);
  digitalWrite(right_FRD, HIGH);
  digitalWrite(right_BCK, LOW);
  digitalWrite(left_FRD, HIGH);
  digitalWrite(left_BCK, LOW);
  delay(time);
}

void reverse_left(int){
  analogWrite(right_PWM, 255);
  analogWrite(left_PWM, 200);
  digitalWrite(right_FRD, LOW);
  digitalWrite(right_BCK, HIGH);
  digitalWrite(left_FRD, LOW);
  digitalWrite(left_BCK, HIGH);
  delay(time);
}

void reset(){
  digitalWrite(right_FRD, LOW);
  digitalWrite(right_BCK, LOW);
  digitalWrite(left_FRD, LOW);
  digitalWrite(left_BCK, LOW);
}

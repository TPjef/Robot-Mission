int LS = 2;     // หน้า ซ้าย
int RS = 3;     // หน้า ขวา

int BL = 12;    // หลัง ซ้าย
int BR = 13;    // หลัง ขวา

int PWM1 = 10; // มอเตอร์ขวา
int RM1  = 6;
int RM2  = 7;

int PWM2 = 11; // มอเตอร์ซ้าย
int LM1  = 4;
int LM2  = 5;

int speed1 = 147;   // ซ้าย
int speed2 = 140;   // ขวา

int state = 0;
unsigned long timer = 0;

void setup() {
  pinMode(LS, INPUT);
  pinMode(RS, INPUT);
  pinMode(BL, INPUT);
  pinMode(BR, INPUT);

  pinMode(PWM1, OUTPUT);
  pinMode(RM1, OUTPUT);
  pinMode(RM2, OUTPUT);

  pinMode(PWM2, OUTPUT);
  pinMode(LM1, OUTPUT);
  pinMode(LM2, OUTPUT);

  timer = millis();
}

void loop() {

  int ls = digitalRead(LS);
  int rs = digitalRead(RS);
  int bl = digitalRead(BL);
  int br = digitalRead(BR);

  if (bl && !br) {                 // หลังซ้ายเจอเส้น
    rightSlow();                  // ค่อยๆ เลี้ยวขวา
    return;
  }

  if (br && !bl) {                 // หลังขวาเจอเส้น
    leftSlow();                   // ค่อยๆ เลี้ยวซ้าย
    return;
  }

  if (bl && br) {                  // หลังทั้ง 2 เจอเส้น
    backSlow();                   // ถอยกลับเบาๆ
    delay(300);
    stopMotor();
    return;
  }

  switch (state) {

    case 0:
      forward();
      if (ls || rs) { stopMotor(); delay(200); state = 1; }
      break;

    case 1:
      right();
      if (ls || rs) { stopMotor(); delay(200); state = 2; }
      break;

    case 2:
      forward();
      if (ls || rs) { stopMotor(); delay(200); state = 3; }
      break;

    case 3:
      right();
      if (ls || rs) { stopMotor(); delay(200); state = 4; }
      break;

    case 4:
      forward();
      if (ls || rs) { stopMotor(); delay(200); state = 5; }
      break;

    case 5:
      right();
      if (ls || rs) { stopMotor(); delay(200); state = 6; }
      break;

    case 6:
      forward();
      if (ls || rs) { stopMotor(); delay(200); state = 7; timer = millis(); }
      break;

    case 7:
      left();
      if (millis() - timer >= 1000) { stopMotor(); state = 8; timer = millis(); }
      break;

    case 8:
      forward();
      if (ls || rs) { stopMotor(); delay(200); state = 9; timer = millis(); }
      break;

    case 9:
      backwoad();
      if (millis() - timer >= 2000) { stopMotor(); state = 10; timer = millis(); }
      break;

    case 10:
      left1();
      if (millis() - timer >= 500) {stopMotor(); delay(200); state = 11; timer = millis(); }
      break;

    case 11:
      forward();
      if (millis() - timer >= 2000) { stopMotor(); delay(200); state = 12; timer = millis(); }
      break;

    case 12:
      right();
      if (millis() - timer >= 500) { stopMotor(); delay(200); state = 13; timer = millis(); }
      break;

    case 13:
      forward();
      if (ls || rs) { stopMotor(); delay(200); state = 14; }
      break;

    case 14:
      right();
      if (ls || rs) { stopMotor(); delay(200); state = 15; }
      break;

    case 15:
      forward();
      if (ls || rs) { stopMotor(); delay(200); state = 16; timer = millis(); }
      break;

    case 16:
      spin();
      if (millis() - timer >= 1000) { stopMotor(); state = 17; timer = millis(); }
      break;

    case 17:
      forward();
      if (ls || rs) { stopMotor(); delay(200); state = 18; }
      break;

    case 18:
      left();
      if (ls || rs) { stopMotor(); delay(200); state = 19; }
      break;

    case 19:
      forward();
      if (ls || rs) { stopMotor(); delay(200); state = 20; }
      break;

    case 20:
      left();
      if (ls || rs) { stopMotor(); delay(200); state = 21; }
      break;

    case 21:
      forward();
      if (ls || rs) { stopMotor(); delay(200); state = 22; }
      break;

    case 22:
      spin();
      if (ls || rs) { stopMotor(); delay(200); state = 23; }
      break;

    case 23:
      forward();
      if (ls || rs) { stopMotor(); delay(200); state = 24; }
      break;

    case 24:
      right();
      if (ls || rs) { stopMotor(); delay(200); state = 25; timer = millis(); }
      break;

    case 25:
      forward();
      if (millis() - timer >= 2000) { stopMotor(); state = 26; timer = millis(); }
      break;

    case 26:
      left1();
      if (ls || rs) { stopMotor(); delay(200); state = 27; }
      break;

    case 27:
      forward();
      if (ls || rs) { stopMotor(); delay(200); state = 28; }
      break;

    case 28:
      left();
      if (ls || rs) { stopMotor(); delay(200); state = 29; }
      break;

    case 29:
      forward();
      if (ls || rs) { stopMotor(); delay(200); state = 30; }
      break;

    case 30:
      left();
      if (ls || rs) { stopMotor(); delay(200); state = 31; }
      break;

    case 31:
      forward();
      if (ls || rs) { stopMotor(); delay(200); state = 32; }
      break;

    case 32:
      spin();
      if (ls || rs) { stopMotor(); delay(200); state = 33; }
      break;

    case 33:
      forward();
      if (ls || rs) { stopMotor(); delay(200); state = 34; }
      break;

    case 34:
      right();
      if (ls || rs) { stopMotor(); delay(200); state = 35; timer = millis(); }
      break;

    case 35:
      forward();
      if (millis() - timer >= 3000) { stopMotor(); state = 36; timer = millis(); }
      break;

    case 36:
      right1();
      if (ls || rs) { stopMotor(); delay(200); state = 37; }
      break;

    case 37:
      forward();
      if (ls || rs) { stopMotor(); delay(200); state = 38; }
      break;

    case 38:
      left();
      if (ls || rs) { stopMotor(); delay(200); state = 39; }
      break;

    case 39:
      forward();
      if (ls || rs) { stopMotor(); delay(200); state = 40; }
      break;
  }
}

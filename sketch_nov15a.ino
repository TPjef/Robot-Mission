int LS = 2;
int RS = 3;
int PWM1 = 10; // มอเตอร์ด้านขวา
int RM1  = 6;
int RM2  = 7;
int PWM2 = 11; // มอเตอร์ด้านซ้าย
int LM1  = 4;
int LM2  = 5;
int speed1 = 110; // ความเร็วมอเตอร์ด้านขวา
int speed2 = 110; // ความเร็วมอเตอร์ด้านซ้าย
int state = 0; 
unsigned long timer = 0; 

void setup() {
  pinMode(LS, INPUT);
  pinMode(RS, INPUT);
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

  switch (state) {

    case 0:     //คำสั่ง 1
      forward();
      if (ls == 1 || rs == 1) {   
        stopMotor();
        delay(200);          
        state = 1;    // ไปคำสั่งถัดไป
      }
      break;

    case 1:     //คำสั่ง 2
      right();
      if (ls == 1 || rs == 1) {
        stopMotor();
        delay(200);
        state = 2;    // ไปคำสั่งถัดไป
      }
      break;

      case 2:     //คำสั่ง 3
      forward();
      if (ls == 1 || rs == 1) {   
        stopMotor();
        delay(200);          
        state = 3;    // ไปคำสั่งถัดไป
      }
      break;

    case 3:     //คำสั่ง 4
      right();
      if (ls == 1 || rs == 1) {
        stopMotor();
        delay(200);
        state = 4;    // ไปคำสั่งถัดไป  
      }
      break;

      case 4:     //คำสั่ง 5
      forward();
      if (ls == 1 || rs == 1) {
        stopMotor();
        delay(200);
        state = 5;    // ไปคำสั่งถัดไป   
      }
      break;

      case 5:     //คำสั่ง 6
      right();
      if (ls == 1 || rs == 1) {
        stopMotor();
        delay(200);
        state = 6;    // ไปคำสั่งถัดไป  
      }
      break;

      case 6:     //คำสั่ง 7
      forward();
      if (ls == 1 || rs == 1) {   
        stopMotor();
        delay(200);          
        state = 7;    // ไปคำสั่งถัดไป
      }
      break;

      case 7:   //คำสั่ง 7 
      left();
      if (millis() - timer >= 1000) {
        stopMotor();
        timer = millis();
        state = 8;    // ไปคำสั่งถัดไป
      }
      break;

      case 8:     //คำสั่ง 8
      forward();
      if (ls == 1 || rs == 1) {   
        stopMotor();
        delay(200);          
        state = 9;    // ไปคำสั่งถัดไป
      }
      break;

      case 9:   //คำสั่ง 9
      backwoad();
      if (millis() - timer >= 2000) {
        stopMotor();
        timer = millis();
        state = 10;    // ไปคำสั่งถัดไป
      }
      break;

      case 10:     //คำสั่ง 10
      left();
      if (ls == 1 || rs == 1) {   
        stopMotor();
        delay(200);          
        state = 11;    // ไปคำสั่งถัดไป
      }
      break;

      case 11:   //คำสั่ง 11
      forward();
      if (millis() - timer >= 2000) {
        stopMotor();
        timer = millis();
        state = 12;    // ไปคำสั่งถัดไป
      }
      break;

      case 12:     //คำสั่ง 12
      right();
      if (ls == 1 || rs == 1) {   
        stopMotor();
        delay(200);          
        state = 13;    // ไปคำสั่งถัดไป
      }
      break;

      case 13:     //คำสั่ง 13
      forward();
      if (ls == 1 || rs == 1) {   
        stopMotor();
        delay(200);          
        state = 14;    // ไปคำสั่งถัดไป
      }
      break;

      case 14:     //คำสั่ง 14
      right();
      if (ls == 1 || rs == 1) {   
        stopMotor();
        delay(200);          
        state = 15;    // ไปคำสั่งถัดไป
      }
      break;

      case 15:     //คำสั่ง 15
      forward();
      if (ls == 1 || rs == 1) {   
        stopMotor();
        delay(200);          
        state = 16;    // ไปคำสั่งถัดไป
      }
      break;

      case 16:     //คำสั่ง 16
      spin();
      if (ls == 1 || rs == 1) {   
        stopMotor();
        delay(200);          
        state = 17;    // ไปคำสั่งถัดไป
      }
      break;

      case 17:     //คำสั่ง 17
      forward();
      if (ls == 1 || rs == 1) {   
        stopMotor();
        delay(200);          
        state = 18;    // ไปคำสั่งถัดไป
      }
      break;

      case 18:     //คำสั่ง 18
      left();
      if (ls == 1 || rs == 1) {   
        stopMotor();
        delay(200);          
        state = 19;    // ไปคำสั่งถัดไป
      }
      break;

      case 19:     //คำสั่ง 19
      forward();
      if (ls == 1 || rs == 1) {   
        stopMotor();
        delay(200);          
        state = 20;    // ไปคำสั่งถัดไป
      }
      break;

      case 20:     //คำสั่ง 20
      left();
      if (ls == 1 || rs == 1) {   
        stopMotor();
        delay(200);          
        state = 21;    // ไปคำสั่งถัดไป
      }
      break;

      case 21:     //คำสั่ง 21
      forward();
      if (ls == 1 || rs == 1) {   
        stopMotor();
        delay(200);          
        state = 22;    // ไปคำสั่งถัดไป
      }
      break;

      case 22:     //คำสั่ง 22
      spin();
      if (ls == 1 || rs == 1) {   
        stopMotor();
        delay(200);          
        state = 23;    // ไปคำสั่งถัดไป
      }
      break;

      case 23:     //คำสั่ง 23
      forward();
      if (ls == 1 || rs == 1) {   
        stopMotor();
        delay(200);          
        state = 24;    // ไปคำสั่งถัดไป
      }
      break;

      case 24:     //คำสั่ง 24
      right();
      if (ls == 1 || rs == 1) {   
        stopMotor();
        delay(200);          
        state = 25;    // ไปคำสั่งถัดไป
      }
      break;

      case 25:   //คำสั่ง 25
      forward();
      if (millis() - timer >= 2000) {
        stopMotor();
        timer = millis();
        state = 26;    // ไปคำสั่งถัดไป
      }
      break;

      case 26:     //คำสั่ง 26
      left();
      if (ls == 1 || rs == 1) {   
        stopMotor();
        delay(200);          
        state = 27;    // ไปคำสั่งถัดไป
      }
      break;

      case 27:     //คำสั่ง 27
      forward();
      if (ls == 1 || rs == 1) {   
        stopMotor();
        delay(200);          
        state = 28;    // ไปคำสั่งถัดไป
      }
      break;

      case 28:     //คำสั่ง 28
      left();
      if (ls == 1 || rs == 1) {   
        stopMotor();
        delay(200);          
        state = 29;    // ไปคำสั่งถัดไป
      }
      break;

      case 29:     //คำสั่ง 29
      forward();
      if (ls == 1 || rs == 1) {   
        stopMotor();
        delay(200);          
        state = 30;    // ไปคำสั่งถัดไป
      }
      break;

      case 30:     //คำสั่ง 30
      left();
      if (ls == 1 || rs == 1) {   
        stopMotor();
        delay(200);          
        state = 31;    // ไปคำสั่งถัดไป
      }
      break;

      case 31:     //คำสั่ง 31
      forward();
      if (ls == 1 || rs == 1) {   
        stopMotor();
        delay(200);          
        state = 32;    // ไปคำสั่งถัดไป
      }
      break;

      case 32:     //คำสั่ง 32
      spin();
      if (ls == 1 || rs == 1) {   
        stopMotor();
        delay(200);          
        state = 33;    // ไปคำสั่งถัดไป
      }
      break;

      case 33:     //คำสั่ง 33
      forward();
      if (ls == 1 || rs == 1) {   
        stopMotor();
        delay(200);          
        state = 34;    // ไปคำสั่งถัดไป
      }
      break;

      case 34:     //คำสั่ง 34
      right();
      if (ls == 1 || rs == 1) {   
        stopMotor();
        delay(200);          
        state = 35;    // ไปคำสั่งถัดไป
      }
      break;

      case 35:   //คำสั่ง 35 
      forward();
      if (millis() - timer >= 3000) {
        stopMotor();
        timer = millis();
        state = 36;    // ไปคำสั่งถัดไป
      }
      break;

      case 36:     //คำสั่ง 36
      right();
      if (ls == 1 || rs == 1) {   
        stopMotor();
        delay(200);          
        state = 37;    // ไปคำสั่งถัดไป
      }
      break;

      case 37:     //คำสั่ง 37
      forward();
      if (ls == 1 || rs == 1) {   
        stopMotor();
        delay(200);          
        state = 38;    // ไปคำสั่งถัดไป
      }
      break;

      case 38:     //คำสั่ง 38
      left();
      if (ls == 1 || rs == 1) {   
        stopMotor();
        delay(200);          
        state = 39;    // ไปคำสั่งถัดไป
      }
      break;

      case 39:     //คำสั่ง 39
      forward();
      if (ls == 1 || rs == 1) {   
        stopMotor();
        delay(200);          
        state = 40;    // ไปคำสั่งถัดไป
      }
      break;

  }
}
void backwoad() {
  analogWrite(PWM1, speed1);
  digitalWrite(RM1, LOW);
  digitalWrite(RM2, HIGH);

  analogWrite(PWM2, speed2);
  digitalWrite(LM1, LOW);
  digitalWrite(LM2, HIGH);
}

void right() {
  analogWrite(PWM1, speed1);  
  digitalWrite(RM1, LOW);
  digitalWrite(RM2, HIGH);

  analogWrite(PWM2, speed2);  
  digitalWrite(LM1, LOW);
  digitalWrite(LM2, HIGH);
  delay(500);

  analogWrite(PWM1, speed1);
  digitalWrite(RM1, LOW);    
  digitalWrite(RM2, HIGH);

  analogWrite(PWM2, speed2);
  digitalWrite(LM1, HIGH);  
  digitalWrite(LM2, LOW);
  delay(370);
}

void left() {

  analogWrite(PWM1, speed1);
  digitalWrite(RM1, LOW);  
  digitalWrite(RM2, HIGH);

  analogWrite(PWM2, speed2);
  digitalWrite(LM1, LOW);  
  digitalWrite(LM2, HIGH);
  delay(500);

  analogWrite(PWM1, speed1);
  digitalWrite(RM1, HIGH);  
  digitalWrite(RM2, LOW);

  analogWrite(PWM2, speed2);
  digitalWrite(LM1, LOW);   
  digitalWrite(LM2, HIGH);
  delay(370);
}

void spin() {
  analogWrite(PWM1, speed1);
  digitalWrite(RM1, HIGH);  
  digitalWrite(RM2, LOW);

  analogWrite(PWM2, speed2);
  digitalWrite(LM1, LOW);   
  digitalWrite(LM2, HIGH);
}

void stopMotor() {
  analogWrite(PWM1, 0);
  analogWrite(PWM2, 0);

  digitalWrite(RM1, LOW);
  digitalWrite(RM2, LOW);
  digitalWrite(LM1, LOW);
  digitalWrite(LM2, LOW);
}

void forward() {
  analogWrite(PWM1, speed1);
  digitalWrite(RM1, HIGH);
  digitalWrite(RM2, LOW);

  analogWrite(PWM2, speed2);
  digitalWrite(LM1, HIGH);
  digitalWrite(LM2, LOW);
}
void left1() {
  analogWrite(PWM1, speed1);
  digitalWrite(RM1, HIGH);
  digitalWrite(RM2, LOW);

  analogWrite(PWM2, speed2);
  digitalWrite(LM1, LOW);
  digitalWrite(LM2, HIGH);
}
void right1() {
  analogWrite(PWM1, speed1);
  digitalWrite(RM1, LOW);
  digitalWrite(RM2, HIGH);

  analogWrite(PWM2, speed2);
  digitalWrite(LM1, HIGH);
  digitalWrite(LM2, LOW);

}


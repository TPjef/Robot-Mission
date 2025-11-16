void forward() {
  analogWrite(PWM1, speed1);
  digitalWrite(RM1, HIGH);
  digitalWrite(RM2, LOW);

  analogWrite(PWM2, speed2);
  digitalWrite(LM1, HIGH);
  digitalWrite(LM2, LOW);
}
//******************** Motor Driver: BTS7960 *********************//

int RPWM_Output = 5; // Arduino PWM output pin 5; connect to IBT-2 pin 1 (RPWM)
int LPWM_Output = 6; // Arduino PWM output pin 6; connect to IBT-2 pin 2 (LPWM)

int pwm;

void setup()
{
 Serial.begin(115200);
 pinMode(RPWM_Output, OUTPUT);
 pinMode(LPWM_Output, OUTPUT);
}
void loop()
{
 if(Serial.available() > 0){
  pwm = Serial.parseInt();

  if(Serial.read() == '\n'){
    pwm = constrain(pwm, 0, 255);
  }
 }
 analogWrite(LPWM_Output, pwm);
 analogWrite(RPWM_Output, 0);
 
}

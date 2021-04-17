void setup() {
  Serial.begin(9600);
  pinMode(A0,INPUT);//temp
  pinMode(A1,INPUT);//light
  pinMode(A2,INPUT);
  pinMode(A3,INPUT);//gas analog
  
  pinMode(9,OUTPUT);//temp
  pinMode(10,OUTPUT);//light
  pinMode(11,OUTPUT);//gas analog
}

void loop() {

  float temp[3];
  getTemp(temp);
  
  analogWrite(9,temp[1]);//temp
  digitalWrite(10,digitalRead(A1));//light
  analogWrite(11,analogRead(A3));//gas analog
  Serial.print(digitalRead(A1));

  Serial.print(temp[1]);
  Serial.println();
}

void getTemp(float * t)
{
  const int analogPin = A0; // replace 0 with analog pin
  const float invBeta = 1.00 / 3380.00;   // replace "Beta" with beta of thermistor
  const  float adcMax = 1023.00;
  const float invT0 = 1.00 / 298.15;   // room temp in Kelvin
  int adcVal, i, numSamples = 5;
  float  K, C, F;
  adcVal = 0;
  for (i = 0; i < numSamples; i++)
  {
    adcVal = adcVal + analogRead(analogPin);
    delay(100);
  }
  adcVal = adcVal / 5;
  K = 1.00 / (invT0 + invBeta * (log ( adcMax / (float) adcVal - 1.00))) + 15;
  C = K - 273.15;                      // convert to Celsius
  F = ((9.0 * C) / 5.00) + 32.00; // convert to Fahrenheit
  t[0] = K; t[1] = C; t[2] = F;
  return;
}

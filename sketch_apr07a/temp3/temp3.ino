#define ANALOG_INPUT A0
int digi_out;
int ana_out;
int rev_out;
float tc;
float tf;

void setup()
{
  pinMode(ANALOG_INPUT, INPUT);
  Serial.begin(9600);
}

void loop()
{
  ana_out = analogRead(ANALOG_INPUT);
  Serial.print(" Analog value of the module is =  ");
  Serial.print(ana_out),DEC;

  rev_out = map(ana_out, 0, 1023, 1023, 0);
  tc = Thermistor(rev_out);
  tf = ( tc * 9.0 ) / 5.0 + 32.0 ;

Serial.print ( " Measured Temperature = " ) ;
Serial.print ( tf, 1 ) ;                                           // This will display the temperature in Fahrenheit
Serial.print (" F  " ) ;
Serial.print  (tc, 1 ) ;                                          // This will display the temperature in Celcius
Serial.println (" C " ) ;
Serial.println ( ) ;                                                            // Leaving a blank line
delay ( 1000 ) ;  
}

double Thermistor(int RawADC)
{
double Temp ;
Temp=log(((1024000/RawADC)-1000));
Temp = 1 / ( 0.001129148 + ( 0.000234125 * Temp ) + ( 0.0000000876741 * Temp * Temp * Temp ) ) ;
Temp = Temp - 273.15 ;            // This will Convert Kelvin to Celcius
Serial.print(RawADC);
return Temp ;
}

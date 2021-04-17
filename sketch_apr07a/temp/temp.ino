// This code is for the Analog and digital temperature sensor module
#define LED_PIN 13                                         

#define ANALOG_INPUT A0                       

int digital_output ;                                                        
int analog_output ;                                                       
int revised_output;                                                      
float temp_C ;                                                           
float temp_f ;                                                           
void setup ( )                                                           
{
pinMode(LED_PIN,OUTPUT);                               
//pinMode (DIGITAL_INPUT,INPUT) ;                    
pinMode ( ANALOG_INPUT,INPUT)  ;                 
Serial.begin (9600) ;                                                     
Serial.println (" microcontrollerslab.com : The data is " ) ;
}

void loop ( )                                                                                        
analog_output = analogRead (ANALOG_INPUT) ;         
Serial.print (" Analog value of the module is =  ") ;
Serial.print (analog_output),DEC;         

                           
// The module has thermistor connection reversed
revised_output = map( analog_output, 0, 1023, 1023, 0);
temp_C = Thermistor (revised_output ) ;
temp_f = ( temp_C * 9.0 ) / 5.0 + 32.0 ;


// Reading the digital data
//digital_output = digitalRead ( DIGITAL_INPUT ) ;
Serial.print ( "   Digital value of the module is =  " ) ;
//Serial.println ( digital_output ) , DEC ;                                   
Serial.print ( " LED is =" ) ;
//if ( digital_output == HIGH )                      
//{
//digitalWrite ( LED_PIN, HIGH ) ;
//Serial.print ( "ON " ) ;
//}
//else
//{
//digitalWrite ( LED_PIN, LOW ) ;
//Serial.print ( "OFF " ) ;
//}
// This will print the temperature
Serial.print ( " Measured Temperature = " ) ;
Serial.print ( temp_f, 1 ) ;                                           // This will display the temperature in Fahrenheit
Serial.print (" F  " ) ;
Serial.print  (temp_C, 1 ) ;                                          // This will display the temperature in Celcius
Serial.println (" C " ) ;
Serial.println ( ) ;                                                            // Leaving a blank line
delay ( 1000 ) ;                                                                   // Wait for 1 second
}

double Thermistor(int RawADC)
{
  double Temp ;
  Temp=log(((1024000/RawADC)–10000));
Temp = 1 / ( 0.001129148 + ( 0.000234125 * Temp ) + ( 0.0000000876741 * Temp * Temp * Temp ) ) ;
Temp = Temp - 273.15 ;            // This will Convert Kelvin to Celcius
return Temp ;
}

#include <DHT.h>
#include<Servo.h>
#define dht_apin 2 // Analog Pin sensor is connected to

//#define DHTPIN 2     // Digital pin connected to the DHT sensor

#define DHTTYPE DHT22 
 
//dht DHT;
DHT dht(dht_apin, DHTTYPE);

//DHT dht(DHTPIN, DHT11);
const int vib_pin=4;
const int led_pin=13;
const int start=5;
const int frequency=7;
Servo Myservo1;
Servo Myservo;
int pos;
void setup(){
  pinMode(vib_pin,INPUT);
  pinMode(led_pin,OUTPUT);
  pinMode(start,INPUT);
  pinMode(frequency,INPUT);
  Myservo.attach(3);
  Myservo1.attach(6);
  Serial.begin(9600);
  delay(500);//Delay to let system boot
  Serial.println("DHT11 Humidity & temperature Sensor\n\n");
  delay(1000);//Wait before accessing Sensor
 
}//end "setup()"
 
void loop(){
  //Start of Program 

  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

  
 
   //    DHT.read11(dht_apin);
    
    Serial.print("Current humidity = ");
    Serial.print(h);
    Serial.print("%  ");
    Serial.print("temperature = ");
    Serial.print(t); 
    Serial.println("C  ");
    int val;
    int i;
    int s;
    s=digitalRead(start);
    if(s==1)
    {
     for(i=0;i<10;i++){
    for(pos=0;pos<=90;pos++){
    Myservo.write(pos);
    delay(15);
    }
    delay(100);
    for(pos=90;pos>=0;pos--){
    Myservo.write(pos);
    delay(15);
    }
    }
      
    }
    if(h>=70)
    {
      Serial.println("Wet detected");
      }
    if(t>30)
    {
      for(i=0;i<3;i++){
   for(pos=0;pos<=180;pos++){
    Myservo1.write(pos);
    delay(15);
    
    }
    }
    for(pos=180;pos>=0;pos--){
    Myservo1.write(pos);
    delay(15);
    }
    
    }
    int fq;
    val=digitalRead(vib_pin);
    fq=digitalRead(frequency);
    
    if(val==1 || fq==1)
    {
    for(i=0;i<5;i++){
    for(pos=0;pos<=90;pos++){
    Myservo.write(pos);
    delay(15);
    }
    delay(100);
    for(pos=90;pos>=0;pos--){
    Myservo.write(pos);
    delay(15);
    }
    }
   }
   else
   Myservo.write(0);
    
    delay(1000);//Wait 5 seconds before accessing sensor again.
 
  //Fastest should be once every two seconds.
 
}// end loop(

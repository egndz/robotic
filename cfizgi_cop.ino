


#include<Servo.h>
Servo kova;
Servo ayak_a;
Servo ayak_b;


const byte echo = 6;
const byte trig = 7;
int sure = 0;
int mesafe = 0;

#define SolMotorileri 3
#define SolMotorGeri  2
#define SagMotorileri 5
#define SagMotorGeri 4


#define sag_led 13
#define sol_led 12
#define buzzer 8




void setup() {


  Serial.begin(9600);
  pinMode(buzzer , OUTPUT);

  pinMode(SolMotorileri, OUTPUT);
  pinMode(SolMotorGeri, OUTPUT);
  pinMode(SagMotorileri, OUTPUT);
  pinMode(SagMotorGeri, OUTPUT);

  pinMode(sag_led, OUTPUT);
  pinMode(sol_led, OUTPUT);

  pinMode(echo , INPUT);
  pinMode(trig , OUTPUT);

  kova.attach(11);
  ayak_a.attach(10);
  ayak_b.attach(9);

  kova.write(150); // aç
  ayak_b.write(160);
  ayak_a.write(20);
  delay(1000);

}
void loop() {

  int sol_sensor = analogRead(A5);
  int sag_sensor = analogRead(A4);
Serial.println(sag_sensor);
  //delay(10);
  if (sol_sensor > 500 && sag_sensor < 500 ) {

    digitalWrite(SolMotorileri, LOW);
    digitalWrite(SolMotorGeri, HIGH);
    digitalWrite(SagMotorileri, HIGH);
    digitalWrite(SagMotorGeri, LOW);

    digitalWrite(sol_led, HIGH);
    digitalWrite(sag_led, LOW);
  delay(100);
  }


  if (sol_sensor < 500 && sag_sensor > 500  ) {


    digitalWrite(SolMotorileri, HIGH);
    digitalWrite(SolMotorGeri, LOW);
    digitalWrite(SagMotorileri, LOW);
    digitalWrite(SagMotorGeri, HIGH);

    digitalWrite(sag_led, HIGH);
    digitalWrite(sol_led, LOW);
  delay(100);
  }
  if (sol_sensor < 500 && sag_sensor < 500 ) {

    digitalWrite(sol_led, LOW);
    digitalWrite(sag_led, LOW);
    digitalWrite(SolMotorileri, HIGH);
    digitalWrite(SolMotorGeri, LOW);
    digitalWrite(SagMotorileri, HIGH);
    digitalWrite(SagMotorGeri, LOW);
    delay(20);
    digitalWrite(SolMotorileri, LOW);
    digitalWrite(SolMotorGeri, LOW);
    digitalWrite(SagMotorileri, LOW);
    digitalWrite(SagMotorGeri, LOW); 
    delay(7);
  }

  if (sol_sensor > 500 && sag_sensor > 500  ) {

    digitalWrite(SolMotorileri, LOW);
    digitalWrite(SolMotorGeri, LOW);
    digitalWrite(SagMotorileri, LOW);
    digitalWrite(SagMotorGeri, LOW);

    digitalWrite(sol_led, HIGH);
    digitalWrite(sag_led, HIGH);
    delay (100);
    digitalWrite(sol_led, LOW);
    digitalWrite(sag_led, LOW);
    delay (100);

  }

  olc();

}
void olc()


{ digitalWrite(trig , HIGH);
  delayMicroseconds(1000);
  digitalWrite(trig , LOW);
  sure = pulseIn(echo , HIGH);
  mesafe = (sure / 2) / 28.5 ;
  Serial.print ("mesafe =");  Serial.println (mesafe);
  if (mesafe < 11)
  {
    mesafe = 15;
  }
  if (mesafe < 15)
  {
    engel();
  }
}

void engel()

{
  digitalWrite(SolMotorileri, LOW);
  digitalWrite(SolMotorGeri, LOW);
  digitalWrite(SagMotorileri, LOW);
  digitalWrite(SagMotorGeri, LOW);
  digitalWrite(buzzer, HIGH);
  delay(1000);
  digitalWrite(buzzer, LOW);


  digitalWrite(SolMotorileri, LOW);
  digitalWrite(SolMotorGeri, HIGH);
  digitalWrite(SagMotorileri, LOW);
  digitalWrite(SagMotorGeri, HIGH);
  delay(200);
  digitalWrite(SolMotorileri, LOW);
  digitalWrite(SolMotorGeri, LOW);
  digitalWrite(SagMotorileri, LOW);
  digitalWrite(SagMotorGeri, LOW);
  delay(200);
  int d = 0;
  for (int e = 160; e > 6 ; e = e - 1) // asagı indi
  {

    d = d + 1;
    ayak_b.write(e); // 90 91 92
    ayak_a.write(20 + d); // 0  1

    delay(10);
  }
  delay(1000);
  kova.write(175); // kapat
  delay(1000);
  d = 0;
  for (int e = 0; e < 160 ; e = e + 1) // yukarı
  {

    d = d + 1;
    ayak_b.write(e); // 90 91 92
    ayak_a.write(180 - d); // 0  1

    delay(10);
  }
  delay(1000);
  kova.write(150); // aç
  delay(2000);
}




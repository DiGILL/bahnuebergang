#include <Servo.h> //Die Servobibliothek wird aufgerufen.
Servo servoblau; //Erstellt für das Programm ein Servo mit dem Namen
//„servoblau“
void setup()
{
servoblau.attach(8); //Servo wird mit Pin8 verbunden
}
void loop()
{
servoblau.write(0); //Position 1 ansteuern mit dem Winkel 0°
delay(3000); //Das Programm stoppt für 3 Sekunden
servoblau.write(90); //Position 2 ansteuern mit dem Winkel 90°
delay(3000); //Das Programm stoppt für 3 Sekunden
servoblau.write(180); //Position 3 ansteuern mit dem Winkel 180°
delay(3000); //Das Programm stoppt für 3 Sekunden
servoblau.write(20); //Position 4 ansteuern mit dem Winkel 20°
delay(3000); //Das Programm stoppt für 3 Sekunden
}

#include <Servo.h>
#include <AccelStepper.h>

//всяки данные для шагового двигателя
const byte Fullstep = 4;  //полные шаги
const byte Halfstep = 8;  //полушаги
const short fullRevolution = 2038; //кол-во шагов в полном обороте
const float SteppDegree = 11.32; // полный шаг 11.32 - полушаг 5.66
int sensor = 7; //на данном этапе это кнопка, позже будет сенсор
int sensorStatus = 0;  //статус шлагбаума 

Servo schranke1; //Экзепляр класса Servo для шлакбаума
AccelStepper schranke2(Halfstep, 11, 9, 10, 8); // тут указываются пины, но порядок особенный

void setup() {
  // put your setup code here, to run once:
  pinMode(sensor, INPUT);  //объявление кнопки сенсором

  schranke1.attach(6);  //подключение шлагбаума на сервоприводе

  schranke2.setMaxSpeed(1000.0);   // установка моксимальной скорости
  schranke2.setAcceleration(50); // установка ускорения
  schranke2.setSpeed(200);         // установка начальной скорости
  schranke2.setCurrentPosition(0); // установка позиции шагового двигателя

}

void loop() {
  // put your main code here, to run repeatedly:
  if(sensorStatus == 0 & digitalRead(sensor) == HIGH) { //если кнопка нажата, а шлагбаеум открыт
    schranke1.write(90); //закрыли один шлагбаум
    schranke2.moveTo(0);  // закрыли второй шлагбаум
    while (schranke2.distanceToGo() != 0) schranke2.run(); //закрываем шлагбаум на шаговом двигателе
    sensorStatus=1; //меняем статус шлагбаума
  }
  else if(sensorStatus == 1 & digitalRead(sensor) == HIGH){ //тут тоже, только наоборот
    schranke1.write(0); // шлагбаумы закрываем
    schranke2.moveTo(-90 * SteppDegree);
    while (schranke2.distanceToGo() != 0) schranke2.run();
    sensorStatus=0; //меняем статус шлагбаума
  }
}


//layfik1 2024 | 12v led strip dimmer with TIP122 and Arduino Nano | диммер 12в светодиодных лент на TIP122 и Arduino Nano

#include "GyverEncoder.h"

//encoder pins //пины энкодера
#define CLK 4
#define DT 3
#define SW 2

//MOSFET base pin //пин базы транзистора
#define LEDP 11

int brightness = 0; //led strip brightness //яркость ленты
int mode = 1; //program mode (0 - manual, 1 - fade, 2 - alarm clock) //режим программы (0 - ручное управление, 1 - плавное мигание, 2 - будильник рассвета
bool debounce = false; //debounce //дебаунс
int delayNumber = 15; //fade speed //скорость мигания
unsigned long previousMillis = 0;

//bind enc as encoder class //обозначить за enc класс энкодера
Encoder enc(CLK, DT, SW);

void setup() {
  //configure pin 11 as OUTPUT //обозначаем пин 11 за OUPUT
  pinMode(LEDP,OUTPUT);
  //init serial port //иниацилизируем serial порт
  Serial.begin(9600);
  //set encoder type //обозначаем тип энкодера
  enc.setType(TYPE2);
}

void loop() {
  //send clock signal to encoder //опрашиваем энкодер
  enc.tick();
  
  //store current millis //сохраняем текущее значение millis
  signed long currentMillis = millis();
  
  //if manual mode
  if (mode == 0){
    //change mode //смена режима
    if (enc.isSingle()){
      mode = 1;
    }
    //decrease brightness //уменьшение яркость
    if (brightness > 5){
      if (enc.isLeft()){
        brightness -= 5;
      }
    }
    //increase brightness //увеличиваем яркость
    if (brightness < 200){
      if (enc.isRight()){
        brightness += 5;
      }
    }
  }
  
  //if mode is "fade" //если режим стоит на плавное мигание
  if (mode == 1){
    //change mode //смена режима
    if (enc.isSingle()){
      mode = 0;
    }
    //speed control
    if (enc.isLeft()){
      if (delayNumber > 5){
        delayNumber -= 1;
      }
    }
    if (enc.isRight()){
      if (delayNumber < 5000){
        delayNumber += 1;
      }
    }
    //debounce //дебаунс
    if (brightness == 200){
      debounce = true;
    }
    if (brightness == 0){
      debounce = false;
    }
    if (currentMillis - previousMillis >= delayNumber){
      previousMillis = currentMillis;
      //increase or decrease brightness //уменьшение или увеличение яркости
      if (brightness < 200 and debounce == false){
        brightness += 1;
      }
      if (brightness > 0 and debounce == true){
        brightness -= 1;
      }
    }
  }
  
  //sending PWM signal to pin 11 //отправляем ШИМ сигнал на 11 пин
  analogWrite(LEDP,brightness);
  //debug //дебаг
//  Serial.print("brightness: ");
//  Serial.println(brightness);
//  Serial.print("mode: ");
//  Serial.println(mode);
//  Serial.print("delay: ");
//  Serial.println(delayNumber);
}

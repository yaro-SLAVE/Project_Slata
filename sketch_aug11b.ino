#include <Wire.h>                            // подключаем библиотеку для работы с шиной I2C
#include <LiquidCrystal_I2C.h>               // подключаем библиотеку для работы с LCD дисплеем
#include <iarduino_KB.h>                     // подключаем библиотеку для работы с матричной клавиатурой
// Объявляем переменные и константы:
LiquidCrystal_I2C lcd(0x27,16,2);            // объявляем переменную для работы с LCD дисплеем, указывая параметры дисплея (адрес I2C = 0x27, количество столбцов = 16, количество строк = 2)
iarduino_KB       KB(9,8,7,6,5,4,3,2);       // объявляем переменную для работы с матричной клавиатурой, указывая номера aeduino подключенные к шлейфу клавиатуры, начиная с первого вывода шлейфа
void setup(){
  Serial.begin(9600);                        // открываем последовательный порт на скорости 9600 бод
  KB.begin(KB1);                             // инициируем клавиатуру (KB1 - эастичная матричная клавиатура 4х4)
  lcd.init();                                // инициируем LCD дисплей
  lcd.backlight();                           // включаем подсветку LCD дисплея
  lcd.setCursor(0, 0);                       // устанавливаем курсор в позицию: столбец 0, строка 0
  lcd.print("iArduino.ru");                  // выводим текст "iArduino.ru"
  lcd.setCursor(0, 1);                       // устанавливаем курсор в позицию: столбец 0, строка 1
  lcd.print("Received data:");               // выводим текст "Received data:"
}
void loop(){

}
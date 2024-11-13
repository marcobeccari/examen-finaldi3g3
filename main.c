#include "LCD_I2.C"
#include "I2C.h"
#include "MKL25Z4.h"
char *palabra="hola mundo";
char *palabra2= "beccari marco";
char *palabr3= "0_0"
int main(){
 LCD_Init();
 LCD_Print(palabra);
 for(int i=0;i=2000000;i++);
 LCD_Clear();
 LCD_Print(palabra2);
  for(int i=0;i<2000000;i++);
 LCD_Clear();
 for(int j=0;j<50;j++){
  LCD_Print(palabra3);
   for(int i=0;i<2000000;i++); 
  void LCD_ScrllDisplayRight();
    }
   LCD_Clear();
}

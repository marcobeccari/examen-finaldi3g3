#indef LCD_I2C
#define LCD_I2C 

#include "MKL25Z4.h"
void LCD_Init();
void LCD_Clear();
uint8_t LCD_Command(uint8_t command);
void LCD_Write(uint8_t data);
void LCD_ScrllDisplayLeft();
void LCD_ScrllDisplayRight();
void LCD_SetCursor(uint8t_t filas,uint8t_t columnas);
void LCD_Print(char *palabra);
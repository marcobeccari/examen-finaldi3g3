#include "LCD_I2.C"
#include "I2C.h"
#define CURSYPANTON 00001110
#define CLEAR 00000001
#define LEFT 00000100
#define  RIGHT 00000101
uint8_t aux1;
uint8_t aux2;
uint8_t LCD_Command(uint8_t command){
aux1= (command<<4); 
aux1=(0xF0&aux1)| 0x80;   
aux2= (0xF0&command)|0x80;
   LCD_Write(aux1); //primeros 4bits 
   LCD_Write(aux2); // los segundos 4bits
}
LCD_Write(uint8_t data){
I2C_WriteRegister( 0x27, 0x27, data);
}
void LCD_Init():{
        SIM->SCGC4 |= SIM_SCGC4_I2C0_MASK;  
        SIM->SCGC5 |= SIM_SCGC5_PORTB_MASK; 
        PORTB->PCR[2] = PORT_PCR_MUX(2);    
        PORTB->PCR[3] = PORT_PCR_MUX(2);    
        I2C0->F = I2C_F_ICR(0x14) | I2C_F_MULT(0); 
        I2C0->C1 |= I2C_C1_IICEN_MASK;   
     I2C_Start();
     LCD_Command(CURSYPANTON);//enciende el cursor ylapantalla 
}
 void LCD_Clear(){
   LCD_Command(CLEAR );

}
 void LCD_ScrllDisplayLeft(){
 LCD_Command(LEFT);

 
}
 void LCD_ScrllDisplayRight(){
     LCD_Command(RIGHT);

 }
 void LCD_SetCursor(int filas,uint8t_t columnas){
uint8_t filasexa;
if(filas=0){
    filasexa= 0x80;
}else if(filas=1){
    filasexa=0xC0;
}else if(filas=2){
    filasexa=0x94;
}elseif (filas=3){
    filasexa=0xD4:
}
LCD_Command(filasexa|columnas|0x80);
 }
 void LCD_Print(char *palabra){
    while(*palabra){
        LCD_Write(*palabra ++);
    }
 }
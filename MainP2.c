/*
 * File:   MainP2.c
 * Author: Rito Alfonso
 *
 * Created on March 9, 2021, 1:41 PM
 */
#include "device_config.h"
#include <math.h>
#include <xc.h>

#define _XTAL_FREQ 1000000
#define DELAY_SWEEP 300
enum por_dir { output, input};
enum por_ACDC { digital, analog};
enum exponent{bbase = 2, limit = 8};
enum Botton_State1 {no_pushed0, pushed0};
enum Botton_State2 {no_pushed1, pushed1};
enum Botton_State3 {no_pushed2, pushed2};
enum Botton_State4 {no_pushed3, pushed3};
enum Botton_State5 {no_pushed4, pushed4};
enum Botton_State6 {no_pushed5, pushed5};
enum Botton_State7 {no_pushed6, pushed6};
enum Botton_State8 {no_pushed7, pushed7};
enum Led_State1 {led_OFF0, led_ON0};
enum Led_State2 {led_OFF1, led_ON1};
enum Led_State3 {led_OFF2, led_ON2};
enum Led_State4 {led_OFF3, led_ON3};
enum Led_State5 {led_OFF4, led_ON4};
enum Led_State6 {led_OFF5, led_ON5};
enum Led_State7 {led_OFF6, led_ON6};
enum Led_State8 {led_OFF7, led_ON7};
int indicador = -1;
void portsInit(void);
void knightrider(void);
unsigned char random (void);
unsigned char LEDstatus, BUTTONstatus = 0;

void main(void) {
    portsInit();
    while( 1 ) {
        LEDstatus = random();
        LATA = LEDstatus;
    //LEDstatus = LATA;
        BUTTONstatus = ~PORTD;
    
//    if (PORTDbits.RD0 == pushed0 && indicador==0 || PORTDbits.RD1 == pushed1 && indicador==1 || PORTDbits.RD2 == pushed2 && indicador==2 || PORTDbits.RD3 == pushed3 && indicador==3 || PORTDbits.RD4 == pushed4 && indicador==4 || PORTDbits.RD5 == pushed5 && indicador==5 || PORTDbits.RD6 == pushed6 && indicador==6 || PORTDbits.RD7 == pushed7 && indicador==7 )
        if (LEDstatus == BUTTONstatus)
            knightrider();
        //random ();
    }   
    
}

void portsInit( void) {
    ANSELA= digital;
    TRISA = 0x00; //led 1
    ANSELD= digital;
    TRISD = 0xFF; //led 1
//    TRISBbits.TRISB1 = output; //led 2
//    TRISBbits.TRISB2 = output; //led 3
//    TRISBbits.TRISB3 = output; //led 4
//    TRISBbits.TRISB4 = output; //led 5
//    TRISBbits.TRISB5 = output; //led 6
//    TRISBbits.TRISB6 = output; //led 7
//    TRISBbits.TRISB7 = output; //led 8

//
//ANSELD=digital;
// TRISDbits.TRISD0 = input; //boton 1
//TRISDbits.TRISD1 = input; //boton 2
//TRISDbits.TRISD2 = input; //boton 3
//TRISDbits.TRISD3 = input; //boton 4
//TRISDbits.TRISD4 = input; //boton 5
//TRISDbits.TRISD5 = input; //boton 6
//TRISDbits.TRISD6 = input; //boton 7
//TRISDbits.TRISD7 = input; //boton 8
}
void knightrider (void) {
    for (unsigned char i = 0; i < 8; i++){
        LATA = (unsigned char) pow(2, i); // 2^3 = 8 => 0000 1000
        __delay_ms(200);
    }
    for (unsigned char i = 7; i > 0; i--){
        LATA = (unsigned char) pow(2, i); // 2^3 = 8 => 0000 1000
        __delay_ms(200);
    }
    LATA = 0x01;
    __delay_ms(1000);
}
//    LATBbits.LATB0 = led_ON0;
//            __delay_ms(300);
//        LATBbits.LATB0 = led_OFF0;
//            __delay_ms(300);
//        LATBbits.LATB1 = led_ON1;
//            __delay_ms(300);
//        LATBbits.LATB1 = led_OFF1;
//            __delay_ms(300);
//        LATBbits.LATB2 = led_ON2;
//            __delay_ms(300);
//        LATBbits.LATB2 = led_OFF2;
//            __delay_ms(300);
//        LATBbits.LATB3 = led_ON3;
//            __delay_ms(300);
//        LATBbits.LATB3 = led_OFF3;
//            __delay_ms(300);
//        LATBbits.LATB4 = led_ON4;
//            __delay_ms(300);
//        LATBbits.LATB4 = led_OFF4;
//            __delay_ms(300);
//        LATBbits.LATB5 = led_ON5;
//            __delay_ms(300);
//        LATBbits.LATB5 = led_OFF5;
//            __delay_ms(300);
//        LATBbits.LATB6 = led_ON6;
//            __delay_ms(300);
//        LATBbits.LATB6 = led_OFF6;
//            __delay_ms(300);
//        LATBbits.LATB7 = led_ON7;
//            __delay_ms(300);
//        LATBbits.LATB7 = led_OFF7;
//            __delay_ms(300);


unsigned char random (void){
    indicador = rand() % 8;
    unsigned char  numero = 0;
    switch (indicador) //encender leds random
    {
        case 0:
          numero = 0x01; //0000 0001;
        __delay_ms(1000);
        break;
        case 1:
             numero = 0x02; //0000 0010;
        __delay_ms(1000);
        case 2:
          numero = 0x04; // 0000 0100
        __delay_ms(1000);
        break;
        case 3:
          numero = 0x08; // 0000 1000
        __delay_ms(1000);
        break;
        case 4:
          numero = 0X10; // 0001 0000
        __delay_ms(1000);
        break;
        case 5:
          numero = 0X20; // 
        __delay_ms(1000);
        break;
        case 6:
          numero = 0X40; 
        __delay_ms(1000);
        break;
        default:
          numero = 0x80;
        __delay_ms(1000);
        break;
    }
    return numero;
}
#ifndef NUMBERS_H
#define NUMBERS_H

#include "hardware/pio.h"
#include "led_commands.h"

#define CLEAN '\0'
//Definir cor dos números

double red[25]={1.0, 1.0, 1.0, 1.0, 1.0, 
                1.0, 1.0, 1.0, 1.0, 1.0, 
                1.0, 1.0, 1.0, 1.0, 1.0, 
                1.0, 1.0, 1.0, 1.0, 1.0, 
                1.0, 1.0, 1.0, 1.0, 1.0,};

double green[25]=  {0.0, 0.0, 0.0, 0.0, 0.0, 
                    0.0, 0.0, 0.0, 0.0, 0.0, 
                    0.0, 0.0, 0.0, 0.0, 0.0, 
                    0.0, 0.0, 0.0, 0.0, 0.0, 
                    0.0, 0.0, 0.0, 0.0, 0.0,};

double blue[25]={1.0, 1.0, 1.0, 1.0, 1.0, 
                 1.0, 1.0, 1.0, 1.0, 1.0, 
                 1.0, 1.0, 1.0, 1.0, 1.0, 
                 1.0, 1.0, 1.0, 1.0, 1.0, 
                 1.0, 1.0, 1.0, 1.0, 1.0,};

//definir imagem dos números
uint all_off[25] = {0, 0, 0, 0, 0,
                    0, 0, 0, 0, 0, 
                    0, 0, 0, 0, 0,
                    0, 0, 0, 0, 0,
                    0, 0, 0, 0, 0};

uint numb0[25] =   {0, 1, 1, 1, 0,
                    0, 1, 0, 1, 0, 
                    0, 1, 0, 1, 0,
                    0, 1, 0, 1, 0,
                    0, 1, 1, 1, 0};

uint numb1[25] =   {0, 0, 1, 0, 0,
                    0, 1, 1, 0, 0, 
                    0, 0, 1, 0, 0,
                    0, 0, 1, 0, 0,
                    0, 1, 1, 1, 0};

uint numb2[25] =   {0, 1, 1, 1, 0,
                    0, 0, 0, 1, 0, 
                    0, 1, 1, 1, 0,
                    0, 1, 0, 0, 0,
                    0, 1, 1, 1, 0};

uint numb3[25] =   {0, 1, 1, 1, 0,
                    0, 0, 0, 1, 0, 
                    0, 1, 1, 1, 0,
                    0, 0, 0, 1, 0,
                    0, 1, 1, 1, 0};

uint numb4[25] =   {0, 1, 0, 1, 0,
                    0, 1, 0, 1, 0, 
                    0, 1, 1, 1, 0,
                    0, 0, 0, 1, 0,
                    0, 0, 0, 1, 0};

uint numb5[25] =   {0, 1, 1, 1, 0,
                    0, 1, 0, 0, 0, 
                    0, 1, 1, 1, 0,
                    0, 0, 0, 1, 0,
                    0, 1, 1, 1, 0};

uint numb6[25] =   {0, 1, 1, 1, 0,
                    0, 1, 0, 0, 0, 
                    0, 1, 1, 1, 0,
                    0, 1, 0, 1, 0,
                    0, 1, 1, 1, 0};

uint numb7[25] =   {0, 1, 1, 1, 0,
                    0, 0, 0, 1, 0, 
                    0, 0, 0, 1, 0,
                    0, 0, 0, 1, 0,
                    0, 0, 0, 1, 0};

uint numb8[25] =   {0, 1, 1, 1, 0,
                    0, 1, 0, 1, 0, 
                    0, 1, 1, 1, 0,
                    0, 1, 0, 1, 0,
                    0, 1, 1, 1, 0};

uint numb9[25] =   {0, 1, 1, 1, 0,
                    0, 1, 0, 1,0, 
                    0, 1, 1, 1, 0,
                    0, 0, 0, 1, 0,
                    0, 1, 1, 1, 0};

void print_number(char c,PIO pio,uint32_t sm){
    uint32_t valor_leds;

    switch(c){
        case '0':
        put_leds(numb0,red,green,red,valor_leds,pio,sm);
        break;
        case '1':
        put_leds(numb1,red,green,blue,valor_leds,pio,sm);
        break;
        case '2':
        put_leds(numb2,red,green,blue,valor_leds,pio,sm);
        break;
        case '3':
        put_leds(numb3,red,green,blue,valor_leds,pio,sm);
        break;
        case '4':
        put_leds(numb4,red,green,blue,valor_leds,pio,sm);
        break;
        case '5':
        put_leds(numb5,red,green,blue,valor_leds,pio,sm);
        break;
        case '6':
        put_leds(numb6,red,green,blue,valor_leds,pio,sm);
        break;
        case '7':
        put_leds(numb7,red,green,blue,valor_leds,pio,sm);
        break;
        case '8':
        put_leds(numb8,red,green,blue,valor_leds,pio,sm);
        break;
        case '9':
        put_leds(numb9,red,green,blue,valor_leds,pio,sm);
        break;
        case '\0':
        put_leds(all_off,red,green,blue,valor_leds,pio,sm);
        break;
    }
}
#endif//NUMBERS_H
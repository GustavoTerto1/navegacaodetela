/*
 * File:   man.c
 * Author: 20185147
 *
 * Created on 14 de Maio de 2021, 16:23
 */
#include <xc.h>
#include "config.h"
#include "delay.h"
#include "dispLCD4vias.h"
#include "teclado.h"


void main(void) 
{
    char cont_senha = 0;
    char senhaOK = 0;
    char estado_senha = 0;
    char senha[4] = {0,0,0,0};
    char senha_correta [4] = {'2','1','1','8'};
    
    
    char estado = 0;
    char tecla = 0;
    dispLCD_init();
    teclado_init();
    while( 1 )
   {
        tecla = teclado();
        switch ( estado )
        {        
            case 0:
                    estado = 1; 
                    break;
            case 1:
                    dispLCD(0,0, "BEM VINDO       ");
                    delay(3000);
                    estado = 10;
                     break;        
            case 10:
                    dispLCD(0,0,"TERTOS TEK       ");
                    dispLCD(1,0,"OPERACAO C: CFG  ");
                    if( tecla == '1')
                        estado = 20;
                    if( tecla == '0')
                       estado = 100;
                        break;
            case 20: 
                    dispLCD(0,0,"operando...       ");
                    if( tecla == '*')
                    estado = 10;
                       break;
            case 30:
                      dispLCD(0,0,"CONFIGURACAO    ");
                    if( tecla == '#')
                    estado = 10;
                       break;
}      }                         
                    
         switch(estado_senha)            
         {
            case 0:
                    break;
            case 10:
                    cont_senha = 0;
                    senha[0] = 0;
                    senha[1] = 0;
                    senha[2] = 0;
                    senha[3] = 0;
                    break;
            case 12:
                    if( tecla >= '0' && tecla <= '9')
                        estado_senha = 14;
                    break;
            case 14:
                    senha[cont_senha] = tecla;
                    estado_senha = 16;
                    break;
            case 16:
                    ++cont_senha;
                    if (cont_senha < 4 )
                        estado_senha = 12;
                    else
                        estado_senha = 20;
                    break;
         }     
}

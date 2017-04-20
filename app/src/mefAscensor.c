/*============================================================================
 * Licencia: 
 * Autor: 
 * Fecha: 
 *===========================================================================*/

/*==================[inlcusiones]============================================*/

#include "mefAscensor.h"   // <= su propio archivo de cabecera
#include "sapi.h"       // <= Biblioteca sAPI

/*==================[definiciones y macros]==================================*/

#define EN_PLANTA_BAJA 0
#define MODO_CONFIGURACION 1
#define BAJANDO 2
#define SUBIENDO 3
#define PARADO 4
#define YENDO_A_PLANTA_BAJA 5

#define PlantaBaja 0

/*==================[definiciones de datos internos]=========================*/

/*==================[definiciones de datos externos]=========================*/
unsigned short EstadoActual;
unsigned short PisoSolicitado;
unsigned short PisoActual;
/*==================[declaraciones de funciones internas]====================*/

/*==================[declaraciones de funciones externas]====================*/

/*==================[definiciones de funciones internas]=====================*/

/*==================[definiciones de funciones externas]=====================*/

// Inicializar la MEF de ascensor
void ascensorInicializarMEF( void ){
   // TODO: hacer!!
    EstadoActual=EN_PLANTA_BAJA;
    gpioWrite(LED3, ON);
    
}

// Actualizar la MEF de ascensor
void ascensorActualizarMEF( void ){
   // TODO: hacer!!
   switch(EstadoActual){
        case EN_PLANTA_BAJA:
            gpioWrite(LED3, ON);
            if(!gpioRead(TEC1))EstadoActual=SUBIENDO;    
            else if(!gpioRead(TEC2))EstadoActual=BAJANDO;
            break;
        
        case MODO_CONFIGURACION:
                
            break;
        
        case BAJANDO:
            gpioWrite(LED3, OFF);
            gpioWrite(LEDB, ON);    
            if(PisoActual==PisoSolicitado)EstadoActual=PARADO;
            break;
        
        case SUBIENDO:
            gpioWrite(LED3, OFF);
            gpioWrite(LEDB, ON);  
            if(PisoActual==PisoSolicitado)EstadoActual=PARADO;
            break;
        
        case PARADO:
            gpioWrite(LED3, ON);
            gpioWrite(LEDB, OFF);
            if(PisoActual==PlantaBaja)EstadoActual=EN_PLANTA_BAJA;    
            break;
        
        case YENDO_A_PLANTA_BAJA:
            gpioWrite(LED3, OFF);
            gpioWrite(LEDB, ON); 
            if(PisoActual==PlantaBaja)EstadoActual=EN_PLANTA_BAJA;
            break;
         
        default:
            ascensorInicializarMEF();
            break;
    }     
}

/*==================[fin del archivo]========================================*/

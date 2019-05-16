/*
 * PORT.h
 *
 *  Created on: Mar 13, 2019
 *      Author: Ahmed Talaat
 */

#ifndef PORT_H_
#define PORT_H_

#include "STD_Types.h"




typedef enum {

    INPUT,
    OUTPUT
}Port_PinDirectionType;

typedef enum {

    A,
    B,
    C,
    D,
    E,
    F

}Port_Name;

typedef enum {

	LOW,
	HIGH


}DIO_LevelType;


void Port_Init( Port_Name n );




#endif /* PORT_H_ */

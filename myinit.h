/*
 * myinit.h
 *
 *  Created on: Apr 24, 2016
 *      Author: daniel
 */

#ifndef MYINIT_H_
#define MYINIT_H_

#include "defines.h"

/*
 * STATIC FUNCTION DEFINITIONS -- Start
 */
_i32 establishConnectionWithAP();
_i32 configureSimpleLinkToDefaultState();
_i32 initializeAppVariables();
int init_main();

#endif /* MYINIT_H_ */

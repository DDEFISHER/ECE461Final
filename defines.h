/*
 * defines.h
 *
 *  Created on: Apr 24, 2016
 *      Author: daniel
 */

#ifndef DEFINES_H_
#define DEFINES_H_

#include "passkey.h"
#include <stdlib.h>
#include <string.h>

#include "driverlib.h"
#include "simplelink.h"
#include "sl_common.h"

#define APPLICATION_VERSION "1.0.0"

#define MCLK_FREQUENCY 48000000
#define PWM_PERIOD 255

#define SL_STOP_TIMEOUT        0xFF

#define SMALL_BUF           32
#define MAX_SEND_BUF_SIZE   512
#define MAX_SEND_RCV_SIZE   1024

#define BUF_SIZE        1400
#define NO_OF_PACKETS   1000
#define min(X,Y) ((X) < (Y) ? (X) : (Y))

#endif /* DEFINES_H_ */

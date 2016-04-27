/*
 * events.h
 *
 *  Created on: Apr 24, 2016
 *      Author: daniel
 */

#ifndef EVENTS_H_
#define EVENTS_H_

#include "defines.h"

void SimpleLinkWlanEventHandler(SlWlanEvent_t *pWlanEvent);
void SimpleLinkNetAppEventHandler(SlNetAppEvent_t *pNetAppEvent);
void SimpleLinkHttpServerCallback(SlHttpServerEvent_t *pHttpEvent,
                                  SlHttpServerResponse_t *pHttpResponse);
void SimpleLinkGeneralEventHandler(SlDeviceEvent_t *pDevEvent);
void SimpleLinkSockEventHandler(SlSockEvent_t *pSock);

#endif /* EVENTS_H_ */

/**** DO NOT EDIT -- this file has been automatically generated from @emmoco.com.FirstApp on 2013-11-05T15:45:21 ****/
/**** protocolLevel = 13, toolsVersion = 13.3.13.201310241808 ****/

#ifndef FirstApp__H
#define FirstApp__H

#include "Em_Types.h"
#include "Em_Message.h"

#ifdef __cplusplus
extern "C" {
#endif

/* -------- connection callback functions implemented by the application -------- */

void FirstApp_connectHandler(void);
void FirstApp_disconnectHandler(void);

/* -------- resource types defined in the schema -------- */

/* -------- resource callback functions implemented by the application -------- */

/* resource data */
typedef int16_t FirstApp_data_t;
extern void FirstApp_data_fetch(FirstApp_data_t* output);
extern void FirstApp_data_store(FirstApp_data_t* input);

/* -------- application functions implemented in FirstApp.c -------- */

void FirstApp_accept(bool enable);
void FirstApp_activateParameters(uint8_t group);
void FirstApp_broadcastOff(void);
void FirstApp_disconnect(void);
void FirstApp_pairingOn(uint8_t secs, void(*handler)(void));
void FirstApp_pairingOff(void(*handler)(void));
void FirstApp_reset(void);
void FirstApp_setDeviceName(const char* name);
void FirstApp_start(void);

#ifdef __cplusplus
}
#endif

#endif /* FirstApp__H */

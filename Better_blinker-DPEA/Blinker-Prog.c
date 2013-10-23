#include "Blinker.h"
#include "Hal.h"
#define TESTCOUNTVAL 0
static void tickHandler(void);
#define NUM_LEDS 15
static Blinker_cmd_t cmdVal = Blinker_START_CMD;
static Blinker_count_t countVal = 13;
static Blinker_delay_t delayVal = 1.2 * (Blinker_delay_scale); //=1000, delayVal = 1200
int onOrOff=1;
#define FOREVER -1
static Blinker_count_t curCount = FOREVER;
static Blinker_delay_t curTime = 0;
int *pattern[3];
uint16_t ledArray0[15]={2,3,4,5,6,7,8,15,14,13,12,11,10,9};
uint16_t ledArray1[15]={0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1};
uint16_t ledArray2[15]={0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1};
//uint16_t patternLength[3]={15,15,10};
   /*
   (D9,D13)(D13,D9,D6)(D8mD6,D9)
   */
void main() {
    Hal_init();
    Hal_tickStart(Blinker_delay_step, tickHandler);
    Blinker_start();
    Hal_idleLoop();
    pattern[0]=ledArray0;
    pattern[1]=ledArray1;
    pattern[2]=ledArray2;
    
    
   
}
int current;
static void tickHandler(void) {

    if (cmdVal == Blinker_STOP_CMD) {
        return;
    }
    
    if (curTime < delayVal) {
        curTime += Blinker_delay_step;
      
        return;
    }
if(current>15)
{
    onOrOff=0;
}
if(current<0)
{
    onOrOff=1;
}
    if (curCount == FOREVER || curCount-- > 0) {
       
        
 //pattern[1][current];
 int i;

 if(onOrOff==1){
 Hal_User_ledOn(ledArray0[current]);   
 }

 if(onOrOff==0)
 {
   Hal_User_ledOff(ledArray0[current]);    
 }
    }
    else {
        cmdVal = Blinker_STOP_CMD;
       // Hal_ledOff();
    }
        curTime = 0;
    Blinker_ledState_indicate();

 if(onOrOff==1){
    current+=1;
} if(onOrOff==0) 
{
    current -=1;
}
}


/* -------- SCHEMA CALLBACKS -------- */

void Blinker_connectHandler(void) {
    Hal_connected();
}

void Blinker_disconnectHandler(void) {
    Hal_disconnected();
}

void Blinker_cmd_store(Blinker_cmd_t* input) {
    cmdVal = *input;
    uint8_t i;
    switch (cmdVal) {
        case Blinker_START_CMD:
            curCount = countVal > 0 ? countVal * 2 : FOREVER;
            curTime = 0;
            //current=4;
            break;
        case Blinker_STOP_CMD:
        
            break;
    }
}

void Blinker_count_fetch(Blinker_count_t* output) {
    *output = countVal;
}

void Blinker_count_store(Blinker_count_t* input) {
    countVal = *input;
}

void Blinker_delay_fetch(Blinker_delay_t* output) {
    *output = delayVal;
}

void Blinker_delay_store(Blinker_delay_t* input) {
    delayVal = *input;
}

void Blinker_ledState_fetch(Blinker_ledState_t* output) {
    *output = Hal_ledRead() ? Blinker_LED_ON : Blinker_LED_OFF;
}


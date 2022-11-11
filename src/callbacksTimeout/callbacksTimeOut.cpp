#include "callbacksTimeout/callbacksTimeOut.h"

unsigned long _lasted_time;
void callback_timeouted(void (*callback)(void), unsigned int time_out_in_milleseconds )
{
    if((unsigned long)( millis() - _lasted_time ) >= time_out_in_milleseconds ){
        _lasted_time = millis();
        callback();
    };
    
}
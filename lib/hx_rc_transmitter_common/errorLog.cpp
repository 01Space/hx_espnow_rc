#include "errorLog.h"

#include <SPIFFS.h> 

#include <stdio.h>
#include <stdarg.h>

ErrorLog ErrorLog::instance;

//=====================================================================
//=====================================================================
ErrorLog::ErrorLog() 
{

}

//=====================================================================
//=====================================================================
void ErrorLog::write( const char* msg )
{
    Serial.print(msg);

    File logFile = SPIFFS.open("/errorLog.txt", FILE_APPEND);
    if (!logFile) 
    {
        Serial.println("- failed to open log file for writing");
        return;
    }
    logFile.print(msg);
    logFile.close();

}

//=====================================================================
//=====================================================================
void ErrorLog::writeOnce( const char* msg )
{
    if ( this->writeOnceDisabled ) return;
    this->write( msg );
}

//=====================================================================
//=====================================================================
void ErrorLog::disableWriteOnce()
{
    this->writeOnceDisabled = true;
}

//=====================================================================
//=====================================================================
void ErrorLog::signalError()
{
    this->hasError = true;
}

//=====================================================================
//=====================================================================
bool ErrorLog::getHasErrorAndClear()
{
    bool res = this->hasError;
    this->hasError = false;
    return res;
}
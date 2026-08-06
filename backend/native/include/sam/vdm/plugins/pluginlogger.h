/*
file       :  pluginlogger.h
description:  Logger for the plugin manager
Notes      :  This file depends on the data provider framework
*/
#pragma once
#ifdef CEE_SAM_DATA_PROVIDER_FRAMEWORK

#include <string>
#include "cdphlLogger.h"
#include "sam/base/stdcontainers.h"

//----------------------------------------------------------------------------------------------
// This class set the default logger level for the pluging manager
//-----------------------------------------------------------------------------------------------
class PluginLogger: public cdphl::Logger {
  private:
    static int m_lowestErrorLevel;

  public:
    PluginLogger();
    virtual void
    log(Logger::Level messageLevel, const std::string& message) override;
    static void
    setErrorLevel(int errorLevel);
    static int
    getErrorLevel();
};

#endif

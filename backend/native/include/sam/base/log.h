/*********************************************************************
 *                                                                   *
 *                          DevTools 3.1.0                           *
 *                                                                   *
 *  These coded instructions, statements and computer programs       *
 *  contain unpublished proprietary information of Tech Soft 3D,     *
 *  and are protected by Federal copyright law.  They may not be     *
 *  disclosed to third parties or copied or duplicated in any form,  *
 *  in whole or in part, without the prior written consent of        *
 *  Tech Soft 3D.                                                    *
 *                                                                   *
 *                 Copyright (C) 2026, Tech Soft 3D                  *
 *                                                                   *
 *********************************************************************/
/* Logging functionalities */

#ifndef SRC_BASE_LOG_DEF
#define SRC_BASE_LOG_DEF

enum SAM_LOG_LEVEL { SAM_LOG_LEVEL_DEBUG, SAM_LOG_LEVEL_INFO, SAM_LOG_LEVEL_WARNING, SAM_LOG_LEVEL_ERROR, SAM_LOG_LEVEL_FATAL };

#define SAM_LOG_DEBUG(...) vsy_logDebug(__func__, __VA_ARGS__)

extern void
vsy_log(int log_level, const char* func_name, const char* format, ...);

extern void
vsy_logDebug(const char* func_name, const char* format, ...);

extern void
vsy_logInfo(const char* func_name, const char* format, ...);

extern void
vsy_logWarning(const char* func_name, const char* format, ...);

extern void
vsy_logError(const char* func_name, const char* format, ...);

extern void
vsy_logFatal(const char* func_name, const char* format, ...);

#endif /*SRC_BASE_LOG_DEF*/

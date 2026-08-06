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
#pragma once
#include "sam/base/stdcontainers.h"

/* space for gathering error messages, warnings or information*/
class AdapaterLogger {
  public:
    enum class errorMode { THROW_EXCEPTIONS = 1, DEBUG_TRAP = 2 };
#ifndef NDEBUG
    AdapaterLogger(errorMode errorReporting): mode(errorReporting) {};
#else
    AdapaterLogger(errorMode) {};
#endif

    void
    notifyError(const vsy::string& errorMessage);

    void
    addNotifications(const vsy::string& message);

    const vsy::vector<vsy::string>&
    notifications() const;

    int
    notifiedErrorCount();

    void
    resetLogger();

  private:
    vsy::vector<vsy::string> m_notifications;
#ifndef NDEBUG
    errorMode mode = errorMode::DEBUG_TRAP;
#endif
    int accumulatedErrorCounter = 0; // accumulated error counter
};
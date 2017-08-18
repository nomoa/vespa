// Copyright 2017 Yahoo Holdings. Licensed under the terms of the Apache 2.0 license. See LICENSE in the project root.

#include "process.h"
#include <string.h>

FastOS_ProcessInterface::FastOS_ProcessInterface (const char *cmdLine,
                         bool pipeStdin,
                         FastOS_ProcessRedirectListener *stdoutListener,
                         FastOS_ProcessRedirectListener *stderrListener,
                         int bufferSize) :
    _extradoublehackforalignment(0.0),
    _cmdLine(NULL),
    _pipeStdin(pipeStdin),
    _stdoutListener(stdoutListener),
    _stderrListener(stderrListener),
    _bufferSize(bufferSize),
    _next(NULL),
    _prev(NULL)
{
    _cmdLine = strdup(cmdLine);
}

FastOS_ProcessInterface::~FastOS_ProcessInterface ()
{
    free (_cmdLine);
}

//
// Created by maj3 on 23.05.2020.
//

#ifndef OPENGLTEST_WINDOWSVAL_H
#define OPENGLTEST_WINDOWSVAL_H

#include <iostream>

const uint PIPE_CLIENT_END = 0x00000000;
const uint PIPE_SERVER_END = 0x00000001;
const uint FILE_FLAG_OVERLAPPED = 0x40000000;
const uint FILE_ATTRIBUTE_NORMAL = 0x00000080;
const uint FILE_SHARE_READ = 0x00000001;
const uint FILE_SHARE_WRITE = 0x00000002;

const uint PIPE_UNLIMITED_INSTANCES = 255;

const uint SECURITY_SQOS_PRESENT = 0x00100000;
const uint SECURITY_ANONYMOUS = 0 << 16;
const uint SECURITY_IDENTIFICATION = 1 << 16;
const uint SECURITY_IMPERSONATION = 2 << 16;
const uint SECURITY_DELEGATION = 3 << 16;

const uint NMPWAIT_WAIT_FOREVER = 0xffffffff;
const uint NMPWAIT_NOWAIT = 0x00000001;
const uint NMPWAIT_USE_DEFAULT_WAIT = 0x00000000;

const uint GENERIC_READ = (0x80000000);
const uint GENERIC_WRITE = (0x40000000);
const uint GENERIC_EXECUTE = (0x20000000);
const uint GENERIC_ALL = (0x10000000);
const uint PAGE_READONLY = (0x02);

const uint FILE_MAP_WRITE = 0x0002;
const uint FILE_MAP_READ = 0x0004;

const uint CREATE_NEW        = 1;
const uint CREATE_ALWAYS     = 2;
const uint OPEN_EXISTING     = 3;
const uint OPEN_ALWAYS       = 4;
const uint TRUNCATE_EXISTING = 5;
const uint FILE_FLAG_FIRST_PIPE_INSTANCE = 0x00080000;

const int INVALID_HANDLE_VALUE = -1;
const long ERROR_BROKEN_PIPE = 109;
const long ERROR_IO_PENDING = 997;
const long ERROR_PIPE_BUSY = 231;
const long ERROR_NO_DATA = 232;
const long ERROR_PIPE_NOT_CONNECTED = 233;
const long ERROR_PIPE_CONNECTED = 535;
const long ERROR_PIPE_LISTENING = 536;

const int BI_RGB = 0;
const uint _MAX_PATH = 256;
const uint MAX_PATH = 256;
const int FILE_ATTRIBUTE_DIRECTORY = 16;

#endif //OPENGLTEST_WINDOWSVAL_H

#pragma once

#include <iostream>
#include <array>
#include <string>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <termios.h>
#include <time.h>
#include <unistd.h>
#include <limits>
#include <memory>
#include <sstream>
#include <bitset>

#define KEY_UP 0x48
#define KEY_DOWN 0x50
#define KEY_ENTER 0X0D
#define KEY_BS 0x08

int open_port(void);

void configure_port(const int fd);


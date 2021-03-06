#pragma once
#ifndef LOGGER_H_
#define LOGGER_H_

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "Token.h"

void Info(const char *formato, ...);
void Error(const char *formato, ...);
void Debug(const char *formato, ...);
char *TokenString(int token);

extern int DEBUG;

#endif
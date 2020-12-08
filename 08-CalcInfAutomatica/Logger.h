#pragma once
#ifndef LOGGER_H_
#define LOGGER_H_

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void Info(const char *prefijo, const char *formato, ...);
void Debug(const char *prefijo, const char *formato, ...);

extern int DEBUG;

#endif
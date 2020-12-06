#pragma once
#ifndef ERROR_H_
#define ERROR_H_

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "Token.h"

void ErrorLexico(int c);
void ErrorSintactico(int count, ...);

#endif
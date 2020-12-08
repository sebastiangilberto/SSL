#pragma once
#ifndef SCANNER_H_
#define SCANNER_H_

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#include "Logger.h"
#include "Token.h"

extern char LEXEMA[TAMNOM];
extern int FLAG_TOKEN;

Token GetNextToken();

#endif
#pragma once
#ifndef SCANNER_H_
#define SCANNER_H_

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#include "Constants.h"
#include "Logger.h"
#include "Token.h"

int GetNextToken();

#endif
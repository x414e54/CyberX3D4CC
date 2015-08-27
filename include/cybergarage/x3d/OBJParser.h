/******************************************************************
*
*	CyberX3D for C++
*
*	Copyright (C) Satoshi Konno 1996-2007
*
*	File:	OBJParser.h
*
******************************************************************/

#ifndef _CX3D_OBJPARSER_H_
#define _CX3D_OBJPARSER_H_

#ifdef CX3D_SUPPORT_OBJ

#include <cybergarage/x3d/Parser.h>

namespace CyberX3D {

class OBJParser : public Parser {
public:

	OBJParser();
	virtual ~OBJParser();

	bool load(const char *fileName, void (*callbackFn)(int nLine, void *info) = NULL, void *callbackFnInfo = NULL);
};

}

#endif

#endif

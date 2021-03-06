/******************************************************************
*
*	CyberX3D for C++
*
*	Copyright (C) Satoshi Konno 1996-2007
*
*	File:	FileImage.h
*
******************************************************************/

#ifndef _CX3D_FILEIMAGE_H_
#define _CX3D_FILEIMAGE_H_

#include <cybergarage/x3d/CyberX3DConfig.h>

#ifdef CX3D_SUPPORT_OLDCPP
#include <cybergarage/x3d/OldCpp.h>
#endif

#include <cybergarage/x3d/FileUtil.h>

namespace CyberX3D {

typedef unsigned char RGBColor24[3];
typedef unsigned char RGBAColor32[4];

const int R = 0;
const int G = 1;
const int B = 2;

class FileImage {

public:

	FileImage();
	virtual ~FileImage();

	bool isOk() const;
	
	virtual int			getFileType() const = 0;

	virtual int			getWidth() const = 0;
	virtual int			getHeight() const = 0;
	virtual RGBColor24	*getImage() const = 0;
	virtual RGBAColor32	*getImage32() const { return 0; }

	virtual bool hasAlphaChannel() const {
		return false;
	}

	virtual bool hasTransparencyColor() const {
		return false;
	}

	virtual void getTransparencyColor(RGBColor24 color) const {
	};

	RGBColor24	*getImage(int newx, int newy) const;
	RGBAColor32	*getImage32(int newx, int newy) const;
	RGBAColor32	*getRGBAImage() const;
	RGBAColor32	*getRGBAImage(int newx, int newy) const;
};

}

#endif

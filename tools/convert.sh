#!/bin/bash
FILE=$1.in
OUT_CLASS=$1
OUT_DEFINE=${OUT_CLASS^^}
OUT_TYPE=${OUT_DEFINE%NODE}_NODE
OUT_DEFINE=${OUT_CLASS^^}
OUT_FILE=../src/cybergarage/x3d/$OUT_CLASS.cpp

echo "
/******************************************************************
*
*	CyberX3D for C++
*
*	Copyright (C) Satoshi Konno 1996-2007
*
*	File:	$OUT_CLASS.cpp
*
******************************************************************/

#include <cybergarage/x3d/$OUT_CLASS.h>

using namespace CyberX3D;
" > $OUT_FILE

sed -e "s/\t\(SF[^ ]*\) \*\([^;]*\);/static const char \2ExposedFieldName[] = \"\2\";/g" $FILE >> $OUT_FILE

echo "
$OUT_CLASS::$OUT_CLASS() 
{
	setHeaderFlag(false);
	setType($OUT_TYPE);
" >> $OUT_FILE
		
sed -e "s/\t\(SF[^ ]*\) \*\([^;]*\);/	\2Field = new \1();\n	addExposedField(\2ExposedFieldName, \2Field);\n/g" $FILE >> $OUT_FILE

echo "}

$OUT_CLASS::~$OUT_CLASS() 
{
}" >> $OUT_FILE

to_function() {
OUT_CLASS=$4
echo "
////////////////////////////////////////////////
//	$2
////////////////////////////////////////////////

$1 *$OUT_CLASS::get$2Field() const
{
	if (isInstanceNode() == false)
		return $3Field;
	return ($1 *)getExposedField($3ExposedFieldName);
}"

if [ "$1" == "SFString" ]; then
echo "void $OUT_CLASS::set$2(const char *value) 
{
	get$2Field()->setValue(value);
}

const char *$OUT_CLASS::get$2() const 
{
	return get$2Field()->getValue();
}"
elif [ "$1" == "SFInt32" ]; then
echo "void $OUT_CLASS::set$2(int value) 
{
	get$2Field()->setValue(value);
}

int $OUT_CLASS::get$2() const 
{
	return get$2Field()->getValue();
}"
elif [ "$1" == "SFVec3f" ]; then
echo "void $OUT_CLASS::set$2(float value[]) 
{
	get$2Field()->setValue(value);
}

void $OUT_CLASS::set$2(float r, float g, float b) 
{
	get$2Field()->setValue(r, g, b);
}

void $OUT_CLASS::get$2(float value[]) const 
{
	get$2Field()->getValue(value);
}"
elif [ "$1" == "SFFloat" ]; then
echo "void $OUT_CLASS::set$2(float value) 
{
	get$2Field()->setValue(value);
}

float $OUT_CLASS::get$2() const 
{
	return get$2Field()->getValue();
}"
fi

}

export -f to_function

sed -e "s/\t\(SF[^ ]*\) \*\([^;]*\);/to_function \1 \u\2 \2 $OUT_CLASS &/e" $FILE >> $OUT_FILE

echo "
////////////////////////////////////////////////
//	List
////////////////////////////////////////////////

$OUT_CLASS *$OUT_CLASS::next() const 
{
	return ($OUT_CLASS *)Node::next(getType());
}

$OUT_CLASS *$OUT_CLASS::nextTraversal() const 
{
	return ($OUT_CLASS *)Node::nextTraversalByType(getType());
}

////////////////////////////////////////////////
//	virtual functions
////////////////////////////////////////////////
	
bool $OUT_CLASS::isChildNodeType(Node *node) const
{
}

void $OUT_CLASS::initialize() 
{
}

void $OUT_CLASS::uninitialize() 
{
}

void $OUT_CLASS::update() 
{
}

////////////////////////////////////////////////
//	Infomation
////////////////////////////////////////////////

void $OUT_CLASS::outputContext(std::ostream &printStream, const char *indentString) const
{
}

" >> $OUT_FILE

OUT_FILE=../include/cybergarage/x3d/$OUT_CLASS.h

echo "/******************************************************************
*
*	CyberX3D for C++
*
*	Copyright (C) Satoshi Konno 1996-2007
*
*	File:	$OUT_CLASS.h
*
******************************************************************/

#ifndef _CX3D_${OUT_DEFINE}_H_
#define _CX3D_${OUT_DEFINE}_H_

#include <cybergarage/x3d/VRML97Fields.h>
#include <cybergarage/x3d/Node.h>

namespace CyberX3D {

class $OUT_CLASS : public Node {
" > $OUT_FILE

sed -e "s/\t\(SF[^ ]*\) \*\([^;]*\);/\t\1 *\2Field;/g" $FILE >> $OUT_FILE

echo "
public:

	$OUT_CLASS();
	virtual ~$OUT_CLASS();" >> $OUT_FILE

to_function_header() {
echo "
	////////////////////////////////////////////////
	//	$2
	////////////////////////////////////////////////

	$1 *get$2Field() const;"

if [ "$1" == "SFString" ]; then
echo "
	void set$2(const char *value);
	const char *get$2() const;"
elif [ "$1" == "SFInt32" ]; then
echo "
	void set$2(int value);
	int get$2() const;"
elif [ "$1" == "SFVec3f" ]; then
echo "
	void set$2(float value[]);
	void set$2(float r, float g, float b);
	void get$2(float value[]) const;"
elif [ "$1" == "SFFloat" ]; then
echo "
	void set$2(float value);
	float get$2() const;"
fi

}

export -f to_function_header

sed -e "s/\t\(SF[^ ]*\) \*\([^;]*\);/to_function_header \1 \u\2 \2 &/e" $FILE >> $OUT_FILE

echo "
	////////////////////////////////////////////////
	//	List
	////////////////////////////////////////////////

	$OUT_CLASS *next() const;
	$OUT_CLASS *nextTraversal() const;

	////////////////////////////////////////////////
	//	virtual functions
	////////////////////////////////////////////////
	
	bool isChildNodeType(Node *node) const;
	void initialize();
	void uninitialize();
	void update();
	void outputContext(std::ostream &printStream, const char *indentString) const;
};

}

#endif" >> $OUT_FILE

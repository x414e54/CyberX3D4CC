/******************************************************************
*
*	CyberX3D for C++
*
*	Copyright (C) Satoshi Konno 1996-2007
*
*	File:	IndexedTriangleSetNode.h
*
******************************************************************/

#ifndef _CX3D_INDEXEDTRIANGLESETNODE_H_
#define _CX3D_INDEXEDTRIANGLESETNODE_H_

#include <cybergarage/x3d/ComposedGeometryNode.h>
#include <cybergarage/x3d/NormalNode.h>
#include <cybergarage/x3d/ColorNode.h>
#include <cybergarage/x3d/CoordinateNode.h>
#include <cybergarage/x3d/TextureCoordinateNode.h>

namespace CyberX3D {

class IndexedTriangleSetNode : public ComposedGeometryNode 
{
	MFInt32 *indexField;
	
	MFInt32 *set_indexField;

public:

	IndexedTriangleSetNode();
	virtual ~IndexedTriangleSetNode();
	
	////////////////////////////////////////////////
	//	List
	////////////////////////////////////////////////

	IndexedTriangleSetNode *next() const;
	IndexedTriangleSetNode *nextTraversal() const;

	////////////////////////////////////////////////
	// set_Index
	////////////////////////////////////////////////

	MFInt32 *getSetIndexField() const;

	////////////////////////////////////////////////
	// Index
	////////////////////////////////////////////////

	MFInt32 *getIndexField() const;

	void addIndex(int value);
	int getNIndexes() const;
	int getIndex(int index) const;
	void clearIndex();

	////////////////////////////////////////////////
	//	functions
	////////////////////////////////////////////////
	
	bool isChildNodeType(Node *node) const;
	void initialize();
	void uninitialize();
	void update();

	////////////////////////////////////////////////
	//	recomputeDisplayList
	////////////////////////////////////////////////

#ifdef CX3D_SUPPORT_OPENGL
	void recomputeDisplayList();
#endif

	////////////////////////////////////////////////
	//	Polygon
	////////////////////////////////////////////////

	int getNPolygons() const;

	////////////////////////////////////////////////
	//	Infomation
	////////////////////////////////////////////////

	void outputContext(std::ostream &printStream, const char *indentString) const;

};

}

#endif


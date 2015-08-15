/******************************************************************
*
*	CyberX3D for C++
*
*	Copyright (C) Satoshi Konno 1996-2007
*
*	File:	BoxNode.h
*
******************************************************************/

#ifndef _CX3D_BOX_H_
#define _CX3D_BOX_H_

#include <cybergarage/x3d/VRML97Fields.h>
#include <cybergarage/x3d/Geometry3DNode.h>

namespace CyberX3D {

class BoxNode : public Geometry3DNode {

	SFVec3f *sizeField;
	
public:

	BoxNode();
	virtual ~BoxNode();

	////////////////////////////////////////////////
	//	size
	////////////////////////////////////////////////

	SFVec3f *getSizeField() const;

	void setSize(float value[]);
	void setSize(float x, float y, float z);
	void getSize(float value[]) const;
	float getX() const;
	float getY() const;
	float getZ() const;

	////////////////////////////////////////////////
	//	List
	////////////////////////////////////////////////

	BoxNode *next() const;
	BoxNode *nextTraversal() const;

	////////////////////////////////////////////////
	//	functions
	////////////////////////////////////////////////
	
	bool isChildNodeType(Node *node) const;
	void initialize();
	void uninitialize();
	void update();

	////////////////////////////////////////////////
	//	BoundingBox
	////////////////////////////////////////////////

	void recomputeBoundingBox();

	////////////////////////////////////////////////
	//	Polygons
	////////////////////////////////////////////////

	int getNPolygons() const {
		return 6;
	}

	////////////////////////////////////////////////
	//	getVertexData
	////////////////////////////////////////////////

	virtual void getVertexData(void *vertex_data);

	////////////////////////////////////////////////
	//	getVertexArray
	////////////////////////////////////////////////

	virtual void getVertexArray(VertexArray& array);

	////////////////////////////////////////////////
	//	recomputeDisplayList
	////////////////////////////////////////////////

#ifdef CX3D_SUPPORT_OPENGL
	void recomputeDisplayList();
#endif

	////////////////////////////////////////////////
	//	Infomation
	////////////////////////////////////////////////

	void outputContext(std::ostream &printStream, const char *indentString) const;
};

}

#endif

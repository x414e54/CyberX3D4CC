/******************************************************************
*
*	CyberX3D for C++
*
*	Copyright (C) Satoshi Konno 1996-2007
*
*	File:	IndexedTriangleSetNode.cpp
*
*	Revisions;
*
*	11/27/02
*		- The first revision.
*
******************************************************************/

#include <cybergarage/x3d/IndexedTriangleSetNode.h>
#include <cybergarage/x3d/Graphic3D.h>

using namespace CyberX3D;

static const char indexEventInString[] = "index";

IndexedTriangleSetNode::IndexedTriangleSetNode() 
{
	setHeaderFlag(false);
	setType(INDEXEDTRIANGLESET_NODE);

	///////////////////////////
	// Field 
	///////////////////////////

	// index  field
	indexField = new MFInt32();
	indexField->setName(indexFieldString);
	addField(indexField);

	///////////////////////////
	// EventIn
	///////////////////////////

	// index  EventIn
	set_indexField = new MFInt32();
	set_indexField->setName(indexFieldString);
	addEventIn(set_indexField);
}

IndexedTriangleSetNode::~IndexedTriangleSetNode() 
{
}

////////////////////////////////////////////////
//	List
////////////////////////////////////////////////

IndexedTriangleSetNode *IndexedTriangleSetNode::next() const
{
	return (IndexedTriangleSetNode *)Node::next(getType());
}

IndexedTriangleSetNode *IndexedTriangleSetNode::nextTraversal() const
{
	return (IndexedTriangleSetNode *)Node::nextTraversalByType(getType());
}

////////////////////////////////////////////////
// set_index
////////////////////////////////////////////////

MFInt32 *IndexedTriangleSetNode::getSetIndexField() const
{
	if (isInstanceNode() == false)
		return set_indexField;
	return (MFInt32 *)getEventIn(indexEventInString);
}

////////////////////////////////////////////////
// CoordIndex
////////////////////////////////////////////////

MFInt32 *IndexedTriangleSetNode::getIndexField() const
{
	if (isInstanceNode() == false)
		return indexField;
	return (MFInt32 *)getField(indexFieldString);
}

void IndexedTriangleSetNode::addIndex(int value) 
{
	getIndexField()->addValue(value);
}

int IndexedTriangleSetNode::getNIndexes() const
{
	return getIndexField()->getSize();
}

int IndexedTriangleSetNode::getIndex(int index) const
{
	return getIndexField()->get1Value(index);
}

void IndexedTriangleSetNode::clearIndex() 
{
	getIndexField()->clear();
}
	
////////////////////////////////////////////////
//	functions
////////////////////////////////////////////////
	
bool IndexedTriangleSetNode::isChildNodeType(Node *node) const
{
	if (node->isColorNode() || node->isCoordinateNode() || node->isNormalNode() || node->isTextureCoordinateNode())
		return true;
	else
		return false;
}

void IndexedTriangleSetNode::uninitialize() 
{
}

void IndexedTriangleSetNode::update() 
{
}

////////////////////////////////////////////////
//	Infomation
////////////////////////////////////////////////

void IndexedTriangleSetNode::outputContext(std::ostream &printStream, const char *indentString) const
{
}

////////////////////////////////////////////////
//	IndexedTriangleSetNode::initialize
////////////////////////////////////////////////

void IndexedTriangleSetNode::initialize() 
{
}

////////////////////////////////////////////////////////////
//	getNPolygons
////////////////////////////////////////////////////////////

int IndexedTriangleSetNode::getNPolygons() const
{
	CoordinateNode *coordNode = getCoordinateNodes();
	if (!coordNode)
		return 0;

	int nCoordIndexes = coordNode->getNPoints();
	int nCoordIndex = nCoordIndexes / 3;

	return nCoordIndex;
}

////////////////////////////////////////////////
//	IndexedTriangleSetNode::recomputeDisplayList
////////////////////////////////////////////////

#ifdef CX3D_SUPPORT_OPENGL

void IndexedTriangleSetNode::recomputeDisplayList() 
{
}

#endif


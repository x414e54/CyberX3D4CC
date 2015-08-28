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
	return getNIndexes() / 3;
}

////////////////////////////////////////////////
//	IndexedTriangleSetNode::getVertexArray
////////////////////////////////////////////////

size_t IndexedTriangleSetNode::getNumVertexArrays()
{
	return 1;
}

void IndexedTriangleSetNode::getVertexArray(VertexArray& array, size_t id) 
{
	if (id != 0) return;

	VertexFormat format;
	format.addAttribute<float>("position", 3);
	format.addAttribute<float>("normal", 3);
	format.addAttribute<float>("texcoord", 2);
	const CoordinateNode *v_node = (CoordinateNode*)getCoordField()->getValue();
	array = VertexArray(v_node->getNPoints(), getNIndexes(), false, format);
}

////////////////////////////////////////////////
//	IndexedTriangleSetNode::getVertexData
////////////////////////////////////////////////

void IndexedTriangleSetNode::getVertexData(size_t id, void *vertex_data)
{
	if (id >= getNumVertexArrays()) {
		return;
	}

	VertexArray array;
	getVertexArray(array, id);
 	const VertexFormat& format = array.getFormat();
	
	char* buffer = (char*)vertex_data;

	const Attribute& att_v = *format.getAttribute(0);
	const Attribute& att_n = *format.getAttribute(1);
	const Attribute& att_t = *format.getAttribute(2);

	const CoordinateNode *v_node = (CoordinateNode*)getCoordField()->getValue();
	const NormalNode *n_node = (NormalNode*)getNormalField()->getValue();
	const TextureCoordinateNode *t_node = (TextureCoordinateNode*)getTexCoordField()->getValue();

	float v[3];
	float n[3];
	float t[3];

	for (int i = 0; i < v_node->getNPoints(); ++i) {
		v_node->getPoint(i, v);
		n_node->getVector(i, n);
		t_node->getPoint(i, t);

		memcpy(buffer + getIndexForVert(i, array, att_v),
			   v, att_v.getByteSize());
		memcpy(buffer + getIndexForVert(i, array, att_n),
			   n, att_n.getByteSize());
		memcpy(buffer + getIndexForVert(i, array, att_t),
			   t, att_t.getByteSize());
	}
}

////////////////////////////////////////////////
//	IndexedTriangleSetNode::getElementData
////////////////////////////////////////////////

void IndexedTriangleSetNode::getElementData(size_t id, void *index_data)
{
	if (id >= getNumVertexArrays()) {
		return;
	}

	const CoordinateNode *v_node = (CoordinateNode*)getCoordField()->getValue();
	const int max_points = v_node->getNPoints();

	int index = 0;

	int *buffer = (int*)index_data;
	for (int i = 0; i < getNIndexes(); ++i) {
		index = getIndex(i);
		if (index < 0 || index >= max_points) {
			// Invalid index, just set to 0.
			index = 0;		
		}

		memcpy(buffer, &index, sizeof(int));
		++buffer;
	}
}

////////////////////////////////////////////////
//	IndexedTriangleSetNode::recomputeDisplayList
////////////////////////////////////////////////

#ifdef CX3D_SUPPORT_OPENGL

void IndexedTriangleSetNode::recomputeDisplayList() 
{
}

#endif


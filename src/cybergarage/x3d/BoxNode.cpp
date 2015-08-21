/******************************************************************
*
*	CyberX3D for C++
*
*	Copyright (C) Satoshi Konno 1996-2007
*
*	File:	BoxNode.cpp
*
******************************************************************/

#include <cybergarage/x3d/BoxNode.h>
#include <cybergarage/x3d/Graphic3D.h>

using namespace CyberX3D;

BoxNode::BoxNode() 
{
	setHeaderFlag(false);
	setType(BOX_NODE);

	// size exposed field
	sizeField = new SFVec3f(2.0f, 2.0f, 2.0f);
	sizeField->setName(sizeFieldString);
	addExposedField(sizeField);
}

BoxNode::~BoxNode() 
{
}

////////////////////////////////////////////////
//	size
////////////////////////////////////////////////

SFVec3f *BoxNode::getSizeField() const 
{
	if (isInstanceNode() == false)
		return sizeField;
	return (SFVec3f *)getExposedField(sizeFieldString);
}

void BoxNode::setSize(float value[]) 
{
	getSizeField()->setValue(value);
}

void BoxNode::setSize(float x, float y, float z) 
{
	getSizeField()->setValue(x, y, z);
}

void BoxNode::getSize(float value[]) const
{
	getSizeField()->getValue(value);
}

float BoxNode::getX() const
{
	return getSizeField()->getX();
}

float BoxNode::getY()const 
{
	return getSizeField()->getY();
}

float BoxNode::getZ()const 
{
	return getSizeField()->getZ();
}

////////////////////////////////////////////////
//	List
////////////////////////////////////////////////

BoxNode *BoxNode::next()const 
{
	return (BoxNode *)Node::next(getType());
}

BoxNode *BoxNode::nextTraversal()const 
{
	return (BoxNode *)Node::nextTraversalByType(getType());
}

////////////////////////////////////////////////
//	functions
////////////////////////////////////////////////
	
bool BoxNode::isChildNodeType(Node *node) const
{
	return false;
}

void BoxNode::initialize() 
{
	recomputeBoundingBox();
#ifdef CX3D_SUPPORT_OPENGL
	recomputeDisplayList();
#endif
}

void BoxNode::uninitialize() 
{
}

void BoxNode::update() 
{
}

////////////////////////////////////////////////
//	Infomation
////////////////////////////////////////////////

void BoxNode::outputContext(std::ostream &printStream, const char *indentString) const
{
	SFVec3f *size = getSizeField();
	printStream << indentString << "\t" << "size " << size << std::endl;
}

////////////////////////////////////////////////
//	BoxNode::recomputeBoundingBox
////////////////////////////////////////////////

void BoxNode::recomputeBoundingBox() 
{
	setBoundingBoxCenter(0.0f, 0.0f, 0.0f);
	setBoundingBoxSize(getX()/2.0f, getY()/2.0f, getZ()/2.0f);
}

////////////////////////////////////////////////
//	BoxNode::getVertexArray
////////////////////////////////////////////////

size_t BoxNode::getNumVertexArrays()
{
	return 1;
}

void BoxNode::getVertexArray(VertexArray& array, size_t id) 
{
	if (id != 0) return;

	VertexFormat format;
	format.addAttribute<float>("position", 3);
	format.addAttribute<float>("normal", 3);
	format.addAttribute<float>("texcoord", 2);
	array = VertexArray(36, 0, false, format);
}

////////////////////////////////////////////////
//	BoxNode::getVertexData
////////////////////////////////////////////////

void BoxNode::getVertexData(size_t id, void *vertex_data)
{
	if (id >= getNumVertexArrays()) {
		return;
	}

	VertexArray array;
	getVertexArray(array, id);
 	const VertexFormat& format = array.getFormat();

	static float n[6][3] = {
			{0.0, 0.0, 1.0}, {0.0, -1.0, 0.0}, {0.0, 0.0, 1.0},
			{0.0, 1.0, 0.0}, {1.0, 0.0, 0.0}, {-1.0, 0.0, 0.0}};

	static int faces[6][6] = {
			{ 3, 2, 1, 1, 0, 3 }, { 7, 6, 2, 2, 3, 7 },
			{ 4, 5, 6, 6, 7, 4 }, { 0, 1, 5, 5, 4, 0 },
			{ 1, 2, 6, 6, 5,1  }, { 3, 0, 4, 4, 7, 3 }};

	static float t[6][2] = {
			{ 0.0f, 1.0f }, { 1.0f, 1.0f },
			{ 1.0f, 0.0f }, { 1.0f, 0.0f },
			{ 0.0f, 0.0f }, { 0.0f, 1.0f } };

	float v[8][3];

	v[0][0] = v[3][0] = v[4][0] = v[7][0] = -getX()/2.0f;
	v[1][0] = v[2][0] = v[5][0] = v[6][0] = getX()/2.0f;
	v[2][1] = v[3][1] = v[6][1] = v[7][1] = -getY()/2.0f;
	v[0][1] = v[1][1] = v[4][1] = v[5][1] = getY()/2.0f;
	v[4][2] = v[5][2] = v[6][2] = v[7][2] = -getZ()/2.0f;
	v[0][2] = v[1][2] = v[2][2] = v[3][2] = getZ()/2.0f;

	
	char* buffer = (char*)vertex_data;

	const Attribute& position = *format.getAttribute(0);
	const Attribute& normal = *format.getAttribute(1);
	const Attribute& tex_coord = *format.getAttribute(2);

	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			const int vertex = i*6 + j;
			memcpy(buffer + getIndexForVert(vertex, array, position),
			       v[faces[i][j]], position.getByteSize());
			memcpy(buffer + getIndexForVert(vertex, array, normal),
			       n[i], normal.getByteSize());
			memcpy(buffer + getIndexForVert(vertex, array, tex_coord),
			       t[j], tex_coord.getByteSize());
		}
	}
}

////////////////////////////////////////////////
//	DrawBox
//
//	   4+--------+5
//	   /|       /|
//	  / |      / |
//	0+--------+1 |
//	 |  |     |  |
//	 | 7+-----|--+6
//	 | /      | /
//	 |/       |/
//	3+--------+2
//
////////////////////////////////////////////////

#ifdef CX3D_SUPPORT_OPENGL

static void DrawBox(float x0, float x1, float y0, float y1,	float z0, float z1)
{
    static float n[6][3] = {
			{0.0, 0.0, 1.0}, {0.0, -1.0, 0.0}, {0.0, 0.0, 1.0},
			{0.0, 1.0, 0.0}, {1.0, 0.0, 0.0}, {-1.0, 0.0, 0.0}};

    static int faces[6][4] = {
			{ 3, 2, 1, 0 }, { 7, 6, 2, 3 }, { 4, 5, 6, 7 },
			{ 0, 1, 5, 4 }, { 1, 2, 6, 5 }, { 3, 0, 4, 7 }};

    static float t[4][2] = {
			{ 0.0f, 1.0f }, { 1.0f, 1.0f },
			{ 1.0f, 0.0f }, { 0.0f, 0.0f } };

    float	v[8][3];

	v[0][0] = v[3][0] = v[4][0] = v[7][0] = x0;
	v[1][0] = v[2][0] = v[5][0] = v[6][0] = x1;
	v[2][1] = v[3][1] = v[6][1] = v[7][1] = y0;
	v[0][1] = v[1][1] = v[4][1] = v[5][1] = y1;
	v[4][2] = v[5][2] = v[6][2] = v[7][2] = z0;
	v[0][2] = v[1][2] = v[2][2] = v[3][2] = z1;

	glFrontFace(GL_CCW);

    for (int i = 0; i < 6; i++) {
		glBegin(GL_POLYGON);
		glNormal3fv(n[i]);
		glTexCoord2fv(t[0]);
		glVertex3fv(v[faces[i][0]]);
		glTexCoord2fv(t[1]);
		glVertex3fv(v[faces[i][1]]);
		glTexCoord2fv(t[2]);
		glVertex3fv(v[faces[i][2]]);
		glTexCoord2fv(t[3]);
		glVertex3fv(v[faces[i][3]]);
		glEnd();
    }
}

////////////////////////////////////////////////
//	BoxNode::recomputeDisplayList
////////////////////////////////////////////////

void BoxNode::recomputeDisplayList() {	
	unsigned int nCurrentDisplayList = getDisplayList();
	if (0 < nCurrentDisplayList)
		glDeleteLists(nCurrentDisplayList, 1);

	unsigned int nNewDisplayList = glGenLists(1);
	glNewList(nNewDisplayList, GL_COMPILE);
		DrawBox(-getX()/2.0f, getX()/2.0f, -getY()/2.0f, getY()/2.0f, -getZ()/2.0f, getZ()/2.0f);
	glEndList();

	setDisplayList(nNewDisplayList);
};

#endif

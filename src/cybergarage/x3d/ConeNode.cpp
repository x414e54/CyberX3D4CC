
/******************************************************************
*
*	CyberX3D for C++
*
*	Copyright (C) Satoshi Konno 1996-2007
*
*	File:	ConeNode.cpp
*
******************************************************************/

#include <cybergarage/x3d/ConeNode.h>
#include <cybergarage/x3d/Graphic3D.h>

using namespace CyberX3D;

ConeNode::ConeNode() 
{
	setHeaderFlag(false);
	setType(CONE_NODE);

	// bottomRadius field
	bottomRadiusField = new SFFloat(1.0f);
	addExposedField(bottomRadiusFieldString, bottomRadiusField);

	// height field
	heightField = new SFFloat(2.0f);
	addExposedField(heightFieldString, heightField);

	// side field
	sideField = new SFBool(true);
	addExposedField(sideFieldString, sideField);

	// bottom field
	bottomField = new SFBool(true);
	addExposedField(bottomFieldString, bottomField);

	///////////////////////////
	// Slice
	///////////////////////////

	setSlices(DEFAULT_CONENODE_SLICES);
}

ConeNode::~ConeNode() 
{
}

////////////////////////////////////////////////
//	bottomRadius
////////////////////////////////////////////////

SFFloat *ConeNode::getBottomRadiusField() const
{
	if (isInstanceNode() == false)
		return bottomRadiusField;
	return (SFFloat *)getExposedField(bottomRadiusFieldString);
}

void ConeNode::setBottomRadius(float value) 
{
	getBottomRadiusField()->setValue(value);
}

float ConeNode::getBottomRadius()  const
{
	return getBottomRadiusField()->getValue();
}

////////////////////////////////////////////////
//	height
////////////////////////////////////////////////

SFFloat *ConeNode::getHeightField() const
{
	if (isInstanceNode() == false)
		return heightField;
	return (SFFloat *)getExposedField(heightFieldString);
}

void ConeNode::setHeight(float value) 
{
	getHeightField()->setValue(value);
}

float ConeNode::getHeight()  const
{
	return getHeightField()->getValue();
}

////////////////////////////////////////////////
//	side
////////////////////////////////////////////////

SFBool *ConeNode::getSideField() const
{
	if (isInstanceNode() == false)
		return sideField;
	return (SFBool *)getExposedField(sideFieldString);
}

void ConeNode::setSide(bool value) 
{
	getSideField()->setValue(value);
}

void ConeNode::setSide(int value) 
{
	setSide(value ? true : false);
}

bool ConeNode::getSide()  const
{
	return getSideField()->getValue();
}

////////////////////////////////////////////////
//	bottom
////////////////////////////////////////////////

SFBool *ConeNode::getBottomField() const
{
	if (isInstanceNode() == false)
		return bottomField;
	return (SFBool *)getExposedField(bottomFieldString);
}

void ConeNode::setBottom(bool value) 
{
	getBottomField()->setValue(value);
}

void ConeNode::setBottom(int value) 
{
	setBottom(value ? true : false);
}

bool ConeNode::getBottom()  const
{
	return getBottomField()->getValue();
}

////////////////////////////////////////////////
//	List
////////////////////////////////////////////////

ConeNode *ConeNode::next()  const
{
	return (ConeNode *)Node::next(getType());
}

ConeNode *ConeNode::nextTraversal()  const
{
	return (ConeNode *)Node::nextTraversalByType(getType());
}

////////////////////////////////////////////////
//	functions
////////////////////////////////////////////////
	
bool ConeNode::isChildNodeType(Node *node) const
{
	return false;
}

void ConeNode::initialize() 
{
	recomputeBoundingBox();
#ifdef CX3D_SUPPORT_OPENGL
	recomputeDisplayList();
#endif
}

void ConeNode::uninitialize() 
{
}

void ConeNode::update() 
{
}

////////////////////////////////////////////////
//	BoundingBox
////////////////////////////////////////////////

void ConeNode::recomputeBoundingBox() 
{
	setBoundingBoxCenter(0.0f, 0.0f, 0.0f);
	setBoundingBoxSize(getBottomRadius(), getHeight()/2.0f, getBottomRadius());
}

////////////////////////////////////////////////
//	Polygons
////////////////////////////////////////////////

int ConeNode::getNPolygons() const
{
	int nPolys = 0;
	int slices = getSlices();
	
	if (getSide() == true)
		nPolys += slices;

	if (getBottom() == true)
		nPolys += slices;

	return nPolys;
}

////////////////////////////////////////////////
//	Infomation
////////////////////////////////////////////////

void ConeNode::outputContext(std::ostream &printStream, const char *indentString) const 
{
	SFBool *side = getSideField();
	SFBool *bottom = getBottomField();

	printStream << indentString << "\t" << "bottomRadius " << getBottomRadius() << std::endl;
	printStream << indentString << "\t" << "height " << getHeight() << std::endl;
	printStream << indentString << "\t" << "side " << side << std::endl;
	printStream << indentString << "\t" << "bottom " << bottom << std::endl;
}

////////////////////////////////////////////////
//	ConeNode::getVertexArray
////////////////////////////////////////////////

size_t ConeNode::getNumVertexArrays()
{
	return 1;
}

void ConeNode::getVertexArray(VertexArray& array, size_t id) 
{
	if (id != 0) return;

	VertexFormat format;
	format.addAttribute<float>("position", 3);
	format.addAttribute<float>("normal", 3);
	format.addAttribute<float>("texcoord", 2);
	array = VertexArray(getSlices() * 6, 0, false, format);
}

////////////////////////////////////////////////
//	ConeNode::getVertexData
////////////////////////////////////////////////

void ConeNode::getVertexData(size_t id, void *vertex_data)
{
	if (id >= getNumVertexArrays() || getSlices() == 0.0) {
		return;
	}

	const size_t count = 6;//getBottom() ? 6 : 3;
	const size_t start = getSide() ? 0 : 3;

	if (start == count) {
		return;
	}

	VertexArray array;
	getVertexArray(array, id);
 	const VertexFormat& format = array.getFormat();

#define hPI 1.57079632679489661923
#define PI_2 6.28318530717958647693

	const int slices = getSlices();

	char* buffer = (char*)vertex_data;

	const Attribute& pos = *format.getAttribute(0);
	const Attribute& norm = *format.getAttribute(1);
	const Attribute& tex = *format.getAttribute(2);

	// TODO Stacks?

	const float h = getHeight();
	const float r = getBottomRadius();
	const float ny = (hPI - atan(h/r)) / hPI;
	const float segment_radius = PI_2 / getSlices();
	const float segment_length = 1.0 / getSlices();
	const float bottom_n[3] = {0.0, -1.0, 0.0};

	// TODO indexed list
	for (int i = 0; i < slices; ++i) {
		const float length = i * segment_length;
		const float length2 = length + segment_length;
		const float angle = i * segment_radius;
		const float angle2 = angle + segment_radius;
		const float xz[2] = {r * cos(angle), r * sin(angle)};
		const float xz2[2] = {r * cos(angle2), r * sin(angle2)}; 

		const float verts[6][3] = {
			{xz[0], -h/2.0, xz[1]},
			{0.0, h/2.0, 0.0},
			{xz2[0], -h/2.0, xz2[1]},
			{0.0, h/2.0, 0.0},
			{xz[0], -h/2.0, xz[1]},
			{xz2[0], -h/2.0, xz2[1]}
		};

		const float t[6][2] = {
			{1.0 - length, 0.0},
			{1.0 - length, 1.0},
			{1.0 - length2, 0.0},
			{0.5, 0.5},
			{(0.5 * sin(angle)) + 0.5, (0.5 * cos(angle)) + 0.5},
			{(0.5 * sin(angle2)) + 0.5, (0.5 * cos(angle2)) + 0.5},
		};

		for (int j = start; j < count; ++j) {
			const size_t vertex_id = ((j > 2) ? (slices * 3) : 0) +
						 ((3*i) + (j % 3));
			
			const float (&v)[3] = verts[j];

			memcpy(buffer + getIndexForVert(vertex_id, array, pos),
			       v, pos.getByteSize());
			const float len = sqrt((v[0] * v[0])
						+ (v[2] * v[2]));
			const float n[3] = {
				xz[0], ny, xz[1] 
			};

			memcpy(buffer + getIndexForVert(vertex_id, array, norm),
			       (j > 2) ? bottom_n : n, norm.getByteSize());

			memcpy(buffer + getIndexForVert(vertex_id, array, tex),
			       t[j], tex.getByteSize());
		}
	}
}

////////////////////////////////////////////////
//	ConeNode::recomputeDisplayList
////////////////////////////////////////////////

#ifdef CX3D_SUPPORT_OPENGL

void ConeNode::recomputeDisplayList() {
	unsigned int nCurrentDisplayList = getDisplayList();
	if (0 < nCurrentDisplayList)
		glDeleteLists(nCurrentDisplayList, 1);

	int slices = getSlices();

	unsigned int nNewDisplayList = glGenLists(1);
	glNewList(nNewDisplayList, GL_COMPILE);

		glFrontFace(GL_CCW);

		GLUquadricObj *quadObj;

	    glPushMatrix ();

		glMatrixMode(GL_TEXTURE);
		glLoadIdentity();
	    glRotatef (180.0, 0.0, 1.0, 0.0);

		glMatrixMode(GL_MODELVIEW);
	
	    glRotatef (180.0, 0.0, 1.0, 0.0);
	    glRotatef (90.0, 1.0, 0.0, 0.0);
	    glTranslatef (0.0, 0.0, -getHeight()/2.0f);

		if (getSide()) {
		    quadObj = gluNewQuadric ();
		    gluQuadricDrawStyle (quadObj, GLU_FILL);
			gluQuadricNormals (quadObj, GLU_SMOOTH);
		    gluQuadricTexture(quadObj, GL_TRUE);
		    gluCylinder (quadObj, 0.0, getBottomRadius(), getHeight(), slices, 10);
			gluDeleteQuadric(quadObj);
		}

		if (getBottom()) {
		    glTranslatef (0.0, 0.0, getHeight());
		    quadObj = gluNewQuadric ();
		    gluQuadricTexture(quadObj, GL_TRUE);
			gluDisk(quadObj, 0.0, getBottomRadius(), slices, 10);
			gluDeleteQuadric(quadObj);
		    glTranslatef (0.0, 0.0, -1.0);
		}

	    glPopMatrix ();
	glEndList();

	setDisplayList(nNewDisplayList);
};

#endif


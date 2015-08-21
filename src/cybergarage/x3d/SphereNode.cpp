/******************************************************************
*
*	CyberX3D for C++
*
*	Copyright (C) Satoshi Konno 1996-2007
*
*	File:	SphereNode.cpp
*
******************************************************************/

#include <cmath>

#include <cybergarage/x3d/SphereNode.h>
#include <cybergarage/x3d/Graphic3D.h>

using namespace CyberX3D;

SphereNode::SphereNode() 
{
	setHeaderFlag(false);
	setType(SPHERE_NODE);

	///////////////////////////
	// Exposed Field 
	///////////////////////////

	// radius exposed field
	radiusField = new SFFloat(1.0f);
	addExposedField(radiusFieldString, radiusField);

	///////////////////////////
	// Slice
	///////////////////////////

	setSlices(DEFAULT_SPHERE_SLICES);
}

SphereNode::~SphereNode() 
{
}

////////////////////////////////////////////////
//	Radius
////////////////////////////////////////////////

SFFloat *SphereNode::getRadiusField() const
{
	if (isInstanceNode() == false)
		return radiusField;
	return (SFFloat *)getExposedField(radiusFieldString);
}
	
void SphereNode::setRadius(float value) 
{
	getRadiusField()->setValue(value);
}

float SphereNode::getRadius() const
{
	return getRadiusField()->getValue();
} 

////////////////////////////////////////////////
//	List
////////////////////////////////////////////////

SphereNode *SphereNode::next() const
{
	return (SphereNode *)Node::next(getType());
}

SphereNode *SphereNode::nextTraversal() const
{
	return (SphereNode *)Node::nextTraversalByType(getType());
}

////////////////////////////////////////////////
//	functions
////////////////////////////////////////////////
	
bool SphereNode::isChildNodeType(Node *node) const
{
	return false;
}

void SphereNode::initialize() 
{
	recomputeBoundingBox();
#ifdef CX3D_SUPPORT_OPENGL
		recomputeDisplayList();
#endif
}

void SphereNode::uninitialize() 
{
}

void SphereNode::update() 
{
}

////////////////////////////////////////////////
//	BoundingBox
////////////////////////////////////////////////

void SphereNode::recomputeBoundingBox() 
{
	setBoundingBoxCenter(0.0f, 0.0f, 0.0f);
	setBoundingBoxSize(getRadius(), getRadius(), getRadius());
}

////////////////////////////////////////////////
//	Polygons
////////////////////////////////////////////////

int SphereNode::getNPolygons() const
{
	int slices = getSlices();

	return (slices * slices);
}

////////////////////////////////////////////////
//	Infomation
////////////////////////////////////////////////

void SphereNode::outputContext(std::ostream &printStream, const char *indentString) const
{
	printStream << indentString << "\t" << "radius " << getRadius() << std::endl;
}

////////////////////////////////////////////////
//	SphereNode::getVertexArray
////////////////////////////////////////////////

size_t SphereNode::getNumVertexArrays()
{
	return 1;
}

void SphereNode::getVertexArray(VertexArray& array, size_t id) 
{
	if (id != 0) return;

	VertexFormat format;
	format.addAttribute<float>("position", 3);
	format.addAttribute<float>("normal", 3);
	format.addAttribute<float>("texcoord", 2);
	array = VertexArray(60, 0, false, format);
}

////////////////////////////////////////////////
//	SphereNode::getVertexData
////////////////////////////////////////////////

void SphereNode::getVertexData(size_t id, void *vertex_data)
{
	if (id >= getNumVertexArrays()) {
		return;
	}

	VertexArray array;
	getVertexArray(array, id);
 	const VertexFormat& format = array.getFormat();

// Just fun with an icosphere for now
// http://blog.andreaskahler.com/2009/06/creating-icosphere-mesh-in-code.html
// Maybe convert to uv sphere later

#define PI   3.14159265358979323846
#define PI_2 6.28318530717958647693

	float r = (1.0 + sqrt(5.0))/ 2.0;
	const float v[12][3] = {
		{-1.0, r, 0.0}, {1.0, r, 0.0}, {-1.0, -r, 0.0}, {1.0, -r, 0.0},
		{0.0, -1.0, r}, {0.0, 1.0, r}, {0.0, -1.0, -r}, {0.0, 1.0, -r},
		{r, 0.0, -1.0}, {r, 0.0, 1.0}, {-r, 0.0, -1.0}, {-r, 0.0, 1.0}
	};

	static int faces[20][3] = {
		{0, 11, 5}, {0, 5,  1}, { 0, 1,  7}, { 0, 7, 10},  {0, 10, 11},
		{1,  5, 9}, {5, 11, 4}, {11, 10, 2}, {10, 7,  6},  {7,  1,  8},
		{3,  9, 4}, {3, 4,  2}, { 3, 2,  6}, { 3, 6,  8},  {3,  8,  9},
		{4,  9, 5}, {2, 4, 11}, { 6, 2, 10}, { 8, 6,  7},  {9,  8,  1},
	};

	char* buffer = (char*)vertex_data;

	const Attribute& pos = *format.getAttribute(0);
	const Attribute& norm = *format.getAttribute(1);
	const Attribute& tex = *format.getAttribute(2);

	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 3; j++) {
			const int vertex_id = i*3 + j;
			const float (&vertex)[3] = v[faces[i][j]];
			memcpy(buffer + getIndexForVert(vertex_id, array, pos),
			       v[faces[i][j]], pos.getByteSize());
			
			float length = sqrt((vertex[0] * vertex[0])
					  + (vertex[1] * vertex[1])
                                          + (vertex[2] * vertex[2])); 

			float n[3] = {
				vertex[0] / length,
				vertex[1] / length,
				vertex[2] / length
			};

			memcpy(buffer + getIndexForVert(vertex_id, array, norm),
			       n, norm.getByteSize());

			float t[2] = {
				0.5 + (atan2(n[2], n[0]) / (PI_2)),
				0.5 - (asin(n[1]) / PI)
			};

			memcpy(buffer + getIndexForVert(vertex_id, array, tex),
			       t, tex.getByteSize());
		}
	}
}

////////////////////////////////////////////////
//	SphereNode::recomputeDisplayList
////////////////////////////////////////////////

#ifdef CX3D_SUPPORT_OPENGL

void SphereNode::recomputeDisplayList() 
{
	unsigned int nCurrentDisplayList = getDisplayList();
	if (0 < nCurrentDisplayList)
		glDeleteLists(nCurrentDisplayList, 1);

	int slices = getSlices();

	unsigned int nNewDisplayList = glGenLists(1);
	glNewList(nNewDisplayList, GL_COMPILE);
		glFrontFace(GL_CCW);

	    glPushMatrix ();
	
		glMatrixMode(GL_TEXTURE);
		glLoadIdentity();
	    glRotatef (180.0, 0.0, 1.0, 0.0);
		
		glMatrixMode(GL_MODELVIEW);

	    glRotatef (90.0, 1.0, 0.0, 0.0);
	    glRotatef (180.0, 0.0, 0.0, 1.0);

	    GLUquadricObj *quadObj = gluNewQuadric ();
	    gluQuadricDrawStyle(quadObj, GLU_FILL);
	    gluQuadricNormals(quadObj, GLU_SMOOTH);
	    gluQuadricTexture(quadObj, GL_TRUE);
	    gluSphere(quadObj, getRadius(), slices, slices);
		gluDeleteQuadric(quadObj);

	    glPopMatrix ();

	glEndList();

	setDisplayList(nNewDisplayList);
};

#endif

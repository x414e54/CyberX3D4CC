
/******************************************************************
*
*	CyberX3D for C++
*
*	Copyright (C) Satoshi Konno 1996-2007
*
*	File:	CommonSurfaceShaderNode.cpp
*
******************************************************************/

#include <cybergarage/x3d/CommonSurfaceShaderNode.h>

using namespace CyberX3D;

static const char alphaFactorExposedFieldName[] = "alphaFactor";
static const char alphaTextureExposedFieldName[] = "alphaTexture";
static const char alphaTextureChannelMaskExposedFieldName[] = "alphaTextureChannelMask";
static const char alphaTextureCoordinatesIdExposedFieldName[] = "alphaTextureCoordinatesId";
static const char alphaTextureIdExposedFieldName[] = "alphaTextureId";

static const char ambientFactorExposedFieldName[] = "ambientFactor";
static const char ambientTextureExposedFieldName[] = "ambientTexture";
static const char ambientTextureChannelMaskExposedFieldName[] = "ambientTextureChannelMask";
static const char ambientTextureCoordinatesIdExposedFieldName[] = "ambientTextureCoordinatesId";
static const char ambientTextureIdExposedFieldName[] = "ambientTextureId";

static const char binormalTextureCoordinatesIdExposedFieldName[] = "binormalTextureCoordinatesId";

static const char diffuseFactorExposedFieldName[] = "diffuseFactor";
static const char diffuseTextureExposedFieldName[] = "diffuseTexture";
static const char diffuseTextureChannelMaskExposedFieldName[] = "diffuseTextureChannelMask";
static const char diffuseTextureCoordinatesIdExposedFieldName[] = "diffuseTextureCoordinatesId";
static const char diffuseTextureIdExposedFieldName[] = "diffuseTextureId";

static const char displacementAxisExposedFieldName[] = "displacementAxis";
static const char displacementFactorExposedFieldName[] = "displacementFactor";
static const char displacementTextureExposedFieldName[] = "displacementTexture";
static const char displacementTextureCoordinatesIdExposedFieldName[] = "displacementTextureCoordinatesId";
static const char displacementTextureIdExposedFieldName[] = "displacementTextureId";

static const char emissiveFactorExposedFieldName[] = "emissiveFactor";
static const char emissiveTextureExposedFieldName[] = "emissiveTexture";
static const char emissiveTextureChannelMaskExposedFieldName[] = "emissiveTextureChannelMask";
static const char emissiveTextureCoordinatesIdExposedFieldName[] = "emissiveTextureCoordinatesId";
static const char emissiveTextureIdExposedFieldName[] = "emissiveTextureId";

static const char environmentFactorExposedFieldName[] = "environmentFactor";
static const char environmentTextureExposedFieldName[] = "environmentTexture";
static const char environmentTextureChannelMaskExposedFieldName[] = "environmentTextureChannelMask";
static const char environmentTextureCoordinatesIdExposedFieldName[] = "environmentTextureCoordinatesId";
static const char environmentTextureIdExposedFieldName[] = "environmentTextureId";

static const char fresnelBlendExposedFieldName[] = "fresnelBlend";
static const char invertAlphaTextureExposedFieldName[] = "invertAlphaTexture";

static const char normalBiasExposedFieldName[] = "normalBias";
static const char normalFormatExposedFieldName[] = "normalFormat";
static const char normalScaleExposedFieldName[] = "normalScale";
static const char normalSpaceExposedFieldName[] = "normalSpace";
static const char normalTextureExposedFieldName[] = "normalTexture";
static const char normalTextureChannelMaskExposedFieldName[] = "normalTextureChannelMask";
static const char normalTextureCoordinatesIdExposedFieldName[] = "normalTextureCoordinatesId";
static const char normalTextureIdExposedFieldName[] = "normalTextureId";

static const char reflectionFactorExposedFieldName[] = "reflectionFactor";
static const char reflectionTextureChannelMaskExposedFieldName[] = "reflectionTextureChannelMask";
static const char reflectionTextureCoordinatesIdExposedFieldName[] = "reflectionTextureCoordinatesId";
static const char reflectionTextureIdExposedFieldName[] = "reflectionTextureId";
static const char relativeIndexOfRefractionExposedFieldName[] = "relativeIndexOfRefraction";

static const char shininessFactorExposedFieldName[] = "shininessFactor";
static const char shininessTextureExposedFieldName[] = "shininessTexture";
static const char shininessTextureChannelMaskExposedFieldName[] = "shininessTextureChannelMask";
static const char shininessTextureCoordinatesIdExposedFieldName[] = "shininessTextureCoordinatesId";
static const char shininessTextureIdExposedFieldName[] = "shininessTextureId";

static const char specularFactorExposedFieldName[] = "specularFactor";
static const char specularTextureExposedFieldName[] = "specularTexture";
static const char specularTextureChannelMaskExposedFieldName[] = "specularTextureChannelMask";
static const char specularTextureCoordinatesIdExposedFieldName[] = "specularTextureCoordinatesId";
static const char specularTextureIdExposedFieldName[] = "specularTextureId";

static const char tangentTextureCoordinatesIdExposedFieldName[] = "tangentTextureCoordinatesId";

static const char transmissionFactorExposedFieldName[] = "transmissionFactor";
static const char transmissionTextureExposedFieldName[] = "transmissionTexture";
static const char transmissionTextureChannelMaskExposedFieldName[] = "transmissionTextureChannelMask";
static const char transmissionTextureCoordinatesIdExposedFieldName[] = "transmissionTextureCoordinatesId";
static const char transmissionTextureIdExposedFieldName[] = "transmissionTextureId";

CommonSurfaceShaderNode::CommonSurfaceShaderNode() 
{
	setHeaderFlag(false);
	setType(COMMONSURFACESHADER_NODE);

	alphaFactorField = new SFFloat();
	addExposedField(alphaFactorExposedFieldName, alphaFactorField);

	alphaTextureField = new SFNode();
	addExposedField(alphaTextureExposedFieldName, alphaTextureField);

	alphaTextureChannelMaskField = new SFString();
	addExposedField(alphaTextureChannelMaskExposedFieldName, alphaTextureChannelMaskField);

	alphaTextureCoordinatesIdField = new SFInt32();
	addExposedField(alphaTextureCoordinatesIdExposedFieldName, alphaTextureCoordinatesIdField);

	alphaTextureIdField = new SFInt32();
	addExposedField(alphaTextureIdExposedFieldName, alphaTextureIdField);


	ambientFactorField = new SFVec3f();
	addExposedField(ambientFactorExposedFieldName, ambientFactorField);

	ambientTextureField = new SFNode();
	addExposedField(ambientTextureExposedFieldName, ambientTextureField);

	ambientTextureChannelMaskField = new SFString();
	addExposedField(ambientTextureChannelMaskExposedFieldName, ambientTextureChannelMaskField);

	ambientTextureCoordinatesIdField = new SFInt32();
	addExposedField(ambientTextureCoordinatesIdExposedFieldName, ambientTextureCoordinatesIdField);

	ambientTextureIdField = new SFInt32();
	addExposedField(ambientTextureIdExposedFieldName, ambientTextureIdField);


	binormalTextureCoordinatesIdField = new SFInt32();
	addExposedField(binormalTextureCoordinatesIdExposedFieldName, binormalTextureCoordinatesIdField);


	diffuseFactorField = new SFVec3f();
	addExposedField(diffuseFactorExposedFieldName, diffuseFactorField);

	diffuseTextureField = new SFNode();
	addExposedField(diffuseTextureExposedFieldName, diffuseTextureField);

	diffuseTextureChannelMaskField = new SFString();
	addExposedField(diffuseTextureChannelMaskExposedFieldName, diffuseTextureChannelMaskField);

	diffuseTextureCoordinatesIdField = new SFInt32();
	addExposedField(diffuseTextureCoordinatesIdExposedFieldName, diffuseTextureCoordinatesIdField);

	diffuseTextureIdField = new SFInt32();
	addExposedField(diffuseTextureIdExposedFieldName, diffuseTextureIdField);


	displacementAxisField = new SFString();
	addExposedField(displacementAxisExposedFieldName, displacementAxisField);

	displacementFactorField = new SFFloat();
	addExposedField(displacementFactorExposedFieldName, displacementFactorField);

	displacementTextureField = new SFNode();
	addExposedField(displacementTextureExposedFieldName, displacementTextureField);

	displacementTextureCoordinatesIdField = new SFInt32();
	addExposedField(displacementTextureCoordinatesIdExposedFieldName, displacementTextureCoordinatesIdField);

	displacementTextureIdField = new SFInt32();
	addExposedField(displacementTextureIdExposedFieldName, displacementTextureIdField);


	emissiveFactorField = new SFVec3f();
	addExposedField(emissiveFactorExposedFieldName, emissiveFactorField);

	emissiveTextureField = new SFNode();
	addExposedField(emissiveTextureExposedFieldName, emissiveTextureField);

	emissiveTextureChannelMaskField = new SFString();
	addExposedField(emissiveTextureChannelMaskExposedFieldName, emissiveTextureChannelMaskField);

	emissiveTextureCoordinatesIdField = new SFInt32();
	addExposedField(emissiveTextureCoordinatesIdExposedFieldName, emissiveTextureCoordinatesIdField);

	emissiveTextureIdField = new SFInt32();
	addExposedField(emissiveTextureIdExposedFieldName, emissiveTextureIdField);


	environmentFactorField = new SFVec3f();
	addExposedField(environmentFactorExposedFieldName, environmentFactorField);

	environmentTextureField = new SFNode();
	addExposedField(environmentTextureExposedFieldName, environmentTextureField);

	environmentTextureChannelMaskField = new SFString();
	addExposedField(environmentTextureChannelMaskExposedFieldName, environmentTextureChannelMaskField);

	environmentTextureCoordinatesIdField = new SFInt32();
	addExposedField(environmentTextureCoordinatesIdExposedFieldName, environmentTextureCoordinatesIdField);

	environmentTextureIdField = new SFInt32();
	addExposedField(environmentTextureIdExposedFieldName, environmentTextureIdField);


	fresnelBlendField = new SFFloat();
	addExposedField(fresnelBlendExposedFieldName, fresnelBlendField);

	invertAlphaTextureField = new SFBool();
	addExposedField(invertAlphaTextureExposedFieldName, invertAlphaTextureField);


	normalBiasField = new SFVec3f();
	addExposedField(normalBiasExposedFieldName, normalBiasField);

	normalFormatField = new SFString();
	addExposedField(normalFormatExposedFieldName, normalFormatField);

	normalScaleField = new SFVec3f();
	addExposedField(normalScaleExposedFieldName, normalScaleField);

	normalSpaceField = new SFString();
	addExposedField(normalSpaceExposedFieldName, normalSpaceField);

	normalTextureField = new SFNode();
	addExposedField(normalTextureExposedFieldName, normalTextureField);

	normalTextureChannelMaskField = new SFString();
	addExposedField(normalTextureChannelMaskExposedFieldName, normalTextureChannelMaskField);

	normalTextureCoordinatesIdField = new SFInt32();
	addExposedField(normalTextureCoordinatesIdExposedFieldName, normalTextureCoordinatesIdField);

	normalTextureIdField = new SFInt32();
	addExposedField(normalTextureIdExposedFieldName, normalTextureIdField);


	reflectionFactorField = new SFVec3f();
	addExposedField(reflectionFactorExposedFieldName, reflectionFactorField);

	reflectionTextureChannelMaskField = new SFString();
	addExposedField(reflectionTextureChannelMaskExposedFieldName, reflectionTextureChannelMaskField);

	reflectionTextureCoordinatesIdField = new SFInt32();
	addExposedField(reflectionTextureCoordinatesIdExposedFieldName, reflectionTextureCoordinatesIdField);

	reflectionTextureIdField = new SFInt32();
	addExposedField(reflectionTextureIdExposedFieldName, reflectionTextureIdField);

	relativeIndexOfRefractionField = new SFFloat();
	addExposedField(relativeIndexOfRefractionExposedFieldName, relativeIndexOfRefractionField);


	shininessFactorField = new SFFloat();
	addExposedField(shininessFactorExposedFieldName, shininessFactorField);

	shininessTextureField = new SFNode();
	addExposedField(shininessTextureExposedFieldName, shininessTextureField);

	shininessTextureChannelMaskField = new SFString();
	addExposedField(shininessTextureChannelMaskExposedFieldName, shininessTextureChannelMaskField);

	shininessTextureCoordinatesIdField = new SFInt32();
	addExposedField(shininessTextureCoordinatesIdExposedFieldName, shininessTextureCoordinatesIdField);

	shininessTextureIdField = new SFInt32();
	addExposedField(shininessTextureIdExposedFieldName, shininessTextureIdField);


	specularFactorField = new SFVec3f();
	addExposedField(specularFactorExposedFieldName, specularFactorField);

	specularTextureField = new SFNode();
	addExposedField(specularTextureExposedFieldName, specularTextureField);

	specularTextureChannelMaskField = new SFString();
	addExposedField(specularTextureChannelMaskExposedFieldName, specularTextureChannelMaskField);

	specularTextureCoordinatesIdField = new SFInt32();
	addExposedField(specularTextureCoordinatesIdExposedFieldName, specularTextureCoordinatesIdField);

	specularTextureIdField = new SFInt32();
	addExposedField(specularTextureIdExposedFieldName, specularTextureIdField);


	tangentTextureCoordinatesIdField = new SFInt32();
	addExposedField(tangentTextureCoordinatesIdExposedFieldName, tangentTextureCoordinatesIdField);


	transmissionFactorField = new SFVec3f();
	addExposedField(transmissionFactorExposedFieldName, transmissionFactorField);

	transmissionTextureField = new SFNode();
	addExposedField(transmissionTextureExposedFieldName, transmissionTextureField);

	transmissionTextureChannelMaskField = new SFString();
	addExposedField(transmissionTextureChannelMaskExposedFieldName, transmissionTextureChannelMaskField);

	transmissionTextureCoordinatesIdField = new SFInt32();
	addExposedField(transmissionTextureCoordinatesIdExposedFieldName, transmissionTextureCoordinatesIdField);

	transmissionTextureIdField = new SFInt32();
	addExposedField(transmissionTextureIdExposedFieldName, transmissionTextureIdField);

}

CommonSurfaceShaderNode::~CommonSurfaceShaderNode() 
{
}

////////////////////////////////////////////////
//	AlphaFactor
////////////////////////////////////////////////

SFFloat *CommonSurfaceShaderNode::getAlphaFactorField() const
{
	if (isInstanceNode() == false)
		return alphaFactorField;
	return (SFFloat *)getExposedField(alphaFactorExposedFieldName);
}
void CommonSurfaceShaderNode::setAlphaFactor(float value) 
{
	getAlphaFactorField()->setValue(value);
}

float CommonSurfaceShaderNode::getAlphaFactor() const 
{
	return getAlphaFactorField()->getValue();
}

////////////////////////////////////////////////
//	AlphaTexture
////////////////////////////////////////////////

SFNode *CommonSurfaceShaderNode::getAlphaTextureField() const
{
	if (isInstanceNode() == false)
		return alphaTextureField;
	return (SFNode *)getExposedField(alphaTextureExposedFieldName);
}

////////////////////////////////////////////////
//	AlphaTextureChannelMask
////////////////////////////////////////////////

SFString *CommonSurfaceShaderNode::getAlphaTextureChannelMaskField() const
{
	if (isInstanceNode() == false)
		return alphaTextureChannelMaskField;
	return (SFString *)getExposedField(alphaTextureChannelMaskExposedFieldName);
}
void CommonSurfaceShaderNode::setAlphaTextureChannelMask(const char *value) 
{
	getAlphaTextureChannelMaskField()->setValue(value);
}

const char *CommonSurfaceShaderNode::getAlphaTextureChannelMask() const 
{
	return getAlphaTextureChannelMaskField()->getValue();
}

////////////////////////////////////////////////
//	AlphaTextureCoordinatesId
////////////////////////////////////////////////

SFInt32 *CommonSurfaceShaderNode::getAlphaTextureCoordinatesIdField() const
{
	if (isInstanceNode() == false)
		return alphaTextureCoordinatesIdField;
	return (SFInt32 *)getExposedField(alphaTextureCoordinatesIdExposedFieldName);
}
void CommonSurfaceShaderNode::setAlphaTextureCoordinatesId(int value) 
{
	getAlphaTextureCoordinatesIdField()->setValue(value);
}

int CommonSurfaceShaderNode::getAlphaTextureCoordinatesId() const 
{
	return getAlphaTextureCoordinatesIdField()->getValue();
}

////////////////////////////////////////////////
//	AlphaTextureId
////////////////////////////////////////////////

SFInt32 *CommonSurfaceShaderNode::getAlphaTextureIdField() const
{
	if (isInstanceNode() == false)
		return alphaTextureIdField;
	return (SFInt32 *)getExposedField(alphaTextureIdExposedFieldName);
}
void CommonSurfaceShaderNode::setAlphaTextureId(int value) 
{
	getAlphaTextureIdField()->setValue(value);
}

int CommonSurfaceShaderNode::getAlphaTextureId() const 
{
	return getAlphaTextureIdField()->getValue();
}


////////////////////////////////////////////////
//	AmbientFactor
////////////////////////////////////////////////

SFVec3f *CommonSurfaceShaderNode::getAmbientFactorField() const
{
	if (isInstanceNode() == false)
		return ambientFactorField;
	return (SFVec3f *)getExposedField(ambientFactorExposedFieldName);
}
void CommonSurfaceShaderNode::setAmbientFactor(float value[]) 
{
	getAmbientFactorField()->setValue(value);
}

void CommonSurfaceShaderNode::setAmbientFactor(float r, float g, float b) 
{
	getAmbientFactorField()->setValue(r, g, b);
}

void CommonSurfaceShaderNode::getAmbientFactor(float value[]) const 
{
	getAmbientFactorField()->getValue(value);
}

////////////////////////////////////////////////
//	AmbientTexture
////////////////////////////////////////////////

SFNode *CommonSurfaceShaderNode::getAmbientTextureField() const
{
	if (isInstanceNode() == false)
		return ambientTextureField;
	return (SFNode *)getExposedField(ambientTextureExposedFieldName);
}

////////////////////////////////////////////////
//	AmbientTextureChannelMask
////////////////////////////////////////////////

SFString *CommonSurfaceShaderNode::getAmbientTextureChannelMaskField() const
{
	if (isInstanceNode() == false)
		return ambientTextureChannelMaskField;
	return (SFString *)getExposedField(ambientTextureChannelMaskExposedFieldName);
}
void CommonSurfaceShaderNode::setAmbientTextureChannelMask(const char *value) 
{
	getAmbientTextureChannelMaskField()->setValue(value);
}

const char *CommonSurfaceShaderNode::getAmbientTextureChannelMask() const 
{
	return getAmbientTextureChannelMaskField()->getValue();
}

////////////////////////////////////////////////
//	AmbientTextureCoordinatesId
////////////////////////////////////////////////

SFInt32 *CommonSurfaceShaderNode::getAmbientTextureCoordinatesIdField() const
{
	if (isInstanceNode() == false)
		return ambientTextureCoordinatesIdField;
	return (SFInt32 *)getExposedField(ambientTextureCoordinatesIdExposedFieldName);
}
void CommonSurfaceShaderNode::setAmbientTextureCoordinatesId(int value) 
{
	getAmbientTextureCoordinatesIdField()->setValue(value);
}

int CommonSurfaceShaderNode::getAmbientTextureCoordinatesId() const 
{
	return getAmbientTextureCoordinatesIdField()->getValue();
}

////////////////////////////////////////////////
//	AmbientTextureId
////////////////////////////////////////////////

SFInt32 *CommonSurfaceShaderNode::getAmbientTextureIdField() const
{
	if (isInstanceNode() == false)
		return ambientTextureIdField;
	return (SFInt32 *)getExposedField(ambientTextureIdExposedFieldName);
}
void CommonSurfaceShaderNode::setAmbientTextureId(int value) 
{
	getAmbientTextureIdField()->setValue(value);
}

int CommonSurfaceShaderNode::getAmbientTextureId() const 
{
	return getAmbientTextureIdField()->getValue();
}


////////////////////////////////////////////////
//	BinormalTextureCoordinatesId
////////////////////////////////////////////////

SFInt32 *CommonSurfaceShaderNode::getBinormalTextureCoordinatesIdField() const
{
	if (isInstanceNode() == false)
		return binormalTextureCoordinatesIdField;
	return (SFInt32 *)getExposedField(binormalTextureCoordinatesIdExposedFieldName);
}
void CommonSurfaceShaderNode::setBinormalTextureCoordinatesId(int value) 
{
	getBinormalTextureCoordinatesIdField()->setValue(value);
}

int CommonSurfaceShaderNode::getBinormalTextureCoordinatesId() const 
{
	return getBinormalTextureCoordinatesIdField()->getValue();
}


////////////////////////////////////////////////
//	DiffuseFactor
////////////////////////////////////////////////

SFVec3f *CommonSurfaceShaderNode::getDiffuseFactorField() const
{
	if (isInstanceNode() == false)
		return diffuseFactorField;
	return (SFVec3f *)getExposedField(diffuseFactorExposedFieldName);
}
void CommonSurfaceShaderNode::setDiffuseFactor(float value[]) 
{
	getDiffuseFactorField()->setValue(value);
}

void CommonSurfaceShaderNode::setDiffuseFactor(float r, float g, float b) 
{
	getDiffuseFactorField()->setValue(r, g, b);
}

void CommonSurfaceShaderNode::getDiffuseFactor(float value[]) const 
{
	getDiffuseFactorField()->getValue(value);
}

////////////////////////////////////////////////
//	DiffuseTexture
////////////////////////////////////////////////

SFNode *CommonSurfaceShaderNode::getDiffuseTextureField() const
{
	if (isInstanceNode() == false)
		return diffuseTextureField;
	return (SFNode *)getExposedField(diffuseTextureExposedFieldName);
}

////////////////////////////////////////////////
//	DiffuseTextureChannelMask
////////////////////////////////////////////////

SFString *CommonSurfaceShaderNode::getDiffuseTextureChannelMaskField() const
{
	if (isInstanceNode() == false)
		return diffuseTextureChannelMaskField;
	return (SFString *)getExposedField(diffuseTextureChannelMaskExposedFieldName);
}
void CommonSurfaceShaderNode::setDiffuseTextureChannelMask(const char *value) 
{
	getDiffuseTextureChannelMaskField()->setValue(value);
}

const char *CommonSurfaceShaderNode::getDiffuseTextureChannelMask() const 
{
	return getDiffuseTextureChannelMaskField()->getValue();
}

////////////////////////////////////////////////
//	DiffuseTextureCoordinatesId
////////////////////////////////////////////////

SFInt32 *CommonSurfaceShaderNode::getDiffuseTextureCoordinatesIdField() const
{
	if (isInstanceNode() == false)
		return diffuseTextureCoordinatesIdField;
	return (SFInt32 *)getExposedField(diffuseTextureCoordinatesIdExposedFieldName);
}
void CommonSurfaceShaderNode::setDiffuseTextureCoordinatesId(int value) 
{
	getDiffuseTextureCoordinatesIdField()->setValue(value);
}

int CommonSurfaceShaderNode::getDiffuseTextureCoordinatesId() const 
{
	return getDiffuseTextureCoordinatesIdField()->getValue();
}

////////////////////////////////////////////////
//	DiffuseTextureId
////////////////////////////////////////////////

SFInt32 *CommonSurfaceShaderNode::getDiffuseTextureIdField() const
{
	if (isInstanceNode() == false)
		return diffuseTextureIdField;
	return (SFInt32 *)getExposedField(diffuseTextureIdExposedFieldName);
}
void CommonSurfaceShaderNode::setDiffuseTextureId(int value) 
{
	getDiffuseTextureIdField()->setValue(value);
}

int CommonSurfaceShaderNode::getDiffuseTextureId() const 
{
	return getDiffuseTextureIdField()->getValue();
}


////////////////////////////////////////////////
//	DisplacementAxis
////////////////////////////////////////////////

SFString *CommonSurfaceShaderNode::getDisplacementAxisField() const
{
	if (isInstanceNode() == false)
		return displacementAxisField;
	return (SFString *)getExposedField(displacementAxisExposedFieldName);
}
void CommonSurfaceShaderNode::setDisplacementAxis(const char *value) 
{
	getDisplacementAxisField()->setValue(value);
}

const char *CommonSurfaceShaderNode::getDisplacementAxis() const 
{
	return getDisplacementAxisField()->getValue();
}

////////////////////////////////////////////////
//	DisplacementFactor
////////////////////////////////////////////////

SFFloat *CommonSurfaceShaderNode::getDisplacementFactorField() const
{
	if (isInstanceNode() == false)
		return displacementFactorField;
	return (SFFloat *)getExposedField(displacementFactorExposedFieldName);
}
void CommonSurfaceShaderNode::setDisplacementFactor(float value) 
{
	getDisplacementFactorField()->setValue(value);
}

float CommonSurfaceShaderNode::getDisplacementFactor() const 
{
	return getDisplacementFactorField()->getValue();
}

////////////////////////////////////////////////
//	DisplacementTexture
////////////////////////////////////////////////

SFNode *CommonSurfaceShaderNode::getDisplacementTextureField() const
{
	if (isInstanceNode() == false)
		return displacementTextureField;
	return (SFNode *)getExposedField(displacementTextureExposedFieldName);
}

////////////////////////////////////////////////
//	DisplacementTextureCoordinatesId
////////////////////////////////////////////////

SFInt32 *CommonSurfaceShaderNode::getDisplacementTextureCoordinatesIdField() const
{
	if (isInstanceNode() == false)
		return displacementTextureCoordinatesIdField;
	return (SFInt32 *)getExposedField(displacementTextureCoordinatesIdExposedFieldName);
}
void CommonSurfaceShaderNode::setDisplacementTextureCoordinatesId(int value) 
{
	getDisplacementTextureCoordinatesIdField()->setValue(value);
}

int CommonSurfaceShaderNode::getDisplacementTextureCoordinatesId() const 
{
	return getDisplacementTextureCoordinatesIdField()->getValue();
}

////////////////////////////////////////////////
//	DisplacementTextureId
////////////////////////////////////////////////

SFInt32 *CommonSurfaceShaderNode::getDisplacementTextureIdField() const
{
	if (isInstanceNode() == false)
		return displacementTextureIdField;
	return (SFInt32 *)getExposedField(displacementTextureIdExposedFieldName);
}
void CommonSurfaceShaderNode::setDisplacementTextureId(int value) 
{
	getDisplacementTextureIdField()->setValue(value);
}

int CommonSurfaceShaderNode::getDisplacementTextureId() const 
{
	return getDisplacementTextureIdField()->getValue();
}


////////////////////////////////////////////////
//	EmissiveFactor
////////////////////////////////////////////////

SFVec3f *CommonSurfaceShaderNode::getEmissiveFactorField() const
{
	if (isInstanceNode() == false)
		return emissiveFactorField;
	return (SFVec3f *)getExposedField(emissiveFactorExposedFieldName);
}
void CommonSurfaceShaderNode::setEmissiveFactor(float value[]) 
{
	getEmissiveFactorField()->setValue(value);
}

void CommonSurfaceShaderNode::setEmissiveFactor(float r, float g, float b) 
{
	getEmissiveFactorField()->setValue(r, g, b);
}

void CommonSurfaceShaderNode::getEmissiveFactor(float value[]) const 
{
	getEmissiveFactorField()->getValue(value);
}

////////////////////////////////////////////////
//	EmissiveTexture
////////////////////////////////////////////////

SFNode *CommonSurfaceShaderNode::getEmissiveTextureField() const
{
	if (isInstanceNode() == false)
		return emissiveTextureField;
	return (SFNode *)getExposedField(emissiveTextureExposedFieldName);
}

////////////////////////////////////////////////
//	EmissiveTextureChannelMask
////////////////////////////////////////////////

SFString *CommonSurfaceShaderNode::getEmissiveTextureChannelMaskField() const
{
	if (isInstanceNode() == false)
		return emissiveTextureChannelMaskField;
	return (SFString *)getExposedField(emissiveTextureChannelMaskExposedFieldName);
}
void CommonSurfaceShaderNode::setEmissiveTextureChannelMask(const char *value) 
{
	getEmissiveTextureChannelMaskField()->setValue(value);
}

const char *CommonSurfaceShaderNode::getEmissiveTextureChannelMask() const 
{
	return getEmissiveTextureChannelMaskField()->getValue();
}

////////////////////////////////////////////////
//	EmissiveTextureCoordinatesId
////////////////////////////////////////////////

SFInt32 *CommonSurfaceShaderNode::getEmissiveTextureCoordinatesIdField() const
{
	if (isInstanceNode() == false)
		return emissiveTextureCoordinatesIdField;
	return (SFInt32 *)getExposedField(emissiveTextureCoordinatesIdExposedFieldName);
}
void CommonSurfaceShaderNode::setEmissiveTextureCoordinatesId(int value) 
{
	getEmissiveTextureCoordinatesIdField()->setValue(value);
}

int CommonSurfaceShaderNode::getEmissiveTextureCoordinatesId() const 
{
	return getEmissiveTextureCoordinatesIdField()->getValue();
}

////////////////////////////////////////////////
//	EmissiveTextureId
////////////////////////////////////////////////

SFInt32 *CommonSurfaceShaderNode::getEmissiveTextureIdField() const
{
	if (isInstanceNode() == false)
		return emissiveTextureIdField;
	return (SFInt32 *)getExposedField(emissiveTextureIdExposedFieldName);
}
void CommonSurfaceShaderNode::setEmissiveTextureId(int value) 
{
	getEmissiveTextureIdField()->setValue(value);
}

int CommonSurfaceShaderNode::getEmissiveTextureId() const 
{
	return getEmissiveTextureIdField()->getValue();
}


////////////////////////////////////////////////
//	EnvironmentFactor
////////////////////////////////////////////////

SFVec3f *CommonSurfaceShaderNode::getEnvironmentFactorField() const
{
	if (isInstanceNode() == false)
		return environmentFactorField;
	return (SFVec3f *)getExposedField(environmentFactorExposedFieldName);
}
void CommonSurfaceShaderNode::setEnvironmentFactor(float value[]) 
{
	getEnvironmentFactorField()->setValue(value);
}

void CommonSurfaceShaderNode::setEnvironmentFactor(float r, float g, float b) 
{
	getEnvironmentFactorField()->setValue(r, g, b);
}

void CommonSurfaceShaderNode::getEnvironmentFactor(float value[]) const 
{
	getEnvironmentFactorField()->getValue(value);
}

////////////////////////////////////////////////
//	EnvironmentTexture
////////////////////////////////////////////////

SFNode *CommonSurfaceShaderNode::getEnvironmentTextureField() const
{
	if (isInstanceNode() == false)
		return environmentTextureField;
	return (SFNode *)getExposedField(environmentTextureExposedFieldName);
}

////////////////////////////////////////////////
//	EnvironmentTextureChannelMask
////////////////////////////////////////////////

SFString *CommonSurfaceShaderNode::getEnvironmentTextureChannelMaskField() const
{
	if (isInstanceNode() == false)
		return environmentTextureChannelMaskField;
	return (SFString *)getExposedField(environmentTextureChannelMaskExposedFieldName);
}
void CommonSurfaceShaderNode::setEnvironmentTextureChannelMask(const char *value) 
{
	getEnvironmentTextureChannelMaskField()->setValue(value);
}

const char *CommonSurfaceShaderNode::getEnvironmentTextureChannelMask() const 
{
	return getEnvironmentTextureChannelMaskField()->getValue();
}

////////////////////////////////////////////////
//	EnvironmentTextureCoordinatesId
////////////////////////////////////////////////

SFInt32 *CommonSurfaceShaderNode::getEnvironmentTextureCoordinatesIdField() const
{
	if (isInstanceNode() == false)
		return environmentTextureCoordinatesIdField;
	return (SFInt32 *)getExposedField(environmentTextureCoordinatesIdExposedFieldName);
}
void CommonSurfaceShaderNode::setEnvironmentTextureCoordinatesId(int value) 
{
	getEnvironmentTextureCoordinatesIdField()->setValue(value);
}

int CommonSurfaceShaderNode::getEnvironmentTextureCoordinatesId() const 
{
	return getEnvironmentTextureCoordinatesIdField()->getValue();
}

////////////////////////////////////////////////
//	EnvironmentTextureId
////////////////////////////////////////////////

SFInt32 *CommonSurfaceShaderNode::getEnvironmentTextureIdField() const
{
	if (isInstanceNode() == false)
		return environmentTextureIdField;
	return (SFInt32 *)getExposedField(environmentTextureIdExposedFieldName);
}
void CommonSurfaceShaderNode::setEnvironmentTextureId(int value) 
{
	getEnvironmentTextureIdField()->setValue(value);
}

int CommonSurfaceShaderNode::getEnvironmentTextureId() const 
{
	return getEnvironmentTextureIdField()->getValue();
}


////////////////////////////////////////////////
//	FresnelBlend
////////////////////////////////////////////////

SFFloat *CommonSurfaceShaderNode::getFresnelBlendField() const
{
	if (isInstanceNode() == false)
		return fresnelBlendField;
	return (SFFloat *)getExposedField(fresnelBlendExposedFieldName);
}
void CommonSurfaceShaderNode::setFresnelBlend(float value) 
{
	getFresnelBlendField()->setValue(value);
}

float CommonSurfaceShaderNode::getFresnelBlend() const 
{
	return getFresnelBlendField()->getValue();
}

////////////////////////////////////////////////
//	InvertAlphaTexture
////////////////////////////////////////////////

SFBool *CommonSurfaceShaderNode::getInvertAlphaTextureField() const
{
	if (isInstanceNode() == false)
		return invertAlphaTextureField;
	return (SFBool *)getExposedField(invertAlphaTextureExposedFieldName);
}


////////////////////////////////////////////////
//	NormalBias
////////////////////////////////////////////////

SFVec3f *CommonSurfaceShaderNode::getNormalBiasField() const
{
	if (isInstanceNode() == false)
		return normalBiasField;
	return (SFVec3f *)getExposedField(normalBiasExposedFieldName);
}
void CommonSurfaceShaderNode::setNormalBias(float value[]) 
{
	getNormalBiasField()->setValue(value);
}

void CommonSurfaceShaderNode::setNormalBias(float r, float g, float b) 
{
	getNormalBiasField()->setValue(r, g, b);
}

void CommonSurfaceShaderNode::getNormalBias(float value[]) const 
{
	getNormalBiasField()->getValue(value);
}

////////////////////////////////////////////////
//	NormalFormat
////////////////////////////////////////////////

SFString *CommonSurfaceShaderNode::getNormalFormatField() const
{
	if (isInstanceNode() == false)
		return normalFormatField;
	return (SFString *)getExposedField(normalFormatExposedFieldName);
}
void CommonSurfaceShaderNode::setNormalFormat(const char *value) 
{
	getNormalFormatField()->setValue(value);
}

const char *CommonSurfaceShaderNode::getNormalFormat() const 
{
	return getNormalFormatField()->getValue();
}

////////////////////////////////////////////////
//	NormalScale
////////////////////////////////////////////////

SFVec3f *CommonSurfaceShaderNode::getNormalScaleField() const
{
	if (isInstanceNode() == false)
		return normalScaleField;
	return (SFVec3f *)getExposedField(normalScaleExposedFieldName);
}
void CommonSurfaceShaderNode::setNormalScale(float value[]) 
{
	getNormalScaleField()->setValue(value);
}

void CommonSurfaceShaderNode::setNormalScale(float r, float g, float b) 
{
	getNormalScaleField()->setValue(r, g, b);
}

void CommonSurfaceShaderNode::getNormalScale(float value[]) const 
{
	getNormalScaleField()->getValue(value);
}

////////////////////////////////////////////////
//	NormalSpace
////////////////////////////////////////////////

SFString *CommonSurfaceShaderNode::getNormalSpaceField() const
{
	if (isInstanceNode() == false)
		return normalSpaceField;
	return (SFString *)getExposedField(normalSpaceExposedFieldName);
}
void CommonSurfaceShaderNode::setNormalSpace(const char *value) 
{
	getNormalSpaceField()->setValue(value);
}

const char *CommonSurfaceShaderNode::getNormalSpace() const 
{
	return getNormalSpaceField()->getValue();
}

////////////////////////////////////////////////
//	NormalTexture
////////////////////////////////////////////////

SFNode *CommonSurfaceShaderNode::getNormalTextureField() const
{
	if (isInstanceNode() == false)
		return normalTextureField;
	return (SFNode *)getExposedField(normalTextureExposedFieldName);
}

////////////////////////////////////////////////
//	NormalTextureChannelMask
////////////////////////////////////////////////

SFString *CommonSurfaceShaderNode::getNormalTextureChannelMaskField() const
{
	if (isInstanceNode() == false)
		return normalTextureChannelMaskField;
	return (SFString *)getExposedField(normalTextureChannelMaskExposedFieldName);
}
void CommonSurfaceShaderNode::setNormalTextureChannelMask(const char *value) 
{
	getNormalTextureChannelMaskField()->setValue(value);
}

const char *CommonSurfaceShaderNode::getNormalTextureChannelMask() const 
{
	return getNormalTextureChannelMaskField()->getValue();
}

////////////////////////////////////////////////
//	NormalTextureCoordinatesId
////////////////////////////////////////////////

SFInt32 *CommonSurfaceShaderNode::getNormalTextureCoordinatesIdField() const
{
	if (isInstanceNode() == false)
		return normalTextureCoordinatesIdField;
	return (SFInt32 *)getExposedField(normalTextureCoordinatesIdExposedFieldName);
}
void CommonSurfaceShaderNode::setNormalTextureCoordinatesId(int value) 
{
	getNormalTextureCoordinatesIdField()->setValue(value);
}

int CommonSurfaceShaderNode::getNormalTextureCoordinatesId() const 
{
	return getNormalTextureCoordinatesIdField()->getValue();
}

////////////////////////////////////////////////
//	NormalTextureId
////////////////////////////////////////////////

SFInt32 *CommonSurfaceShaderNode::getNormalTextureIdField() const
{
	if (isInstanceNode() == false)
		return normalTextureIdField;
	return (SFInt32 *)getExposedField(normalTextureIdExposedFieldName);
}
void CommonSurfaceShaderNode::setNormalTextureId(int value) 
{
	getNormalTextureIdField()->setValue(value);
}

int CommonSurfaceShaderNode::getNormalTextureId() const 
{
	return getNormalTextureIdField()->getValue();
}


////////////////////////////////////////////////
//	ReflectionFactor
////////////////////////////////////////////////

SFVec3f *CommonSurfaceShaderNode::getReflectionFactorField() const
{
	if (isInstanceNode() == false)
		return reflectionFactorField;
	return (SFVec3f *)getExposedField(reflectionFactorExposedFieldName);
}
void CommonSurfaceShaderNode::setReflectionFactor(float value[]) 
{
	getReflectionFactorField()->setValue(value);
}

void CommonSurfaceShaderNode::setReflectionFactor(float r, float g, float b) 
{
	getReflectionFactorField()->setValue(r, g, b);
}

void CommonSurfaceShaderNode::getReflectionFactor(float value[]) const 
{
	getReflectionFactorField()->getValue(value);
}

////////////////////////////////////////////////
//	ReflectionTextureChannelMask
////////////////////////////////////////////////

SFString *CommonSurfaceShaderNode::getReflectionTextureChannelMaskField() const
{
	if (isInstanceNode() == false)
		return reflectionTextureChannelMaskField;
	return (SFString *)getExposedField(reflectionTextureChannelMaskExposedFieldName);
}
void CommonSurfaceShaderNode::setReflectionTextureChannelMask(const char *value) 
{
	getReflectionTextureChannelMaskField()->setValue(value);
}

const char *CommonSurfaceShaderNode::getReflectionTextureChannelMask() const 
{
	return getReflectionTextureChannelMaskField()->getValue();
}

////////////////////////////////////////////////
//	ReflectionTextureCoordinatesId
////////////////////////////////////////////////

SFInt32 *CommonSurfaceShaderNode::getReflectionTextureCoordinatesIdField() const
{
	if (isInstanceNode() == false)
		return reflectionTextureCoordinatesIdField;
	return (SFInt32 *)getExposedField(reflectionTextureCoordinatesIdExposedFieldName);
}
void CommonSurfaceShaderNode::setReflectionTextureCoordinatesId(int value) 
{
	getReflectionTextureCoordinatesIdField()->setValue(value);
}

int CommonSurfaceShaderNode::getReflectionTextureCoordinatesId() const 
{
	return getReflectionTextureCoordinatesIdField()->getValue();
}

////////////////////////////////////////////////
//	ReflectionTextureId
////////////////////////////////////////////////

SFInt32 *CommonSurfaceShaderNode::getReflectionTextureIdField() const
{
	if (isInstanceNode() == false)
		return reflectionTextureIdField;
	return (SFInt32 *)getExposedField(reflectionTextureIdExposedFieldName);
}
void CommonSurfaceShaderNode::setReflectionTextureId(int value) 
{
	getReflectionTextureIdField()->setValue(value);
}

int CommonSurfaceShaderNode::getReflectionTextureId() const 
{
	return getReflectionTextureIdField()->getValue();
}

////////////////////////////////////////////////
//	RelativeIndexOfRefraction
////////////////////////////////////////////////

SFFloat *CommonSurfaceShaderNode::getRelativeIndexOfRefractionField() const
{
	if (isInstanceNode() == false)
		return relativeIndexOfRefractionField;
	return (SFFloat *)getExposedField(relativeIndexOfRefractionExposedFieldName);
}
void CommonSurfaceShaderNode::setRelativeIndexOfRefraction(float value) 
{
	getRelativeIndexOfRefractionField()->setValue(value);
}

float CommonSurfaceShaderNode::getRelativeIndexOfRefraction() const 
{
	return getRelativeIndexOfRefractionField()->getValue();
}


////////////////////////////////////////////////
//	ShininessFactor
////////////////////////////////////////////////

SFFloat *CommonSurfaceShaderNode::getShininessFactorField() const
{
	if (isInstanceNode() == false)
		return shininessFactorField;
	return (SFFloat *)getExposedField(shininessFactorExposedFieldName);
}
void CommonSurfaceShaderNode::setShininessFactor(float value) 
{
	getShininessFactorField()->setValue(value);
}

float CommonSurfaceShaderNode::getShininessFactor() const 
{
	return getShininessFactorField()->getValue();
}

////////////////////////////////////////////////
//	ShininessTexture
////////////////////////////////////////////////

SFNode *CommonSurfaceShaderNode::getShininessTextureField() const
{
	if (isInstanceNode() == false)
		return shininessTextureField;
	return (SFNode *)getExposedField(shininessTextureExposedFieldName);
}

////////////////////////////////////////////////
//	ShininessTextureChannelMask
////////////////////////////////////////////////

SFString *CommonSurfaceShaderNode::getShininessTextureChannelMaskField() const
{
	if (isInstanceNode() == false)
		return shininessTextureChannelMaskField;
	return (SFString *)getExposedField(shininessTextureChannelMaskExposedFieldName);
}
void CommonSurfaceShaderNode::setShininessTextureChannelMask(const char *value) 
{
	getShininessTextureChannelMaskField()->setValue(value);
}

const char *CommonSurfaceShaderNode::getShininessTextureChannelMask() const 
{
	return getShininessTextureChannelMaskField()->getValue();
}

////////////////////////////////////////////////
//	ShininessTextureCoordinatesId
////////////////////////////////////////////////

SFInt32 *CommonSurfaceShaderNode::getShininessTextureCoordinatesIdField() const
{
	if (isInstanceNode() == false)
		return shininessTextureCoordinatesIdField;
	return (SFInt32 *)getExposedField(shininessTextureCoordinatesIdExposedFieldName);
}
void CommonSurfaceShaderNode::setShininessTextureCoordinatesId(int value) 
{
	getShininessTextureCoordinatesIdField()->setValue(value);
}

int CommonSurfaceShaderNode::getShininessTextureCoordinatesId() const 
{
	return getShininessTextureCoordinatesIdField()->getValue();
}

////////////////////////////////////////////////
//	ShininessTextureId
////////////////////////////////////////////////

SFInt32 *CommonSurfaceShaderNode::getShininessTextureIdField() const
{
	if (isInstanceNode() == false)
		return shininessTextureIdField;
	return (SFInt32 *)getExposedField(shininessTextureIdExposedFieldName);
}
void CommonSurfaceShaderNode::setShininessTextureId(int value) 
{
	getShininessTextureIdField()->setValue(value);
}

int CommonSurfaceShaderNode::getShininessTextureId() const 
{
	return getShininessTextureIdField()->getValue();
}


////////////////////////////////////////////////
//	SpecularFactor
////////////////////////////////////////////////

SFVec3f *CommonSurfaceShaderNode::getSpecularFactorField() const
{
	if (isInstanceNode() == false)
		return specularFactorField;
	return (SFVec3f *)getExposedField(specularFactorExposedFieldName);
}
void CommonSurfaceShaderNode::setSpecularFactor(float value[]) 
{
	getSpecularFactorField()->setValue(value);
}

void CommonSurfaceShaderNode::setSpecularFactor(float r, float g, float b) 
{
	getSpecularFactorField()->setValue(r, g, b);
}

void CommonSurfaceShaderNode::getSpecularFactor(float value[]) const 
{
	getSpecularFactorField()->getValue(value);
}

////////////////////////////////////////////////
//	SpecularTexture
////////////////////////////////////////////////

SFNode *CommonSurfaceShaderNode::getSpecularTextureField() const
{
	if (isInstanceNode() == false)
		return specularTextureField;
	return (SFNode *)getExposedField(specularTextureExposedFieldName);
}

////////////////////////////////////////////////
//	SpecularTextureChannelMask
////////////////////////////////////////////////

SFString *CommonSurfaceShaderNode::getSpecularTextureChannelMaskField() const
{
	if (isInstanceNode() == false)
		return specularTextureChannelMaskField;
	return (SFString *)getExposedField(specularTextureChannelMaskExposedFieldName);
}
void CommonSurfaceShaderNode::setSpecularTextureChannelMask(const char *value) 
{
	getSpecularTextureChannelMaskField()->setValue(value);
}

const char *CommonSurfaceShaderNode::getSpecularTextureChannelMask() const 
{
	return getSpecularTextureChannelMaskField()->getValue();
}

////////////////////////////////////////////////
//	SpecularTextureCoordinatesId
////////////////////////////////////////////////

SFInt32 *CommonSurfaceShaderNode::getSpecularTextureCoordinatesIdField() const
{
	if (isInstanceNode() == false)
		return specularTextureCoordinatesIdField;
	return (SFInt32 *)getExposedField(specularTextureCoordinatesIdExposedFieldName);
}
void CommonSurfaceShaderNode::setSpecularTextureCoordinatesId(int value) 
{
	getSpecularTextureCoordinatesIdField()->setValue(value);
}

int CommonSurfaceShaderNode::getSpecularTextureCoordinatesId() const 
{
	return getSpecularTextureCoordinatesIdField()->getValue();
}

////////////////////////////////////////////////
//	SpecularTextureId
////////////////////////////////////////////////

SFInt32 *CommonSurfaceShaderNode::getSpecularTextureIdField() const
{
	if (isInstanceNode() == false)
		return specularTextureIdField;
	return (SFInt32 *)getExposedField(specularTextureIdExposedFieldName);
}
void CommonSurfaceShaderNode::setSpecularTextureId(int value) 
{
	getSpecularTextureIdField()->setValue(value);
}

int CommonSurfaceShaderNode::getSpecularTextureId() const 
{
	return getSpecularTextureIdField()->getValue();
}


////////////////////////////////////////////////
//	TangentTextureCoordinatesId
////////////////////////////////////////////////

SFInt32 *CommonSurfaceShaderNode::getTangentTextureCoordinatesIdField() const
{
	if (isInstanceNode() == false)
		return tangentTextureCoordinatesIdField;
	return (SFInt32 *)getExposedField(tangentTextureCoordinatesIdExposedFieldName);
}
void CommonSurfaceShaderNode::setTangentTextureCoordinatesId(int value) 
{
	getTangentTextureCoordinatesIdField()->setValue(value);
}

int CommonSurfaceShaderNode::getTangentTextureCoordinatesId() const 
{
	return getTangentTextureCoordinatesIdField()->getValue();
}


////////////////////////////////////////////////
//	TransmissionFactor
////////////////////////////////////////////////

SFVec3f *CommonSurfaceShaderNode::getTransmissionFactorField() const
{
	if (isInstanceNode() == false)
		return transmissionFactorField;
	return (SFVec3f *)getExposedField(transmissionFactorExposedFieldName);
}
void CommonSurfaceShaderNode::setTransmissionFactor(float value[]) 
{
	getTransmissionFactorField()->setValue(value);
}

void CommonSurfaceShaderNode::setTransmissionFactor(float r, float g, float b) 
{
	getTransmissionFactorField()->setValue(r, g, b);
}

void CommonSurfaceShaderNode::getTransmissionFactor(float value[]) const 
{
	getTransmissionFactorField()->getValue(value);
}

////////////////////////////////////////////////
//	TransmissionTexture
////////////////////////////////////////////////

SFNode *CommonSurfaceShaderNode::getTransmissionTextureField() const
{
	if (isInstanceNode() == false)
		return transmissionTextureField;
	return (SFNode *)getExposedField(transmissionTextureExposedFieldName);
}

////////////////////////////////////////////////
//	TransmissionTextureChannelMask
////////////////////////////////////////////////

SFString *CommonSurfaceShaderNode::getTransmissionTextureChannelMaskField() const
{
	if (isInstanceNode() == false)
		return transmissionTextureChannelMaskField;
	return (SFString *)getExposedField(transmissionTextureChannelMaskExposedFieldName);
}
void CommonSurfaceShaderNode::setTransmissionTextureChannelMask(const char *value) 
{
	getTransmissionTextureChannelMaskField()->setValue(value);
}

const char *CommonSurfaceShaderNode::getTransmissionTextureChannelMask() const 
{
	return getTransmissionTextureChannelMaskField()->getValue();
}

////////////////////////////////////////////////
//	TransmissionTextureCoordinatesId
////////////////////////////////////////////////

SFInt32 *CommonSurfaceShaderNode::getTransmissionTextureCoordinatesIdField() const
{
	if (isInstanceNode() == false)
		return transmissionTextureCoordinatesIdField;
	return (SFInt32 *)getExposedField(transmissionTextureCoordinatesIdExposedFieldName);
}
void CommonSurfaceShaderNode::setTransmissionTextureCoordinatesId(int value) 
{
	getTransmissionTextureCoordinatesIdField()->setValue(value);
}

int CommonSurfaceShaderNode::getTransmissionTextureCoordinatesId() const 
{
	return getTransmissionTextureCoordinatesIdField()->getValue();
}

////////////////////////////////////////////////
//	TransmissionTextureId
////////////////////////////////////////////////

SFInt32 *CommonSurfaceShaderNode::getTransmissionTextureIdField() const
{
	if (isInstanceNode() == false)
		return transmissionTextureIdField;
	return (SFInt32 *)getExposedField(transmissionTextureIdExposedFieldName);
}
void CommonSurfaceShaderNode::setTransmissionTextureId(int value) 
{
	getTransmissionTextureIdField()->setValue(value);
}

int CommonSurfaceShaderNode::getTransmissionTextureId() const 
{
	return getTransmissionTextureIdField()->getValue();
}

////////////////////////////////////////////////
//	List
////////////////////////////////////////////////

CommonSurfaceShaderNode *CommonSurfaceShaderNode::next() const 
{
	return (CommonSurfaceShaderNode *)Node::next(getType());
}

CommonSurfaceShaderNode *CommonSurfaceShaderNode::nextTraversal() const 
{
	return (CommonSurfaceShaderNode *)Node::nextTraversalByType(getType());
}

////////////////////////////////////////////////
//	virtual functions
////////////////////////////////////////////////
	
bool CommonSurfaceShaderNode::isChildNodeType(Node *node) const
{
}

void CommonSurfaceShaderNode::initialize() 
{
}

void CommonSurfaceShaderNode::uninitialize() 
{
}

void CommonSurfaceShaderNode::update() 
{
}

////////////////////////////////////////////////
//	Infomation
////////////////////////////////////////////////

void CommonSurfaceShaderNode::outputContext(std::ostream &printStream, const char *indentString) const
{
}



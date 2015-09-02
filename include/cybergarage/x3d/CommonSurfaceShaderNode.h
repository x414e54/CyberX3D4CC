/******************************************************************
*
*	CyberX3D for C++
*
*	Copyright (C) Satoshi Konno 1996-2007
*
*	File:	CommonSurfaceShaderNode.h
*
******************************************************************/

#ifndef _CX3D_COMMONSURFACESHADERNODE_H_
#define _CX3D_COMMONSURFACESHADERNODE_H_

#include <cybergarage/x3d/VRML97Fields.h>
#include <cybergarage/x3d/Node.h>

namespace CyberX3D {

class CommonSurfaceShaderNode : public Node {

	SFFloat *alphaFactorField;
	SFNode *alphaTextureField;
	SFString *alphaTextureChannelMaskField;
	SFInt32 *alphaTextureCoordinatesIdField;
	SFInt32 *alphaTextureIdField;

	SFVec3f *ambientFactorField;
	SFNode *ambientTextureField;
	SFString *ambientTextureChannelMaskField;
	SFInt32 *ambientTextureCoordinatesIdField;
	SFInt32 *ambientTextureIdField;

	SFInt32 *binormalTextureCoordinatesIdField;

	SFVec3f *diffuseFactorField;
	SFNode *diffuseTextureField;
	SFString *diffuseTextureChannelMaskField;
	SFInt32 *diffuseTextureCoordinatesIdField;
	SFInt32 *diffuseTextureIdField;

	SFString *displacementAxisField;
	SFFloat *displacementFactorField;
	SFNode *displacementTextureField;
	SFInt32 *displacementTextureCoordinatesIdField;
	SFInt32 *displacementTextureIdField;

	SFVec3f *emissiveFactorField;
	SFNode *emissiveTextureField;
	SFString *emissiveTextureChannelMaskField;
	SFInt32 *emissiveTextureCoordinatesIdField;
	SFInt32 *emissiveTextureIdField;

	SFVec3f *environmentFactorField;
	SFNode *environmentTextureField;
	SFString *environmentTextureChannelMaskField;
	SFInt32 *environmentTextureCoordinatesIdField;
	SFInt32 *environmentTextureIdField;

	SFFloat *fresnelBlendField;
	SFBool *invertAlphaTextureField;

	SFVec3f *normalBiasField;
	SFString *normalFormatField;
	SFVec3f *normalScaleField;
	SFString *normalSpaceField;
	SFNode *normalTextureField;
	SFString *normalTextureChannelMaskField;
	SFInt32 *normalTextureCoordinatesIdField;
	SFInt32 *normalTextureIdField;

	SFVec3f *reflectionFactorField;
	SFString *reflectionTextureChannelMaskField;
	SFInt32 *reflectionTextureCoordinatesIdField;
	SFInt32 *reflectionTextureIdField;
	SFFloat *relativeIndexOfRefractionField;

	SFFloat *shininessFactorField;
	SFNode *shininessTextureField;
	SFString *shininessTextureChannelMaskField;
	SFInt32 *shininessTextureCoordinatesIdField;
	SFInt32 *shininessTextureIdField;

	SFVec3f *specularFactorField;
	SFNode *specularTextureField;
	SFString *specularTextureChannelMaskField;
	SFInt32 *specularTextureCoordinatesIdField;
	SFInt32 *specularTextureIdField;

	SFInt32 *tangentTextureCoordinatesIdField;

	SFVec3f *transmissionFactorField;
	SFNode *transmissionTextureField;
	SFString *transmissionTextureChannelMaskField;
	SFInt32 *transmissionTextureCoordinatesIdField;
	SFInt32 *transmissionTextureIdField;

public:

	CommonSurfaceShaderNode();
	virtual ~CommonSurfaceShaderNode();

	////////////////////////////////////////////////
	//	AlphaFactor
	////////////////////////////////////////////////

	SFFloat *getAlphaFactorField() const;

	void setAlphaFactor(float value);
	float getAlphaFactor() const;

	////////////////////////////////////////////////
	//	AlphaTexture
	////////////////////////////////////////////////

	SFNode *getAlphaTextureField() const;

	////////////////////////////////////////////////
	//	AlphaTextureChannelMask
	////////////////////////////////////////////////

	SFString *getAlphaTextureChannelMaskField() const;

	void setAlphaTextureChannelMask(const char *value);
	const char *getAlphaTextureChannelMask() const;

	////////////////////////////////////////////////
	//	AlphaTextureCoordinatesId
	////////////////////////////////////////////////

	SFInt32 *getAlphaTextureCoordinatesIdField() const;

	void setAlphaTextureCoordinatesId(int value);
	int getAlphaTextureCoordinatesId() const;

	////////////////////////////////////////////////
	//	AlphaTextureId
	////////////////////////////////////////////////

	SFInt32 *getAlphaTextureIdField() const;

	void setAlphaTextureId(int value);
	int getAlphaTextureId() const;


	////////////////////////////////////////////////
	//	AmbientFactor
	////////////////////////////////////////////////

	SFVec3f *getAmbientFactorField() const;

	void setAmbientFactor(float value[]);
	void setAmbientFactor(float r, float g, float b);
	void getAmbientFactor(float value[]) const;

	////////////////////////////////////////////////
	//	AmbientTexture
	////////////////////////////////////////////////

	SFNode *getAmbientTextureField() const;

	////////////////////////////////////////////////
	//	AmbientTextureChannelMask
	////////////////////////////////////////////////

	SFString *getAmbientTextureChannelMaskField() const;

	void setAmbientTextureChannelMask(const char *value);
	const char *getAmbientTextureChannelMask() const;

	////////////////////////////////////////////////
	//	AmbientTextureCoordinatesId
	////////////////////////////////////////////////

	SFInt32 *getAmbientTextureCoordinatesIdField() const;

	void setAmbientTextureCoordinatesId(int value);
	int getAmbientTextureCoordinatesId() const;

	////////////////////////////////////////////////
	//	AmbientTextureId
	////////////////////////////////////////////////

	SFInt32 *getAmbientTextureIdField() const;

	void setAmbientTextureId(int value);
	int getAmbientTextureId() const;


	////////////////////////////////////////////////
	//	BinormalTextureCoordinatesId
	////////////////////////////////////////////////

	SFInt32 *getBinormalTextureCoordinatesIdField() const;

	void setBinormalTextureCoordinatesId(int value);
	int getBinormalTextureCoordinatesId() const;


	////////////////////////////////////////////////
	//	DiffuseFactor
	////////////////////////////////////////////////

	SFVec3f *getDiffuseFactorField() const;

	void setDiffuseFactor(float value[]);
	void setDiffuseFactor(float r, float g, float b);
	void getDiffuseFactor(float value[]) const;

	////////////////////////////////////////////////
	//	DiffuseTexture
	////////////////////////////////////////////////

	SFNode *getDiffuseTextureField() const;

	////////////////////////////////////////////////
	//	DiffuseTextureChannelMask
	////////////////////////////////////////////////

	SFString *getDiffuseTextureChannelMaskField() const;

	void setDiffuseTextureChannelMask(const char *value);
	const char *getDiffuseTextureChannelMask() const;

	////////////////////////////////////////////////
	//	DiffuseTextureCoordinatesId
	////////////////////////////////////////////////

	SFInt32 *getDiffuseTextureCoordinatesIdField() const;

	void setDiffuseTextureCoordinatesId(int value);
	int getDiffuseTextureCoordinatesId() const;

	////////////////////////////////////////////////
	//	DiffuseTextureId
	////////////////////////////////////////////////

	SFInt32 *getDiffuseTextureIdField() const;

	void setDiffuseTextureId(int value);
	int getDiffuseTextureId() const;


	////////////////////////////////////////////////
	//	DisplacementAxis
	////////////////////////////////////////////////

	SFString *getDisplacementAxisField() const;

	void setDisplacementAxis(const char *value);
	const char *getDisplacementAxis() const;

	////////////////////////////////////////////////
	//	DisplacementFactor
	////////////////////////////////////////////////

	SFFloat *getDisplacementFactorField() const;

	void setDisplacementFactor(float value);
	float getDisplacementFactor() const;

	////////////////////////////////////////////////
	//	DisplacementTexture
	////////////////////////////////////////////////

	SFNode *getDisplacementTextureField() const;

	////////////////////////////////////////////////
	//	DisplacementTextureCoordinatesId
	////////////////////////////////////////////////

	SFInt32 *getDisplacementTextureCoordinatesIdField() const;

	void setDisplacementTextureCoordinatesId(int value);
	int getDisplacementTextureCoordinatesId() const;

	////////////////////////////////////////////////
	//	DisplacementTextureId
	////////////////////////////////////////////////

	SFInt32 *getDisplacementTextureIdField() const;

	void setDisplacementTextureId(int value);
	int getDisplacementTextureId() const;


	////////////////////////////////////////////////
	//	EmissiveFactor
	////////////////////////////////////////////////

	SFVec3f *getEmissiveFactorField() const;

	void setEmissiveFactor(float value[]);
	void setEmissiveFactor(float r, float g, float b);
	void getEmissiveFactor(float value[]) const;

	////////////////////////////////////////////////
	//	EmissiveTexture
	////////////////////////////////////////////////

	SFNode *getEmissiveTextureField() const;

	////////////////////////////////////////////////
	//	EmissiveTextureChannelMask
	////////////////////////////////////////////////

	SFString *getEmissiveTextureChannelMaskField() const;

	void setEmissiveTextureChannelMask(const char *value);
	const char *getEmissiveTextureChannelMask() const;

	////////////////////////////////////////////////
	//	EmissiveTextureCoordinatesId
	////////////////////////////////////////////////

	SFInt32 *getEmissiveTextureCoordinatesIdField() const;

	void setEmissiveTextureCoordinatesId(int value);
	int getEmissiveTextureCoordinatesId() const;

	////////////////////////////////////////////////
	//	EmissiveTextureId
	////////////////////////////////////////////////

	SFInt32 *getEmissiveTextureIdField() const;

	void setEmissiveTextureId(int value);
	int getEmissiveTextureId() const;


	////////////////////////////////////////////////
	//	EnvironmentFactor
	////////////////////////////////////////////////

	SFVec3f *getEnvironmentFactorField() const;

	void setEnvironmentFactor(float value[]);
	void setEnvironmentFactor(float r, float g, float b);
	void getEnvironmentFactor(float value[]) const;

	////////////////////////////////////////////////
	//	EnvironmentTexture
	////////////////////////////////////////////////

	SFNode *getEnvironmentTextureField() const;

	////////////////////////////////////////////////
	//	EnvironmentTextureChannelMask
	////////////////////////////////////////////////

	SFString *getEnvironmentTextureChannelMaskField() const;

	void setEnvironmentTextureChannelMask(const char *value);
	const char *getEnvironmentTextureChannelMask() const;

	////////////////////////////////////////////////
	//	EnvironmentTextureCoordinatesId
	////////////////////////////////////////////////

	SFInt32 *getEnvironmentTextureCoordinatesIdField() const;

	void setEnvironmentTextureCoordinatesId(int value);
	int getEnvironmentTextureCoordinatesId() const;

	////////////////////////////////////////////////
	//	EnvironmentTextureId
	////////////////////////////////////////////////

	SFInt32 *getEnvironmentTextureIdField() const;

	void setEnvironmentTextureId(int value);
	int getEnvironmentTextureId() const;


	////////////////////////////////////////////////
	//	FresnelBlend
	////////////////////////////////////////////////

	SFFloat *getFresnelBlendField() const;

	void setFresnelBlend(float value);
	float getFresnelBlend() const;

	////////////////////////////////////////////////
	//	InvertAlphaTexture
	////////////////////////////////////////////////

	SFBool *getInvertAlphaTextureField() const;


	////////////////////////////////////////////////
	//	NormalBias
	////////////////////////////////////////////////

	SFVec3f *getNormalBiasField() const;

	void setNormalBias(float value[]);
	void setNormalBias(float r, float g, float b);
	void getNormalBias(float value[]) const;

	////////////////////////////////////////////////
	//	NormalFormat
	////////////////////////////////////////////////

	SFString *getNormalFormatField() const;

	void setNormalFormat(const char *value);
	const char *getNormalFormat() const;

	////////////////////////////////////////////////
	//	NormalScale
	////////////////////////////////////////////////

	SFVec3f *getNormalScaleField() const;

	void setNormalScale(float value[]);
	void setNormalScale(float r, float g, float b);
	void getNormalScale(float value[]) const;

	////////////////////////////////////////////////
	//	NormalSpace
	////////////////////////////////////////////////

	SFString *getNormalSpaceField() const;

	void setNormalSpace(const char *value);
	const char *getNormalSpace() const;

	////////////////////////////////////////////////
	//	NormalTexture
	////////////////////////////////////////////////

	SFNode *getNormalTextureField() const;

	////////////////////////////////////////////////
	//	NormalTextureChannelMask
	////////////////////////////////////////////////

	SFString *getNormalTextureChannelMaskField() const;

	void setNormalTextureChannelMask(const char *value);
	const char *getNormalTextureChannelMask() const;

	////////////////////////////////////////////////
	//	NormalTextureCoordinatesId
	////////////////////////////////////////////////

	SFInt32 *getNormalTextureCoordinatesIdField() const;

	void setNormalTextureCoordinatesId(int value);
	int getNormalTextureCoordinatesId() const;

	////////////////////////////////////////////////
	//	NormalTextureId
	////////////////////////////////////////////////

	SFInt32 *getNormalTextureIdField() const;

	void setNormalTextureId(int value);
	int getNormalTextureId() const;


	////////////////////////////////////////////////
	//	ReflectionFactor
	////////////////////////////////////////////////

	SFVec3f *getReflectionFactorField() const;

	void setReflectionFactor(float value[]);
	void setReflectionFactor(float r, float g, float b);
	void getReflectionFactor(float value[]) const;

	////////////////////////////////////////////////
	//	ReflectionTextureChannelMask
	////////////////////////////////////////////////

	SFString *getReflectionTextureChannelMaskField() const;

	void setReflectionTextureChannelMask(const char *value);
	const char *getReflectionTextureChannelMask() const;

	////////////////////////////////////////////////
	//	ReflectionTextureCoordinatesId
	////////////////////////////////////////////////

	SFInt32 *getReflectionTextureCoordinatesIdField() const;

	void setReflectionTextureCoordinatesId(int value);
	int getReflectionTextureCoordinatesId() const;

	////////////////////////////////////////////////
	//	ReflectionTextureId
	////////////////////////////////////////////////

	SFInt32 *getReflectionTextureIdField() const;

	void setReflectionTextureId(int value);
	int getReflectionTextureId() const;

	////////////////////////////////////////////////
	//	RelativeIndexOfRefraction
	////////////////////////////////////////////////

	SFFloat *getRelativeIndexOfRefractionField() const;

	void setRelativeIndexOfRefraction(float value);
	float getRelativeIndexOfRefraction() const;


	////////////////////////////////////////////////
	//	ShininessFactor
	////////////////////////////////////////////////

	SFFloat *getShininessFactorField() const;

	void setShininessFactor(float value);
	float getShininessFactor() const;

	////////////////////////////////////////////////
	//	ShininessTexture
	////////////////////////////////////////////////

	SFNode *getShininessTextureField() const;

	////////////////////////////////////////////////
	//	ShininessTextureChannelMask
	////////////////////////////////////////////////

	SFString *getShininessTextureChannelMaskField() const;

	void setShininessTextureChannelMask(const char *value);
	const char *getShininessTextureChannelMask() const;

	////////////////////////////////////////////////
	//	ShininessTextureCoordinatesId
	////////////////////////////////////////////////

	SFInt32 *getShininessTextureCoordinatesIdField() const;

	void setShininessTextureCoordinatesId(int value);
	int getShininessTextureCoordinatesId() const;

	////////////////////////////////////////////////
	//	ShininessTextureId
	////////////////////////////////////////////////

	SFInt32 *getShininessTextureIdField() const;

	void setShininessTextureId(int value);
	int getShininessTextureId() const;


	////////////////////////////////////////////////
	//	SpecularFactor
	////////////////////////////////////////////////

	SFVec3f *getSpecularFactorField() const;

	void setSpecularFactor(float value[]);
	void setSpecularFactor(float r, float g, float b);
	void getSpecularFactor(float value[]) const;

	////////////////////////////////////////////////
	//	SpecularTexture
	////////////////////////////////////////////////

	SFNode *getSpecularTextureField() const;

	////////////////////////////////////////////////
	//	SpecularTextureChannelMask
	////////////////////////////////////////////////

	SFString *getSpecularTextureChannelMaskField() const;

	void setSpecularTextureChannelMask(const char *value);
	const char *getSpecularTextureChannelMask() const;

	////////////////////////////////////////////////
	//	SpecularTextureCoordinatesId
	////////////////////////////////////////////////

	SFInt32 *getSpecularTextureCoordinatesIdField() const;

	void setSpecularTextureCoordinatesId(int value);
	int getSpecularTextureCoordinatesId() const;

	////////////////////////////////////////////////
	//	SpecularTextureId
	////////////////////////////////////////////////

	SFInt32 *getSpecularTextureIdField() const;

	void setSpecularTextureId(int value);
	int getSpecularTextureId() const;


	////////////////////////////////////////////////
	//	TangentTextureCoordinatesId
	////////////////////////////////////////////////

	SFInt32 *getTangentTextureCoordinatesIdField() const;

	void setTangentTextureCoordinatesId(int value);
	int getTangentTextureCoordinatesId() const;


	////////////////////////////////////////////////
	//	TransmissionFactor
	////////////////////////////////////////////////

	SFVec3f *getTransmissionFactorField() const;

	void setTransmissionFactor(float value[]);
	void setTransmissionFactor(float r, float g, float b);
	void getTransmissionFactor(float value[]) const;

	////////////////////////////////////////////////
	//	TransmissionTexture
	////////////////////////////////////////////////

	SFNode *getTransmissionTextureField() const;

	////////////////////////////////////////////////
	//	TransmissionTextureChannelMask
	////////////////////////////////////////////////

	SFString *getTransmissionTextureChannelMaskField() const;

	void setTransmissionTextureChannelMask(const char *value);
	const char *getTransmissionTextureChannelMask() const;

	////////////////////////////////////////////////
	//	TransmissionTextureCoordinatesId
	////////////////////////////////////////////////

	SFInt32 *getTransmissionTextureCoordinatesIdField() const;

	void setTransmissionTextureCoordinatesId(int value);
	int getTransmissionTextureCoordinatesId() const;

	////////////////////////////////////////////////
	//	TransmissionTextureId
	////////////////////////////////////////////////

	SFInt32 *getTransmissionTextureIdField() const;

	void setTransmissionTextureId(int value);
	int getTransmissionTextureId() const;

	////////////////////////////////////////////////
	//	List
	////////////////////////////////////////////////

	CommonSurfaceShaderNode *next() const;
	CommonSurfaceShaderNode *nextTraversal() const;

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

#endif

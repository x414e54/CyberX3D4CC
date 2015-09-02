/******************************************************************
*
*   CyberX3D for C++
*
*   Copyright (C) Satoshi Konno 1996-2007
*
*   File:   OBJParser.cpp
*
******************************************************************/

#include <cybergarage/x3d/CyberX3DConfig.h>
#include <cybergarage/x3d/ParserFunc.h>
#include <cybergarage/x3d/OBJParser.h>

#ifdef CX3D_SUPPORT_OBJ

#include <algorithm>
#include <tiny_obj_loader.h>

using namespace CyberX3D;
using namespace tinyobj;

////////////////////////////////////////////////
//  OBJParser
////////////////////////////////////////////////

OBJParser::OBJParser()
{
}

////////////////////////////////////////////////
//  ~OBJParser
////////////////////////////////////////////////

OBJParser::~OBJParser()
{
}

////////////////////////////////////////////////
//  convert_path
////////////////////////////////////////////////

static std::string convert_path(std::string path, std::string base)
{
    std::replace(path.begin(), path.end(), '\\', '/');
    return base + "/" + path;
}

////////////////////////////////////////////////
//  OBJParser::load
////////////////////////////////////////////////

bool OBJParser::load(const char *objFile, void (*callbackFn)(int nLine, void *info), void *callbackFnInfo)
{
    std::vector<shape_t> shapes;
    std::vector<material_t> materials;

    std::string path = objFile;
    std::size_t pos = path.find_last_of("/");
    path = path.substr(0, pos) + "/";

    std::string error = LoadObj(shapes, materials, objFile, path.c_str());

    if (!error.empty()) {
        return false;
    }

    beginParse();

    for (std::vector<material_t>::iterator material = materials.begin();
         material != materials.end(); ++material) {
        AppearanceNode *appearanceNode = (AppearanceNode*)CreateX3DNode(APPEARANCE_NODE);
        appearanceNode->setName(material->name.c_str());
        ParserAddNode(appearanceNode);

        ParserPushNode(appearanceNode);

            CommonSurfaceShaderNode *shaderNode = (CommonSurfaceShaderNode*)CreateX3DNode(COMMONSURFACESHADER_NODE);
            shaderNode->setAmbientFactor(material->ambient);
            shaderNode->setDiffuseFactor(material->diffuse);
            shaderNode->setSpecularFactor(material->specular);
            shaderNode->setTransmissionFactor(material->transmittance);
            shaderNode->setEmissiveFactor(material->emission);
            shaderNode->setShininessFactor(material->shininess);
            shaderNode->setRelativeIndexOfRefraction(material->ior);
            shaderNode->setAlphaFactor(material->dissolve);
            // TODO illumination modes
            //material.illum
            ParserAddNode(shaderNode);

            ParserPushNode(shaderNode);

                ImageTextureNode *texture = (ImageTextureNode*)CreateX3DNode(IMAGETEXTURE_NODE);
                texture->addUrl(convert_path(material->ambient_texname, path).c_str());
                shaderNode->getAmbientTextureField()->setValue(texture);
                ParserAddNode(texture);

                texture = (ImageTextureNode*)CreateX3DNode(IMAGETEXTURE_NODE);
                texture->addUrl(convert_path(material->diffuse_texname, path).c_str());
                shaderNode->getDiffuseTextureField()->setValue(texture);
                ParserAddNode(texture);

                texture = (ImageTextureNode*)CreateX3DNode(IMAGETEXTURE_NODE);
                texture->addUrl(convert_path(material->specular_texname, path).c_str());
                shaderNode->getSpecularTextureField()->setValue(texture);
                ParserAddNode(texture);

                texture = (ImageTextureNode*)CreateX3DNode(IMAGETEXTURE_NODE);
                texture->addUrl(convert_path(material->specular_highlight_texname, path).c_str());
                shaderNode->getShininessTextureField()->setValue(texture);
                ParserAddNode(texture);

                texture = (ImageTextureNode*)CreateX3DNode(IMAGETEXTURE_NODE);
                texture->addUrl(convert_path(material->bump_texname, path).c_str());
                shaderNode->getNormalTextureField()->setValue(texture);
                ParserAddNode(texture);

                texture = (ImageTextureNode*)CreateX3DNode(IMAGETEXTURE_NODE);
                texture->addUrl(convert_path(material->alpha_texname, path).c_str());
                shaderNode->getAlphaTextureField()->setValue(texture);
                ParserAddNode(texture);

                texture = (ImageTextureNode*)CreateX3DNode(IMAGETEXTURE_NODE);
                texture->addUrl(convert_path(material->displacement_texname, path).c_str());
                shaderNode->getDisplacementTextureField()->setValue(texture);
                ParserAddNode(texture);

            ParserPopNode();

        ParserPopNode();
    }

    for (std::vector<shape_t>::iterator shape = shapes.begin(); shape != shapes.end(); ++shape) {
        ShapeNode *shapeNode = (ShapeNode*)CreateX3DNode(SHAPE_NODE);
        shapeNode->setName(shape->name.c_str());
        ParserAddNode(shapeNode);

        ParserPushNode(shapeNode);

            // TODO multiple ids!
            if (shape->mesh.material_ids.size() > 0 && shape->mesh.material_ids[0] < materials.size())
            {
                Node *referenceNode = GetParserObject()->findLastNode(materials[shape->mesh.material_ids[0]].name.c_str());
                if (referenceNode) {
                    Node* node = referenceNode->createDEFNode();
                    ParserAddNode(node);
                }
            }

            IndexedTriangleSetNode *data = (IndexedTriangleSetNode*)CreateX3DNode(INDEXEDTRIANGLESET_NODE);
            ParserAddNode(data);

            ParserPushNode(data);

                if (shape->mesh.positions.size() > 0) {
                    CoordinateNode *coordinates = (CoordinateNode*)CreateX3DNode(COORDINATE_NODE);
                    coordinates->getPointField()->setValue(shape->mesh.positions.size(), (float(*)[3])&shape->mesh.positions[0]);
                    data->getCoordField()->setValue(coordinates);
                    ParserAddNode(coordinates);
                }
                if (shape->mesh.normals.size() > 0) {
                    NormalNode *normals = (NormalNode*)CreateX3DNode(NORMAL_NODE);
                    normals->getVectorField()->setValue(shape->mesh.normals.size(), (float(*)[3])&shape->mesh.normals[0]);
                    data->getNormalField()->setValue(normals);
                    ParserAddNode(normals);
                }
                if (shape->mesh.texcoords.size() > 0) {
                    TextureCoordinateNode *texcoords = (TextureCoordinateNode*)CreateX3DNode(TEXTURECOORDINATE_NODE);
                    texcoords->getPointField()->setValue(shape->mesh.texcoords.size(), (float(*)[2])&shape->mesh.texcoords[0]);
                    data->getTexCoordField()->setValue(texcoords);
                    ParserAddNode(texcoords);
                }
                if (shape->mesh.indices.size() > 0) {
                    data->getIndexField()->setValue(shape->mesh.indices.size(), (int*)&shape->mesh.indices[0]);
                }

            ParserPopNode();

        ParserPopNode();
    }

    endParse();

    return true;
}

#endif

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

#ifdef X3D_SUPPORT_OBJ

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
//  OBJParser::load
////////////////////////////////////////////////

bool OBJParser::load(const char *objFile, void (*callbackFn)(int nLine, void *info), void *callbackFnInfo)
{
    std::vector<shape_t> shapes;
    std::vector<material_t> materials;

    LoadObj(shapes, materials, objFile);

    beginParse();

    for (std::vector<material_t>::iterator material = materials.begin();
         material != materials.end(); ++material) {
        AppearanceNode *appearanceNode = (AppearanceNode*)CreateX3DNode(APPEARANCE_NODE);
        appearanceNode->setName(material->name.c_str());
        ParserAddNode(appearanceNode);

        ParserPushNode(appearanceNode);

            // TODO add support for "CommonSurfaceShader" and do this correctly.
            MaterialNode *materialNode = (MaterialNode*)CreateX3DNode(MATERIAL_NODE);
            materialNode->setAmbientIntensity(material->ambient[0]);
            materialNode->setDiffuseColor(material->diffuse);
            materialNode->setSpecularColor(material->specular);
            //materialNode->setTransmittance(material.transmittance);
            materialNode->setEmissiveColor(material->emission);
            materialNode->setShininess(material->shininess);
            //materialNode->setIor(material.ior);
            //materialNode->setTransparency(material.dissolve);
            //materialNode->setIllum(material.illum);
            ParserAddNode(materialNode);
            
            MultiTextureNode *textures = (MultiTextureNode*)CreateX3DNode(MULTITEXTURE_NODE);
            ParserAddNode(textures);
            
            ParserPushNode(textures);
            
                ImageTextureNode *texture = (ImageTextureNode*)CreateX3DNode(IMAGETEXTURE_NODE);
                texture->addUrl(material->ambient_texname.c_str());
                //texture->setContainerField("ambientTexture");
                ParserAddNode(texture);

                texture = (ImageTextureNode*)CreateX3DNode(IMAGETEXTURE_NODE);
                texture->addUrl(material->diffuse_texname.c_str());
                //texture->setContainerField("diffuseTexture");
                ParserAddNode(texture);

                texture = (ImageTextureNode*)CreateX3DNode(IMAGETEXTURE_NODE);
                texture->addUrl(material->specular_texname.c_str());
                //texture->setContainerField("specularTexture");
                ParserAddNode(texture);

                texture = (ImageTextureNode*)CreateX3DNode(IMAGETEXTURE_NODE);
                texture->addUrl(material->normal_texname.c_str());
                //texture->setContainerField("normalTexture");
                ParserAddNode(texture);

                std::string param;
                if (!(param = material->unknown_parameter.find("disp")->second).empty()) {
                    texture = (ImageTextureNode*)CreateX3DNode(IMAGETEXTURE_NODE);
                    texture->addUrl(param.c_str());
                    ParserAddNode(texture);
                } else if (!(param = material->unknown_parameter.find("disp")->second).empty()) {
                    texture = (ImageTextureNode*)CreateX3DNode(IMAGETEXTURE_NODE);
                    texture->addUrl(param.c_str());
                    ParserAddNode(texture);
                }
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
            if (shape->mesh.positions.size() > 0) {
                CoordinateNode *coordinates = (CoordinateNode*)CreateX3DNode(COORDINATE_NODE);
                coordinates->getPointField()->setValue(shape->mesh.positions.size(), (float(*)[3])&shape->mesh.positions[0]);
                data->getCoordField()->setValue(coordinates);
            }
            if (shape->mesh.normals.size() > 0) {
                NormalNode *normals = (NormalNode*)CreateX3DNode(NORMAL_NODE);
                normals->getVectorField()->setValue(shape->mesh.normals.size(), (float(*)[3])&shape->mesh.normals[0]);
                data->getCoordField()->setValue(normals);
            }
            if (shape->mesh.texcoords.size() > 0) {
                TextureCoordinateNode *texcoords = (TextureCoordinateNode*)CreateX3DNode(TEXTURECOORDINATE_NODE);
                texcoords->getPointField()->setValue(shape->mesh.texcoords.size(), (float(*)[2])&shape->mesh.texcoords[0]);
                data->getCoordField()->setValue(texcoords);
            }
            if (shape->mesh.indices.size() > 0) {
                data->getIndexField()->setValue(shape->mesh.indices.size(), (int*)&shape->mesh.indices[0]);
            }
            ParserAddNode(data);

        ParserPopNode();
    }

    endParse();

    return true;
}

#endif

/*
  ==============================================================================

    Map.cpp
    Created: 11 Feb 2021 10:11:09pm
    Author:  omay

  ==============================================================================
*/

#include "Map.h"
#include "yaml-cpp\yaml.h"
#include "MainManager.h"

using namespace rdd;

Map::Map() 
    : _origin(0.0f, 0.0f, 0.0f)
{
    _mapImagePath = "";
    _resolution = 0.0f;
    _occupiedThresh = -1.0f;
    _freeThresh = -1.0f;
    _negate = false;
}


bool Map::loadMap(File yamlFile) {
    YAML::Node root;
    
    try {
        root = YAML::LoadFile(yamlFile.getFullPathName().toStdString());
    }
    catch (YAML::BadFile e) {
        return false;
    }

    if (!root["image"] || !root["resolution"] || !root["origin"] || root["origin"].size() != 3)
        return false;

    _mapImagePath = root["image"].as<std::string>();
    _resolution = root["resolution"].as<float>();

    YAML::Node orig = root["origin"];
    _origin.x = orig[0].as<float>();
    _origin.y = orig[1].as<float>();
    _origin.z = orig[2].as<float>();
    
    _occupiedThresh = (root["occupied_thresh"] ? root["occupied_thresh"].as<float>() : 0.65f);
    _freeThresh = (root["free_thresh"] ? root["free_thresh"].as<float>() : 0.196f);
    _negate = (root["negate"] ? (root["negate"].as<int>() != 0) : false);


    if (File::isAbsolutePath(_mapImagePath))
        _mapImage = PNGImageFormat::loadFrom(File(_mapImagePath));
    else {
        _mapImagePath = yamlFile.getParentDirectory().getFullPathName() + "/" + _mapImagePath;

        _mapImage = PNGImageFormat::loadFrom(File(_mapImagePath));
    }


    return true;
}

Image& Map::getMapImage() {
    return _mapImage;
}

float Map::getOccupiedThresh() {
    return _occupiedThresh;
}

float Map::getFreeThresh() {
    return _freeThresh;
}

bool Map::getNegate() {
    return _negate;
}
/*
  ==============================================================================

    Util.h
    Created: 10 Feb 2021 8:46:51pm
    Author:  omay

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

namespace rdd {

    class Util {

    protected:
        Util() {};

    public:
        static Point<float> polarToCartesian(float angle, float dist, bool flipY = false) {
            if (flipY)
               return Point<float>(dist * cos(angle), -dist * sin(angle));
            else
               return Point<float>(dist * cos(angle), dist * sin(angle));
        }




		// JSON functions

		static bool getIntFromJsonObject(DynamicObject* obj, const String& id, int& buffer) {

			if (obj->hasProperty(Identifier(id))) {
				auto prop = obj->getProperty(Identifier(id));
				if (prop.isInt()) {
					buffer = prop.operator int();
					return true;
				}
				else
					return false;
			}
			else
				return false;
		}


		static bool getDoubleFromJsonObject(DynamicObject* obj, const String& id, double& buffer) {

			if (obj->hasProperty(Identifier(id))) {
				auto prop = obj->getProperty(Identifier(id));
				if (prop.isDouble()) {
					buffer = prop.operator double();
					return true;
				}
				else
					return false;
			}
			else
				return false;
		}

		static bool getFloatFromJsonObject(DynamicObject* obj, const String& id, float& buffer) {

			if (obj->hasProperty(Identifier(id))) {
				auto prop = obj->getProperty(Identifier(id));
				if (prop.isDouble()) {
					buffer = (float)prop.operator double();
					return true;
				}
				else
					return false;
			}
			else
				return false;
		}


		static bool getStringFromJsonObject(DynamicObject* obj, const String& id, String& buffer) {

			if (obj->hasProperty(Identifier(id))) {
				auto prop = obj->getProperty(Identifier(id));
				if (prop.isString()) {
					buffer = prop.operator String();
					return true;
				}
				else
					return false;
			}
			else
				return false;
		}


		static DynamicObject* getChildObjectFromJsonObject(DynamicObject* obj, const String& id) {

			if (obj->hasProperty(Identifier(id))) {
				auto prop = obj->getProperty(Identifier(id));
				if (prop.isObject()) {
					return prop.getDynamicObject();
				}
				else
					return nullptr;
			}
			else
				return nullptr;

		}


		static Array<var>* getArrayFromJsonObject(DynamicObject* obj, const String& id) {

			if (obj->hasProperty(Identifier(id))) {
				auto prop = obj->getProperty(Identifier(id));
				if (prop.isArray()) {
					return prop.getArray();
				}
				else
					return nullptr;
			}
			else
				return nullptr;

		}

		static String toString(double x) {
			if (abs(x) - floor(abs(x)) != 0.0)
				return String(x);
			else
				return String(x) + String(".0");
		}

		static String toString(float x) {
			if (abs(x) - floor(abs(x)) != 0.0f)
				return String(x);
			else
				return String(x) + String(".0");
		}


    };
};
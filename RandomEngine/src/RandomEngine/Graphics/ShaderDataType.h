#pragma once

#include "RandomEngine/Core/Base.h"

enum class ShaderDataType {
	None = 0,
	Float, Vector2f, Vector3f, Vector4f, Matrix3f, Matrix4f,
	Integer, Vector2, Vector3, Vector4, Matrix3, Matrix4,
	Boolean, Struct
};

static unsigned int GetShaderDataTypeSize(ShaderDataType type) {
	switch (type)
	{
		case ShaderDataType::None:			return 0;
		case ShaderDataType::Float:			return sizeof(float);
		case ShaderDataType::Vector2f:		return 2 * sizeof(float);
		case ShaderDataType::Vector3f:		return 3 * sizeof(float);
		case ShaderDataType::Vector4f:		return 4 * sizeof(float);
		case ShaderDataType::Matrix3f:		return 3 * 3 * sizeof(float);
		case ShaderDataType::Matrix4f:		return 4 * 4 * sizeof(float);
		case ShaderDataType::Integer:		return sizeof(int);
		case ShaderDataType::Vector2:		return 2 * sizeof(int);
		case ShaderDataType::Vector3:		return 3 * sizeof(int);
		case ShaderDataType::Vector4:		return 4 * sizeof(int);
		case ShaderDataType::Matrix3:		return 3 * 3 * sizeof(int);
		case ShaderDataType::Matrix4:		return 4 * 4 * sizeof(int);
		case ShaderDataType::Boolean:		return sizeof(bool);
		case ShaderDataType::Struct:		return 0;
		default: 
			RE_CORE_ASSERT(false, "Unknown ShaderDataType value!"); 
			return 0;
	}
}

static unsigned int GetShaderDataTypeCount(ShaderDataType type) {
	switch (type)
	{
	case ShaderDataType::None:			return 0;
	case ShaderDataType::Float:			return 1;
	case ShaderDataType::Vector2f:		return 2;
	case ShaderDataType::Vector3f:		return 3;
	case ShaderDataType::Vector4f:		return 4;
	case ShaderDataType::Matrix3f:		return 3 * 3;
	case ShaderDataType::Matrix4f:		return 4 * 4;
	case ShaderDataType::Integer:		return 1;
	case ShaderDataType::Vector2:		return 2;
	case ShaderDataType::Vector3:		return 3;
	case ShaderDataType::Vector4:		return 4;
	case ShaderDataType::Matrix3:		return 3 * 3;
	case ShaderDataType::Matrix4:		return 4 * 4;
	case ShaderDataType::Boolean:		return 1;
	case ShaderDataType::Struct:		return 0;
	default:
		RE_CORE_ASSERT(false, "Unknown ShaderDataType value!");
		return 0;
	}
}

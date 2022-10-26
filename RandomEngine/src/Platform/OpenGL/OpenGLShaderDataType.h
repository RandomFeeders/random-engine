#pragma once

#include <glad/glad.h>
#include "RandomEngine/Graphics/ShaderDataType.h"

static GLenum ShaderDataTypeToOpenGLDataType(ShaderDataType type) {
	switch (type)
	{
		case ShaderDataType::None:			return GL_NONE;
		case ShaderDataType::Float:			return GL_FLOAT;
		case ShaderDataType::Vector2f:		return GL_FLOAT;
		case ShaderDataType::Vector3f:		return GL_FLOAT;
		case ShaderDataType::Vector4f:		return GL_FLOAT;
		case ShaderDataType::Matrix3f:		return GL_FLOAT;
		case ShaderDataType::Matrix4f:		return GL_FLOAT;
		case ShaderDataType::Integer:		return GL_INT;
		case ShaderDataType::Vector2:		return GL_INT;
		case ShaderDataType::Vector3:		return GL_INT;
		case ShaderDataType::Vector4:		return GL_INT;
		case ShaderDataType::Matrix3:		return GL_INT;
		case ShaderDataType::Matrix4:		return GL_INT;
		case ShaderDataType::Boolean:		return GL_BOOL;
		case ShaderDataType::Struct:		return GL_NONE;
		default:
			RE_CORE_ASSERT(false, "Unknown ShaderDataType value!");
			return GL_NONE;
	}
}

#pragma once

#include <iostream>
#include <sstream>
#include <glm/ext.hpp>
#include <glm/gtx/quaternion.hpp>

#include "RandomEngine/Core/Types.h"

namespace RandomEngine::Maths {

	struct Quaternion : public glm::quat {

		using glm::quat::qua;

		Quaternion(const glm::quat& q) : glm::quat(q) { }

		inline String ToString() const {
			std::stringstream ss;
			ss << "Quaternion { " << x << ", " << y << ", " << z << ", " << w << " }";
			return ss.str();
		}

		friend std::ostream& operator<<(std::ostream& stream, const Quaternion& quat) {
			stream << quat.ToString();
			return stream;
		}

	};

}

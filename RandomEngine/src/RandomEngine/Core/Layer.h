#pragma once

#include "RandomEngine/Events/Event.h"
#include "RandomEngine/Core/Timestep.h"

namespace RandomEngine {

	class Layer {

		protected:
			std::string _name;

		public:
			Layer(const std::string& name = "Layer");
			virtual ~Layer() = default;

			virtual void OnAttach();
			virtual void OnDetach();
			virtual void OnUpdate(Timestep timestep);
			virtual void OnGUIRender();
			virtual void OnEvent(Event& event);

			inline const std::string& GetName() const { return _name; }
	};

}

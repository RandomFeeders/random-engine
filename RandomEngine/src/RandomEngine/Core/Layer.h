#pragma once

#include "RandomEngine/Core/Types.h"
#include "RandomEngine/Events/Event.h"
#include "RandomEngine/Core/Timestep.h"

namespace RandomEngine {

	class Layer {

		protected:
			String _name;

		public:
			Layer(const String& name = "Layer");
			virtual ~Layer() = default;

			virtual void OnAttach();
			virtual void OnDetach();
			virtual void OnUpdate(Timestep timestep);
			virtual void OnGUIRender();
			virtual void OnEvent(Event& event);

			inline const String& GetName() const { return _name; }
	};

}

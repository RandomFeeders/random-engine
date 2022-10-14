#pragma once

#include "REPCH.h"

#include "Core.h"
#include "Events/Event.h"

namespace RandomEngine {

	class Layer {

		protected:
			std::string _name;

		public:
			Layer(const std::string& name = "Layer");
			virtual ~Layer();

			virtual void OnAttach();
			virtual void OnDetach();
			virtual void OnUpdate();
			virtual void OnEvent(Event& event);

			inline const std::string& GetName() const { return _name; }
	};

}
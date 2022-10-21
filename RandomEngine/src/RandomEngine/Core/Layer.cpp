#include "REPCH.h"

#include "Layer.h"

namespace RandomEngine {

	Layer::Layer(const std::string& name)
		: _name(name) { }

	void Layer::OnAttach() { }

	void Layer::OnDetach() { }

	void Layer::OnUpdate() { }

	void Layer::OnGUIRender() { }

	void Layer::OnEvent(Event& event) { }

}
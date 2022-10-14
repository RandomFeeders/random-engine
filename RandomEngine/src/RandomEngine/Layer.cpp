#include "REPCH.h"

#include "Layer.h"

namespace RandomEngine {

	Layer::Layer(const std::string& name)
		: _name(name) { }

	Layer::~Layer() { }

	void Layer::OnAttach() { }

	void Layer::OnDetach() { }

	void Layer::OnUpdate() { }

	void Layer::OnEvent(Event& event) { }

}
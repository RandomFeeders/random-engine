#include "REPCH.h"
#include "Layer.h"

namespace RandomEngine {

	Layer::Layer(const String& name)
		: _name(name) { }

	void Layer::OnAttach() { }

	void Layer::OnDetach() { }

	void Layer::OnUpdate(UpdateArgs args) { }

	void Layer::OnGUIRender() { }

	void Layer::OnEvent(Event& event) { }

}

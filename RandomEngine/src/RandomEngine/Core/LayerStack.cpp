#include "REPCH.h"
#include "LayerStack.h"

namespace RandomEngine {

	LayerStack::LayerStack() {
		_layerInsertIndex = 0;
	}

	LayerStack::~LayerStack() {
		for (Layer* layer : _layers) {
			layer->OnDetach();
			delete layer;
		}
	}

	void LayerStack::PushLayer(Layer* layer) {
		_layers.emplace(begin() + _layerInsertIndex++, layer);
	}

	void LayerStack::PushOverlay(Layer* overlay) {
		_layers.emplace_back(overlay);
	}

	void LayerStack::PopLayer(Layer* layer) {
		auto iterator = std::find(_layers.begin(), _layers.end(), layer);
		if (iterator != _layers.end()) {
			_layers.erase(iterator);
			_layerInsertIndex--;
		}
	}

	void LayerStack::PopOverlay(Layer* overlay) {
		auto iterator = std::find(_layers.begin(), _layers.end(), overlay);
		if (iterator != _layers.end()) {
			_layers.erase(iterator);
		}
	}

}

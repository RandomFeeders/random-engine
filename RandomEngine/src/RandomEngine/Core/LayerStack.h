#pragma once

#include "Layer.h"

namespace RandomEngine {

	class LayerStack {

		private:
			std::vector<Layer*> _layers;
			unsigned int _layerInsertIndex;

		public:
			LayerStack();
			~LayerStack();

			void PushLayer(Layer* layer);
			void PushOverlay(Layer* overlay);
			void PopLayer(Layer* layer);
			void PopOverlay(Layer* overlay);

			inline std::vector<Layer*>::iterator begin() { return _layers.begin(); }
			inline std::vector<Layer*>::iterator end() { return _layers.end(); }
	};

}
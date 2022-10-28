#pragma once

#include "Layer.h"

namespace RandomEngine {

	class LayerStack {

		private:
			List<Layer*> _layers;
			unsigned int _layerInsertIndex;

		public:
			LayerStack();
			~LayerStack();

			void PushLayer(Layer* layer);
			void PushOverlay(Layer* overlay);
			void PopLayer(Layer* layer);
			void PopOverlay(Layer* overlay);

			inline List<Layer*>::iterator begin() { return _layers.begin(); }
			inline List<Layer*>::iterator end() { return _layers.end(); }
	};

}

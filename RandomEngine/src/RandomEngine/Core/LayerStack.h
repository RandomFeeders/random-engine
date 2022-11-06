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

			inline Iterator<Layer*> begin() { return _layers.begin(); }
			inline Iterator<Layer*> end() { return _layers.end(); }
			inline ReverseIterator<Layer*> rbegin() { return _layers.rbegin(); }
			inline ReverseIterator<Layer*> rend() { return _layers.rend(); }

			inline ConstIterator<Layer*> begin() const { return _layers.begin(); }
			inline ConstIterator<Layer*> end() const { return _layers.end(); }
			inline ConstReverseIterator<Layer*> rbegin() const { return _layers.rbegin(); }
			inline ConstReverseIterator<Layer*> rend() const { return _layers.rend(); }
	};

}

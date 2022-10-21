#pragma once

#include <backends/imgui_impl_opengl3.h>
#include "RandomEngine/Core/Layer.h"

namespace RandomEngine {

	class GuiLayer : public Layer {

		private:
			float _time = 0.0f;

		public:
			GuiLayer();
			~GuiLayer();

			void OnAttach() override;
			void OnDetach() override;
			void OnGUIRender() override;

			void Begin();
			void End();
	};

}
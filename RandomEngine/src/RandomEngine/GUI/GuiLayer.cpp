#include "REPCH.h"

#include "RandomEngine/GuiOpenGLRenderer.h"
#include "GuiLayer.h"

namespace RandomEngine {

	GuiLayer::GuiLayer()
		: Layer("GuiLayer") {

	}

	GuiLayer::~GuiLayer() {

	}

	void GuiLayer::OnAttach() {
		ImGui::CreateContext();
		ImGui::StyleColorsDark();

		ImGuiIO& io = ImGui::GetIO();
		io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
		io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;

		io.KeyMap[ImGuiKey_Tab] = GLFW_KEY_TAB;
		io.KeyMap[ImGuiKey_LeftArrow] = GLFW_KEY_LEFT;
		io.KeyMap[ImGuiKey_RightArrow] = GLFW_KEY_RIGHT;
		io.KeyMap[ImGuiKey_UpArrow] = GLFW_KEY_UP;
		io.KeyMap[ImGuiKey_DownArrow] = GLFW_KEY_DOWN;
		io.KeyMap[ImGuiKey_PageUp] = GLFW_KEY_PAGE_UP;
		io.KeyMap[ImGuiKey_PageDown] = GLFW_KEY_PAGE_DOWN;
		io.KeyMap[ImGuiKey_Home] = GLFW_KEY_HOME;
		io.KeyMap[ImGuiKey_End] = GLFW_KEY_END;
		io.KeyMap[ImGuiKey_Insert] = GLFW_KEY_INSERT;
		io.KeyMap[ImGuiKey_Delete] = GLFW_KEY_DELETE;
		io.KeyMap[ImGuiKey_Backspace] = GLFW_KEY_BACKSPACE;
		io.KeyMap[ImGuiKey_Space] = GLFW_KEY_SPACE;
		io.KeyMap[ImGuiKey_Enter] = GLFW_KEY_ENTER;
		io.KeyMap[ImGuiKey_Escape] = GLFW_KEY_ESCAPE;

		io.KeyMap[ImGuiKey_A] = GLFW_KEY_A;
		// io.KeyMap[ImGuiKey_B] = GLFW_KEY_B;
		io.KeyMap[ImGuiKey_C] = GLFW_KEY_C;
		// io.KeyMap[ImGuiKey_D] = GLFW_KEY_D;
		// io.KeyMap[ImGuiKey_E] = GLFW_KEY_E;
		// io.KeyMap[ImGuiKey_F] = GLFW_KEY_F;
		// io.KeyMap[ImGuiKey_G] = GLFW_KEY_G;
		// io.KeyMap[ImGuiKey_H] = GLFW_KEY_H;
		// io.KeyMap[ImGuiKey_I] = GLFW_KEY_I;
		// io.KeyMap[ImGuiKey_J] = GLFW_KEY_J;
		// io.KeyMap[ImGuiKey_K] = GLFW_KEY_K;
		// io.KeyMap[ImGuiKey_L] = GLFW_KEY_L;
		// io.KeyMap[ImGuiKey_M] = GLFW_KEY_M;
		// io.KeyMap[ImGuiKey_N] = GLFW_KEY_N;
		// io.KeyMap[ImGuiKey_O] = GLFW_KEY_O;
		// io.KeyMap[ImGuiKey_P] = GLFW_KEY_P;
		// io.KeyMap[ImGuiKey_Q] = GLFW_KEY_Q;
		// io.KeyMap[ImGuiKey_R] = GLFW_KEY_R;
		// io.KeyMap[ImGuiKey_S] = GLFW_KEY_S;
		// io.KeyMap[ImGuiKey_T] = GLFW_KEY_T;
		// io.KeyMap[ImGuiKey_U] = GLFW_KEY_U;
		io.KeyMap[ImGuiKey_V] = GLFW_KEY_V;
		// io.KeyMap[ImGuiKey_W] = GLFW_KEY_W;
		io.KeyMap[ImGuiKey_X] = GLFW_KEY_X;
		io.KeyMap[ImGuiKey_Y] = GLFW_KEY_Y;
		io.KeyMap[ImGuiKey_Z] = GLFW_KEY_Z;

		ImGui_ImplOpenGL3_Init("#version 410");
	}

	void GuiLayer::OnDetach() {

	}

	void GuiLayer::OnUpdate() {
		ImGuiIO& io = ImGui::GetIO();
		Application& app = Application::GetInstance();
		io.DisplaySize = ImVec2(app.GetWindow().GetWidth(), app.GetWindow().GetHeight());

		float time = glfwGetTime();
		io.DeltaTime = _time > 0.0f ? (time - _time) : (1.0f / 60.0f);
		_time = time;

		ImGui_ImplOpenGL3_NewFrame();
		ImGui::NewFrame();

		static bool show = true;
		ImGui::ShowDemoWindow(&show);

		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	}

	void GuiLayer::OnEvent(Event& event) {
		EventDispatcher dispatcher(event);

		dispatcher.Dispatch<MouseButtonPressedEvent>(BIND_EVENT_FN(GuiLayer::OnMouseButtonPressed));
		dispatcher.Dispatch<MouseButtonReleasedEvent>(BIND_EVENT_FN(GuiLayer::OnMouseButtonReleased));
		dispatcher.Dispatch<MouseMovedEvent>(BIND_EVENT_FN(GuiLayer::OnMouseMove));
		dispatcher.Dispatch<MouseScrolledEvent>(BIND_EVENT_FN(GuiLayer::OnMouseScrolled));

		dispatcher.Dispatch<KeyPressedEvent>(BIND_EVENT_FN(GuiLayer::OnKeyPressed));
		dispatcher.Dispatch<KeyReleasedEvent>(BIND_EVENT_FN(GuiLayer::OnKeyReleased));
		dispatcher.Dispatch<KeyTypedEvent>(BIND_EVENT_FN(GuiLayer::OnKeyTyped));

		dispatcher.Dispatch<WindowResizeEvent>(BIND_EVENT_FN(GuiLayer::OnWindowResize));
	}

	bool GuiLayer::OnMouseButtonPressed(MouseButtonPressedEvent& e) {
		ImGuiIO& io = ImGui::GetIO();
		io.MouseDown[e.GetMouseButton()] = true;

		return false;
	}

	bool GuiLayer::OnMouseButtonReleased(MouseButtonReleasedEvent& e) {
		ImGuiIO& io = ImGui::GetIO();
		io.MouseDown[e.GetMouseButton()] = false;

		return false;
	}

	bool GuiLayer::OnMouseMove(MouseMovedEvent& e) {
		ImGuiIO& io = ImGui::GetIO();
		io.MousePos = ImVec2(e.GetX(), e.GetY());

		return false;
	}

	bool GuiLayer::OnMouseScrolled(MouseScrolledEvent& e) {
		ImGuiIO& io = ImGui::GetIO();
		io.MouseWheelH += e.GetXOffset();
		io.MouseWheel += e.GetYOffset();

		return false;
	}

	bool GuiLayer::OnKeyPressed(KeyPressedEvent& e) {
		ImGuiIO& io = ImGui::GetIO();
		io.KeysDown[e.GetKeyCode()] = true;
		io.KeyCtrl = io.KeysDown[GLFW_KEY_LEFT_CONTROL] || io.KeysDown[GLFW_KEY_RIGHT_CONTROL];
		io.KeyShift = io.KeysDown[GLFW_KEY_LEFT_SHIFT] || io.KeysDown[GLFW_KEY_RIGHT_SHIFT];
		io.KeyAlt = io.KeysDown[GLFW_KEY_LEFT_ALT] || io.KeysDown[GLFW_KEY_RIGHT_ALT];
		io.KeySuper = io.KeysDown[GLFW_KEY_LEFT_SUPER] || io.KeysDown[GLFW_KEY_RIGHT_SUPER];

		return false;
	}

	bool GuiLayer::OnKeyReleased(KeyReleasedEvent& e) {
		ImGuiIO& io = ImGui::GetIO();
		io.KeysDown[e.GetKeyCode()] = false;

		return false;
	}

	bool GuiLayer::OnKeyTyped(KeyTypedEvent& e) {
		ImGuiIO& io = ImGui::GetIO();
		unsigned int c = e.GetKeyCode();
		if (c > 0 && c < 0x10000)
			io.AddInputCharacter(c);

		return false;
	}

	bool GuiLayer::OnWindowResize(WindowResizeEvent& e) {
		ImGuiIO& io = ImGui::GetIO();
		io.DisplaySize = ImVec2(e.GetWidth(), e.GetHeight());
		io.DisplayFramebufferScale = ImVec2(1.0f, 1.0f);
		glViewport(0, 0, e.GetWidth(), e.GetHeight());

		return false;
	}

}
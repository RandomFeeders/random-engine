#include "REPCH.h"
#include "GuiLayer.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <imgui.h>
#include <backends/imgui_impl_glfw.h>
#include <backends/imgui_impl_opengl3.h>

#include "RandomEngine/Core/Application.h"

namespace RandomEngine {

	GuiLayer::GuiLayer()
		: Layer("GuiLayer") { }

	GuiLayer::~GuiLayer() { }

	void GuiLayer::OnAttach() {
		// Base ImGui initialization
		IMGUI_CHECKVERSION();
		ImGui::CreateContext();
		ImGuiIO& io = ImGui::GetIO(); (void)io;
		io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;		// Enable keyboard controls
		// io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;		// Enable keyboard controls
		io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;			// Enable docking
		io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;			// Enable multi-viewport / platform windows
		// io.ConfigFlags |= ImGuiConfigFlags_ViewportsNoTaskBarIcons;
		// io.ConfigFlags |= ImGuiConfigFlags_ViewportsNoMerge;

		// Setup ImGui Style
		ImGui::StyleColorsDark();
		ImGuiStyle& style = ImGui::GetStyle();
		if (HAS_FLAG(io.ConfigFlags, ImGuiConfigFlags_ViewportsEnable)) {
			style.WindowRounding = 0.0f;
			style.Colors[ImGuiCol_WindowBg].w = 1.0f;
		}

		// Setup platform/renderer binding
		Application& app = Application::GetInstance();
		auto window = static_cast<GLFWwindow*>(app.GetWindow().GetNativeWindow());

		ImGui_ImplGlfw_InitForOpenGL(window, true);
		ImGui_ImplOpenGL3_Init("#version 410");
	}

	void GuiLayer::OnDetach() {
		ImGui_ImplOpenGL3_Shutdown();
		ImGui_ImplGlfw_Shutdown();
		ImGui::DestroyContext();
	}

	void GuiLayer::OnGUIRender() {
		static bool show = true;
		ImGui::ShowDemoWindow(&show);
	}

	void GuiLayer::Begin() {
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();
	}

	void GuiLayer::End() {
		Application& app = Application::GetInstance();
		ImGuiIO& io = ImGui::GetIO();
		io.DisplaySize = ImVec2((float)app.GetWindow().GetWidth(), (float)app.GetWindow().GetHeight());

		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

		if (HAS_FLAG(io.ConfigFlags, ImGuiConfigFlags_ViewportsEnable)) {
			auto backupContext = glfwGetCurrentContext();
			ImGui::UpdatePlatformWindows();
			ImGui::RenderPlatformWindowsDefault();
			glfwMakeContextCurrent(backupContext);
		}
	}

}

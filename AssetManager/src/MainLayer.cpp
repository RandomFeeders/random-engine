#include "MainLayer.h"

namespace RandomEngine::AssetManager {

	MainLayer::MainLayer() {
		auto& app = Application::GetInstance();
		auto& window = app.GetWindow();
		_windowSize = RandomEngine::Maths::Vector2ui(window.GetWidth(), window.GetHeight());
		_data = CreateScope<WindowData>();
		_fileWindowData = CreateScope<FileWindowData>();
	}

	void MainLayer::Close() {
		_isWindowOpened = false;
	}

	void MainLayer::OnUpdate(RandomEngine::UpdateArgs args) {
		Graphics::RenderCommands::SetClearColor({ 0.1f, 0.1f, 0.1f, 1.0f });
		Graphics::RenderCommands::Clear();

		if (!_isWindowOpened) {
			auto& app = Application::GetInstance();
			app.Close();
			return;
		}

		HandleMenuButton(&_data->FileNew, [&](MainLayer& layer) {
			OpenFileDialog("New");
		});

		HandleMenuButton(&_data->FileOpen, [&](MainLayer& layer) {

		});

		HandleMenuButton(&_data->FileSave, [&](MainLayer& layer) {

		});

		HandleMenuButton(&_data->FileSaveAs, [&](MainLayer& layer) {

		});

		HandleMenuButton(&_data->FileClose, [&](MainLayer& layer) {

		});

		HandleMenuButton(&_data->FileExit, [&](MainLayer& layer) {
			layer.Close();
		});
	}

	void MainLayer::HandleMenuButton(bool* trigger, auto action) {
		if (!*trigger) return;
		*trigger = false;
		action(*this);
	}

	void MainLayer::OnEvent(RandomEngine::Event& e) {

	}

	void MainLayer::RenderMenu() {
		auto viewport = ImGui::GetMainViewport();
		ImGui::SetNextWindowPos(viewport->WorkPos);
		ImGui::SetNextWindowSize(viewport->WorkSize);
		ImGui::SetNextWindowViewport(viewport->ID);

		ImGui::Begin(
			"Asset Manager",
			&_isWindowOpened,
			ImGuiWindowFlags_MenuBar |
			ImGuiWindowFlags_NoCollapse |
			ImGuiWindowFlags_NoSavedSettings |
			ImGuiWindowFlags_NoResize |
			//ImGuiWindowFlags_NoMove |
			ImGuiWindowFlags_NoTitleBar
		);

		if (ImGui::BeginMenuBar()) {
			if (ImGui::BeginMenu("File")) {
				ImGui::MenuItem(RE_ICON_FILE " New", "Ctrl+N", &_data->FileNew);
				ImGui::MenuItem(RE_ICON_FOLDER_OPEN " Open...", "Ctrl+O", &_data->FileOpen);
				ImGui::MenuItem(RE_ICON_FLOPPY_DISK " Save", "Ctrl+S", &_data->FileSave, _data->FileCreated || (_data->FileOpened && !_data->FileSaved));
				ImGui::MenuItem(RE_ICON_FLOPPY_DISK " Save As...", "Ctrl+Alt+S", &_data->FileSaveAs, _data->FileCreated || (_data->FileOpened && !_data->FileSaved));
				ImGui::MenuItem(RE_ICON_FOLDER_CLOSED " Close", "Ctrl+W", &_data->FileClose, _data->FileOpened);
				ImGui::Separator();
				ImGui::MenuItem(RE_ICON_DOOR_OPEN " Sair", "Alt+F4", &_data->FileExit);
				ImGui::EndMenu();
			}

			ImGui::EndMenuBar();
		}


		ImGui::End();
	}

	void MainLayer::RenderFileDialog() {
		if (!_fileWindowData->Opened) return;

		auto& io = ImGui::GetIO();
		auto size = ImVec2(800, 600);
		ImGui::SetNextWindowPos(
			ImVec2(
				io.DisplaySize.x,
				io.DisplaySize.y
				// 0.0f, 0.0f// (io.DisplaySize.x - size.x),
				// (io.DisplaySize.y - size.y)
			), 
			ImGuiCond_Always, 
			ImVec2(0.5f, 0.5f)
		);
		ImGui::SetNextWindowSize(size);

		ImGui::OpenPopup(_fileWindowData->WindowTitle.c_str());
		if (ImGui::BeginPopupModal(
				_fileWindowData->WindowTitle.c_str(),
				&_fileWindowData->Opened,
				ImGuiWindowFlags_NoScrollbar |
				ImGuiWindowFlags_NoScrollWithMouse
			)) {

			ImGui::EndPopup();
		}
	}

	void MainLayer::RenderDebug() {
		ImGui::SetNextWindowPos(ImVec2(0, 0));

		ImGui::Begin("Debug");

		ImGui::Text("File Opened:  ");
		ImGui::SameLine();
		ImGui::Text(_data->FileOpened ? "TRUE" : "FALSE");

		ImGui::Text("File Saved:   ");
		ImGui::SameLine();
		ImGui::Text(_data->FileSaved ? "TRUE" : "FALSE");

		ImGui::Text("File Created: ");
		ImGui::SameLine();
		ImGui::Text(_data->FileCreated ? "TRUE" : "FALSE");

		ImGui::Separator();

		ImGui::Text("File Window Title:  ");
		ImGui::SameLine();
		ImGui::Text(_fileWindowData->WindowTitle.c_str());

		ImGui::Text("File Window Path:    ");
		ImGui::SameLine();
		ImGui::Text(_fileWindowData->FilePath.c_str());

		ImGui::Text("File Window Opened:    ");
		ImGui::SameLine();
		ImGui::Text(_fileWindowData->Opened ? "TRUE" : "FALSE");

		ImGui::Separator();

		auto& io = ImGui::GetIO();

		ImGui::Text("Window:    ");
		ImGui::SameLine();
		ImGui::Text(std::to_string(io.DisplaySize.x).c_str());
		ImGui::SameLine();
		ImGui::Text("  ");
		ImGui::SameLine();
		ImGui::Text(std::to_string(io.DisplaySize.y).c_str());

		ImGui::End();
	}

	void MainLayer::OnGUIRender() {
		RenderMenu();
		RenderFileDialog();
		RenderDebug();
	}

	void MainLayer::OpenFileDialog(String title) {
		_fileWindowData->WindowTitle = title;
		_fileWindowData->Opened = true;
	}

}

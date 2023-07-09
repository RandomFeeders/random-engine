#pragma once

#include <RandomEngine.h>

namespace RandomEngine::AssetManager {

	class MainLayer : public RandomEngine::Layer {

		private:
			struct WindowData {
				bool FileNew = false;
				bool FileOpen = false;
				bool FileSave = false;
				bool FileSaveAs = false;
				bool FileClose = false;
				bool FileExit = false;

				bool FileOpened = false;
				bool FileSaved = false;
				bool FileCreated = false;
				Scope<IO::File> File;
			};

			struct FileWindowData {
				String WindowTitle;
				String FilePath;
				bool Opened;
			};

			bool _isWindowOpened = true;
			Scope<WindowData> _data;
			Scope<FileWindowData> _fileWindowData;
			RandomEngine::Maths::Vector2ui _windowSize;

			void RenderMenu();
			void RenderFileDialog();
			void RenderDebug();
			void HandleMenuButton(bool* trigger, auto action);

		public:
			MainLayer();

			void OnUpdate(RandomEngine::UpdateArgs args) override;
			void OnEvent(RandomEngine::Event& e) override;
			void OnGUIRender() override;

			void OpenFileDialog(String title);
			void Close();
	};

}



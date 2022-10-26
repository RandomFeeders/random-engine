#pragma once

#include <string>
#include <fstream>

namespace Sandbox::FileUtils {

	static char* ReadFile(const char* filePath) {
		FILE* file = fopen(filePath, "rt");
		fseek(file, 0, SEEK_END);
		unsigned long lenght = ftell(file);
		char* data = new char[lenght + 1];
		memset(data, 0, lenght + 1);
		fseek(file, 0, SEEK_SET);
		fread(data, 1, lenght, file);
		fclose(file);
		data[lenght] = '\0';
		return data;
	}

}

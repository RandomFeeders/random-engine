#include "REPCH.h"
#include "Parse.h"

#include "RandomEngine/Core/Base.h"

short ParseShort(String value) {
	int i = std::stoi(value);
	RE_CORE_ASSERT(i > SHRT_MAX || i < SHRT_MIN, "Value out of bounds of a short");
	return (short)i;
}

ushort ParseUShort(String value) {
	uint i = std::stoul(value);
	RE_CORE_ASSERT(i > USHRT_MAX || i < 0, "Value out of bounds of a short");
	return (ushort)i;
}

int ParseInt(String value) { return std::stoi(value); }
uint ParseUInt(String value) { return std::stoul(value); }
long ParseLong(String value) { return std::stol(value); }
ulong ParseULong(String value) { return std::stoul(value); }
llong ParseLLong(String value) { return std::stoll(value); }
ullong ParseULLong(String value) { return std::stoull(value); }
float ParseFloat(String value) { return std::stof(value); }
double ParseDouble(String value) { return std::stod(value); }

template<typename T>
bool TryParse(String value, T* result, auto parseFunc, T defaultValue) {
	try {
		*result = parseFunc(value);
		return true;
	}
	catch (...) {
		*result = defaultValue;
		return false;
	}
}

bool TryParseShort(String value, short* result) {
	return TryParse(value, result, [](String v) { return ParseShort(v); }, (short)0);
}

bool TryParseUShort(String value, ushort* result) {
	return TryParse(value, result, [](String v) { return ParseUShort(v); }, (ushort)0);
}

bool TryParseInt(String value, int* result) {
	return TryParse(value, result, [](String v) { return ParseInt(v); }, 0);
}

bool TryParseUInt(String value, uint* result) {
	return TryParse(value, result, [](String v) { return ParseUInt(v); }, 0u);
}

bool TryParseLong(String value, long* result) {
	return TryParse(value, result, [](String v) { return ParseLong(v); }, 0l);
}

bool TryParseULong(String value, ulong* result) {
	return TryParse(value, result, [](String v) { return ParseULong(v); }, 0ul);
}

bool TryParseLLong(String value, llong* result) {
	return TryParse(value, result, [](String v) { return ParseLLong(v); }, 0ll);
}

bool TryParseULLong(String value, ullong* result) {
	return TryParse(value, result, [](String v) { return ParseULLong(v); }, 0ull);
}

bool TryParseFloat(String value, float* result) {
	return TryParse(value, result, [](String v) { return ParseFloat(v); }, 0.0f);
}

bool TryParseDouble(String value, double* result) {
	return TryParse(value, result, [](String v) { return ParseDouble(v); }, 0.0);
}

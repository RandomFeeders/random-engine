#pragma once

#include "RandomEngine/Core/Base.h"
#include "RandomEngine/Core/Types.h"

namespace {

	short ParseShort(String value);
	ushort ParseUShort(String value);
	int ParseInt(String value);
	uint ParseUInt(String value);
	long ParseLong(String value);
	ulong ParseULong(String value);
	llong ParseLLong(String value);
	ullong ParseULLong(String value);
	float ParseFloat(String value);
	double ParseDouble(String value);

	bool TryParseShort(String value, short* result);
	bool TryParseUShort(String value, ushort* result);
	bool TryParseInt(String value, int* result);
	bool TryParseUInt(String value, uint* result);
	bool TryParseLong(String value, long* result);
	bool TryParseULong(String value, ulong* result);
	bool TryParseLLong(String value, llong* result);
	bool TryParseULLong(String value, ullong* result);
	bool TryParseFloat(String value, float* result);
	bool TryParseDouble(String value, double* result);

}

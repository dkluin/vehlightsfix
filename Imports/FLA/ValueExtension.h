#pragma once

template <typename from, typename to, to(*GetFunc)(const void* basicPtr), void SetFunc(void* basicPtr, to ID)>
class CValueExtension
{
	from m_Value;

public:
	// Constructor
	CValueExtension() {}

	// Returns ID
	to Get() const
	{
		return GetFunc(&m_Value);
	}

	// Sets ID
	void Set(to ID)
	{
		SetFunc(&m_Value, ID);
	}
};

// CValueExtensionInt
template <typename from, typename to, to(*GetFunc)(const void* basicPtr), void SetFunc(void* basicPtr, to ID)> 
class CValueExtensionNum : public CValueExtension<from, to, GetFunc, SetFunc>
{
public:
	// Assignnment operators
	CValueExtensionNum& operator=(to dwModelIndex) { Set(dwModelIndex); return *this; }
	CValueExtensionNum& operator=(const CValueExtensionNum& dwModelIndex) { Set(dwModelIndex.Get()); return *this; }

	// Comparison operators
	bool operator==(to dwModelIndex) { return Get() == dwModelIndex; }
	bool operator==(const CValueExtension& dwModelIndex) { return Get() == dwModelIndex.Get(); }
	bool operator>=(to dwModelIndex) { return Get() >= dwModelIndex; }
	bool operator>=(const CValueExtension& dwModelIndex) { return Get() >= dwModelIndex.Get(); }
	bool operator<=(to dwModelIndex) { return Get() <= dwModelIndex; }
	bool operator<=(const CValueExtension& dwModelIndex) { return Get() <= dwModelIndex.Get(); }
	bool operator>(to dwModelIndex) { return Get() > dwModelIndex; }
	bool operator>(const CValueExtension& dwModelIndex) { return Get() > dwModelIndex.Get(); }
	bool operator<(to dwModelIndex) { return Get() < dwModelIndex; }
	bool operator<(const CValueExtension& dwModelIndex) { return Get() < dwModelIndex.Get(); }
	bool operator!=(to dwModelIndex) { return Get() != dwModelIndex; }
	bool operator!=(const CValueExtension& dwModelIndex) { return Get() != dwModelIndex.Get(); }

	// Conversion operators
	operator to() { return Get(); }
};
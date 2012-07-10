#pragma once

#include <msclr\marshal.h>

using namespace msclr::interop;

ref class StringHelper
{
public:
	static const char *ToNative(System::String ^string)
	{
		if(!m_context)
			m_context = gcnew marshal_context();

		return m_context->marshal_as<const char*>(string);
	}

private:
	static marshal_context ^m_context;
};
#include "stdafx.h"
#include "NodeAttribute.h"

using namespace ManagedFbx;

NodeAttribute::NodeAttribute(FbxNodeAttribute *nativeAttr)
{
	m_nativeAttribute = nativeAttr;
}

NodeAttributeType NodeAttribute::Type::get()
{
	return (NodeAttributeType)m_nativeAttribute->GetAttributeType();
}

string ^NodeAttribute::Name::get()
{
	return gcnew string(m_nativeAttribute->GetName());
}

void NodeAttribute::Name::set(string ^value)
{
	m_nativeAttribute->SetName(StringHelper::ToNative(value));
}

#include "stdafx.h"
#include "SceneNodeAttribute.h"

using namespace ManagedFbx;

SceneNodeAttribute::SceneNodeAttribute(FbxNodeAttribute *nativeAttr)
{
	m_nativeAttribute = nativeAttr;
}

NodeAttributeType^ SceneNodeAttribute::AttributeType::get()
{
	return (NodeAttributeType)m_nativeAttribute->GetAttributeType();
}

string ^SceneNodeAttribute::Name::get()
{
	return gcnew string(m_nativeAttribute->GetName());
}

void SceneNodeAttribute::Name::set(string ^value)
{
	m_nativeAttribute->SetName(StringHelper::ToNative(value));
}

#include "stdafx.h"
#include "SceneNode.h"

using namespace ManagedFbx;

SceneNode::SceneNode(FbxNode *node)
{
	m_nativeNode = node;

	m_children = gcnew List<SceneNode^>();
	m_attributes = gcnew List<NodeAttribute^>();

	for(int i = 0; i < m_nativeNode->GetChildCount(); i++)
	{
		auto sub = m_nativeNode->GetChild(i);
		m_children->Add(gcnew SceneNode(sub));
	}

	for(int i = 0; i < m_nativeNode->GetNodeAttributeCount(); i++)
	{
		auto attr = m_nativeNode->GetNodeAttributeByIndex(i);
		m_attributes->Add(gcnew NodeAttribute(attr));
	}
}

IEnumerable<SceneNode^>^ SceneNode::ChildNodes::get()
{
	return m_children->AsReadOnly();
}

IEnumerable<NodeAttribute^>^ SceneNode::Attributes::get()
{
	return m_attributes->AsReadOnly();
}

string ^SceneNode::Name::get()
{
	return gcnew string(m_nativeNode->GetName());
}

void SceneNode::Name::set(string ^value)
{
	m_nativeNode->SetName(StringHelper::ToNative(value));
}

void SceneNode::AddChild(SceneNode ^node)
{
	m_nativeNode->AddChild(node->m_nativeNode);
	m_children->Add(node);
}

void SceneNode::Position::set(Vector3 value)
{
	m_nativeNode->LclTranslation.Set(value);
}

void SceneNode::Rotation::set(Vector3 value)
{
	m_nativeNode->LclRotation.Set(value);
}

void SceneNode::Scale::set(Vector3 value)
{
	m_nativeNode->LclScaling.Set(value);
}

Vector3 SceneNode::Position::get()
{
	return Vector3(m_nativeNode->LclTranslation.Get());
}

Vector3 SceneNode::Rotation::get()
{
	return Vector3(m_nativeNode->LclRotation.Get());
}

Vector3 SceneNode::Scale::get()
{
	return Vector3(m_nativeNode->LclScaling.Get());
}

Mesh ^SceneNode::Model::get()
{
	return gcnew Mesh(m_nativeNode->GetMesh());
}
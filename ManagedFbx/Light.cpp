#include "stdafx.h"
#include "Light.h"

using namespace ManagedFbx;

Light::Light(FbxLight *nativeLight)
{
	m_nativeLight = nativeLight;
}

LightType Light::Type::get()
{
	return (LightType)m_nativeLight->LightType.Get();
}

Vector3 Light::Colour::get()
{
	return Vector3(m_nativeLight->Color.Get());
}
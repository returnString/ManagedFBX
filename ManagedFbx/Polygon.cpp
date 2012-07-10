#include "stdafx.h"
#include "Polygon.h"

using namespace ManagedFbx;

array<int> ^Polygon::Indices::get()
{
	return m_indices;
}

void Polygon::Indices::set(array<int> ^value)
{
	m_indices = value;
}
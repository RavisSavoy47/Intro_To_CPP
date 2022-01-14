#include "Component.h"


Component::Component()
{
	m_owner = nullptr;
	m_name = nullptr;
	m_started = false;
}

Component::Component(const char* name)
{
	m_name = name;
}

Component::~Component()
{
}

/// <summary>
/// Assigns the owner of the actor
/// </summary>
/// <param name="owner"></param>
void Component::assignOwner(Actor* owner)
{
	if (getOwner())
		return;

	m_owner = owner;
}

/// <summary>
/// Set to be destoryed
/// </summary>
void Component::onDestroy()
{
}


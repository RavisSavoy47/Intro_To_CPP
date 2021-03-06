#include "Actor.h"
#include "Transform2D.h"
#include <string.h>
#include "Collider.h"
#include "Component.h"

Actor::Actor()
{
    m_transform = new Transform2D(this);
}

Actor::~Actor()
{
    delete m_transform;
}

Actor::Actor(float x, float y, const char* name = "Actor")
{
    //Initialze default values
    m_transform = new Transform2D(this);
    m_transform->setLocalPosition({ x,y });
    m_name = name;
}



void Actor::onCollision(Actor* other)
{
}

Component* Actor::addComponent(Component* component)
{
    //Return null if this component has an owner already
    Actor* owner = component->getOwner();
    if (owner)
        return nullptr;

    component->assignOwner(this);

    //Create a new array with a size one greater than our old array
    Component** appendedArray = new Component* [m_componentCount + 1];
    //Copy the values from the old array to the new array
    for (int i = 0; i < m_componentCount; i++)
    {
        appendedArray[i] = m_components[i];
    }

    //Set the last value in the new array to be the actor we want to add
    appendedArray[m_componentCount] = component;

    if (m_componentCount > 1)
        delete[] m_components;
    else if (m_componentCount == 1)
        delete m_components;

    //Set old array to hold the values of the new array
    m_components = appendedArray;
    m_componentCount++;

    return component;
}

bool Actor::removeComponent(Component* component)
{
    //Check to see if the actor was null
    if (!component)
        return false;

    bool componentRemoved = false;
    //Create a new array with a size one greater than our old array
    Component** newArray = new Component* [m_componentCount - 1];
    //Create variable to access newcomponent index
    int j = 0;
    //Copy the values from the old array to the new array
    for (int i = 0; i < m_componentCount; i++)
    {
        if (component != m_components[i])
        {
            newArray[j] = m_components[i];
            j++;
        }
        else
        {
            componentRemoved = true;
        }
    }

    if (componentRemoved)
    {
        delete[] m_components;
        //Set the old array to the new array
        m_components = newArray;
        m_componentCount--;
        delete component;
    }
    else
        delete[] newArray;

    //Return whether or not the removal was successful
    return componentRemoved;
}

bool Actor::removeComponent(const char* name)
{
    //Check to see if the component Name was null
    if (!name)
    {
        return false;
    }

    bool componentRemoved = false;
    Component* componentToDelete = nullptr;

    //Create a new component with a size one less than our old component
    Component** newComponent = new Component * [m_componentCount - 1];
    //Create variable to access component index
    int j = 0;
    //Copy values from the old component to the new component
    for (int i = 0; i < m_componentCount; i++)
    {
        if (strcmp(m_components[i]->getName(), name) == 0)
        {
            newComponent[j] = m_components[i];
            j++;
        }
        else
        {
            componentRemoved = true;
            componentToDelete = m_components[i];
        }
    }
    //Set the old component to the new component
    if (componentRemoved)
    {
        m_components = newComponent;
        m_componentCount--;
        delete componentToDelete;
    }
    //Return whether or not the removal was successful
    return componentRemoved;
}

Component* Actor::getComponet(const char* componentName)
{
    //Iterates through the component array
    for (int i = 0; i < m_componentCount; i++)
    {
        //Return the component if the name is the same as the current component
        if (strcmp(m_components[i]->getName(), componentName) == 0)
            return m_components[i];
    }

    //Returns null if it cant find a match
    return nullptr;
}

void Actor::start()
{
    m_started = true;
}

void Actor::update(float deltaTime)
{
    for (int i = 0; i < m_componentCount; i++)
    {
        if (m_components[i]->getStarted())
            m_components[i]->start();

        m_components[i]->update(deltaTime);
    }
}

void Actor::draw()
{
    for (int i = 0; i < m_componentCount; i++)
        m_components[i]->draw();
    
}

void Actor::end()
{
    m_started = false;

    for (int i = 0; i < m_componentCount; i++)
        m_components[i]->end();
}

void Actor::onDestroy()
{
    for (int i = 0; i < m_componentCount; i++)
        m_components[i]->onDestroy();

    //Removes this actor from its parent if it has one
    if (getTransform()->getParent())
        getTransform()->getParent()->removeChild(getTransform());
}

bool Actor::checkForCollision(Actor* other)
{
    for (int i = 0; i < m_componentCount; i++)
        m_components[i]->onCollision(other);

    return other;
}
#include "stdafx.h"
#include "Object.h"

Object::Object()
{
    //Empty!
}

Object::~Object()
{
    //Empty!
}


void Object::setId(int i)
{
    id = i;
}
    
const int Object::getId() const
{
    return id;
}
    
void Object::imprimir()
{

}
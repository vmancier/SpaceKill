#include <iostream>
#include "Shot.hpp"

using namespace std;

Shot::Shot()
{

}

Shot::Shot(int style)
{
    switch(style)
    {
    case 1:
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    }
}

int Shot::getStyle()
{
    return m_style;
}

int Shot::getDamages()
{
    return m_damageP;
}

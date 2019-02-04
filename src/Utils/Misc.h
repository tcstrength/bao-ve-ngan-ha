#ifndef MISC_H
#define MISC_H

#include <iostream>
#include <assert.h>
#include <cmath>
#include <vector>
#include <map>
#include <list>
#include <glm/glm.hpp>

namespace Misc {

    const float PI = static_cast<float>(std::acos(-1));

    const float RAD_UNIT = PI/180;

    ///////////////////////////////////
    /// \brief randlf random between -1..1
    /// \return double
    ///
    double randlf();

    ///////////////////////////////////
    /// \brief randf random between -1..1
    /// \return float
    ///
    float randf();

    //////////////////////////////////
    /// \brief rand2m random integer between min..max
    ///
    int rand2m(int min, int max);

    //////////////////////////////////
    /// \brief deg2Rad convert degree to radian
    /// \param deg
    /// \return
    ///
    float deg2Rad(float deg);

    //////////////////////////////////
    /// \brief rad2Deg convert radian to degree
    /// \param rad
    /// \return
    ///
    float rad2Deg(float rad);

    //////////////////////////////////
    /// \brief distance2Vec compute distance between 2 vectors
    /// \param p1
    /// \param p2
    /// \return
    ///
    float distance2Vec(const glm::vec2& p1, const glm::vec2& p2);

    //////////////////////////////////
    /// \brief polarProjection everyone know this
    /// \param p1
    /// \param offset
    /// \param radian
    /// \return
    ///
    glm::vec2& polarProjection(const glm::vec2& p1, const float& offset, const float& radian);

}

#endif // MISC_H

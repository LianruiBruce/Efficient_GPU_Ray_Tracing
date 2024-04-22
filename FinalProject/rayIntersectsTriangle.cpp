#include <iostream>
#include <glm/glm.hpp>

bool rayIntersectsTriangle(glm::vec3 rayOrigin,
    glm::vec3 rayVector,
    glm::vec3 vertex0,
    glm::vec3 vertex1,
    glm::vec3 vertex2,
    glm::vec3& outIntersectionPoint) {
    const float EPSILON = 0.0000001f;
    glm::vec3 edge1, edge2, h, s, q;
    float a, f, u, v;
    edge1 = vertex1 - vertex0;
    edge2 = vertex2 - vertex0;
    h = glm::cross(rayVector, edge2);
    a = glm::dot(edge1, h);
    if (a > -EPSILON && a < EPSILON)
        return false;    // This ray is parallel to this triangle.
    f = 1.0 / a;
    s = rayOrigin - vertex0;
    u = f * glm::dot(s, h);
    if (u < 0.0 || u > 1.0)
        return false;
    q = glm::cross(s, edge1);
    v = f * glm::dot(rayVector, q);
    if (v < 0.0 || u + v > 1.0)
        return false;
    // At this stage we can compute t to find out where the intersection point is on the line.
    float t = f * glm::dot(edge2, q);
    if (t > EPSILON) // ray intersection
    {
        outIntersectionPoint = rayOrigin + rayVector * t;
        return true;
    }
    else // This means that there is a line intersection but not a ray intersection.
        return false;
}

int main() {
    glm::vec3 rayOrigin(0.0f, 0.0f, 0.0f);
    glm::vec3 rayDirection(0.0f, 0.0f, 1.0f);
    glm::vec3 vertex0(0.0f, 1.0f, 5.0f);
    glm::vec3 vertex1(1.0f, -1.0f, 5.0f);
    glm::vec3 vertex2(-1.0f, -1.0f, 5.0f);
    glm::vec3 intersectionPoint;

    if (rayIntersectsTriangle(rayOrigin, rayDirection, vertex0, vertex1, vertex2, intersectionPoint)) {
        std::cout << "Intersection at: " << intersectionPoint.x << ", " << intersectionPoint.y << ", " << intersectionPoint.z << std::endl;
    }
    else {
        std::cout << "No intersection.\n";
    }

    return 0;
}

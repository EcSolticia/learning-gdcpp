#pragma once

#include <godot_cpp/classes/object.hpp>

using namespace godot;

class GravityCalculator : public Object {
    GDCLASS(GravityCalculator, Object);

    double G;

protected:
    static void _bind_methods();

public:
    Vector2 get_accel(Vector2 pos1, Vector2 pos2, double mass2);

    void set_G(double G_p);
    double get_G();

    GravityCalculator();
};
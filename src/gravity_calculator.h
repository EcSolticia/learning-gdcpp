#pragma once

#include <vector>
#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/classes/node2d.hpp>
#include <godot_cpp/classes/character_body2d.hpp>

using namespace godot;

class GravityCalculator : public Node {
    GDCLASS(GravityCalculator, Node);

    double G;

protected:
    static void _bind_methods();

public:
    Vector2 get_accel(Vector2 pos1, Vector2 pos2, double mass2);

    void apply_accel(Node* p_body, double delta);
    
    void apply_accel_to_all(double delta);

    void set_G(double G_p);
    double get_G();

    GravityCalculator();
};
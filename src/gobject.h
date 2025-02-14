#pragma once

#include <godot_cpp/classes/character_body2d.hpp>

using namespace godot;

class Gobject : public CharacterBody2D {
    GDCLASS(Gobject, CharacterBody2D);
    
    double mass;
    double density;

protected:
    static void _bind_methods();

public:
    void set_mass(double p_mass);
    double get_mass();

    void set_density(double p_density);
    double get_density();

    Gobject();
    ~Gobject();
};
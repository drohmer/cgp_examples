#pragma once

#include "cgp/cgp.hpp"
#include "environment.hpp"

#include "shadow_mapping/shadow_mapping.hpp"

using cgp::mesh_drawable;

struct gui_parameters {
	bool display_frame = true;
	bool display_wireframe = false;
};

// The structure of the custom scene
struct scene_structure : cgp::scene_inputs_generic {

	// ****************************** //
	// Standard Functions
	// ****************************** //

	void initialize();
	void display_frame();
	void display_gui();

	void display_info();

	// ****************************** //
	// Context
	// ****************************** //

	environment_structure environment;   // Standard environment controler
	window_structure window;
	input_devices inputs;                // Storage for inputs status (mouse, keyboard, window dimension)
	gui_parameters gui;                  // Standard GUI element storage

	// ****************************** //
	// Camera controler
	// ****************************** //

	camera_controller_orbit_euler camera_control;
	camera_projection_perspective camera_projection;

	// ****************************** //
	// Elements and shapes of the scene
	// ****************************** //

	mesh_drawable global_frame;          // The standard global frame

	mesh_drawable camel;
	mesh_drawable cube;
	mesh_drawable ground;

	shadow_mapping_structure shadow_mapping; // Helper structure to handle the shadow mapping
	mat4 view_light;                         // view matrix of the light

	// ****************************** //
	// Callback functions
	// ****************************** //

	void mouse_move_event();
	void mouse_click_event();
	void keyboard_event();
	void idle_frame();

};

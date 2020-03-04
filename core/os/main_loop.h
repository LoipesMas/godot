/*************************************************************************/
/*  main_loop.h                                                          */
/*************************************************************************/
/*                       This file is part of:                           */
/*                           GODOT ENGINE                                */
/*                      https://godotengine.org                          */
/*************************************************************************/
/* Copyright (c) 2007-2020 Juan Linietsky, Ariel Manzur.                 */
/* Copyright (c) 2014-2020 Godot Engine contributors (cf. AUTHORS.md).   */
/*                                                                       */
/* Permission is hereby granted, free of charge, to any person obtaining */
/* a copy of this software and associated documentation files (the       */
/* "Software"), to deal in the Software without restriction, including   */
/* without limitation the rights to use, copy, modify, merge, publish,   */
/* distribute, sublicense, and/or sell copies of the Software, and to    */
/* permit persons to whom the Software is furnished to do so, subject to */
/* the following conditions:                                             */
/*                                                                       */
/* The above copyright notice and this permission notice shall be        */
/* included in all copies or substantial portions of the Software.       */
/*                                                                       */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,       */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF    */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.*/
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY  */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,  */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE     */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                */
/*************************************************************************/

#ifndef MAIN_LOOP_H
#define MAIN_LOOP_H

#include "core/input/input_event.h"
#include "core/reference.h"
#include "core/script_language.h"

class MainLoop : public Object {

	GDCLASS(MainLoop, Object);
	OBJ_CATEGORY("Main Loop");

	Ref<Script> init_script;

protected:
	static void _bind_methods();

public:
	enum {
		//make sure these are replicated in Node
		NOTIFICATION_OS_MEMORY_WARNING = 1009,
		NOTIFICATION_TRANSLATION_CHANGED = 1010,
		NOTIFICATION_WM_ABOUT = 1011,
		NOTIFICATION_CRASH = 1012,
		NOTIFICATION_OS_IME_UPDATE = 1013,
		NOTIFICATION_APP_RESUMED = 1014,
		NOTIFICATION_APP_PAUSED = 1015,
	};

	virtual void init();
	virtual bool iteration(float p_time);
	virtual bool idle(float p_time);
	virtual void finish();

	virtual void global_menu_action(const Variant &p_id, const Variant &p_meta);

	void set_init_script(const Ref<Script> &p_init_script);

	MainLoop();
	virtual ~MainLoop();
};

#endif

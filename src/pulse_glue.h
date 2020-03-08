/*
 * This file is part of pa-applet.
 *
 * © 2012 Fernando Tarlá Cardoso Lemos
 *
 * Refer to the LICENSE file for licensing information.
 *
 */

#ifndef PULSE_GLUE_H
#define PULSE_GLUE_H

#include <pulse/pulseaudio.h>
void pulse_glue_init(void);
void pulse_glue_destroy(void);
void pulse_glue_start(void);
void pulse_glue_sync_volume(void);
void pulse_glue_sync_muted(void);
void pulse_glue_sync_active_profile(void);

GSList *get_sinks();
void set_sink(gchar *sink);
int is_default_sink(const char* sink);

#endif

/*
 * This file is part of pa-applet.
 *
 * © 2012 Fernando Tarlá Cardoso Lemos
 *
 * Refer to the LICENSE file for licensing information.
 *
 */

#ifndef POPUP_MENU_H
#define POPUP_MENU_H

void destroy_popup_menu(void);
void show_popup_menu(GtkStatusIcon *status_icon);
void hide_popup_menu(void);
gboolean is_popup_menu_visible(void);
void update_popup_menu(void);

#endif

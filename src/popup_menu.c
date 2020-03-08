/*
 * This file is part of pa-applet.
 *
 * © 2012 Fernando Tarlá Cardoso Lemos
 *
 * Refer to the LICENSE file for licensing information.
 *
 */

#include <gtk/gtk.h>
#include <string.h>

#include "audio_status.h"
#include "pulse_glue.h"

static GSList *profile_names = NULL;

void destroy_popup_menu(void)
{
    // Nothing needs to be done at the moment
}

static void on_selection_done(GtkMenu *menu, gpointer data)
{
    // Get rid of the copied profile names
    g_slist_free_full(profile_names, (GDestroyNotify)g_free);
    profile_names = NULL;
}

static void on_item_activate(GtkMenuItem *item, gpointer data)//on item select
{
	set_sink(data);
    pulse_glue_sync_active_profile();
}


void show_popup_menu(GtkStatusIcon *status_icon)//right click menu
{

    // Right now we shouldn't have any profile names referenced
    g_assert(!profile_names);

    // Nothing to do if we have no entries
    audio_status *as = shared_audio_status();
    if (!as->profiles)
        return;

    // Create the menu
    GtkWidget *menu = gtk_menu_new();
    g_signal_connect(G_OBJECT(menu), "selection-done", G_CALLBACK(on_selection_done), NULL);

    for (GSList *entry = get_sinks(); entry; entry = entry->next) {
    	pa_sink_info *sinkinfo =((pa_sink_info *)entry->data);
            // Create the item
    	GtkWidget *item =gtk_check_menu_item_new_with_label(sinkinfo->name);
    	gtk_check_menu_item_set_active(GTK_CHECK_MENU_ITEM(item), is_default_sink(sinkinfo->name));

    	gtk_menu_shell_append(GTK_MENU_SHELL(menu), item);
    	// Connect the signal, referecing the copy of the profile name
    	g_signal_connect(G_OBJECT(item), "activate", G_CALLBACK(on_item_activate), g_strdup(sinkinfo->name));

    }

	gtk_widget_show_all(menu);
	gtk_menu_popup(GTK_MENU(menu), NULL, NULL, gtk_status_icon_position_menu,
                status_icon, 0, gtk_get_current_event_time());
}

void hide_popup_menu(void)
{
    // Nothing needs to be done at the moment
}

gboolean is_popup_menu_visible(void)
{
    // Right now we can't tell, but it doesn't really matter as
    // if the user managed to click the tray icon, the popup menu
    // lost focus anyways and was thus dismissed
    return FALSE;
}

void update_popup_menu(void)
{
    // Nothing needs to be done at the moment
}

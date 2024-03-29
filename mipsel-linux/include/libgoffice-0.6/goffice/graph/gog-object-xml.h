/* vim: set sw=8: -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */
/*
 * gog-object-xml.h : 
 *
 * Copyright (C) 2003-2005 Jody Goldberg (jody@gnome.org)
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of version 2 of the GNU General Public
 * License as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301
 * USA
 */
#ifndef GOG_OBJECT_XML_H
#define GOG_OBJECT_XML_H

#include <goffice/graph/goffice-graph.h>
#include <goffice/utils/goffice-utils.h>
#include <glib-object.h>
#include <libxml/tree.h>
#include <gsf/gsf-libxml.h>

G_BEGIN_DECLS

typedef struct _GogPersist GogPersist;

typedef struct {
	GTypeInterface base;

	gboolean (*dom_load) (GogPersist *gp, xmlNode *node);
	void	 (*prep_sax) (GogPersist *gp, GsfXMLIn *xin, xmlChar const **attrs);
	void     (*sax_save) (GogPersist const *gp, GsfXMLOut *output);
} GogPersistClass;

#define GOG_PERSIST_TYPE	 (gog_persist_get_type ())
#define GOG_PERSIST(o)		 (G_TYPE_CHECK_INSTANCE_CAST ((o), GOG_PERSIST_TYPE, GogPersist))
#define IS_GOG_PERSIST(o)	 (G_TYPE_CHECK_INSTANCE_TYPE ((o), GOG_PERSIST_TYPE))
#define GOG_PERSIST_CLASS(k)	 (G_TYPE_CHECK_CLASS_CAST ((k), GOG_PERSIST_TYPE, GogPersistClass))
#define IS_GOG_PERSIST_CLASS(k)	 (G_TYPE_CHECK_CLASS_TYPE ((k), GOG_PERSIST_TYPE))
#define GOG_PERSIST_GET_CLASS(o) (G_TYPE_INSTANCE_GET_INTERFACE ((o), GOG_PERSIST_TYPE, GogPersistClass))

GType gog_persist_get_type (void);

gboolean gog_persist_dom_load (GogPersist *gp, xmlNode *node);
void     gog_persist_sax_save (GogPersist const *gp, GsfXMLOut *output);
void	 gog_persist_prep_sax (GogPersist *gp, 
			       GsfXMLIn *xin, xmlChar const **attrs);

void	   gog_object_set_arg	   (char const *name, char const *val, GogObject *obj);
void	   go_xml_out_add_color (GsfXMLOut *out, char const *id, GOColor c);
void	   gog_object_write_xml_sax(GogObject const *obj, GsfXMLOut *output);

/* deprecated as soon as sax import works */
GogObject *gog_object_new_from_xml (GogObject *parent, xmlNode *node);

typedef void (*GogObjectSaxHandler)(GogObject *obj, gpointer user_data);
void	   gog_object_sax_push_parser (GsfXMLIn *xin, xmlChar const **attrs,
				       GogObjectSaxHandler	handler,
				       gpointer			user_data);
GogObject *gog_xml_read_state_get_obj (GsfXMLIn *xin);

G_END_DECLS

#endif /* GOG_OBJECT_XML_H */

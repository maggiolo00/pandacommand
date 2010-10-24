/* PandaPluginLoader.c generated by valac 0.10.0, the Vala compiler
 * generated from PandaPluginLoader.vala, do not modify */


#include <glib.h>
#include <glib-object.h>
#include <stdlib.h>
#include <string.h>
#include <gmodule.h>
#include <stdio.h>


#define TYPE_PANDA_PLUGIN_LOADER (panda_plugin_loader_get_type ())
#define PANDA_PLUGIN_LOADER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_PANDA_PLUGIN_LOADER, PandaPluginLoader))
#define PANDA_PLUGIN_LOADER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_PANDA_PLUGIN_LOADER, PandaPluginLoaderClass))
#define IS_PANDA_PLUGIN_LOADER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_PANDA_PLUGIN_LOADER))
#define IS_PANDA_PLUGIN_LOADER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_PANDA_PLUGIN_LOADER))
#define PANDA_PLUGIN_LOADER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_PANDA_PLUGIN_LOADER, PandaPluginLoaderClass))

typedef struct _PandaPluginLoader PandaPluginLoader;
typedef struct _PandaPluginLoaderClass PandaPluginLoaderClass;
typedef struct _PandaPluginLoaderPrivate PandaPluginLoaderPrivate;
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_module_close0(var) ((var == NULL) ? NULL : (var = (g_module_close (var), NULL)))

struct _PandaPluginLoader {
	GObject parent_instance;
	PandaPluginLoaderPrivate * priv;
};

struct _PandaPluginLoaderClass {
	GObjectClass parent_class;
};

struct _PandaPluginLoaderPrivate {
	GType t_type;
	GBoxedCopyFunc t_dup_func;
	GDestroyNotify t_destroy_func;
	char* _path;
	GType type;
	GModule* module;
};

typedef GType (*PandaPluginLoaderRegisterPluginFunction) (GModule* module, void* user_data);

static gpointer panda_plugin_loader_parent_class = NULL;

GType panda_plugin_loader_get_type (void) G_GNUC_CONST;
#define PANDA_PLUGIN_LOADER_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), TYPE_PANDA_PLUGIN_LOADER, PandaPluginLoaderPrivate))
enum  {
	PANDA_PLUGIN_LOADER_DUMMY_PROPERTY,
	PANDA_PLUGIN_LOADER_PATH,
	PANDA_PLUGIN_LOADER_T_TYPE,
	PANDA_PLUGIN_LOADER_T_DUP_FUNC,
	PANDA_PLUGIN_LOADER_T_DESTROY_FUNC
};
PandaPluginLoader* panda_plugin_loader_new (GType t_type, GBoxedCopyFunc t_dup_func, GDestroyNotify t_destroy_func, const char* name);
PandaPluginLoader* panda_plugin_loader_construct (GType object_type, GType t_type, GBoxedCopyFunc t_dup_func, GDestroyNotify t_destroy_func, const char* name);
static void panda_plugin_loader_set_path (PandaPluginLoader* self, const char* value);
gboolean panda_plugin_loader_load (PandaPluginLoader* self);
const char* panda_plugin_loader_get_path (PandaPluginLoader* self);
gpointer panda_plugin_loader_new_object (PandaPluginLoader* self);
static void panda_plugin_loader_finalize (GObject* obj);
static void panda_plugin_loader_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec);
static void panda_plugin_loader_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec);



#line 11 "PandaPluginLoader.vala"
PandaPluginLoader* panda_plugin_loader_construct (GType object_type, GType t_type, GBoxedCopyFunc t_dup_func, GDestroyNotify t_destroy_func, const char* name) {
#line 72 "PandaPluginLoader.c"
	PandaPluginLoader * self;
	char* _tmp0_;
	char* _tmp1_;
	char* _tmp2_;
#line 11 "PandaPluginLoader.vala"
	g_return_val_if_fail (name != NULL, NULL);
#line 11 "PandaPluginLoader.vala"
	self = (PandaPluginLoader*) g_object_new (object_type, NULL);
#line 11 "PandaPluginLoader.vala"
	self->priv->t_type = t_type;
#line 11 "PandaPluginLoader.vala"
	self->priv->t_dup_func = t_dup_func;
#line 11 "PandaPluginLoader.vala"
	self->priv->t_destroy_func = t_destroy_func;
#line 12 "PandaPluginLoader.vala"
	g_assert (g_module_supported ());
#line 13 "PandaPluginLoader.vala"
	panda_plugin_loader_set_path (self, _tmp2_ = g_module_build_path (_tmp1_ = g_strconcat (_tmp0_ = g_strconcat (g_getenv ("PWD"), "/plugins/", NULL), name, NULL), name));
#line 91 "PandaPluginLoader.c"
	_g_free0 (_tmp2_);
	_g_free0 (_tmp1_);
	_g_free0 (_tmp0_);
	return self;
}


#line 11 "PandaPluginLoader.vala"
PandaPluginLoader* panda_plugin_loader_new (GType t_type, GBoxedCopyFunc t_dup_func, GDestroyNotify t_destroy_func, const char* name) {
#line 11 "PandaPluginLoader.vala"
	return panda_plugin_loader_construct (TYPE_PANDA_PLUGIN_LOADER, t_type, t_dup_func, t_destroy_func, name);
#line 103 "PandaPluginLoader.c"
}


#line 15 "PandaPluginLoader.vala"
gboolean panda_plugin_loader_load (PandaPluginLoader* self) {
#line 109 "PandaPluginLoader.c"
	gboolean result = FALSE;
	GModule* _tmp0_;
	void* function = NULL;
	void* register_plugin_target = NULL;
	GDestroyNotify register_plugin_target_destroy_notify = NULL;
	PandaPluginLoaderRegisterPluginFunction _tmp1_;
	PandaPluginLoaderRegisterPluginFunction register_plugin;
#line 15 "PandaPluginLoader.vala"
	g_return_val_if_fail (self != NULL, FALSE);
#line 16 "PandaPluginLoader.vala"
	fprintf (stdout, "Loading plugin with path: '%s'\n", self->priv->_path);
#line 17 "PandaPluginLoader.vala"
	self->priv->module = (_tmp0_ = g_module_open (self->priv->_path, G_MODULE_BIND_LOCAL), _g_module_close0 (self->priv->module), _tmp0_);
#line 18 "PandaPluginLoader.vala"
	if (self->priv->module == NULL) {
#line 125 "PandaPluginLoader.c"
		result = FALSE;
#line 19 "PandaPluginLoader.vala"
		return result;
#line 129 "PandaPluginLoader.c"
	}
#line 21 "PandaPluginLoader.vala"
	fprintf (stdout, "Loaded module: '%s'\n", g_module_name (self->priv->module));
#line 23 "PandaPluginLoader.vala"
	g_module_symbol (self->priv->module, "register_plugin", &function);
#line 135 "PandaPluginLoader.c"
	register_plugin = (_tmp1_ = (PandaPluginLoaderRegisterPluginFunction) function, register_plugin_target = NULL, register_plugin_target_destroy_notify = NULL, _tmp1_);
#line 25 "PandaPluginLoader.vala"
	self->priv->type = register_plugin (self->priv->module, register_plugin_target);
#line 26 "PandaPluginLoader.vala"
	fprintf (stdout, "Plugin type: %s\n\n", g_type_name (self->priv->type));
#line 27 "PandaPluginLoader.vala"
	g_module_make_resident (self->priv->module);
#line 143 "PandaPluginLoader.c"
	result = TRUE;
	(register_plugin_target_destroy_notify == NULL) ? NULL : (register_plugin_target_destroy_notify (register_plugin_target), NULL);
	register_plugin = NULL;
	register_plugin_target = NULL;
	register_plugin_target_destroy_notify = NULL;
#line 28 "PandaPluginLoader.vala"
	return result;
#line 151 "PandaPluginLoader.c"
}


#line 31 "PandaPluginLoader.vala"
gpointer panda_plugin_loader_new_object (PandaPluginLoader* self) {
#line 157 "PandaPluginLoader.c"
	gpointer result = NULL;
	GObject* _tmp0_;
#line 31 "PandaPluginLoader.vala"
	g_return_val_if_fail (self != NULL, NULL);
#line 162 "PandaPluginLoader.c"
	result = (_tmp0_ = g_object_new (self->priv->type, NULL), G_IS_INITIALLY_UNOWNED (_tmp0_) ? g_object_ref_sink (_tmp0_) : _tmp0_);
#line 32 "PandaPluginLoader.vala"
	return result;
#line 166 "PandaPluginLoader.c"
}


const char* panda_plugin_loader_get_path (PandaPluginLoader* self) {
	const char* result;
	g_return_val_if_fail (self != NULL, NULL);
	result = self->priv->_path;
#line 5 "PandaPluginLoader.vala"
	return result;
#line 176 "PandaPluginLoader.c"
}


static void panda_plugin_loader_set_path (PandaPluginLoader* self, const char* value) {
	char* _tmp0_;
	g_return_if_fail (self != NULL);
	self->priv->_path = (_tmp0_ = g_strdup (value), _g_free0 (self->priv->_path), _tmp0_);
	g_object_notify ((GObject *) self, "path");
}


static void panda_plugin_loader_class_init (PandaPluginLoaderClass * klass) {
	panda_plugin_loader_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (PandaPluginLoaderPrivate));
	G_OBJECT_CLASS (klass)->get_property = panda_plugin_loader_get_property;
	G_OBJECT_CLASS (klass)->set_property = panda_plugin_loader_set_property;
	G_OBJECT_CLASS (klass)->finalize = panda_plugin_loader_finalize;
	g_object_class_install_property (G_OBJECT_CLASS (klass), PANDA_PLUGIN_LOADER_T_TYPE, g_param_spec_gtype ("t-type", "type", "type", G_TYPE_NONE, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_WRITABLE | G_PARAM_CONSTRUCT_ONLY));
	g_object_class_install_property (G_OBJECT_CLASS (klass), PANDA_PLUGIN_LOADER_T_DUP_FUNC, g_param_spec_pointer ("t-dup-func", "dup func", "dup func", G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_WRITABLE | G_PARAM_CONSTRUCT_ONLY));
	g_object_class_install_property (G_OBJECT_CLASS (klass), PANDA_PLUGIN_LOADER_T_DESTROY_FUNC, g_param_spec_pointer ("t-destroy-func", "destroy func", "destroy func", G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_WRITABLE | G_PARAM_CONSTRUCT_ONLY));
	g_object_class_install_property (G_OBJECT_CLASS (klass), PANDA_PLUGIN_LOADER_PATH, g_param_spec_string ("path", "path", "path", NULL, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE));
}


static void panda_plugin_loader_instance_init (PandaPluginLoader * self) {
	self->priv = PANDA_PLUGIN_LOADER_GET_PRIVATE (self);
}


static void panda_plugin_loader_finalize (GObject* obj) {
	PandaPluginLoader * self;
	self = PANDA_PLUGIN_LOADER (obj);
	_g_free0 (self->priv->_path);
	_g_module_close0 (self->priv->module);
	G_OBJECT_CLASS (panda_plugin_loader_parent_class)->finalize (obj);
}


GType panda_plugin_loader_get_type (void) {
	static volatile gsize panda_plugin_loader_type_id__volatile = 0;
	if (g_once_init_enter (&panda_plugin_loader_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (PandaPluginLoaderClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) panda_plugin_loader_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (PandaPluginLoader), 0, (GInstanceInitFunc) panda_plugin_loader_instance_init, NULL };
		GType panda_plugin_loader_type_id;
		panda_plugin_loader_type_id = g_type_register_static (G_TYPE_OBJECT, "PandaPluginLoader", &g_define_type_info, 0);
		g_once_init_leave (&panda_plugin_loader_type_id__volatile, panda_plugin_loader_type_id);
	}
	return panda_plugin_loader_type_id__volatile;
}


static void panda_plugin_loader_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec) {
	PandaPluginLoader * self;
	self = PANDA_PLUGIN_LOADER (object);
	switch (property_id) {
		case PANDA_PLUGIN_LOADER_PATH:
		g_value_set_string (value, panda_plugin_loader_get_path (self));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}


static void panda_plugin_loader_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec) {
	PandaPluginLoader * self;
	self = PANDA_PLUGIN_LOADER (object);
	switch (property_id) {
		case PANDA_PLUGIN_LOADER_PATH:
		panda_plugin_loader_set_path (self, g_value_get_string (value));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
		case PANDA_PLUGIN_LOADER_T_TYPE:
		self->priv->t_type = g_value_get_gtype (value);
		break;
		case PANDA_PLUGIN_LOADER_T_DUP_FUNC:
		self->priv->t_dup_func = g_value_get_pointer (value);
		break;
		case PANDA_PLUGIN_LOADER_T_DESTROY_FUNC:
		self->priv->t_destroy_func = g_value_get_pointer (value);
		break;
	}
}




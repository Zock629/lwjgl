#ifndef EXTGL_GLX_H
#define EXTGL_GLX_H

#include <X11/Xutil.h>
#include "extgl.h"

/*
 * Names for attributes to glXGetConfig.
 */
#define GLX_USE_GL              1       /* support GLX rendering */
#define GLX_BUFFER_SIZE         2       /* depth of the color buffer */
#define GLX_LEVEL               3       /* level in plane stacking */
#define GLX_RGBA                4       /* true if RGBA mode */
#define GLX_DOUBLEBUFFER        5       /* double buffering supported */
#define GLX_STEREO              6       /* stereo buffering supported */
#define GLX_AUX_BUFFERS         7       /* number of aux buffers */
#define GLX_RED_SIZE            8       /* number of red component bits */
#define GLX_GREEN_SIZE          9       /* number of green component bits */
#define GLX_BLUE_SIZE           10      /* number of blue component bits */
#define GLX_ALPHA_SIZE          11      /* number of alpha component bits */
#define GLX_DEPTH_SIZE          12      /* number of depth bits */
#define GLX_STENCIL_SIZE        13      /* number of stencil bits */
#define GLX_ACCUM_RED_SIZE      14      /* number of red accum bits */
#define GLX_ACCUM_GREEN_SIZE    15      /* number of green accum bits */
#define GLX_ACCUM_BLUE_SIZE     16      /* number of blue accum bits */
#define GLX_ACCUM_ALPHA_SIZE    17      /* number of alpha accum bits */

#define GLX_SAMPLE_BUFFERS_ARB  100000  /* number of multisample buffers */
#define GLX_SAMPLES_ARB         100001  /* number of multisample samples */

/*
 * FBConfig-specific attributes
 */
#define GLX_X_VISUAL_TYPE               0x22
#define GLX_CONFIG_CAVEAT               0x20    /* Like visual_info VISUAL_CAVEAT */
#define GLX_TRANSPARENT_TYPE            0x23
#define GLX_TRANSPARENT_INDEX_VALUE     0x24
#define GLX_TRANSPARENT_RED_VALUE       0x25
#define GLX_TRANSPARENT_GREEN_VALUE     0x26
#define GLX_TRANSPARENT_BLUE_VALUE      0x27
#define GLX_TRANSPARENT_ALPHA_VALUE     0x28
#define GLX_DRAWABLE_TYPE               0x8010
#define GLX_RENDER_TYPE                 0x8011
#define GLX_X_RENDERABLE                0x8012
#define GLX_FBCONFIG_ID                 0x8013
#define GLX_MAX_PBUFFER_WIDTH           0x8016
#define GLX_MAX_PBUFFER_HEIGHT          0x8017
#define GLX_MAX_PBUFFER_PIXELS          0x8018
#define GLX_VISUAL_ID                   0x800B

#define GLX_DRAWABLE_TYPE_SGIX          GLX_DRAWABLE_TYPE
#define GLX_RENDER_TYPE_SGIX            GLX_RENDER_TYPE
#define GLX_X_RENDERABLE_SGIX           GLX_X_RENDERABLE
#define GLX_FBCONFIG_ID_SGIX            GLX_FBCONFIG_ID
#define GLX_MAX_PBUFFER_WIDTH_SGIX      GLX_MAX_PBUFFER_WIDTH
#define GLX_MAX_PBUFFER_HEIGHT_SGIX     GLX_MAX_PBUFFER_HEIGHT
#define GLX_MAX_PBUFFER_PIXELS_SGIX     GLX_MAX_PBUFFER_PIXELS
#define GLX_OPTIMAL_PBUFFER_WIDTH_SGIX  0x8019
#define GLX_OPTIMAL_PBUFFER_HEIGHT_SGIX 0x801A

/*
 * Error return values from glXGetConfig.  Success is indicated by
 * a value of 0.
 */
#define GLX_BAD_SCREEN                  1  /* screen # is bad */
#define GLX_BAD_ATTRIBUTE               2  /* attribute to get is bad */
#define GLX_NO_EXTENSION                3  /* no glx extension on server */
#define GLX_BAD_VISUAL                  4  /* visual # not known by GLX */
#define GLX_BAD_CONTEXT                 5
#define GLX_BAD_VALUE                   6
#define GLX_BAD_ENUM                    7


/* FBConfig attribute values */

/*
 * Generic "don't care" value for glX ChooseFBConfig attributes (except
 * GLX_LEVEL).
 */
#define GLX_DONT_CARE                   0xFFFFFFFF

/* GLX_RENDER_TYPE bits */
#define GLX_RGBA_BIT                    0x00000001
#define GLX_COLOR_INDEX_BIT             0x00000002
#define GLX_RGBA_BIT_SGIX               GLX_RGBA_BIT
#define GLX_COLOR_INDEX_BIT_SGIX        GLX_COLOR_INDEX_BIT

/* GLX_DRAWABLE_TYPE bits */
#define GLX_WINDOW_BIT                  0x00000001
#define GLX_PIXMAP_BIT                  0x00000002
#define GLX_PBUFFER_BIT                 0x00000004
#define GLX_WINDOW_BIT_SGIX             GLX_WINDOW_BIT
#define GLX_PIXMAP_BIT_SGIX             GLX_PIXMAP_BIT
#define GLX_PBUFFER_BIT_SGIX            GLX_PBUFFER_BIT

/* GLX_CONFIG_CAVEAT attribute values */
#define GLX_NONE                        0x8000
#define GLX_SLOW_CONFIG                 0x8001
#define GLX_NON_CONFORMANT_CONFIG       0x800D

/* GLX_X_VISUAL_TYPE attribute values */
#define GLX_TRUE_COLOR                  0x8002
#define GLX_DIRECT_COLOR                0x8003
#define GLX_PSEUDO_COLOR                0x8004
#define GLX_STATIC_COLOR                0x8005
#define GLX_GRAY_SCALE                  0x8006
#define GLX_STATIC_GRAY                 0x8007

/* GLX_TRANSPARENT_TYPE attribute values */
/* #define GLX_NONE                        0x8000 */
#define GLX_TRANSPARENT_RGB             0x8008
#define GLX_TRANSPARENT_INDEX           0x8009

/* glXCreateGLXPbuffer attributes */
#define GLX_PRESERVED_CONTENTS          0x801B
#define GLX_LARGEST_PBUFFER             0x801C
#define GLX_PBUFFER_HEIGHT              0x8040  /* New for GLX 1.3 */
#define GLX_PBUFFER_WIDTH               0x8041  /* New for GLX 1.3 */
#define GLX_PRESERVED_CONTENTS_SGIX     GLX_PRESERVED_CONTENTS
#define GLX_LARGEST_PBUFFER_SGIX        GLX_LARGEST_PBUFFER

/* glXQueryGLXPBuffer attributes */
#define GLX_WIDTH                       0x801D
#define GLX_HEIGHT                      0x801E
#define GLX_EVENT_MASK                  0x801F
#define GLX_WIDTH_SGIX                  GLX_WIDTH
#define GLX_HEIGHT_SGIX                 GLX_HEIGHT
#define GLX_EVENT_MASK_SGIX             GLX_EVENT_MASK

/* glXCreateNewContext render_type attribute values */
#define GLX_RGBA_TYPE                   0x8014
#define GLX_COLOR_INDEX_TYPE            0x8015
#define GLX_RGBA_TYPE_SGIX              GLX_RGBA_TYPE
#define GLX_COLOR_INDEX_TYPE_SGIX       GLX_COLOR_INDEX_TYPE

/* glXQueryContext attributes */
/* #define GLX_FBCONFIG_ID                0x8013 */
/* #define GLX_RENDER_TYPE                0x8011 */
#define GLX_SCREEN                      0x800C

/* glXSelectEvent event mask bits */
#define GLX_PBUFFER_CLOBBER_MASK        0x08000000
#define GLX_PBUFFER_CLOBBER_MASK_SGIX   GLX_PBUFFER_CLOBBER_MASK

/* GLXPbufferClobberEvent event_type values */
#define GLX_DAMAGED                     0x8020
#define GLX_SAVED                       0x8021
#define GLX_DAMAGED_SGIX                GLX_DAMAGED
#define GLX_SAVED_SGIX                  GLX_SAVED

/* GLXPbufferClobberEvent draw_type values */
#define GLX_WINDOW                      0x8022
#define GLX_PBUFFER                     0x8023
#define GLX_WINDOW_SGIX                 GLX_WINDOW
#define GLX_PBUFFER_SGIX                GLX_PBUFFER

/* GLXPbufferClobberEvent buffer_mask bits */
#define GLX_FRONT_LEFT_BUFFER_BIT       0x00000001
#define GLX_FRONT_RIGHT_BUFFER_BIT      0x00000002
#define GLX_BACK_LEFT_BUFFER_BIT        0x00000004
#define GLX_BACK_RIGHT_BUFFER_BIT       0x00000008
#define GLX_AUX_BUFFERS_BIT             0x00000010
#define GLX_DEPTH_BUFFER_BIT            0x00000020
#define GLX_STENCIL_BUFFER_BIT          0x00000040
#define GLX_ACCUM_BUFFER_BIT            0x00000080
#define GLX_FRONT_LEFT_BUFFER_BIT_SGIX  GLX_FRONT_LEFT_BUFFER_BIT
#define GLX_FRONT_RIGHT_BUFFER_BIT_SGIX GLX_FRONT_RIGHT_BUFFER_BIT
#define GLX_BACK_LEFT_BUFFER_BIT_SGIX   GLX_BACK_LEFT_BUFFER_BIT
#define GLX_BACK_RIGHT_BUFFER_BIT_SGIX  GLX_BACK_RIGHT_BUFFER_BIT
#define GLX_AUX_BUFFERS_BIT_SGIX        GLX_AUX_BUFFERS_BIT
#define GLX_DEPTH_BUFFER_BIT_SGIX       GLX_DEPTH_BUFFER_BIT
#define GLX_STENCIL_BUFFER_BIT_SGIX     GLX_STENCIL_BUFFER_BIT
#define GLX_ACCUM_BUFFER_BIT_SGIX       GLX_ACCUM_BUFFER_BIT

/*
 * Extension return values from glXGetConfig.  These are also
 * accepted as parameter values for glXChooseVisual.
 */

#define GLX_X_VISUAL_TYPE_EXT           0x22    /* visual_info extension type */
#define GLX_TRANSPARENT_TYPE_EXT        0x23    /* visual_info extension */
#define GLX_TRANSPARENT_INDEX_VALUE_EXT 0x24    /* visual_info extension */
#define GLX_TRANSPARENT_RED_VALUE_EXT   0x25    /* visual_info extension */
#define GLX_TRANSPARENT_GREEN_VALUE_EXT 0x26    /* visual_info extension */
#define GLX_TRANSPARENT_BLUE_VALUE_EXT  0x27    /* visual_info extension */
#define GLX_TRANSPARENT_ALPHA_VALUE_EXT 0x28    /* visual_info extension */

/* Property values for visual_type */
#define GLX_TRUE_COLOR_EXT              0x8002
#define GLX_DIRECT_COLOR_EXT            0x8003
#define GLX_PSEUDO_COLOR_EXT            0x8004
#define GLX_STATIC_COLOR_EXT            0x8005
#define GLX_GRAY_SCALE_EXT              0x8006
#define GLX_STATIC_GRAY_EXT             0x8007

/* Property values for transparent pixel */
#define GLX_NONE_EXT                    0x8000
#define GLX_TRANSPARENT_RGB_EXT         0x8008
#define GLX_TRANSPARENT_INDEX_EXT       0x8009

/* Property values for visual_rating */
#define GLX_VISUAL_CAVEAT_EXT           0x20    /* visual_rating extension type */
#define GLX_SLOW_VISUAL_EXT             0x8001
#define GLX_NON_CONFORMANT_VISUAL_EXT   0x800D

/*
 * Names for attributes to glXGetClientString.
 */
#define GLX_VENDOR                      0x1
#define GLX_VERSION                     0x2
#define GLX_EXTENSIONS                  0x3

/*
 * Names for attributes to glXQueryContextInfoEXT.
 */
#define GLX_SHARE_CONTEXT_EXT           0x800A  /* id of share context */
#define GLX_VISUAL_ID_EXT               0x800B  /* id of context's visual */
#define GLX_SCREEN_EXT                  0x800C  /* screen number */

/* NV_float_buffer */
#define GLX_FLOAT_COMPONENTS_NV         0x20B0

typedef XID GLXContextID;
typedef XID GLXPixmap;
typedef XID GLXDrawable;
typedef XID GLXPbuffer;
typedef XID GLXWindow;
typedef XID GLXFBConfigID;

typedef struct __GLXcontextRec *GLXContext;

typedef struct __GLXFBConfigRec *GLXFBConfig;

typedef GLXFBConfig * (APIENTRY * glXGetFBConfigsPROC) (Display *dpy, int screen, int *nelements);
typedef GLXFBConfig * (APIENTRY * glXChooseFBConfigPROC) (Display *dpy, int screen, const int *attrib_list, int *nelements);
typedef int (APIENTRY * glXGetFBConfigAttribPROC) (Display *dpy, GLXFBConfig config, int attribute, int *value);
typedef XVisualInfo * (APIENTRY * glXGetVisualFromFBConfigPROC) (Display *dpy, GLXFBConfig config);
typedef GLXWindow (APIENTRY * glXCreateWindowPROC) (Display *dpy, GLXFBConfig config, Window win, const int *attrib_list);
typedef void (APIENTRY * glXDestroyWindowPROC) (Display *dpy, GLXWindow win);
typedef GLXPixmap (APIENTRY * glXCreatePixmapPROC) (Display *dpy, GLXFBConfig config, Pixmap pixmap, const int *attrib_list);
typedef void (APIENTRY * glXDestroyPixmapPROC) (Display *dpy, GLXPixmap pixmap);
typedef GLXPbuffer (APIENTRY * glXCreatePbufferPROC) (Display *dpy, GLXFBConfig config, const int *attrib_list);
typedef void (APIENTRY * glXDestroyPbufferPROC) (Display *dpy, GLXPbuffer pbuf);
typedef void (APIENTRY * glXQueryDrawablePROC) (Display *dpy, GLXDrawable draw, int attribute, unsigned int *value);
typedef GLXContext (APIENTRY * glXCreateNewContextPROC) (Display *dpy, GLXFBConfig config, int render_type, GLXContext share_list, Bool direct);
typedef Bool (APIENTRY * glXMakeContextCurrentPROC) (Display *display, GLXDrawable draw, GLXDrawable read, GLXContext ctx);
typedef GLXDrawable (APIENTRY * glXGetCurrentReadDrawablePROC) (void);
typedef Display * (APIENTRY * glXGetCurrentDisplayPROC) (void);
typedef int (APIENTRY * glXQueryContextPROC) (Display *dpy, GLXContext ctx, int attribute, int *value);
typedef void (APIENTRY * glXSelectEventPROC) (Display *dpy, GLXDrawable draw, unsigned long event_mask);
typedef void (APIENTRY * glXGetSelectedEventPROC) (Display *dpy, GLXDrawable draw, unsigned long *event_mask);

typedef GLXContextID (APIENTRY * glXGetContextIDEXTPROC) (const GLXContext ctx);
typedef GLXDrawable (APIENTRY * glXGetCurrentDrawableEXTPROC) (void);
typedef GLXContext (APIENTRY * glXImportContextEXTPROC) (Display *dpy, GLXContextID contextID);
typedef void (APIENTRY * glXFreeContextEXTPROC) (Display *dpy, GLXContext ctx);
typedef int (APIENTRY * glXQueryContextInfoEXTPROC) (Display *dpy, GLXContext ctx, int attribute, int *value);

typedef XVisualInfo* (APIENTRY * glXChooseVisualPROC) (Display *dpy, int screen, int *attribList);
typedef void (APIENTRY * glXCopyContextPROC) (Display *dpy, GLXContext src, GLXContext dst, unsigned long mask);
typedef GLXContext (APIENTRY * glXCreateContextPROC) (Display *dpy, XVisualInfo *vis, GLXContext shareList, Bool direct);
typedef GLXPixmap (APIENTRY * glXCreateGLXPixmapPROC) (Display *dpy, XVisualInfo *vis, Pixmap pixmap);
typedef void (APIENTRY * glXDestroyContextPROC) (Display *dpy, GLXContext ctx);
typedef void (APIENTRY * glXDestroyGLXPixmapPROC) (Display *dpy, GLXPixmap pix);
typedef int (APIENTRY * glXGetConfigPROC) (Display *dpy, XVisualInfo *vis, int attrib, int *value);
typedef GLXContext (APIENTRY * glXGetCurrentContextPROC) (void);
typedef GLXDrawable (APIENTRY * glXGetCurrentDrawablePROC) (void);
typedef Bool (APIENTRY * glXIsDirectPROC) (Display *dpy, GLXContext ctx);
typedef Bool (APIENTRY * glXMakeCurrentPROC) (Display *dpy, GLXDrawable drawable, GLXContext ctx);
typedef Bool (APIENTRY * glXQueryExtensionPROC) (Display *dpy, int *errorBase, int *eventBase);
typedef Bool (APIENTRY * glXQueryVersionPROC) (Display *dpy, int *major, int *minor);
typedef void (APIENTRY * glXSwapBuffersPROC) (Display *dpy, GLXDrawable drawable);
typedef void (APIENTRY * glXUseXFontPROC) (Font font, int first, int count, int listBase);
typedef void (APIENTRY * glXWaitGLPROC) (void);
typedef void (APIENTRY * glXWaitXPROC) (void);
typedef const char * (APIENTRY * glXGetClientStringPROC) (Display *dpy, int name );
typedef const char * (APIENTRY * glXQueryServerStringPROC) (Display *dpy, int screen, int name );
typedef const char * (APIENTRY * glXQueryExtensionsStringPROC) (Display *dpy, int screen );

/* GLX_SGI_swap_control */
typedef void (APIENTRY * glXSwapIntervalSGIPROC)(int interval);

extern glXGetFBConfigsPROC glXGetFBConfigs;
extern glXChooseFBConfigPROC glXChooseFBConfig;
extern glXGetFBConfigAttribPROC glXGetFBConfigAttrib;
extern glXGetVisualFromFBConfigPROC glXGetVisualFromFBConfig;
extern glXCreateWindowPROC glXCreateWindow;
extern glXDestroyWindowPROC glXDestroyWindow;
extern glXCreatePixmapPROC glXCreatePixmap;
extern glXDestroyPixmapPROC glXDestroyPixmap;
extern glXCreatePbufferPROC glXCreatePbuffer;
extern glXDestroyPbufferPROC glXDestroyPbuffer;
extern glXQueryDrawablePROC glXQueryDrawable;
extern glXCreateNewContextPROC glXCreateNewContext;
extern glXMakeContextCurrentPROC glXMakeContextCurrent;
extern glXGetCurrentReadDrawablePROC glXGetCurrentReadDrawable;
extern glXGetCurrentDisplayPROC glXGetCurrentDisplay;
extern glXQueryContextPROC glXQueryContext;
extern glXSelectEventPROC glXSelectEvent;
extern glXGetSelectedEventPROC glXGetSelectedEvent;

extern glXChooseVisualPROC glXChooseVisual;
extern glXCopyContextPROC glXCopyContext;
extern glXCreateContextPROC glXCreateContext;
extern glXCreateGLXPixmapPROC glXCreateGLXPixmap;
extern glXDestroyContextPROC glXDestroyContext;
extern glXDestroyGLXPixmapPROC glXDestroyGLXPixmap;
extern glXGetConfigPROC glXGetConfig;
extern glXGetCurrentContextPROC glXGetCurrentContext;
extern glXGetCurrentDrawablePROC glXGetCurrentDrawable;
extern glXIsDirectPROC glXIsDirect;
extern glXMakeCurrentPROC glXMakeCurrent;
extern glXQueryExtensionPROC glXQueryExtension;
extern glXQueryVersionPROC glXQueryVersion;
extern glXSwapBuffersPROC glXSwapBuffers;
extern glXUseXFontPROC glXUseXFont;
extern glXWaitGLPROC glXWaitGL;
extern glXWaitXPROC glXWaitX;
extern glXGetClientStringPROC glXGetClientString;
extern glXQueryServerStringPROC glXQueryServerString;
extern glXQueryExtensionsStringPROC glXQueryExtensionsString;

extern glXSwapIntervalSGIPROC glXSwapIntervalSGI;

extern bool extgl_InitGLX(JNIEnv *env, Display *disp, int screen);

#endif

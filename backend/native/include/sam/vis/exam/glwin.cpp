/*----------------------------------------------------------------------
                      GL Module
----------------------------------------------------------------------*/
#include <stdlib.h>
#include "sam/base/basedefs.h"
#include "legacy/vgl/vgldefs.h"

#include "glwin.h"

#ifdef VKI_3DAPI_OPENGL
static GLfloat rgba_zero[4] = {0., 0., 0., 0.};

/* line style mask */
static GLushort lsmask[3] = {0x0f0f, 0x0303, 0x0f03};

/* raster font mask */
static unsigned short fontmask[95][16] = {
{0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000},
{0x0000, 0x0000, 0x1800, 0x1800, 0x0000, 0x1800, 0x1800, 0x1800, 0x1800, 0x1800, 0x1800, 0x1800, 0x0000, 0x0000, 0x0000, 0x0000},
{0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x6c00, 0x6c00, 0x6c00, 0x0000, 0x0000, 0x0000, 0x0000},
{0x0000, 0x0000, 0xd800, 0x4800, 0xfe00, 0x4800, 0x2400, 0xfe00, 0x2400, 0x3600, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000},
{0x0000, 0x1000, 0x1000, 0x7c00, 0xd600, 0x1e00, 0x1c00, 0x7000, 0xf000, 0xd600, 0x7c00, 0x1000, 0x1000, 0x0000, 0x0000, 0x0000},
{0x0000, 0x0000, 0xcc00, 0xd200, 0x7200, 0x6c00, 0x3000, 0x1800, 0x6c00, 0x9c00, 0x9600, 0x6600, 0x0000, 0x0000, 0x0000, 0x0000},
{0x0000, 0x0000, 0x7600, 0xce00, 0xcc00, 0xda00, 0x7600, 0x3600, 0x6800, 0x6c00, 0x2c00, 0x3800, 0x0000, 0x0000, 0x0000, 0x0000},
{0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x2000, 0x3000, 0x3000, 0x3000, 0x0000, 0x0000, 0x0000, 0x0000},
{0x0000, 0x0800, 0x1800, 0x3000, 0x3000, 0x3000, 0x3000, 0x3000, 0x3000, 0x3000, 0x3000, 0x1800, 0x0800, 0x0000, 0x0000, 0x0000},
{0x0000, 0x1000, 0x1800, 0x0c00, 0x0c00, 0x0c00, 0x0c00, 0x0c00, 0x0c00, 0x0c00, 0x0c00, 0x1800, 0x1000, 0x0000, 0x0000, 0x0000},
{0x0000, 0x0000, 0x0000, 0x1800, 0x5a00, 0x7e00, 0x3c00, 0x7e00, 0x5a00, 0x1800, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000},
{0x0000, 0x0000, 0x0000, 0x1800, 0x1800, 0x1800, 0x7e00, 0x7e00, 0x1800, 0x1800, 0x1800, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000},
{0x0000, 0x6000, 0x3000, 0x3000, 0x3000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000},
{0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xfc00, 0xfc00, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000},
{0x0000, 0x0000, 0x3000, 0x3000, 0x3000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000},
{0x0000, 0x0000, 0xc000, 0xc000, 0x6000, 0x6000, 0x3000, 0x3000, 0x1800, 0x1800, 0x0c00, 0x0c00, 0x0000, 0x0000, 0x0000, 0x0000},
{0x0000, 0x0000, 0xfc00, 0xc600, 0xc600, 0xc600, 0xc600, 0xc600, 0xc600, 0xc600, 0xc600, 0x7e00, 0x0000, 0x0000, 0x0000, 0x0000},
{0x0000, 0x0000, 0x1800, 0x1800, 0x1800, 0x1800, 0x1800, 0x1800, 0x1800, 0x1800, 0x7800, 0x1800, 0x0000, 0x0000, 0x0000, 0x0000},
{0x0000, 0x0000, 0xfe00, 0xc000, 0x6000, 0x3000, 0x1800, 0x0c00, 0x0600, 0xc600, 0xc600, 0x7c00, 0x0000, 0x0000, 0x0000, 0x0000},
{0x0000, 0x0000, 0x7c00, 0xc600, 0xc600, 0x0600, 0x0600, 0x1c00, 0x0600, 0xc600, 0xc600, 0x7c00, 0x0000, 0x0000, 0x0000, 0x0000},
{0x0000, 0x0000, 0x0600, 0x0600, 0x0600, 0xfe00, 0x8600, 0x4600, 0x2600, 0x1600, 0x0e00, 0x0600, 0x0000, 0x0000, 0x0000, 0x0000},
{0x0000, 0x0000, 0x7c00, 0xc600, 0x0600, 0x0600, 0x0600, 0xfc00, 0xc000, 0xc000, 0xc000, 0xfe00, 0x0000, 0x0000, 0x0000, 0x0000},
{0x0000, 0x0000, 0x7c00, 0xc600, 0xc600, 0xc600, 0xc600, 0xfc00, 0xc000, 0xc000, 0xc600, 0x7c00, 0x0000, 0x0000, 0x0000, 0x0000},
{0x0000, 0x0000, 0x3000, 0x3000, 0x3000, 0x3000, 0x3000, 0x1800, 0x0c00, 0x0600, 0x0600, 0xfe00, 0x0000, 0x0000, 0x0000, 0x0000},
{0x0000, 0x0000, 0x7c00, 0xc600, 0xc600, 0xc600, 0xc600, 0x7c00, 0xc600, 0xc600, 0xc600, 0x7c00, 0x0000, 0x0000, 0x0000, 0x0000},
{0x0000, 0x0000, 0x7c00, 0xc600, 0x0600, 0x0600, 0x7e00, 0xc600, 0xc600, 0xc600, 0xc600, 0x7c00, 0x0000, 0x0000, 0x0000, 0x0000},
{0x0000, 0x0000, 0x1800, 0x1800, 0x1800, 0x0000, 0x0000, 0x1800, 0x1800, 0x1800, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000},
{0x0000, 0x6000, 0x3000, 0x3000, 0x3000, 0x0000, 0x0000, 0x3000, 0x3000, 0x3000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000},
{0x0000, 0x0000, 0x0400, 0x0c00, 0x1800, 0x3000, 0x6000, 0x3000, 0x1800, 0x0c00, 0x0400, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000},
{0x0000, 0x0000, 0x0000, 0x0000, 0xfc00, 0xfc00, 0x0000, 0x0000, 0xfc00, 0xfc00, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000},
{0x0000, 0x0000, 0x8000, 0xc000, 0x6000, 0x3000, 0x1800, 0x3000, 0x6000, 0xc000, 0x8000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000},
{0x0000, 0x0000, 0x3000, 0x0000, 0x3000, 0x3000, 0x1800, 0xcc00, 0xcc00, 0xcc00, 0x7800, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000},
{0x0000, 0x0000, 0x7c00, 0xc200, 0xdc00, 0xe600, 0xe600, 0xe600, 0xe600, 0xde00, 0xc600, 0x7c00, 0x0000, 0x0000, 0x0000, 0x0000},
{0x0000, 0x0000, 0xc600, 0xc600, 0xc600, 0xc600, 0xc600, 0xfe00, 0xc600, 0xc600, 0xc600, 0x7c00, 0x0000, 0x0000, 0x0000, 0x0000},
{0x0000, 0x0000, 0xfc00, 0xc600, 0xc600, 0xc600, 0xc600, 0xfc00, 0xc600, 0xc600, 0xc600, 0xfc00, 0x0000, 0x0000, 0x0000, 0x0000},
{0x0000, 0x0000, 0x7c00, 0xc600, 0xc600, 0xc000, 0xc000, 0xc000, 0xc000, 0xc600, 0xc600, 0x7c00, 0x0000, 0x0000, 0x0000, 0x0000},
{0x0000, 0x0000, 0xfc00, 0xc600, 0xc600, 0xc600, 0xc600, 0xc600, 0xc600, 0xc600, 0xc600, 0xfc00, 0x0000, 0x0000, 0x0000, 0x0000},
{0x0000, 0x0000, 0xfe00, 0xc000, 0xc000, 0xc000, 0xc000, 0xf800, 0xc000, 0xc000, 0xc000, 0xfe00, 0x0000, 0x0000, 0x0000, 0x0000},
{0x0000, 0x0000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xf800, 0xc000, 0xc000, 0xc000, 0xfe00, 0x0000, 0x0000, 0x0000, 0x0000},
{0x0000, 0x0000, 0x7c00, 0xc600, 0xc600, 0xc600, 0xde00, 0xc000, 0xc000, 0xc600, 0xc600, 0x7c00, 0x0000, 0x0000, 0x0000, 0x0000},
{0x0000, 0x0000, 0xc600, 0xc600, 0xc600, 0xc600, 0xc600, 0xfe00, 0xc600, 0xc600, 0xc600, 0xc600, 0x0000, 0x0000, 0x0000, 0x0000},
{0x0000, 0x0000, 0x3c00, 0x1800, 0x1800, 0x1800, 0x1800, 0x1800, 0x1800, 0x1800, 0x1800, 0x3c00, 0x0000, 0x0000, 0x0000, 0x0000},
{0x0000, 0x0000, 0x7c00, 0xc600, 0xc600, 0xc600, 0x0600, 0x0600, 0x0600, 0x0600, 0x0600, 0x0600, 0x0000, 0x0000, 0x0000, 0x0000},
{0x0000, 0x0000, 0xc200, 0xc600, 0xcc00, 0xd800, 0xf000, 0xf000, 0xd800, 0xcc00, 0xc600, 0xc200, 0x0000, 0x0000, 0x0000, 0x0000},
{0x0000, 0x0000, 0xfe00, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0x0000, 0x0000, 0x0000, 0x0000},
{0x0000, 0x0000, 0x8600, 0x8600, 0x8600, 0x8600, 0x8600, 0x9600, 0xbe00, 0xee00, 0xc600, 0x8200, 0x0000, 0x0000, 0x0000, 0x0000},
{0x0000, 0x0000, 0x8200, 0x8200, 0x8600, 0x8e00, 0x9e00, 0xba00, 0xf200, 0xe200, 0xc200, 0x8200, 0x0000, 0x0000, 0x0000, 0x0000},
{0x0000, 0x0000, 0x7c00, 0xc600, 0xc600, 0xc600, 0xc600, 0xc600, 0xc600, 0xc600, 0xc600, 0x7c00, 0x0000, 0x0000, 0x0000, 0x0000},
{0x0000, 0x0000, 0xc000, 0xc000, 0xc000, 0xc000, 0xfc00, 0xc600, 0xc600, 0xc600, 0xc600, 0xfc00, 0x0000, 0x0000, 0x0000, 0x0000},
{0x0600, 0x0600, 0x7c00, 0xce00, 0xc600, 0xc600, 0xc600, 0xc600, 0xc600, 0xc600, 0xc600, 0x7c00, 0x0000, 0x0000, 0x0000, 0x0000},
{0x0000, 0x0000, 0xc600, 0xc600, 0xc600, 0xcc00, 0xfc00, 0xc600, 0xc600, 0xc600, 0xc600, 0xfc00, 0x0000, 0x0000, 0x0000, 0x0000},
{0x0000, 0x0000, 0x7c00, 0xc600, 0xc600, 0x0600, 0x1c00, 0x7800, 0xe000, 0xc600, 0xc600, 0x7c00, 0x0000, 0x0000, 0x0000, 0x0000},
{0x0000, 0x0000, 0x1800, 0x1800, 0x1800, 0x1800, 0x1800, 0x1800, 0x1800, 0x1800, 0x1800, 0xfe00, 0x0000, 0x0000, 0x0000, 0x0000},
{0x0000, 0x0000, 0x7c00, 0xc600, 0xc600, 0xc600, 0xc600, 0xc600, 0xc600, 0xc600, 0xc600, 0xc600, 0x0000, 0x0000, 0x0000, 0x0000},
{0x0000, 0x0000, 0x7000, 0xf800, 0xcc00, 0xc600, 0xc600, 0xc600, 0xc600, 0xc600, 0xc600, 0xc600, 0x0000, 0x0000, 0x0000, 0x0000},
{0x0000, 0x0000, 0x4400, 0xee00, 0xfe00, 0xfa00, 0xd200, 0xc200, 0xc200, 0xc200, 0xc200, 0xc200, 0x0000, 0x0000, 0x0000, 0x0000},
{0x0000, 0x0000, 0xc600, 0xc600, 0xc600, 0x6c00, 0x3800, 0x3800, 0x6c00, 0xc600, 0xc600, 0xc600, 0x0000, 0x0000, 0x0000, 0x0000},
{0x0000, 0x0000, 0x1800, 0x1800, 0x1800, 0x1800, 0x3c00, 0x6600, 0xc200, 0xc200, 0xc200, 0xc200, 0x0000, 0x0000, 0x0000, 0x0000},
{0x0000, 0x0000, 0xfe00, 0xc000, 0xc000, 0x6000, 0x3000, 0x1800, 0x0c00, 0x0600, 0x0600, 0xfe00, 0x0000, 0x0000, 0x0000, 0x0000},
{0x0000, 0x7800, 0x6000, 0x6000, 0x6000, 0x6000, 0x6000, 0x6000, 0x6000, 0x6000, 0x6000, 0x6000, 0x7800, 0x0000, 0x0000, 0x0000},
{0x0000, 0x7800, 0x6000, 0x6000, 0x6000, 0x6000, 0x6000, 0x6000, 0x6000, 0x6000, 0x6000, 0x6000, 0x7800, 0x0000, 0x0000, 0x0000},
{0x0000, 0x3c00, 0x0c00, 0x0c00, 0x0c00, 0x0c00, 0x0c00, 0x0c00, 0x0c00, 0x0c00, 0x0c00, 0x0c00, 0x3c00, 0x0000, 0x0000, 0x0000},
{0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xc600, 0x6c00, 0x3800, 0x0000, 0x0000, 0x0000, 0x0000},
{0x0000, 0xfe00, 0xfe00, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000},
{0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0800, 0x1800, 0x1800, 0x1800, 0x0000, 0x0000, 0x0000, 0x0000},
{0x0000, 0x0000, 0x7600, 0xce00, 0xc600, 0xc600, 0x7e00, 0xc600, 0x7c00, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000},
{0x0000, 0x0000, 0xfc00, 0xc600, 0xc600, 0xc600, 0xc600, 0xe600, 0xdc00, 0xc000, 0xc000, 0xc000, 0x0000, 0x0000, 0x0000, 0x0000},
{0x0000, 0x0000, 0x7c00, 0xc600, 0xc000, 0xc000, 0xc000, 0xc600, 0x7c00, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000},
{0x0000, 0x0000, 0x7600, 0xce00, 0xc600, 0xc600, 0xc600, 0xc600, 0x7e00, 0x0600, 0x0600, 0x0600, 0x0000, 0x0000, 0x0000, 0x0000},
{0x0000, 0x0000, 0x7c00, 0xc600, 0xc000, 0xfe00, 0xc600, 0xc600, 0x7c00, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000},
{0x0000, 0x0000, 0x3000, 0x3000, 0x3000, 0x3000, 0x3000, 0x3000, 0x7c00, 0x3000, 0x3000, 0x1c00, 0x0000, 0x0000, 0x0000, 0x0000},
{0x7c00, 0xc600, 0x0600, 0x7600, 0xce00, 0xc600, 0xc600, 0xc600, 0x7e00, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000},
{0x0000, 0x0000, 0xc600, 0xc600, 0xc600, 0xc600, 0xc600, 0xe600, 0xdc00, 0xc000, 0xc000, 0xc000, 0x0000, 0x0000, 0x0000, 0x0000},
{0x0000, 0x0000, 0x3c00, 0x1800, 0x1800, 0x1800, 0x1800, 0x1800, 0x3800, 0x0000, 0x1800, 0x1800, 0x0000, 0x0000, 0x0000, 0x0000},
{0x7000, 0x1800, 0x1800, 0x1800, 0x1800, 0x1800, 0x1800, 0x1800, 0x3800, 0x0000, 0x1800, 0x1800, 0x0000, 0x0000, 0x0000, 0x0000},
{0x0000, 0x0000, 0xc600, 0xcc00, 0xd800, 0xf000, 0xf000, 0xd800, 0xce00, 0xc000, 0xc000, 0xc000, 0x0000, 0x0000, 0x0000, 0x0000},
{0x0000, 0x0000, 0x3c00, 0x1800, 0x1800, 0x1800, 0x1800, 0x1800, 0x1800, 0x1800, 0x1800, 0x3800, 0x0000, 0x0000, 0x0000, 0x0000},
{0x0000, 0x0000, 0xc600, 0xc600, 0xc600, 0xd600, 0xfe00, 0xee00, 0xc600, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000},
{0x0000, 0x0000, 0xc600, 0xc600, 0xc600, 0xc600, 0xc600, 0xe600, 0xdc00, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000},
{0x0000, 0x0000, 0x7c00, 0xc600, 0xc600, 0xc600, 0xc600, 0xc600, 0x7c00, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000},
{0xc000, 0xc000, 0xc000, 0xfc00, 0xc600, 0xc600, 0xc600, 0xe600, 0xdc00, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000},
{0x0600, 0x0600, 0x0600, 0x7600, 0xce00, 0xc600, 0xc600, 0xc600, 0x7e00, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000},
{0x0000, 0x0000, 0x6000, 0x6000, 0x6000, 0x6000, 0x6000, 0x7200, 0x6e00, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000},
{0x0000, 0x0000, 0x7c00, 0xc600, 0x0e00, 0x3800, 0xe000, 0xc600, 0x7c00, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000},
{0x0000, 0x0000, 0x1c00, 0x3000, 0x3000, 0x3000, 0x3000, 0x3000, 0xfc00, 0x3000, 0x3000, 0x3000, 0x0000, 0x0000, 0x0000, 0x0000},
{0x0000, 0x0000, 0x7600, 0xce00, 0xc600, 0xc600, 0xc600, 0xc600, 0xc600, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000},
{0x0000, 0x0000, 0xf000, 0xc800, 0xc400, 0xc600, 0xc600, 0xc600, 0xc600, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000},
{0x0000, 0x0000, 0xc600, 0xee00, 0xfe00, 0xd600, 0xc600, 0xc600, 0xc600, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000},
{0x0000, 0x0000, 0xc600, 0xc600, 0x6c00, 0x3800, 0x6c00, 0xc600, 0xc600, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000},
{0x7c00, 0xc600, 0x0600, 0x7600, 0xce00, 0xc600, 0xc600, 0xc600, 0xc600, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000},
{0x0000, 0x0000, 0xfe00, 0xc000, 0x6000, 0x3800, 0x0c00, 0x0600, 0xfe00, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000},
{0x0000, 0x1800, 0x3000, 0x3000, 0x3000, 0x3000, 0x6000, 0x6000, 0x3000, 0x3000, 0x3000, 0x3000, 0x1800, 0x0000, 0x0000, 0x0000},
{0x3000, 0x3000, 0x3000, 0x3000, 0x3000, 0x3000, 0x3000, 0x3000, 0x3000, 0x3000, 0x3000, 0x3000, 0x3000, 0x0000, 0x0000, 0x0000},
{0x0000, 0x6000, 0x3000, 0x3000, 0x3000, 0x3000, 0x1800, 0x1800, 0x3000, 0x3000, 0x3000, 0x3000, 0x6000, 0x0000, 0x0000, 0x0000},
{0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0400, 0xce00, 0x7200, 0x2000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000}};

#endif

static void
GLWin_SetPolyMode(GLWin* glwin, Vint polyflag);
static void
GLWin_vec3Matrix4(Vfloat tm[4][4], Vfloat x[3], Vfloat p[3]);

/*----------------------------------------------------------------------
                      drawing functions
----------------------------------------------------------------------*/
void
GLWinColor(GLWin* glwin, Vfloat c[3])
{
#ifdef VKI_3DAPI_OPENGL
    glColor3fv(c);
#endif
    glwin->crgb[0] = c[0];
    glwin->crgb[1] = c[1];
    glwin->crgb[2] = c[2];
}

void
GLWinTrans(GLWin* glwin, Vfloat transp)
{
    /*
       Transparency may be implemented using patterns or alpha blending
       depending upon the graphics hardware.
    */
}

void
GLWinLineStyle(GLWin* glwin, Vint lstyle)
{
#ifdef VKI_3DAPI_OPENGL
    if (lstyle == 0) {
        glDisable(GL_LINE_STIPPLE);
    }
    else {
        glLineStipple(1, lsmask[lstyle - 1]);
        glEnable(GL_LINE_STIPPLE);
    }
#endif
}

void
GLWinLineWidth(GLWin* glwin, Vint lwidth)
{
#ifdef VKI_3DAPI_OPENGL
    glLineWidth((GLfloat)lwidth);
#endif
}

void
GLWinPointSize(GLWin* glwin, Vint psize)
{
#ifdef VKI_3DAPI_OPENGL
    glPointSize((GLfloat)psize);
#endif
}

void
GLWinSetMode(GLWin* glwin, Vint mode, Vint flag)
{
#ifdef VKI_3DAPI_OPENGL
    if (mode == VGL_BACKFACECULLMODE) {
        if (flag == 0) {
            glDisable(GL_CULL_FACE);
        }
        else {
            glCullFace(GL_BACK);
            glEnable(GL_CULL_FACE);
        }
    }
    else if (mode == VGL_LIGHTMODE) {
        if (flag == 0) {
            glDisable(GL_LIGHTING);
            glDisable(GL_COLOR_MATERIAL);
        }
        else {
            glEnable(GL_LIGHTING);
            glEnable(GL_COLOR_MATERIAL);
        }
        glwin->lightmode = flag;
    }
#endif
}

void
GLWinTexture(GLWin* glwin, Vint width, Vint height, Vfloat c[][3])
{
#ifdef VKI_3DAPI_OPENGL
    int i, j;
    unsigned int* pixels;
    /* turn off texture mapping */
    if (width == 0 && height == 0) {
        glDisable(GL_TEXTURE_1D);
        glDisable(GL_TEXTURE_2D);
        return;
    }
    /* turn on texture mapping */
    /* set texture properties */
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    /* set texture environment */
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    /* load texture data */
    pixels = (unsigned int*)malloc(width * height * sizeof(unsigned int));
    for (i = 0; i < width * height; i++) {
        pixels[i] = 0;
        for (j = 0; j < 3; j++) {
            pixels[i] += (int)(255 * c[i][j]) << (24 - j * 8);
        }
    }
    if (height == 1) {
        glTexImage1D(GL_TEXTURE_1D, 0, 4, width, 0, GL_RGBA, GL_UNSIGNED_BYTE, (GLvoid*)pixels);
        /* 2D texture */
    }
    else {
        glTexImage2D(GL_TEXTURE_2D, 0, 4, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, (GLvoid*)pixels);
    }
    free(pixels);
    if (height == 1) {
        glEnable(GL_TEXTURE_1D);
        glDisable(GL_TEXTURE_2D);
    }
    else {
        glDisable(GL_TEXTURE_1D);
        glEnable(GL_TEXTURE_2D);
    }
#endif
}

void
GLWinPolyPoint(GLWin* glwin, Vint npts, Vfloat x[][3])
{
    GLWin_SetPolyMode(glwin, 1);
    GLWin_SetPolyMode(glwin, 0);
#ifdef VKI_3DAPI_OPENGL
    glBegin(GL_POINTS);
    for (int i = 0; i < npts; i++) {
        glVertex3fv(x[i]);
    }
    glEnd();
#endif
}

void
GLWinPolyPointDC(GLWin* glwin, Vint npts, Vfloat x[3], Vint dc[][3])
{
    GLWin_SetPolyMode(glwin, 1);
    GLWin_SetPolyMode(glwin, 0);
#ifdef VKI_3DAPI_OPENGL
    float xfm[4][4];
    float p[3];
    float xd[3];

    glGetFloatv(GL_MODELVIEW_MATRIX, (GLfloat*)xfm);
    GLWin_vec3Matrix4(xfm, x, p);
    glLoadIdentity();
    glBegin(GL_POINTS);
    for (int i = 0; i < npts; i++) {
        xd[0] = p[0] + dc[i][0] * glwin->projsx;
        xd[1] = p[1] + dc[i][1] * glwin->projsy;
        xd[2] = p[2];
        glVertex3fv(xd);
    }
    glEnd();
    glLoadMatrixf((GLfloat*)xfm);
#endif
}

void
GLWinPolyLine(GLWin* glwin, Vint polylinetype, Vint npts, Vfloat x[][3])
{
    GLWin_SetPolyMode(glwin, 1);
    GLWin_SetPolyMode(glwin, 0);
#ifdef VKI_3DAPI_OPENGL
    int i;

    if (polylinetype == VGL_LINELOOP) {
        glBegin(GL_LINE_LOOP);
        for (i = 0; i < npts; i++) {
            glVertex3fv(x[i]);
        }
        glEnd();
    }
    else if (polylinetype == VGL_LINESTRIP) {
        glBegin(GL_LINE_STRIP);
        for (i = 0; i < npts; i++) {
            glVertex3fv(x[i]);
        }
        glEnd();
    }
#endif
}

void
GLWinPolyLineColor(GLWin* glwin, Vint polylinetype, Vint npts, Vfloat x[][3], Vfloat c[][3])
{
    GLWin_SetPolyMode(glwin, 1);
    GLWin_SetPolyMode(glwin, 0);
#ifdef VKI_3DAPI_OPENGL
    int i;

    if (polylinetype == VGL_LINELOOP) {
        glBegin(GL_LINE_LOOP);
        for (i = 0; i < npts; i++) {
            glColor3fv(c[i]);
            glVertex3fv(x[i]);
        }
        glEnd();
    }
    else if (polylinetype == VGL_LINESTRIP) {
        glBegin(GL_LINE_STRIP);
        for (i = 0; i < npts; i++) {
            glColor3fv(c[i]);
            glVertex3fv(x[i]);
        }
        glEnd();
    }
#endif
}

void
GLWinPolyLineDC(GLWin* glwin, Vint polylinetype, Vint npts, Vfloat x[3], Vint dc[][3])
{
    GLWin_SetPolyMode(glwin, 1);
    GLWin_SetPolyMode(glwin, 0);
#ifdef VKI_3DAPI_OPENGL

    int i;
    float xfm[4][4];
    float p[3];
    float xd[3];

    glGetFloatv(GL_MODELVIEW_MATRIX, (GLfloat*)xfm);
    GLWin_vec3Matrix4(xfm, x, p);
    glLoadIdentity();
    if (polylinetype == VGL_LINELOOP) {
        glBegin(GL_LINE_LOOP);
        for (i = 0; i < npts; i++) {
            xd[0] = p[0] + dc[i][0] * glwin->projsx;
            xd[1] = p[1] + dc[i][1] * glwin->projsy;
            xd[2] = p[2];
            glVertex3fv(xd);
        }
        glEnd();
    }
    else if (polylinetype == VGL_LINESTRIP) {
        glBegin(GL_LINE_STRIP);
        for (i = 0; i < npts; i++) {
            xd[0] = p[0] + dc[i][0] * glwin->projsx;
            xd[1] = p[1] + dc[i][1] * glwin->projsy;
            xd[2] = p[2];
            glVertex3fv(xd);
        }
        glEnd();
    }
    glLoadMatrixf((GLfloat*)xfm);
#endif
}

void
GLWinPolygon(GLWin* glwin, Vint polygontype, Vint npts, Vfloat x[][3], Vint vflag, Vfloat v[])
{
    GLWin_SetPolyMode(glwin, 1);
#ifdef VKI_3DAPI_OPENGL
    int i;
    int vf, tf;
    float (*vn)[3], *t = NULL;

    vf = vflag & VGL_ANYSHADE;
    tf = vflag & VGL_ANYTEXTURE;
    vn = (Vfloat(*)[3])v;
    if (tf) {
        t = &vn[NUMBNORM(vf, polygontype, npts)][0];
    }

    if (polygontype == VGL_POLYGON) {
        glBegin(GL_POLYGON);
        if (vf == VGL_FLATSHADE)
            glNormal3fv(vn[0]);
        for (i = 0; i < npts; i++) {
            if (vf == VGL_VERTEXSHADE)
                glNormal3fv(vn[i]);
            if (tf == VGL_1DTEXTURE)
                glTexCoord1f(t[i]);
            glVertex3fv(x[i]);
        }
        glEnd();
    }
    else if (polygontype == VGL_QUADS) {
        glBegin(GL_QUADS);
        for (i = 0; i < npts; i++) {
            if (vf == VGL_FLATSHADE && i % 4 == 0)
                glNormal3fv(vn[i / 4]);
            if (vf == VGL_VERTEXSHADE)
                glNormal3fv(vn[i]);
            if (tf == VGL_1DTEXTURE)
                glTexCoord1f(t[i]);
            glVertex3fv(x[i]);
        }
        glEnd();
    }
    else if (polygontype == VGL_TRIANGLES) {
        glBegin(GL_TRIANGLES);
        for (i = 0; i < npts; i++) {
            if (vf == VGL_FLATSHADE && i % 4 == 0)
                glNormal3fv(vn[i / 3]);
            if (vf == VGL_VERTEXSHADE)
                glNormal3fv(vn[i]);
            if (tf == VGL_1DTEXTURE)
                glTexCoord1f(t[i]);
            glVertex3fv(x[i]);
        }
        glEnd();
    }
    else if (polygontype == VGL_TRISTRIP) {
        glBegin(GL_TRIANGLE_STRIP);
        for (i = 0; i < npts; i++) {
            if (vf == VGL_VERTEXSHADE)
                glNormal3fv(vn[i]);
            if (tf == VGL_1DTEXTURE)
                glTexCoord1f(t[i]);
            glVertex3fv(x[i]);
        }
        glEnd();
    }
#endif
}

void
GLWinPolygonColor(GLWin* glwin, Vint polygontype, Vint npts, Vfloat x[][3], Vfloat c[][3], Vint vflag, Vfloat v[])
{
    GLWin_SetPolyMode(glwin, 1);
#ifdef VKI_3DAPI_OPENGL
    int i;
    float (*vn)[3];
    vn = (Vfloat(*)[3])v;

    if (polygontype == VGL_POLYGON) {
        glBegin(GL_POLYGON);
        if (vflag == VGL_FLATSHADE)
            glNormal3fv(vn[0]);
        for (i = 0; i < npts; i++) {
            if (vflag == VGL_VERTEXSHADE)
                glNormal3fv(vn[i]);
            glColor3fv(c[i]);
            glVertex3fv(x[i]);
        }
        glEnd();
    }
    else if (polygontype == VGL_QUADS) {
        glBegin(GL_QUADS);
        for (i = 0; i < npts; i++) {
            if (vflag)
                glNormal3fv(vn[i]);
            glColor3fv(c[i]);
            glVertex3fv(x[i]);
        }
        glEnd();
    }
    else if (polygontype == VGL_TRIANGLES) {
        glBegin(GL_TRIANGLES);
        for (i = 0; i < npts; i++) {
            if (vflag)
                glNormal3fv(vn[i]);
            glColor3fv(c[i]);
            glVertex3fv(x[i]);
        }
        glEnd();
    }
    else if (polygontype == VGL_TRISTRIP) {
        glBegin(GL_TRIANGLE_STRIP);
        for (i = 0; i < npts; i++) {
            if (vflag)
                glNormal3fv(vn[i]);
            glColor3fv(c[i]);
            glVertex3fv(x[i]);
        }
        glEnd();
    }
#endif
}

void
GLWinPolygonDC(GLWin* glwin, Vint polygontype, Vint npts, Vfloat x[3], Vint dc[][3])
{
    GLWin_SetPolyMode(glwin, 1);
#ifdef VKI_3DAPI_OPENGL

    int i;
    float xfm[4][4];
    float p[3];
    float xd[3];

    if (glwin->lightmode) {
        glDisable(GL_LIGHTING);
        glDisable(GL_COLOR_MATERIAL);
    }
    glGetFloatv(GL_MODELVIEW_MATRIX, (GLfloat*)xfm);
    GLWin_vec3Matrix4(xfm, x, p);
    glLoadIdentity();
    if (polygontype == VGL_POLYGON) {
        glBegin(GL_POLYGON);
        for (i = 0; i < npts; i++) {
            xd[0] = p[0] + dc[i][0] * glwin->projsx;
            xd[1] = p[1] + dc[i][1] * glwin->projsy;
            xd[2] = p[2];
            glVertex3fv(xd);
        }
        glEnd();
    }
    else if (polygontype == VGL_QUADS) {
        glBegin(GL_QUADS);
        for (i = 0; i < npts; i++) {
            xd[0] = p[0] + dc[i][0] * glwin->projsx;
            xd[1] = p[1] + dc[i][1] * glwin->projsy;
            xd[2] = p[2];
            glVertex3fv(xd);
        }
        glEnd();
    }
    else if (polygontype == VGL_TRISTRIP) {
        glBegin(GL_TRIANGLE_STRIP);
        for (i = 0; i < npts; i++) {
            xd[0] = p[0] + dc[i][0] * glwin->projsx;
            xd[1] = p[1] + dc[i][1] * glwin->projsy;
            xd[2] = p[2];
            glVertex3fv(xd);
        }
        glEnd();
    }
    glLoadMatrixf((GLfloat*)xfm);
    if (glwin->lightmode) {
        glEnable(GL_LIGHTING);
        glEnable(GL_COLOR_MATERIAL);
    }
#endif
}

void
GLWinText(GLWin* glwin, Vfloat x[3], Vchar* string)
{
    GLWin_SetPolyMode(glwin, 1);
    GLWin_SetPolyMode(glwin, 0);
#ifdef VKI_3DAPI_OPENGL
    glRasterPos3fv(x);
    glPushAttrib(GL_LIST_BIT);
    glListBase(glwin->fontoffset);
    glCallLists((GLsizei)strlen(string), GL_UNSIGNED_BYTE, (GLubyte*)string);
    glPopAttrib();
#endif
}

void
GLWinTextDC(GLWin* glwin, Vfloat x[3], Vint dc[3], Vchar* string)
{
    GLWin_SetPolyMode(glwin, 1);
    GLWin_SetPolyMode(glwin, 0);
#ifdef VKI_3DAPI_OPENGL
    float xfm[4][4];
    float p[3], xd[3];

    glGetFloatv(GL_MODELVIEW_MATRIX, (GLfloat*)xfm);
    GLWin_vec3Matrix4(xfm, x, p);
    glLoadIdentity();
    xd[0] = p[0] + dc[0] * glwin->projsx;
    xd[1] = p[1] + dc[1] * glwin->projsy;
    xd[2] = p[2];
    glRasterPos3fv(xd);
    glPushAttrib(GL_LIST_BIT);
    glListBase(glwin->fontoffset);
    glCallLists((GLsizei)strlen(string), GL_UNSIGNED_BYTE, (GLubyte*)string);
    glPopAttrib();
    glLoadMatrixf((GLfloat*)xfm);
#endif
}

/*----------------------------------------------------------------------
                      object begin
----------------------------------------------------------------------*/
GLWin*
GLWinBegin(void)
{
    GLWin* glwin;

    glwin = (GLWin*)malloc(sizeof(GLWin));

#ifdef VKI_3DAPI_OPENGL
    glwin->fontoffset = 0;
#endif
#ifdef VKI_WIND_X11
    glwin->dpy = NULL;
#endif
#ifdef VKI_WIND_WIN32
    glwin->hWnd = NULL;
    glwin->hDC = NULL;
    glwin->hRC = NULL;
#endif
    glwin->pxmn = 0;
    glwin->pxmx = 0;
    glwin->pymn = 0;
    glwin->pymx = 0;
    glwin->right = 0;
    glwin->left = 0;
    glwin->bottom = 0;
    glwin->top = 0;
    glwin->nearz = 0;
    glwin->farz = 0;
    glwin->projsx = 0;
    glwin->projsy = 0;
    glwin->polymode = 0;
    glwin->lightmode = 0;

    return (glwin);
}

/*----------------------------------------------------------------------
                      object end
----------------------------------------------------------------------*/
void
GLWinEnd(GLWin* glwin)
{
    GLWinDestroyWindow(glwin);
    free(glwin);
}

/*----------------------------------------------------------------------
                      create window
----------------------------------------------------------------------*/
void
GLWinCreateWindow(GLWin* glwin, Vint xorig, Vint yorig, Vint xsize, Vint ysize)
{
#ifdef VKI_3DAPI_OPENGL
    int i;
    GLfloat c4[4], x4[4];
#ifdef VKI_WIND_X11
    Display* dpy;
    XVisualInfo* vis;
    Colormap cm;
    XSetWindowAttributes wa;
    Window win;
    GLXContext cx;
    XSizeHints size_hints;
    int ysiz, xori, yori;
    static int al[] = {GLX_DOUBLEBUFFER, GLX_RGBA, GLX_DEPTH_SIZE, 16, None};

    dpy = XOpenDisplay(0);
    vis = glXChooseVisual(dpy, DefaultScreen(dpy), al);
    cx = glXCreateContext(dpy, vis, 0, GL_TRUE);
    cm = XCreateColormap(dpy, RootWindow(dpy, vis->screen), vis->visual, AllocNone);
    wa.colormap = cm;
    wa.border_pixel = 0;
    wa.event_mask = ExposureMask | StructureNotifyMask;
    (void)DisplayWidth(dpy, vis->screen);
    ysiz = DisplayHeight(dpy, vis->screen);
    xori = xorig;
    yori = ysiz - yorig - ysize;

    win = XCreateWindow(dpy, RootWindow(dpy, vis->screen), xori, yori, xsize, ysize, 0, vis->depth, InputOutput, vis->visual,
                        CWBorderPixel | CWColormap | CWEventMask, &wa);
    size_hints.flags = USPosition | USSize;
    size_hints.width = xsize;
    size_hints.height = ysize;
    size_hints.x = xori;
    size_hints.y = yori;

    XSetStandardProperties(dpy, win, "OpenGL X11", "OpenGL", None, 0, 0, &size_hints);
    XFree((char*)vis);

    XMapWindow(dpy, win);
    glXMakeCurrent(dpy, win, cx);
    glwin->dpy = dpy;
    glwin->win = win;
#endif
#ifdef VKI_WIND_WIN32
    HINSTANCE hInstance;
    RECT rect;
#ifdef UNICODE
    static wchar_t szAppName[] = L"OpenGL";
    static wchar_t szTitle[] = L"OpenGL Windows";
#else
    static Vchar szAppName[] = "OpenGL";
    static Vchar szTitle[] = "OpenGL Windows";
#endif
    static WNDCLASS wc;
    static PIXELFORMATDESCRIPTOR pfd = {sizeof(PIXELFORMATDESCRIPTOR),
                                        1,
                                        PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER,
                                        PFD_TYPE_RGBA,
                                        24,
                                        0,
                                        0,
                                        0,
                                        0,
                                        0,
                                        0,
                                        0,
                                        0,
                                        0,
                                        0,
                                        0,
                                        0,
                                        0,
                                        24,
                                        0,
                                        0,
                                        PFD_MAIN_PLANE,
                                        0,
                                        0,
                                        0,
                                        0};
    int nMyPixelFormatID;

    hInstance = GetModuleHandle(NULL);

    wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.lpfnWndProc = (WNDPROC)DefWindowProc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = hInstance;
    wc.hIcon = NULL;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
    wc.lpszMenuName = NULL;
    wc.lpszClassName = szAppName;

    RegisterClass(&wc);

    SetRect(&rect, xorig, yorig, xorig + xsize - 1, yorig + ysize - 1);
    AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN | WS_CLIPSIBLINGS, FALSE);

    glwin->hWnd = CreateWindow(szAppName, szTitle, WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN | WS_CLIPSIBLINGS, rect.left, rect.top,
                               rect.right - rect.left + 1, rect.bottom - rect.top + 1, NULL, NULL, hInstance, NULL);
    ShowWindow(glwin->hWnd, SW_SHOWDEFAULT);
    UpdateWindow(glwin->hWnd);

    glwin->hDC = GetDC(glwin->hWnd);
    nMyPixelFormatID = ChoosePixelFormat(glwin->hDC, &pfd);
    SetPixelFormat(glwin->hDC, nMyPixelFormatID, &pfd);
    glwin->hRC = wglCreateContext(glwin->hDC);
    wglMakeCurrent(glwin->hDC, glwin->hRC);
#endif

    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, rgba_zero);
    glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_FALSE);
    /* material for all lighting */
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, rgba_zero);
    glEnable(GL_NORMALIZE);
    glMatrixMode(GL_MODELVIEW);
    glwin->polymode = -1;

    glEnable(GL_DEPTH_TEST);
    glDepthRange(0., 1.);
    glDepthFunc(GL_LEQUAL);
    glClearDepth(1.);

    glLoadIdentity();
    glClearColor(.0, .0, .0, 1.);

    c4[0] = .5;
    c4[1] = .5;
    c4[2] = .5;
    c4[3] = 0.;
    glLightfv(GL_LIGHT0, GL_AMBIENT, c4);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, rgba_zero);
    glLightfv(GL_LIGHT0, GL_SPECULAR, rgba_zero);
    glEnable(GL_LIGHT0);
    c4[0] = .5;
    c4[1] = .5;
    c4[2] = .5;
    c4[3] = 0.;
    glLightfv(GL_LIGHT1, GL_AMBIENT, rgba_zero);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, c4);
    glLightfv(GL_LIGHT1, GL_SPECULAR, c4);
    x4[0] = 1.;
    x4[1] = 2.;
    x4[2] = 3.;
    x4[3] = 0.;
    glLightfv(GL_LIGHT1, GL_POSITION, x4);
    glEnable(GL_LIGHT1);

    glLightfv(GL_LIGHT2, GL_AMBIENT, rgba_zero);
    glLightfv(GL_LIGHT2, GL_DIFFUSE, c4);
    glLightfv(GL_LIGHT2, GL_SPECULAR, c4);
    x4[0] = -1.;
    x4[1] = -2.;
    x4[2] = -3.;
    x4[3] = 0.;
    glLightfv(GL_LIGHT2, GL_POSITION, x4);
    glEnable(GL_LIGHT2);
    glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);
    glwin->lightmode = VGL_ON;

    glDisable(GL_LINE_STIPPLE);
    glDisable(GL_POLYGON_STIPPLE);
    glEnable(GL_POLYGON_OFFSET_FILL);
    glPolygonOffset(1., 1.);

    /* raster font */
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    glwin->fontoffset = glGenLists(128);
    for (i = 32; i < 127; i++) {
        glNewList(i + glwin->fontoffset, GL_COMPILE);
        glBitmap(16, 16, 0., 2., 9., 0., (GLubyte*)fontmask[i - 32]);
        glEndList();
    }
#endif
    GLWinViewport(glwin, 0, xsize - 1, 0, ysize - 1);
    GLWinOrtho(glwin, -1., 1., -1., 1., -1., 1.);
}

/*----------------------------------------------------------------------
                      destroy window
----------------------------------------------------------------------*/
void
GLWinDestroyWindow(GLWin* glwin)
{
#ifdef VKI_3DAPI_OPENGL
    /* free raster font lists */
    glDeleteLists(glwin->fontoffset, 128);
#endif
}

/*----------------------------------------------------------------------
                      orthographic view
----------------------------------------------------------------------*/
void
GLWinOrtho(GLWin* glwin, Vfloat left, Vfloat right, Vfloat bottom, Vfloat top, Vfloat nearz, Vfloat farz)
{
#ifdef VKI_3DAPI_OPENGL
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho((GLdouble)left, (GLdouble)right, (GLdouble)bottom, (GLdouble)top, (GLdouble)nearz, (GLdouble)farz);
    glMatrixMode(GL_MODELVIEW);
#endif
    glwin->left = left;
    glwin->right = right;
    glwin->bottom = bottom;
    glwin->top = top;
    glwin->nearz = nearz;
    glwin->farz = farz;
    glwin->projsx = (glwin->right - glwin->left) / (glwin->pxmx - glwin->pxmn + 1);
    glwin->projsy = (glwin->top - glwin->bottom) / (glwin->pymx - glwin->pymn + 1);
}

/*----------------------------------------------------------------------
                      Viewport
----------------------------------------------------------------------*/
void
GLWinViewport(GLWin* glwin, Vint left, Vint right, Vint bottom, Vint top)
{
#ifdef VKI_3DAPI_OPENGL
    glViewport(left, bottom, (right - left + 1), (top - bottom + 1));
#endif
    glwin->pxmn = left;
    glwin->pxmx = right;
    glwin->pymn = bottom;
    glwin->pymx = top;
}

/*----------------------------------------------------------------------
                      clear
----------------------------------------------------------------------*/
void
GLWinClear(GLWin* glwin)
{
#ifdef VKI_3DAPI_OPENGL
    glColor3f(0., 0., 0.);
    if (glwin->lightmode) {
        glDisable(GL_LIGHTING);
    }
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    if (glwin->lightmode) {
        glEnable(GL_LIGHTING);
    }
    glColor3fv(glwin->crgb);
#endif
}

/*----------------------------------------------------------------------
                      swap
----------------------------------------------------------------------*/
void
GLWinSwap(GLWin* glwin)
{
#ifdef VKI_3DAPI_OPENGL
    glFlush();
    glFinish();
#ifdef VKI_WIND_X11
    glXSwapBuffers(glwin->dpy, glwin->win);
#endif
#ifdef VKI_WIND_WIN32
    SwapBuffers(glwin->hDC);
#endif

#endif
}

/*----------------------------------------------------------------------
                      rotate
----------------------------------------------------------------------*/
void
GLWinRotate(GLWin* glwin, Vfloat deg, Vchar axis)
{
#ifdef VKI_3DAPI_OPENGL
    if (axis == 'x' || axis == 'X')
        glRotatef(deg, 1., 0., 0.);
    if (axis == 'y' || axis == 'Y')
        glRotatef(deg, 0., 1., 0.);
    if (axis == 'z' || axis == 'Z')
        glRotatef(deg, 0., 0., 1.);
#endif
}

/*----------------------------------------------------------------------
                      translate
----------------------------------------------------------------------*/
void
GLWinTranslate(GLWin* glwin, Vfloat x, Vfloat y, Vfloat z)
{
#ifdef VKI_3DAPI_OPENGL
    glTranslatef(x, y, z);
#endif
}

/*----------------------------------------------------------------------
                      push
----------------------------------------------------------------------*/
void
GLWinXfmPush(GLWin* glwin)
{
#ifdef VKI_3DAPI_OPENGL
    glPushMatrix();
#endif
}

/*----------------------------------------------------------------------
                      pop
----------------------------------------------------------------------*/
void
GLWinXfmPop(GLWin* glwin)
{
#ifdef VKI_3DAPI_OPENGL
    glPopMatrix();
#endif
}

/*----------------------------------------------------------------------
                      load
----------------------------------------------------------------------*/
void
GLWinXfmLoad(GLWin* glwin, Vfloat xfm[4][4])
{
#ifdef VKI_3DAPI_OPENGL
    glLoadMatrixf((GLfloat*)xfm);
#endif
}

/*----------------------------------------------------------------------
                      get
----------------------------------------------------------------------*/
void
GLWinXfmGet(GLWin* glwin, Vfloat tm[4][4])
{
#ifdef VKI_3DAPI_OPENGL
    glGetFloatv(GL_MODELVIEW_MATRIX, (GLfloat*)tm);
#endif
}

/*----------------------------------------------------------------------
                      delay
----------------------------------------------------------------------*/
void
GLWinDelay(GLWin* glwin, Vfloat sec)
{
#ifdef VKI_WIND_X11
    int isec;
    isec = (int)sec;
    sleep(isec);
#endif
#ifdef VKI_WIND_WIN32
    int msec;
    msec = (int)(1000 * sec);
    Sleep(msec);
#endif
}

/*----------------------------------------------------------------------
                      fill draw function object
----------------------------------------------------------------------*/
void
GLWinDrawFun(GLWin* glwin, vgl_DrawFun* df)
{
    vgl_DrawFunSetObj(df, glwin);
    vgl_DrawFunAPI(df, DRAWFUN_APIRETURN);
    vgl_DrawFunSet(df, DRAWFUN_COLOR, (void (*)(void))GLWinColor);
    vgl_DrawFunSet(df, DRAWFUN_TRANS, (void (*)(void))GLWinTrans);
    vgl_DrawFunSet(df, DRAWFUN_LINESTYLE, (void (*)(void))GLWinLineStyle);
    vgl_DrawFunSet(df, DRAWFUN_LINEWIDTH, (void (*)(void))GLWinLineWidth);
    vgl_DrawFunSet(df, DRAWFUN_POINTSIZE, (void (*)(void))GLWinPointSize);
    vgl_DrawFunSet(df, DRAWFUN_SETMODE, (void (*)(void))GLWinSetMode);
    vgl_DrawFunSet(df, DRAWFUN_POLYPOINT, (void (*)(void))GLWinPolyPoint);
    vgl_DrawFunSet(df, DRAWFUN_POLYPOINTDC, (void (*)(void))GLWinPolyPointDC);
    vgl_DrawFunSet(df, DRAWFUN_POLYLINE, (void (*)(void))GLWinPolyLine);
    vgl_DrawFunSet(df, DRAWFUN_POLYLINECOLOR, (void (*)(void))GLWinPolyLineColor);
    vgl_DrawFunSet(df, DRAWFUN_POLYLINEDC, (void (*)(void))GLWinPolyLineDC);
    vgl_DrawFunSet(df, DRAWFUN_POLYGON, (void (*)(void))GLWinPolygon);
    vgl_DrawFunSet(df, DRAWFUN_POLYGONCOLOR, (void (*)(void))GLWinPolygonColor);
    vgl_DrawFunSet(df, DRAWFUN_POLYGONDC, (void (*)(void))GLWinPolygonDC);
    vgl_DrawFunSet(df, DRAWFUN_TEXT, (void (*)(void))GLWinText);
    vgl_DrawFunSet(df, DRAWFUN_TEXTDC, (void (*)(void))GLWinTextDC);
    vgl_DrawFunSet(df, DRAWFUN_DELAY, (void (*)(void))GLWinDelay);
    vgl_DrawFunSet(df, DRAWFUN_CLEAR, (void (*)(void))GLWinClear);
    vgl_DrawFunSet(df, DRAWFUN_SWAP, (void (*)(void))GLWinSwap);
    vgl_DrawFunSet(df, DRAWFUN_XFMPUSH, (void (*)(void))GLWinXfmPush);
    vgl_DrawFunSet(df, DRAWFUN_XFMPOP, (void (*)(void))GLWinXfmPop);
    vgl_DrawFunSet(df, DRAWFUN_XFMLOAD, (void (*)(void))GLWinXfmLoad);
}

/*----------------------------------------------------------------------
                      utility to set polygon lighting
----------------------------------------------------------------------*/
static void
GLWin_SetPolyMode(GLWin* glwin, Vint polyflag)
{
    if (polyflag) {
        if (!glwin->polymode) {
#ifdef VKI_3DAPI_OPENGL
            if (glwin->lightmode) {
                glEnable(GL_LIGHTING);
                glEnable(GL_COLOR_MATERIAL);
            }
#ifdef VKI_WIND_WIN32
            glBegin(GL_POLYGON);
#endif
            glColor3fv(glwin->crgb);
#ifdef VKI_WIND_WIN32
            glEnd();
#endif

#endif
            glwin->polymode = 1;
        }
    }
    else {
        if (glwin->polymode) {
#ifdef VKI_3DAPI_OPENGL
            if (glwin->lightmode) {
                glDisable(GL_LIGHTING);
                glDisable(GL_COLOR_MATERIAL);
            }
            glColor3fv(glwin->crgb);
#endif
            glwin->polymode = 0;
        }
    }
}

/*----------------------------------------------------------------------
                      utility for 3 vector by 4 matrix
----------------------------------------------------------------------*/
#if defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-function"
#endif
static void
GLWin_vec3Matrix4(Vfloat tm[4][4], Vfloat x[3], Vfloat p[3])
{
    p[0] = tm[0][0] * x[0] + tm[1][0] * x[1] + tm[2][0] * x[2] + tm[3][0];
    p[1] = tm[0][1] * x[0] + tm[1][1] * x[1] + tm[2][1] * x[2] + tm[3][1];
    p[2] = tm[0][2] * x[0] + tm[1][2] * x[1] + tm[2][2] * x[2] + tm[3][2];
}
#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif

#ifdef VKI_WIND_WIN32
extern void
sleep(int sec)
{
    int msec;

    msec = 1000 * sec;
    Sleep(msec);
}
#endif

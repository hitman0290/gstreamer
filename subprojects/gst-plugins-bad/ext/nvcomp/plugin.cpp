/* GStreamer
 * Copyright (C) 2024 Seungha Yang <seungha@centricular.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 51 Franklin St, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */

/**
 * plugin-nvcomp:
 *
 * Since: 1.26
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <gst/gst.h>
#include "gstnvcomp.h"
#include "gstnvcompvideodec.h"
#include "gstnvcompvideoenc.h"

static gboolean
plugin_init (GstPlugin * plugin)
{
  if (!gst_cuda_load_library ()) {
    gst_plugin_add_status_warning (plugin, "CUDA library was not found.");
    return TRUE;
  }

  gst_element_register (plugin,
      "nvcompvideodec", GST_RANK_NONE, GST_TYPE_NV_COMP_VIDEO_DEC);
  gst_element_register (plugin,
      "nvcompvideoenc", GST_RANK_NONE, GST_TYPE_NV_COMP_VIDEO_ENC);

  return TRUE;
}

GST_PLUGIN_DEFINE (GST_VERSION_MAJOR, GST_VERSION_MINOR, nvcomp,
    "GStreamer nvCOMP plugin", plugin_init, VERSION, "LGPL",
    GST_PACKAGE_NAME, GST_PACKAGE_ORIGIN)

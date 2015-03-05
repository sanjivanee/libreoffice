/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
/*
 * This file is part of the LibreOffice project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

/*
 This file has been autogenerated by update_pch.sh . It is possible to edit it
 manually (such as when an include file has been moved/renamed/removed. All such
 manual changes will be rewritten by the next run of update_pch.sh (which presumably
 also fixes all possible problems, so it's usually better to use it).
*/

#include <algorithm>
#include <basegfx/matrix/b2dhommatrix.hxx>
#include <basegfx/matrix/b2dhommatrixtools.hxx>
#include <basegfx/numeric/ftools.hxx>
#include <basegfx/point/b2dpoint.hxx>
#include <basegfx/polygon/b2dlinegeometry.hxx>
#include <basegfx/polygon/b2dpolygon.hxx>
#include <basegfx/polygon/b2dpolygonclipper.hxx>
#include <basegfx/polygon/b2dpolygontools.hxx>
#include <basegfx/polygon/b2dpolypolygon.hxx>
#include <basegfx/polygon/b2dpolypolygoncutter.hxx>
#include <basegfx/polygon/b2dpolypolygontools.hxx>
#include <basegfx/range/b2drange.hxx>
#include <basegfx/range/b2drectangle.hxx>
#include <basegfx/tools/canvastools.hxx>
#include <basegfx/tools/gradienttools.hxx>
#include <basegfx/tools/tools.hxx>
#include <basegfx/tuple/b2dtuple.hxx>
#include <basegfx/vector/b2dsize.hxx>
#include <basegfx/vector/b2dvector.hxx>
#include <boost/bind.hpp>
#include <boost/scoped_array.hpp>
#include <boost/utility.hpp>
#include <canvas/canvastools.hxx>
#include <canvas/debug.hxx>
#include <canvas/verbosetrace.hxx>
#include <com/sun/star/geometry/RealPoint2D.hpp>
#include <com/sun/star/rendering/InterpolationMode.hpp>
#include <com/sun/star/rendering/PanoseProportion.hpp>
#include <com/sun/star/rendering/PathCapType.hpp>
#include <com/sun/star/rendering/PathJoinType.hpp>
#include <com/sun/star/rendering/RenderState.hpp>
#include <com/sun/star/rendering/RepaintResult.hpp>
#include <com/sun/star/rendering/StringContext.hpp>
#include <com/sun/star/rendering/TexturingMode.hpp>
#include <com/sun/star/rendering/ViewState.hpp>
#include <com/sun/star/rendering/XAnimatedSprite.hpp>
#include <com/sun/star/rendering/XBitmap.hpp>
#include <com/sun/star/rendering/XBitmapCanvas.hpp>
#include <com/sun/star/rendering/XCachedPrimitive.hpp>
#include <com/sun/star/rendering/XCanvas.hpp>
#include <com/sun/star/rendering/XCanvasFont.hpp>
#include <com/sun/star/rendering/XGraphicDevice.hpp>
#include <com/sun/star/rendering/XPolyPolygon2D.hpp>
#include <com/sun/star/rendering/XSprite.hpp>
#include <com/sun/star/uno/Sequence.hxx>
#include <comphelper/anytostring.hxx>
#include <comphelper/sequence.hxx>
#include <cppuhelper/exc_hlp.hxx>
#include <i18nlangtag/languagetag.hxx>
#include <iterator>
#include <osl/diagnose.h>
#include <osl/getglobalmutex.hxx>
#include <osl/mutex.hxx>
#include <rtl/instance.hxx>
#include <rtl/math.hxx>
#include <rtl/ustring.hxx>
#include <sal/alloca.h>
#include <sal/types.h>
#include <stdio.h>
#include <tools/diagnose_ex.h>
#include <tools/gen.hxx>
#include <tools/poly.hxx>
#include <tools/stream.hxx>
#include <vcl/bitmapex.hxx>
#include <vcl/canvastools.hxx>
#include <vcl/gdimtf.hxx>
#include <vcl/gradient.hxx>
#include <vcl/graph.hxx>
#include <vcl/graphicfilter.hxx>
#include <vcl/graphictools.hxx>
#include <vcl/metaact.hxx>
#include <vcl/metric.hxx>
#include <vcl/outdev.hxx>
#include <vcl/salbtype.hxx>
#include <vcl/svapp.hxx>
#include <vcl/virdev.hxx>
#include <vcl/window.hxx>
#include <vector>

/* vim:set shiftwidth=4 softtabstop=4 expandtab: */
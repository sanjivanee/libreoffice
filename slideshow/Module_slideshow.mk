# -*- Mode: makefile-gmake; tab-width: 4; indent-tabs-mode: t -*-
#
# This file is part of the LibreOffice project.
#
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.
#

$(eval $(call gb_Module_Module,slideshow))

$(eval $(call gb_Module_add_targets,slideshow,\
    $(if $(filter TRUE,$(ENABLE_OPENGL)),Library_OGLTrans) \
    Library_slideshow \
	Package_opengl \
))

# not working
    # CppunitTest_slideshow \

# not built normally (and unbuildable anyway ;)
    # Executable_demoshow \

# vim: set noet sw=4 ts=4:
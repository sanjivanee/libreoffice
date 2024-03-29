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

#include "com/sun/star/uno/Sequence.hxx"
#include "comphelper/processfactory.hxx"
#include "comphelper/types.hxx"
#include "rtl/instance.hxx"
#include "rtl/ustring.hxx"
#include "sal/config.h"
#include "sal/types.h"
#include "svtools/imageresourceaccess.hxx"
#include <algorithm>
#include <boost/optional.hpp>
#include <boost/scoped_ptr.hpp>
#include <boost/unordered_map.hpp>
#include <com/sun/star/awt/ActionEvent.hpp>
#include <com/sun/star/awt/FontEmphasisMark.hpp>
#include <com/sun/star/awt/FontRelief.hpp>
#include <com/sun/star/awt/LineEndFormat.hpp>
#include <com/sun/star/awt/MouseButton.hpp>
#include <com/sun/star/awt/MouseEvent.hpp>
#include <com/sun/star/awt/PopupMenu.hpp>
#include <com/sun/star/awt/PopupMenuDirection.hpp>
#include <com/sun/star/awt/PosSize.hpp>
#include <com/sun/star/awt/SystemPointer.hpp>
#include <com/sun/star/awt/VclWindowPeerAttribute.hpp>
#include <com/sun/star/awt/XActionListener.hpp>
#include <com/sun/star/awt/XCheckBox.hpp>
#include <com/sun/star/awt/XComboBox.hpp>
#include <com/sun/star/awt/XControl.hpp>
#include <com/sun/star/awt/XControlContainer.hpp>
#include <com/sun/star/awt/XControlModel.hpp>
#include <com/sun/star/awt/XDialog.hpp>
#include <com/sun/star/awt/XItemList.hpp>
#include <com/sun/star/awt/XKeyListener.hpp>
#include <com/sun/star/awt/XListBox.hpp>
#include <com/sun/star/awt/XPopupMenu.hpp>
#include <com/sun/star/awt/XRadioButton.hpp>
#include <com/sun/star/awt/XTextComponent.hpp>
#include <com/sun/star/awt/XVclWindowPeer.hpp>
#include <com/sun/star/awt/XView.hpp>
#include <com/sun/star/awt/XWindow.hpp>
#include <com/sun/star/awt/XWindowListener2.hpp>
#include <com/sun/star/beans/NamedValue.hpp>
#include <com/sun/star/beans/NotRemoveableException.hpp>
#include <com/sun/star/beans/Property.hpp>
#include <com/sun/star/beans/PropertyAttribute.hpp>
#include <com/sun/star/beans/PropertyExistException.hpp>
#include <com/sun/star/beans/PropertyValue.hpp>
#include <com/sun/star/beans/StringPair.hpp>
#include <com/sun/star/beans/UnknownPropertyException.hpp>
#include <com/sun/star/beans/XFastPropertySet.hpp>
#include <com/sun/star/beans/XMultiPropertySet.hpp>
#include <com/sun/star/beans/XPropertyContainer.hpp>
#include <com/sun/star/beans/XPropertySet.hpp>
#include <com/sun/star/beans/XPropertySetInfo.hpp>
#include <com/sun/star/beans/XPropertyState.hpp>
#include <com/sun/star/container/NoSuchElementException.hpp>
#include <com/sun/star/container/XChild.hpp>
#include <com/sun/star/container/XEnumeration.hpp>
#include <com/sun/star/container/XIndexAccess.hpp>
#include <com/sun/star/container/XNameAccess.hpp>
#include <com/sun/star/container/XNameContainer.hpp>
#include <com/sun/star/container/XNamed.hpp>
#include <com/sun/star/container/XSet.hpp>
#include <com/sun/star/document/XCodeNameQuery.hpp>
#include <com/sun/star/form/DataSelectionType.hpp>
#include <com/sun/star/form/FormComponentType.hpp>
#include <com/sun/star/form/TabulatorCycle.hpp>
#include <com/sun/star/form/XBoundComponent.hpp>
#include <com/sun/star/form/XBoundControl.hpp>
#include <com/sun/star/form/XConfirmDeleteListener.hpp>
#include <com/sun/star/form/XForm.hpp>
#include <com/sun/star/form/XFormComponent.hpp>
#include <com/sun/star/form/XGrid.hpp>
#include <com/sun/star/form/XLoadable.hpp>
#include <com/sun/star/form/XReset.hpp>
#include <com/sun/star/form/XSubmit.hpp>
#include <com/sun/star/form/binding/XBindableValue.hpp>
#include <com/sun/star/form/runtime/FormFeature.hpp>
#include <com/sun/star/frame/Desktop.hpp>
#include <com/sun/star/frame/FrameSearchFlag.hpp>
#include <com/sun/star/frame/ModuleManager.hpp>
#include <com/sun/star/frame/XComponentLoader.hpp>
#include <com/sun/star/frame/XController.hpp>
#include <com/sun/star/frame/XDispatch.hpp>
#include <com/sun/star/frame/XDispatchProvider.hpp>
#include <com/sun/star/frame/XFrame.hpp>
#include <com/sun/star/frame/XModel.hpp>
#include <com/sun/star/frame/theUICommandDescription.hpp>
#include <com/sun/star/graphic/GraphicObject.hpp>
#include <com/sun/star/graphic/XGraphic.hpp>
#include <com/sun/star/io/NotConnectedException.hpp>
#include <com/sun/star/io/Pipe.hpp>
#include <com/sun/star/io/TextInputStream.hpp>
#include <com/sun/star/io/WrongFormatException.hpp>
#include <com/sun/star/io/XActiveDataSink.hpp>
#include <com/sun/star/io/XActiveDataSource.hpp>
#include <com/sun/star/io/XInputStream.hpp>
#include <com/sun/star/io/XMarkableStream.hpp>
#include <com/sun/star/io/XObjectInputStream.hpp>
#include <com/sun/star/io/XObjectOutputStream.hpp>
#include <com/sun/star/io/XPersistObject.hpp>
#include <com/sun/star/lang/DisposedException.hpp>
#include <com/sun/star/lang/IllegalArgumentException.hpp>
#include <com/sun/star/lang/IndexOutOfBoundsException.hpp>
#include <com/sun/star/lang/Locale.hpp>
#include <com/sun/star/lang/WrappedTargetException.hpp>
#include <com/sun/star/lang/WrappedTargetRuntimeException.hpp>
#include <com/sun/star/lang/XComponent.hpp>
#include <com/sun/star/lang/XInitialization.hpp>
#include <com/sun/star/lang/XMultiServiceFactory.hpp>
#include <com/sun/star/lang/XServiceInfo.hpp>
#include <com/sun/star/lang/XUnoTunnel.hpp>
#include <com/sun/star/sdb/BooleanComparisonMode.hpp>
#include <com/sun/star/sdb/CommandType.hpp>
#include <com/sun/star/sdb/ErrorMessageDialog.hpp>
#include <com/sun/star/sdb/FilterDialog.hpp>
#include <com/sun/star/sdb/OrderDialog.hpp>
#include <com/sun/star/sdb/RowChangeAction.hpp>
#include <com/sun/star/sdb/RowChangeEvent.hpp>
#include <com/sun/star/sdb/RowSetVetoException.hpp>
#include <com/sun/star/sdb/SQLContext.hpp>
#include <com/sun/star/sdb/SQLErrorEvent.hpp>
#include <com/sun/star/sdb/XColumn.hpp>
#include <com/sun/star/sdb/XColumnUpdate.hpp>
#include <com/sun/star/sdb/XQueriesSupplier.hpp>
#include <com/sun/star/sdb/XRowSetChangeBroadcaster.hpp>
#include <com/sun/star/sdb/XRowSetSupplier.hpp>
#include <com/sun/star/sdb/XSQLQueryComposerFactory.hpp>
#include <com/sun/star/sdbc/ColumnValue.hpp>
#include <com/sun/star/sdbc/DataType.hpp>
#include <com/sun/star/sdbc/ResultSetConcurrency.hpp>
#include <com/sun/star/sdbc/ResultSetType.hpp>
#include <com/sun/star/sdbc/XConnection.hpp>
#include <com/sun/star/sdbc/XRowSet.hpp>
#include <com/sun/star/sdbcx/Privilege.hpp>
#include <com/sun/star/sdbcx/XColumnsSupplier.hpp>
#include <com/sun/star/sdbcx/XRowLocate.hpp>
#include <com/sun/star/sdbcx/XTablesSupplier.hpp>
#include <com/sun/star/style/VerticalAlignment.hpp>
#include <com/sun/star/task/InteractionHandler.hpp>
#include <com/sun/star/task/XInteractionContinuation.hpp>
#include <com/sun/star/task/XInteractionHandler.hpp>
#include <com/sun/star/task/XInteractionRequest.hpp>
#include <com/sun/star/text/WritingMode2.hpp>
#include <com/sun/star/text/XText.hpp>
#include <com/sun/star/ucb/AlreadyInitializedException.hpp>
#include <com/sun/star/ucb/PostCommandArgument2.hpp>
#include <com/sun/star/ucb/SimpleFileAccess.hpp>
#include <com/sun/star/ui/ImageType.hpp>
#include <com/sun/star/ui/XImageManager.hpp>
#include <com/sun/star/ui/XUIConfigurationManagerSupplier.hpp>
#include <com/sun/star/ui/dialogs/ExtendedFilePickerElementIds.hpp>
#include <com/sun/star/ui/dialogs/TemplateDescription.hpp>
#include <com/sun/star/ui/dialogs/XExecutableDialog.hpp>
#include <com/sun/star/ui/dialogs/XFilePicker.hpp>
#include <com/sun/star/ui/dialogs/XFilePickerControlAccess.hpp>
#include <com/sun/star/ui/theModuleUIConfigurationManagerSupplier.hpp>
#include <com/sun/star/uno/Any.hxx>
#include <com/sun/star/uno/Exception.hpp>
#include <com/sun/star/uno/Reference.hxx>
#include <com/sun/star/uno/RuntimeException.hpp>
#include <com/sun/star/uno/Sequence.hxx>
#include <com/sun/star/uno/Type.hxx>
#include <com/sun/star/uno/XInterface.hpp>
#include <com/sun/star/util/Date.hpp>
#include <com/sun/star/util/DateTime.hpp>
#include <com/sun/star/util/NumberFormat.hpp>
#include <com/sun/star/util/NumberFormatsSupplier.hpp>
#include <com/sun/star/util/NumberFormatter.hpp>
#include <com/sun/star/util/SearchAlgorithms.hpp>
#include <com/sun/star/util/Time.hpp>
#include <com/sun/star/util/URLTransformer.hpp>
#include <com/sun/star/util/XCancellable.hpp>
#include <com/sun/star/util/XCloneable.hpp>
#include <com/sun/star/util/XModifiable2.hpp>
#include <com/sun/star/util/XModifyBroadcaster.hpp>
#include <com/sun/star/util/XNumberFormatTypes.hpp>
#include <com/sun/star/util/XNumberFormatsSupplier.hpp>
#include <com/sun/star/util/XRefreshable.hpp>
#include <com/sun/star/util/XURLTransformer.hpp>
#include <com/sun/star/xforms/InvalidDataOnSubmitException.hpp>
#include <com/sun/star/xforms/XDataTypeRepository.hpp>
#include <com/sun/star/xforms/XFormsSupplier.hpp>
#include <com/sun/star/xforms/XModel.hpp>
#include <com/sun/star/xml/dom/DocumentBuilder.hpp>
#include <com/sun/star/xml/dom/NodeType.hpp>
#include <com/sun/star/xml/dom/XCharacterData.hpp>
#include <com/sun/star/xml/dom/XDocument.hpp>
#include <com/sun/star/xml/dom/XDocumentBuilder.hpp>
#include <com/sun/star/xml/dom/XDocumentFragment.hpp>
#include <com/sun/star/xml/dom/XElement.hpp>
#include <com/sun/star/xml/dom/XNamedNodeMap.hpp>
#include <com/sun/star/xml/dom/XNode.hpp>
#include <com/sun/star/xml/dom/XNodeList.hpp>
#include <com/sun/star/xml/dom/XText.hpp>
#include <com/sun/star/xml/dom/events/XDocumentEvent.hpp>
#include <com/sun/star/xml/dom/events/XEventListener.hpp>
#include <com/sun/star/xml/dom/events/XEventTarget.hpp>
#include <com/sun/star/xml/sax/Writer.hpp>
#include <com/sun/star/xml/sax/XSAXSerializable.hpp>
#include <com/sun/star/xml/xpath/Libxml2ExtensionHandle.hpp>
#include <com/sun/star/xml/xpath/XPathAPI.hpp>
#include <com/sun/star/xml/xpath/XPathExtension.hpp>
#include <com/sun/star/xml/xpath/XPathObjectType.hpp>
#include <com/sun/star/xml/xpath/XXPathObject.hpp>
#include <com/sun/star/xsd/DataTypeClass.hpp>
#include <com/sun/star/xsd/WhiteSpaceTreatment.hpp>
#include <com/sun/star/xsd/XDataType.hpp>
#include <comphelper/basicio.hxx>
#include <comphelper/container.hxx>
#include <comphelper/enumhelper.hxx>
#include <comphelper/eventattachermgr.hxx>
#include <comphelper/extract.hxx>
#include <comphelper/guarding.hxx>
#include <comphelper/interaction.hxx>
#include <comphelper/listenernotification.hxx>
#include <comphelper/namedvaluecollection.hxx>
#include <comphelper/numbers.hxx>
#include <comphelper/processfactory.hxx>
#include <comphelper/property.hxx>
#include <comphelper/propertysetinfo.hxx>
#include <comphelper/seqstream.hxx>
#include <comphelper/sequence.hxx>
#include <comphelper/servicehelper.hxx>
#include <comphelper/streamsection.hxx>
#include <comphelper/string.hxx>
#include <comphelper/types.hxx>
#include <comphelper/uno3.hxx>
#include <config_features.h>
#include <connectivity/dbconversion.hxx>
#include <connectivity/dbexception.hxx>
#include <connectivity/dbtools.hxx>
#include <connectivity/formattedcolumnvalue.hxx>
#include <connectivity/predicateinput.hxx>
#include <cppuhelper/exc_hlp.hxx>
#include <cppuhelper/factory.hxx>
#include <cppuhelper/implbase1.hxx>
#include <cppuhelper/implbase2.hxx>
#include <cppuhelper/propshlp.hxx>
#include <cppuhelper/queryinterface.hxx>
#include <cppuhelper/supportsservice.hxx>
#include <cppuhelper/typeprovider.hxx>
#include <cppuhelper/weak.hxx>
#include <cppuhelper/weakref.hxx>
#include <ctype.h>
#include <editeng/adjustitem.hxx>
#include <editeng/editeng.hxx>
#include <editeng/editobj.hxx>
#include <editeng/editstat.hxx>
#include <editeng/editview.hxx>
#include <editeng/eeitem.hxx>
#include <editeng/escapementitem.hxx>
#include <editeng/fhgtitem.hxx>
#include <editeng/fontitem.hxx>
#include <editeng/frmdiritem.hxx>
#include <editeng/langitem.hxx>
#include <editeng/lspcitem.hxx>
#include <editeng/scriptspaceitem.hxx>
#include <editeng/scripttypeitem.hxx>
#include <editeng/unofored.hxx>
#include <editeng/unoipset.hxx>
#include <editeng/unoprnms.hxx>
#include <editeng/wghtitem.hxx>
#include <functional>
#include <i18nlangtag/languagetag.hxx>
#include <iterator>
#include <limits.h>
#include <limits>
#include <list>
#include <memory>
#include <o3tl/compat_functional.hxx>
#include <ooo/vba/XVBAToOOEventDescGen.hpp>
#include <osl/diagnose.h>
#include <osl/file.hxx>
#include <osl/mutex.hxx>
#include <rtl/alloc.h>
#include <rtl/math.hxx>
#include <rtl/strbuf.hxx>
#include <rtl/string.hxx>
#include <rtl/tencinfo.h>
#include <rtl/textenc.h>
#include <rtl/ustrbuf.hxx>
#include <rtl/ustring.hxx>
#include <sal/macros.h>
#include <sal/types.h>
#include <sfx2/docfile.hxx>
#include <sfx2/filedlghelper.hxx>
#include <sfx2/imgmgr.hxx>
#include <sfx2/msgpool.hxx>
#include <sfx2/objsh.hxx>
#include <sfx2/sfxuno.hxx>
#include <stdio.h>
#include <string.h>
#include <svl/inettype.hxx>
#include <svl/itempool.hxx>
#include <svl/itemset.hxx>
#include <svl/languageoptions.hxx>
#include <svl/numuno.hxx>
#include <svl/undo.hxx>
#include <svl/urihelper.hxx>
#include <svl/zforlist.hxx>
#include <svtools/cliplistener.hxx>
#include <svtools/imageresourceaccess.hxx>
#include <svtools/transfer.hxx>
#include <svx/svdobj.hxx>
#include <svx/svdpool.hxx>
#include <toolkit/awt/vclxdevice.hxx>
#include <toolkit/helper/emptyfontdescriptor.hxx>
#include <toolkit/helper/vclunohelper.hxx>
#include <tools/color.hxx>
#include <tools/date.hxx>
#include <tools/datetime.hxx>
#include <tools/debug.hxx>
#include <tools/diagnose_ex.h>
#include <tools/inetmsg.hxx>
#include <tools/inetstrm.hxx>
#include <tools/mapunit.hxx>
#include <tools/simplerm.hxx>
#include <tools/solar.h>
#include <tools/stream.hxx>
#include <tools/time.hxx>
#include <tools/urlobj.hxx>
#include <tools/wintypes.hxx>
#include <ucbhelper/activedatasink.hxx>
#include <ucbhelper/content.hxx>
#include <uno/mapping.hxx>
#include <unotools/datetime.hxx>
#include <unotools/desktopterminationobserver.hxx>
#include <unotools/lingucfg.hxx>
#include <unotools/localedatawrapper.hxx>
#include <unotools/sharedunocomponent.hxx>
#include <unotools/streamhelper.hxx>
#include <unotools/syslocale.hxx>
#include <unotools/textsearch.hxx>
#include <unotools/ucblockbytes.hxx>
#include <unotools/ucbstreamhelper.hxx>
#include <vcl/bmpacc.hxx>
#include <vcl/cvtgrf.hxx>
#include <vcl/fixed.hxx>
#include <vcl/graphicfilter.hxx>
#include <vcl/keycodes.hxx>
#include <vcl/mapmod.hxx>
#include <vcl/msgbox.hxx>
#include <vcl/outdev.hxx>
#include <vcl/settings.hxx>
#include <vcl/stdtext.hxx>
#include <vcl/svapp.hxx>
#include <vcl/timer.hxx>
#include <vcl/waitobj.hxx>
#include <vcl/window.hxx>
#include <vector>

/* vim:set shiftwidth=4 softtabstop=4 expandtab: */

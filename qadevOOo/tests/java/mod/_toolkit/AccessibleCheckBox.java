/*
 * This file is part of the LibreOffice project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 * This file incorporates work covered by the following license notice:
 *
 *   Licensed to the Apache Software Foundation (ASF) under one or more
 *   contributor license agreements. See the NOTICE file distributed
 *   with this work for additional information regarding copyright
 *   ownership. The ASF licenses this file to you under the Apache
 *   License, Version 2.0 (the "License"); you may not use this file
 *   except in compliance with the License. You may obtain a copy of
 *   the License at http://www.apache.org/licenses/LICENSE-2.0 .
 */
package mod._toolkit;

import com.sun.star.accessibility.AccessibleRole;
import com.sun.star.accessibility.XAccessible;
import com.sun.star.accessibility.XAccessibleAction;
import com.sun.star.accessibility.XAccessibleComponent;
import com.sun.star.accessibility.XAccessibleText;
import com.sun.star.awt.XExtendedToolkit;
import com.sun.star.awt.XWindow;
import com.sun.star.frame.XController;
import com.sun.star.frame.XDispatch;
import com.sun.star.frame.XDispatchProvider;
import com.sun.star.frame.XModel;
import com.sun.star.lang.XMultiServiceFactory;
import com.sun.star.text.XTextDocument;
import com.sun.star.uno.UnoRuntime;
import com.sun.star.uno.XInterface;
import com.sun.star.util.URL;
import com.sun.star.util.XURLTransformer;

import java.io.PrintWriter;

import lib.StatusException;
import lib.TestCase;
import lib.TestEnvironment;
import lib.TestParameters;

import util.AccessibilityTools;
import util.SOfficeFactory;
import util.utils;


/**
 * Test for object which is represented by accessible compoent of
 * check box in 'InsertTable' dialog. <p>
 *
 * Object implements the following interfaces :
 * <ul>
 *  <li> <code>::com::sun::star::accessibility::XAccessibleExtendedComponent</code></li>
 *  <li> <code>::com::sun::star::accessibility::XAccessibleEventBroadcaster</code></li>
 *  <li> <code>::com::sun::star::accessibility::XAccessibleComponent</code></li>
 *  <li> <code>::com::sun::star::accessibility::XAccessibleValue</code></li>
 *  <li> <code>::com::sun::star::accessibility::XAccessibleAction</code></li>
 *  <li> <code>::com::sun::star::accessibility::XAccessibleContext</code></li>
 *  <li> <code>::com::sun::star::accessibility::XAccessibleText</code></li>
 * </ul> <p>
 *
 * @see com.sun.star.accessibility.XAccessibleExtendedComponent
 * @see com.sun.star.accessibility.XAccessibleEventBroadcaster
 * @see com.sun.star.accessibility.XAccessibleComponent
 * @see com.sun.star.accessibility.XAccessibleValue
 * @see com.sun.star.accessibility.XAccessibleAction
 * @see com.sun.star.accessibility.XAccessibleContext
 * @see com.sun.star.accessibility.XAccessibleText
 * @see ifc.accessibility._XAccessibleExtendedComponent
 * @see ifc.accessibility._XAccessibleEventBroadcaster
 * @see ifc.accessibility._XAccessibleComponent
 * @see ifc.accessibility._XAccessibleValue
 * @see ifc.accessibility._XAccessibleAction
 * @see ifc.accessibility._XAccessibleContext
 * @see ifc.accessibility._XAccessibleText
 */
public class AccessibleCheckBox extends TestCase {
    private static XTextDocument xTextDoc = null;
    private static XAccessibleAction action = null;
    private static DiagThread psDiag = null;

    /**
     * Opens 'Insert Table' dialog using document dispatch provider
     * running in a separate thread. Finds active top window (the dialog
     * window) and finds first accessible check box walking through the
     * accessible component tree.
     */
    @Override
    protected TestEnvironment createTestEnvironment(TestParameters Param,
                                                    PrintWriter log) {
        XMultiServiceFactory msf = Param.getMSF();
        log.println("Creating text document");

        if (xTextDoc == null) {
            try {
                SOfficeFactory SOF = SOfficeFactory.getFactory(msf);
                xTextDoc = SOF.createTextDoc(null);
            } catch (com.sun.star.uno.Exception e) {
                throw new StatusException("Can't create document", e);
            }
        }

        util.utils.shortWait(Param.getInt("ShortWait"));

        XInterface oObj = null;

        log.println("getting toolkit");

        try {
            oObj = (XInterface) msf.createInstance("com.sun.star.awt.Toolkit");
        } catch (com.sun.star.uno.Exception e) {
            log.println("Couldn't get toolkit");
            e.printStackTrace(log);
            throw new StatusException("Couldn't get toolkit", e);
        }

        XExtendedToolkit tk = UnoRuntime.queryInterface(
                                      XExtendedToolkit.class, oObj);

        util.utils.shortWait(Param.getInt("ShortWait"));

        log.println("Opening Dialog in second thread");

        psDiag = new DiagThread(xTextDoc, msf);
        psDiag.start();

        util.utils.shortWait(Param.getInt("ShortWait"));

        new AccessibilityTools();

        util.utils.shortWait(Param.getInt("ShortWait"));

        log.println("Getting the active TopWindow");

        XWindow xWindow = UnoRuntime.queryInterface(XWindow.class,
                                                              tk.getActiveTopWindow());

        XAccessible xRoot = AccessibilityTools.getAccessibleObject(xWindow);


        AccessibilityTools.printAccessibleTree(log, xRoot, Param.getBool(util.PropertyName.DEBUG_IS_ACTIVE));
        oObj = AccessibilityTools.getAccessibleObjectForRole(xRoot, AccessibleRole.PUSH_BUTTON,
                                             "Cancel");

        action = UnoRuntime.queryInterface(
                         XAccessibleAction.class, oObj);

        oObj = AccessibilityTools.getAccessibleObjectForRole(xRoot, AccessibleRole.CHECK_BOX);

        log.println("ImplementationName " + utils.getImplName(oObj));

        TestEnvironment tEnv = new TestEnvironment(oObj);

        final XAccessibleComponent acomp = UnoRuntime.queryInterface(
                                                   XAccessibleComponent.class,
                                                   oObj);

        tEnv.addObjRelation("EventProducer",
                            new ifc.accessibility._XAccessibleEventBroadcaster.EventProducer() {
            public void fireEvent() {
                System.out.println("Grabbing focus ... ");
                acomp.grabFocus();
            }
        });

        XAccessibleText text = UnoRuntime.queryInterface(
                                       XAccessibleText.class, oObj);

        tEnv.addObjRelation("XAccessibleText.Text", text.getText());

        tEnv.addObjRelation("EditOnly",
                            "This method isn't supported in this component");

        tEnv.addObjRelation("LimitedBounds", "yes");

        return tEnv;
    }

    /**
     * Closes the dialog using accessible button 'Cancel' found in
     * <code>createTestEnvironment()</code>.
     */
    @Override
    protected void cleanup(TestParameters Param, PrintWriter log) {
        try {
            log.println("closing dialog");
            action.doAccessibleAction(0);
            log.println("interrupting corresponding Thread");
            psDiag.interrupt();
            log.println("closing the document");
            util.DesktopTools.closeDoc(xTextDoc);
            log.println("reinitialize the variable");
            xTextDoc = null;
        } catch (com.sun.star.lang.IndexOutOfBoundsException ioe) {
            log.println("Couldn't close dialog");
        } catch (com.sun.star.lang.DisposedException de) {
            log.println("Dialog already disposed");
        }
    }

    @Override
    protected void initialize(TestParameters Param, PrintWriter log) {
    }

    /**
     * Thread for opening modal dialog 'Insert Table'.
     */
    public class DiagThread extends Thread {
        public XTextDocument xTextDoc = null;
        public XMultiServiceFactory msf = null;

        public DiagThread(XTextDocument xTextDoc, XMultiServiceFactory msf) {
            this.xTextDoc = xTextDoc;
            this.msf = msf;
        }

        @Override
        public void run() {
            XModel aModel = UnoRuntime.queryInterface(XModel.class,
                                                               xTextDoc);

            XController xController = aModel.getCurrentController();

            //Opening PrinterSetupDialog
            try {
                String aSlotID = ".uno:InsertTable";
                XDispatchProvider xDispProv = UnoRuntime.queryInterface(
                                                      XDispatchProvider.class,
                                                      xController);
                XURLTransformer xParser = UnoRuntime.queryInterface(
                                                  XURLTransformer.class,
                                                  msf.createInstance(
                                                          "com.sun.star.util.URLTransformer"));

                // Because it's an in/out parameter we must use an array of URL objects.
                URL[] aParseURL = new URL[1];
                aParseURL[0] = new URL();
                aParseURL[0].Complete = aSlotID;
                xParser.parseStrict(aParseURL);

                URL aURL = aParseURL[0];
                XDispatch xDispatcher = xDispProv.queryDispatch(aURL, "", 0);

                if (xDispatcher != null) {
                    xDispatcher.dispatch(aURL, null);
                }
            } catch (com.sun.star.uno.Exception e) {
                log.println("Couldn't open dialog");
            }
        }
    }
}
/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
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
#ifndef INCLUDED_SVX_SOURCE_INC_FMOBJ_HXX
#define INCLUDED_SVX_SOURCE_INC_FMOBJ_HXX

#include <svx/svdouno.hxx>
#include <com/sun/star/container/XIndexContainer.hpp>
#include <com/sun/star/form/XForms.hpp>
#include <com/sun/star/script/ScriptEventDescriptor.hpp>


// FmFormObj

class SVX_DLLPUBLIC FmFormObj: public SdrUnoObj
{
    ::com::sun::star::uno::Sequence< ::com::sun::star::script::ScriptEventDescriptor >  aEvts;  // events des Objects
    ::com::sun::star::uno::Sequence< ::com::sun::star::script::ScriptEventDescriptor>   m_aEventsHistory;
                // valid if and only if m_pEnvironmentHistory != NULL, this are the events which we're set when
                // m_pEnvironmentHistory was created

    // Informationen fuer die Controlumgebung
    // werden nur vorgehalten, wenn ein Object sich nicht in einer Objectliste befindet
    ::com::sun::star::uno::Reference< ::com::sun::star::container::XIndexContainer>     m_xParent;
    ::com::sun::star::uno::Reference< ::com::sun::star::form::XForms >                  m_xEnvironmentHistory;
    sal_Int32           m_nPos;

    OutputDevice*       m_pLastKnownRefDevice;
                            // the last ref device we know, as set at the model
                            // only to be used for comparison with the current ref device!

public:
    FmFormObj(const OUString& rModelName);
    FmFormObj();

    TYPEINFO_VISIBILITY_OVERRIDE(SAL_DLLPRIVATE);

    SAL_DLLPRIVATE const ::com::sun::star::uno::Reference< ::com::sun::star::container::XIndexContainer>&
        GetOriginalParent() const { return m_xParent; }
    SAL_DLLPRIVATE const ::com::sun::star::uno::Sequence< ::com::sun::star::script::ScriptEventDescriptor >&
        GetOriginalEvents() const { return aEvts; }
    SAL_DLLPRIVATE sal_Int32
        GetOriginalIndex() const { return m_nPos; }

    SAL_DLLPRIVATE void SetObjEnv(
            const ::com::sun::star::uno::Reference< ::com::sun::star::container::XIndexContainer>& xForm,
            const sal_Int32 nIdx,
            const ::com::sun::star::uno::Sequence< ::com::sun::star::script::ScriptEventDescriptor >& rEvts );
    SAL_DLLPRIVATE void ClearObjEnv();

public:
    SAL_DLLPRIVATE virtual ~FmFormObj();
    SAL_DLLPRIVATE virtual void SetPage(SdrPage* pNewPage) SAL_OVERRIDE;

    SAL_DLLPRIVATE virtual sal_uInt32 GetObjInventor() const SAL_OVERRIDE;
    SAL_DLLPRIVATE virtual sal_uInt16 GetObjIdentifier() const SAL_OVERRIDE;
    SAL_DLLPRIVATE virtual void NbcReformatText() SAL_OVERRIDE;

    SAL_DLLPRIVATE virtual FmFormObj* Clone() const SAL_OVERRIDE;
    // #116235# virtual SdrObject*  Clone(SdrPage* pPage, SdrModel* pModel) const;
    SAL_DLLPRIVATE FmFormObj& operator= (const FmFormObj& rObj);

    SAL_DLLPRIVATE virtual void SetModel(SdrModel* pNewModel) SAL_OVERRIDE;

    SAL_DLLPRIVATE virtual void clonedFrom(const FmFormObj* _pSource);

    SAL_DLLPRIVATE static ::com::sun::star::uno::Reference< ::com::sun::star::uno::XInterface> ensureModelEnv(
                  const ::com::sun::star::uno::Reference< ::com::sun::star::uno::XInterface>& _rSourceContainer,
                  const ::com::sun::star::uno::Reference< ::com::sun::star::form::XForms>& _rTopLevelDestContainer);

    /** returns the FmFormObj behind the given SdrObject

        In case the SdrObject *is* an FmFormObject, this is a simple cast. In case the SdrObject
        is a virtual object whose referenced object is an FmFormObj, then this referenced
        object is returned. In all other cases, NULL is returned.
    */
    SAL_DLLPRIVATE static       FmFormObj* GetFormObject( SdrObject* _pSdrObject );
    SAL_DLLPRIVATE static const FmFormObj* GetFormObject( const SdrObject* _pSdrObject );

    SAL_DLLPRIVATE virtual void SetUnoControlModel( const ::com::sun::star::uno::Reference< com::sun::star::awt::XControlModel >& _rxModel ) SAL_OVERRIDE;

protected:
    SAL_DLLPRIVATE virtual bool        EndCreate( SdrDragStat& rStat, SdrCreateCmd eCmd ) SAL_OVERRIDE;
    SAL_DLLPRIVATE virtual void        BrkCreate( SdrDragStat& rStat ) SAL_OVERRIDE;

    // #i70852# overload Layer interface to force to FormColtrol layer
    SAL_DLLPRIVATE virtual SdrLayerID GetLayer() const SAL_OVERRIDE;
    SAL_DLLPRIVATE virtual void NbcSetLayer(SdrLayerID nLayer) SAL_OVERRIDE;

private:
    /** isolates the control model from its form component hierarchy, i.e. removes it from
        its parent.
    */
    SAL_DLLPRIVATE void    impl_isolateControlModel_nothrow();

    /** forwards the reference device of our SdrModel to the control model
    */
    SAL_DLLPRIVATE void    impl_checkRefDevice_nothrow( bool _force = false );
};


#endif // _FM_FMOBJ_HXX

/* vim:set shiftwidth=4 softtabstop=4 expandtab: */

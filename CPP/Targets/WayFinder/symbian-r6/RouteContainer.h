/*
  Copyright (c) 1999 - 2010, Vodafone Group Services Ltd
  All rights reserved.

  Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

  * Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
  * Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
  * Neither the name of the Vodafone Group Services Ltd nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/


#ifndef ROUTECONTAINER_H
#define ROUTECONTAINER_H

// INCLUDES
#include <coecntrl.h>
#include <aknutils.h>
#include "Log.h" 
// FORWARD DECLARATIONS

// CLASS DECLARATION

/**
 *  CRouteContainer  container control class.
 *  
 */
class CRouteContainer : public CCoeControl, MCoeControlObserver
{
public: // Constructors and destructor

   static class CRouteContainer* NewL(class CRouteView* aParent,
         const TRect& aRect,
         const TDesC& aMbmName,
         isab::Log* aLog,
         class CWayFinderAppUi* aAppUi);

   /**
    * Destructor.
    */
   ~CRouteContainer();

private:

   CRouteContainer(isab::Log* aLog) : iLog(aLog) {}
   /**
    * EPOC default constructor.
    * @param aRect Frame rectangle for container.
    */
   void ConstructL(CRouteView* aParent,
         const TRect& aRect,
         const TDesC& aMbmName,
         class CWayFinderAppUi* aAppUi);

public: // New functions

   void SetHeading( TInt aHeading );
   void SetSpeed( TInt aSpeed );
   
   void SetDestination( TDesC &aDestination );

   void SetDistanceToGoal( TInt32 aDistance );
   
   void SetETG( TInt32 aTime );
   void SetETA( TDesC& eta );
   void SetUpLabel(class CEikLabel* aLabel,
                   HBufC* aText, 
                   class CCoeControl& aContainerWindow);

   /**
    * Turns night mode on or off depending on aNightMode.
    * @param aNightMode True if nightmode should be switched on
    *                   False if nightmode should be switched off.
    */
   void SetNightModeL(TBool aNightMode);


public: // Functions from base classes

private: // Functions from base classes

   /**
    * From CoeControl,SizeChanged.
    */
   void SizeChanged();

   /**
    * From CoeControl,CountComponentControls.
    */
   TInt CountComponentControls() const;

   /**
    * From CCoeControl,ComponentControl.
    */
   CCoeControl* ComponentControl(TInt aIndex) const;

   /**
    * From CCoeControl,Draw.
    */
   void Draw(const TRect& aRect) const;

   /**
    * From ?base_class ?member_description
    */
   // event handling section
   // e.g Listbox events
   void HandleControlEventL(CCoeControl* aControl,TCoeEvent aEventType);

   /**
    * From CCoeControl, HandleResourceChange.
    */
   void HandleResourceChange(TInt aType);

   void PositionOfControlChanged(CCoeControl *control, TPoint pos);


private: //data

   CRouteView* iView;

   class CEikLabel* iDestinationLabel;
   class CEikLabel* iDistanceLabel;
   class CEikLabel* iETALabel;
   class CEikLabel* iETGLabel;
   class CEikLabel* iSpeedLabel;

   class CEikLabel* iDestinationInfoLabel;
   class CEikLabel* iDistanceInfoLabel;
   class CEikLabel* iETGInfoLabel;
   class CEikLabel* iETAInfoLabel;
   class CEikLabel* iSpeedInfoLabel;

   class CEikDurationEditor* iDurationETG;

   class CInfoCompass* iCompass;

   class CWayFinderAppUi* iAppUi;

   isab::Log* iLog;

   HBufC* iMbmName;
   TInt iR, iG, iB;
   TRgb iBubblePenColor;
   TRgb iBubbleBgColor;
};

#endif

// End of File
